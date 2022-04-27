#include "glwpp/gl/ctx_only/CtxShader.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

UInt CtxShader::_createGlShader(const ShaderType& type, const SrcLoc& loc){
    UInt id = glCreateShader(static_cast<Enum>(type));
    _printDebug(loc);
    return id;
}

void CtxShader::_deleteGlShader(const UInt& id){
    glDeleteShader(id);
    _printDebug(SrcLoc{});
}

CtxShader::CtxShader(const gl::ShaderType& type, const SrcLoc& loc) : 
    CtxObject(CtxObject::create<&_deleteGlShader>(_createGlShader(type, loc))){
    _printDebug(loc);
}

Int CtxShader::getParamI(const Enum& param, const SrcLoc& loc) const {
    Int dst;
    glGetShaderiv(getId(), param, &dst);
    _printDebug(loc);
    return dst;
}

ShaderType CtxShader::getType(const SrcLoc& loc) const {
    return static_cast<ShaderType>(getParamI( GL_SHADER_TYPE, loc));
}

bool CtxShader::isCompiled(const SrcLoc& loc) const {
    return GL_TRUE == getParamI( GL_COMPILE_STATUS, loc);
};

Int CtxShader::getSourceLength(const SrcLoc& loc) const {
    return getParamI( GL_SHADER_SOURCE_LENGTH, loc);
};

std::string CtxShader::getInfoLog(const SrcLoc& loc) const {
    gl::Int length;
    glGetShaderiv(getId(), GL_INFO_LOG_LENGTH, &length);

    std::string log;
    log.resize(length);
    glGetShaderInfoLog(getId(), length, &length, log.data());
    _printDebug(loc);

    return log;
}

void CtxShader::compile(const std::string& code, const SrcLoc& loc){
    auto c_code = code.c_str();
    glShaderSource(getId(), 1, &c_code, nullptr);
    glCompileShader(getId());
    _printDebug(loc);
}