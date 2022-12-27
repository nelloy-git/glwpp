#pragma once

#include "gl_object/Shader.hpp"

namespace glwpp::GL {

class Program : public Handler {
public:
    Program(Valuable<Context&> auto&& ctx,
            Valuable<const SrcLoc&> auto&& src_loc) : 
        Handler(GetValuable(ctx), new GLuint(0), &Handler::DELETER<_free>, GetValuable(src_loc).add()){
        call<[](Context& ctx, GLuint& dst, const SrcLoc& src_loc){
            dst = ctx.gl.CreateProgram(src_loc);
        }, IsGlThread::Unknown>(data, GetValuable(src_loc).add());
    }
    virtual ~Program(){}

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void attach(Valuable<const Shader&> auto&& shader,
                Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const Shader& shader, const SrcLoc& src_loc){
            ctx.gl.AttachShader(id, shader.id().value(), src_loc);
        }, is_gl_thread>(id(), shader, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void link(Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::LinkProgram, is_gl_thread>(id(), GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void validate(Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::ValidateProgram, is_gl_thread>(id(), GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void use(Valuable<const SrcLoc&> auto&& src_loc){
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
    
    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Uint getUniformBlockIndex(const ConstString& name){
    //     return _addCallCustom<is_gl_thread>([](Context& ctx, const ConstUint& id, const ConstString& name){
    //         return ctx.gl.GetUniformBlockIndex(id, name->c_str());
    //     }, id(), name);
    // }




    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::optional<GLboolean>> isLinked(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLboolean, GL_LINK_STATUS, is_gl_thread>(GetValuable(src_loc).add());
    }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Boolean isValidated(){
    //     static const ConstEnum pname(GL_VALIDATE_STATUS);
    //     return _getParamiAs<Boolean::type, is_gl_thread>(pname);
    // }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::optional<GLint>> getAttachedShadersCount(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLint, GL_ATTACHED_SHADERS, is_gl_thread>(GetValuable(src_loc).add());
    }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveAttributesCount(){
    //     static const ConstEnum pname(GL_ACTIVE_ATTRIBUTES);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveAttributeMaxNameLength(){
    //     static const ConstEnum pname(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveUniformsCount(){
    //     static const ConstEnum pname(GL_ACTIVE_UNIFORMS);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }

    // template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    // Int getActiveUniformMaxNameLength(){
    //     static const ConstEnum pname(GL_ACTIVE_UNIFORM_MAX_LENGTH);
    //     return _getParamiAs<Int::type, is_gl_thread>(pname);
    // }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::optional<std::string>> getInfoLog(Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint id){
            int len;
            std::string dst;
            ctx.gl.GetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
            dst.resize(len);
            ctx.gl.GetProgramInfoLog(id, len, &len, dst.data());
            return dst;
        }, is_gl_thread>(id());
    }

protected:
    static void _free(Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
        ctx.gl.DeleteProgram(*id_ptr, src_loc);
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