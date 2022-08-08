#include "glwpp/gl/obj/Shader.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::utils;

sptr<Shader> Shader::make(const sptr<Context>& ctx, const Val<const gl::ShaderType>& type,
                          const Val<const SrcLoc>& src_loc){
    return sptr<Shader>(new Shader(ctx, type, src_loc));
}

Shader::Shader(const sptr<Context>& ctx, const Val<const gl::ShaderType>& type,
               const Val<const SrcLoc>& src_loc) :
    Object(ctx, Shader::_initer, Shader::_deleter, type, src_loc){
}
           
bool Shader::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                         const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Shader::getParamInt, dst, param, src_loc);
    }
    glGetShaderiv(id(), param, dst);
    debug(src_loc);
    return true;
}


bool Shader::getType(const Val<gl::ShaderType>& dst,
                     const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_SHADER_TYPE, src_loc);
}

bool Shader::isCompiled(const Val<bool>& dst,
                        const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_COMPILE_STATUS, src_loc);
}

bool Shader::getSourceLength(const Val<gl::Int>& dst,
                             const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_SHADER_SOURCE_LENGTH, src_loc);
}

bool Shader::getInfoLog(const Val<std::string>& dst,
                        const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Shader::getInfoLog, dst, src_loc);
    }

    Int length;
    glGetShaderiv(id(), GL_INFO_LOG_LENGTH, &length);
    dst->reserve(length);
    glGetShaderInfoLog(id(), length, &length, dst->data());
    debug(src_loc);
    return true;
}

bool Shader::setSource(const Val<const std::string>& code,
                       const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Shader::setSource, code, src_loc);
    }
    
    auto c_code = code->c_str();
    glShaderSource(id(), 1, &c_code, nullptr);
    debug(src_loc);
    return true;
}

bool Shader::compile(const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Shader::compile, src_loc);
    }

    glCompileShader(id());
    debug(src_loc);
    return true;
}

void Shader::_initer(const Val<UInt>& dst, const Val<const gl::ShaderType>& type,
                     const Val<const utils::SrcLoc>& src_loc){
    *dst = glCreateShader(type.cast_reinterpret<const Enum>());
    debug(src_loc);
}

void Shader::_deleter(const UInt& id){
    glDeleteShader(id);
}
