#pragma once

#include "gl_object/Object.hpp"

namespace glwpp::GL {

namespace detail {

class ShaderBase : public Object {
public:
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void source(const ConstString& code){
        return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& code){
            auto c_str = code->c_str();
            int len = static_cast<int>(code->size());
            cts.gl.ShaderSource(id, 1, &c_str, &len);
            gl.debug(src_loc);
        }, id(), code);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void compile(){
       return _callGL<&GladGLContext::CompileShader>(id());
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getType(){
        static const ConstEnum pname(GL_SHADER_TYPE);
        return _getParamiAs<Enum::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isCompiled(){
        static const ConstEnum pname(GL_COMPILE_STATUS);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getSourceLength(){
        static const ConstEnum pname(GL_SHADER_SOURCE_LENGTH);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT String getInfoLog(){
        return _callGLCustom([](Context& ctx, const ConstUint& id){
            int len;
            std::string dst;
            ctx.gl.GetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
            dst.resize(len);
            ctx.gl.GetShaderInfoLog(*id, len, &len, dst.data());
            return dst;
        }, id());
    }



    EXPORT virtual ~ShaderBase(){
        if (auto ctx = lockCtx()){
            _addCallGl<&GladGLContext::DeleteShader>(id());
        }
    }

protected:
    ShaderBase(const std::shared_ptr<Context>& ctx, const ConstEnum& type) :
        Object(ctx, ctx->addCallCustom([](Context& ctx, const ConstEnum& type){
            return ctx.gl.CreateShader(type);
        }, type)){
    }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParamiAs(const ConstEnum& pname){
        Int dst;
        _addCallGl<&GladGLContext::GetShaderiv, is_gl_thread>(id(), pname, dst);
        return dst.reinterpret<T>();
    }

};

} // namespace detail

class Shader : public detail::ShaderBase, public SharedObject<Shader> {
public:
    EXPORT static std::shared_ptr<Shader> New(const std::shared_ptr<Context>& ctx, const ConstEnum& type){
        return std::shared_ptr<Shader>(new Shader(ctx, type));
    }

protected:
    Shader(const std::shared_ptr<Context>& ctx, const ConstEnum& type) : 
        ShaderBase(ctx, type){
    }
};

} // namespace glwpp::GL