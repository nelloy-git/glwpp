#pragma once

#include "gl_object/Shader.hpp"

namespace glwpp::GL {

class Program : public Handler {
public:
    Program(Valuable<Context&> auto&& ctx,
            Valuable<const SrcLoc&> auto&& src_loc) : 
        Handler(GetValuable(ctx), GetDeleter<&_free>(), GetValuable(src_loc).add()){
        call<[](Context& ctx, GLuint& dst, const SrcLoc& src_loc){
            dst = ctx.gl.CreateProgram(src_loc);
        }, IsGlThread::Unknown>(data, GetValuable(src_loc).add());
    }
    virtual ~Program(){}

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> attach(Valuable<const Shader&> auto&& shader,
                Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const Shader& shader, const SrcLoc& src_loc){
            ctx.gl.AttachShader(id, shader.id().value(), src_loc);
        }, is_gl_thread>(id(), shader, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> link(Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::LinkProgram, is_gl_thread>(id(), GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> validate(Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::ValidateProgram, is_gl_thread>(id(), GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> use(Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::UseProgram, is_gl_thread>(id(), GetValuable(src_loc).add());
    }



    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getAttribLocation(const ConstString& name){
    //     return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
    //         return ctx.gl.GetAttribLocation(id, name->c_str());
    //     }, id(), name);
    // }
    
    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // void bindAttribLocation(const ConstUint& attr_index, const ConstString& name){
    //     return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstUint& attr_index, const ConstString& name){
    //         return ctx.gl.BindAttribLocation(id, attr_index, name->c_str());
    //     }, id(), attr_index, name);
    // }
    
    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getUniformLocation(const ConstString& name){
    //     return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
    //         return ctx.gl.GetUniformLocation(id, name->c_str());
    //     }, id(), name);
    // }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLuint>> getUniformBlockIndex(Valuable<const std::string&> auto&& name,
                                                    Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& program, const std::string& name, const SrcLoc& src_loc){
            return ctx.gl.GetUniformBlockIndex(program, name.c_str(), src_loc);
        }, is_gl_thread>(id(), name, src_loc);
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> setUniformBlockBinding(Valuable<const GLuint&> auto&& block_index,
                                                    Valuable<const GLuint&> auto&& block_binding,
                                                    Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::UniformBlockBinding, is_gl_thread>(id(), block_index, block_binding, GetValuable(src_loc).add());
    }




    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLboolean>> isLinked(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLboolean, GLapi::GL_LINK_STATUS, is_gl_thread>(GetValuable(src_loc).add());
    }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Boolean isValidated(){
    //     static const ConstEnum pname(GLapi::GL_VALIDATE_STATUS);
    //     return _getParamiAs<Boolean::type, is_gl_thread>(pname);
    // }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLint>> getAttachedShadersCount(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLint, GLapi::GL_ATTACHED_SHADERS, is_gl_thread>(GetValuable(src_loc).add());
    }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveAttributesCount(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_ATTRIBUTES);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveAttributeMaxNameLength(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveUniformsCount(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_UNIFORMS);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveUniformMaxNameLength(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_UNIFORM_MAX_LENGTH);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<std::string>> getInfoLog(Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint id){
            int len;
            std::string dst;
            ctx.gl.GetProgramiv(id, GLapi::GL_INFO_LOG_LENGTH, &len);
            dst.resize(len);
            ctx.gl.GetProgramInfoLog(id, len, &len, dst.data());
            return dst;
        }, is_gl_thread>(id());
    }

protected:
    static void _free(Context& ctx, const GLuint id, const SrcLoc& src_loc){
        ctx.gl.DeleteProgram(id, src_loc);
    }
    
    template<typename T, GLenum Pname, IsGlThread is_gl_thread>
    inline auto _getParamiAs(Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const SrcLoc& src_loc){
            GLint dst;
            ctx.gl.GetProgramiv(id, Pname, &dst, src_loc);
            return static_cast<T>(dst);
        }, is_gl_thread>(id(), src_loc);
    }

};

} // namespace glwpp::GL