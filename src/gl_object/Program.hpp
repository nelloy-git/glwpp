#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Shader.hpp"

namespace glwpp::GL {

namespace detail {

class ProgramBase : public Object {
public:
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void attach(const ShaderBase& shader){
        return _addCallGl<&GladGLContext::AttachShader>(id(), shader.id());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void link(){
        return _addCallGl<&GladGLContext::LinkProgram>(id());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void validate(){
        return _addCallGl<&GladGLContext::ValidateProgram>(id());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void use(){
        return _addCallGl<&GladGLContext::UseProgram>(id());
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribLocation(const ConstString& name){
        return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
            return ctx.gl.GetAttribLocation(id, name->c_str());
        }, id(), name);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void bindAttribLocation(const ConstUint& attr_index, const ConstString& name){
        return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstUint& attr_index, const ConstString& name){
            return ctx.gl.BindAttribLocation(id, attr_index, name->c_str());
        }, id(), attr_index, name);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getUniformLocation(const ConstString& name){
        return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
            return ctx.gl.GetUniformLocation(id, name->c_str());
        }, id(), name);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Uint getUniformBlockIndex(const ConstString& name){
        return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
            return ctx.gl.GetUniformBlockIndex(id, name->c_str());
        }, id(), name);
    }




    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isLinked(){
        static const ConstEnum pname(GL_LINK_STATUS);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isValidated(){
        static const ConstEnum pname(GL_VALIDATE_STATUS);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttachedShadersCount(){
        static const ConstEnum pname(GL_ATTACHED_SHADERS);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getActiveAttributesCount(){
        static const ConstEnum pname(GL_ACTIVE_ATTRIBUTES);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getActiveAttributeMaxNameLength(){
        static const ConstEnum pname(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getActiveUniformsCount(){
        static const ConstEnum pname(GL_ACTIVE_UNIFORMS);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getActiveUniformMaxNameLength(){
        static const ConstEnum pname(GL_ACTIVE_UNIFORM_MAX_LENGTH);
        return _getParamiAs<Int::type, is_gl_thread>(pname);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT String getInfoLog(){
        return _callGLCustom([](Context& ctx, const ConstUint& id){
            int len;
            std::string dst;
            ctx.gl.GetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
            dst.resize(len);
            ctx.gl.GetProgramInfoLog(*id, len, &len, dst.data());
            return dst;
        }, id());
    }



    EXPORT virtual ~ProgramBase(){
        if (auto ctx = lockCtx()){
            _addCallGl<&GladGLContext::DeleteProgram>(id());
        }
    }

protected:
    ProgramBase(const std::shared_ptr<Context>& ctx) :
        Object(ctx, ctx->addCallCustom([](Context& ctx){
            return ctx.gl.CreateProgram();
        })){
    }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParamiAs(const ConstEnum& pname){
        Int dst;
        _addCallGl<&GladGLContext::GetProgramiv, is_gl_thread>(id(), pname, dst);
        return dst.reinterpret<T>();
    }

};

} // namespace detail

class Program : public detail::ProgramBase, public SharedObject<Program> {
public:
    EXPORT static std::shared_ptr<Program> New(const std::shared_ptr<Context>& ctx){
        return std::shared_ptr<Program>(new Program(ctx));
    }

protected:
    Program(const std::shared_ptr<Context>& ctx) : 
        ProgramBase(ctx){
    }
};

} // namespace glwpp::GL