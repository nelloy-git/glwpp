#include "glwpp/gl/obj/Shader.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

Shader::Shader(const wptr<Context>& wctx, const Val<const gl::ShaderType>& type,
               const Val<const SrcLoc>& src_loc) :
    Object(wctx, src_loc, &Shader::_initer, &Shader::_deleter, type){
}

           
bool Shader::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                         const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glGetShaderiv, id(), param, dst);
}


bool Shader::getType(const Val<gl::ShaderType> dst,
                     const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_SHADER_TYPE, src_loc, check_ctx);
}

bool Shader::isCompiled(const Val<bool> dst,
                        const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_COMPILE_STATUS, src_loc, check_ctx);
}

bool Shader::getSourceLength(const Val<gl::Int> dst,
                             const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_SHADER_SOURCE_LENGTH, src_loc, check_ctx);
}

namespace {
    void _glInfoLog(const UInt& shader, std::string& dst){
        Int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        dst.reserve(length);
        glGetShaderInfoLog(shader, length, &length, dst.data());
    }
}

bool Shader::getInfoLog(const Val<std::string> dst,
                        const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, _glInfoLog, id(), dst);
}

namespace {
    void _glShaderSource(const UInt& shader, const std::string& code){
        auto c_code = code.c_str();
        glShaderSource(shader, 1, &c_code, nullptr);
    }
}

bool Shader::setSource(const Val<const std::string>& code,
                       const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, _glShaderSource, id(), code);
}

bool Shader::compile(const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glCompileShader, id());
}

void Shader::_initer(UInt& dst, const gl::ShaderType& type){
    dst = glCreateShader(static_cast<Enum>(type));
}

void Shader::_deleter(const UInt& id){
    glDeleteShader(id);
}
