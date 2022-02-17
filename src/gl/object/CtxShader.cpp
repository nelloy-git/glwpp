#include "glwpp/gl/object/CtxShader.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateShader(const ShaderType& type, const SrcLoc& loc){
    auto id = new UInt;
    *id = glCreateShader(static_cast<Enum>(type));
    CtxObject::printDebug(loc);
    return id;
}
static void DeleteShader(UInt *id, bool is_init_thread){
    if (is_init_thread && glIsShader(*id)){
        glDeleteShader(*id);
    }
    delete id;
}
static Int GetParamI(UInt id, Enum param, const SrcLoc& loc){
    Int dst;
    glGetShaderiv(id, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
}
}

CtxShader::CtxShader(const gl::ShaderType& type, const SrcLoc& loc) : 
    CtxObject(&CreateShader, &DeleteShader, type, loc){
}

ShaderType CtxShader::getType(const SrcLoc& loc) const {
    return static_cast<ShaderType>(GetParamI(getId(), GL_SHADER_TYPE, loc));
}

bool CtxShader::isCompiled(const SrcLoc& loc) const {
    return GL_TRUE == GetParamI(getId(), GL_COMPILE_STATUS, loc);
};

Int CtxShader::getSourceLength(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_SHADER_SOURCE_LENGTH, loc);
};

std::string CtxShader::getInfoLog(const SrcLoc& loc) const {
    gl::Int length;
    glGetShaderiv(getId(), GL_INFO_LOG_LENGTH, &length);

    std::string log;
    log.resize(length);
    glGetShaderInfoLog(getId(), length, &length, log.data());
    printDebug(loc);

    return log;
}

void CtxShader::compile(const std::string& code, const SrcLoc& loc){
    auto c_code = code.c_str();
    glShaderSource(getId(), 1, &c_code, nullptr);
    glCompileShader(getId());
    printDebug(loc);
}