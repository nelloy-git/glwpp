#pragma once

#include "gl_object/Handler.hpp"

namespace glwpp::GL {

class Shader : public Handler {
public:
    Shader(Valuable<Context&> auto&& ctx,
           Valuable<const GLenum&> auto&& type,
           Valuable<const SrcLoc&> auto&& src_loc) : 
        Handler(GetValuable(ctx), GetDeleter<&_free>(), GetValuable(src_loc).add()){
        call<[](Context& ctx, const GLenum& type, GLuint& dst, const SrcLoc& src_loc){
            dst = ctx.gl.CreateShader(type, src_loc);
        }, IsGlThread::Unknown>(type, data, GetValuable(src_loc).add());
    }
    virtual ~Shader(){}

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> source(Valuable<const std::string&> auto&& code,
                                    Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint id, const std::string& code, const SrcLoc& src_loc){
            auto c_str = code.c_str();
            int len = static_cast<int>(code.size());
            ctx.gl.ShaderSource(id, 1, &c_str, &len, src_loc);
        }, is_gl_thread>(id(), code, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<void>> compile(Valuable<const SrcLoc&> auto&& src_loc){
       return callGLapi<&GLapi::CompileShader, is_gl_thread>(id(), src_loc);
    }



    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLenum>> getType(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLenum, GLapi::GL_SHADER_TYPE, is_gl_thread>(src_loc);
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLboolean>> isCompiled(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLboolean, GLapi::GL_COMPILE_STATUS, is_gl_thread>(src_loc);
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<GLint>> getSourceLength(Valuable<const SrcLoc&> auto&& src_loc){
        return _getParamiAs<GLint, GLapi::GL_SHADER_SOURCE_LENGTH, is_gl_thread>(src_loc);
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<std::future<std::string>> getInfoLog(Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint id){
            int len;
            std::string dst;
            ctx.gl.GetShaderiv(id, GLapi::GL_INFO_LOG_LENGTH, &len);
            dst.resize(len);
            ctx.gl.GetShaderInfoLog(id, len, &len, dst.data());
            return dst;
        }, is_gl_thread>(id());
    }



protected:
    static void _free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
        ctx.gl.DeleteShader(id, src_loc);
    }

    template<typename T, GLenum Pname, IsGlThread is_gl_thread>
    inline auto _getParamiAs(Valuable<const SrcLoc&> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const SrcLoc& src_loc){
            GLint dst;
            ctx.gl.GetShaderiv(id, Pname, &dst, src_loc);
            return static_cast<T>(dst);
        }, is_gl_thread>(id(), src_loc);
    }

};

} // namespace glwpp::GL