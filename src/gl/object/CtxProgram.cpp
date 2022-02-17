#include "glwpp/gl/object/CtxProgram.hpp"

#include <unordered_map>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateProgram(const SrcLoc& loc){
    auto id = new UInt;
    *id = glCreateProgram();
    CtxObject::printDebug(loc);
    return id;
}
static void DeleteProgram(gl::UInt *id, bool is_init_thread){
    if (is_init_thread && glIsProgram(*id)){
        glDeleteProgram(*id);
    }
    delete id;
}
static Int GetParamI(UInt id, Enum param, const SrcLoc& loc){
    Int dst;
    glGetProgramiv(id, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
}
}

CtxProgram::CtxProgram(const SrcLoc& loc) :
    CtxObject(&CreateProgram, &DeleteProgram, loc){
}

bool CtxProgram::isLinked(const SrcLoc& loc) const {
    return GL_TRUE == GetParamI(getId(), GL_LINK_STATUS, loc);
}

bool CtxProgram::isValidated(const SrcLoc& loc) const {
    return GL_TRUE == GetParamI(getId(), GL_VALIDATE_STATUS, loc);
}

Int CtxProgram::getAttachedShadersCount(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_ATTACHED_SHADERS, loc);
}

Int CtxProgram::getActiveAttributesCount(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_ACTIVE_ATTRIBUTES, loc);
}

Int CtxProgram::getActiveAttributeMaxNameLength(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, loc);
}

Int CtxProgram::getActiveUniformsCount(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_ACTIVE_UNIFORMS, loc);
}

Int CtxProgram::getActiveUniformMaxNameLength(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_ACTIVE_UNIFORM_MAX_LENGTH, loc);
}

std::string CtxProgram::getInfoLog(const SrcLoc& loc) const {
    gl::Int length;
    glGetProgramiv(getId(), GL_INFO_LOG_LENGTH, &length);

    std::string log;
    log.resize(length);
    glGetProgramInfoLog(getId(), length, &length, log.data());
    printDebug(loc);

    return log;
}

Int CtxProgram::getAttributeLocation(const std::string &name, const SrcLoc& loc) const {
    auto res = glGetAttribLocation(getId(), name.c_str());
    printDebug(loc);
    return res;
}

Int CtxProgram::getUniformLocation(const std::string &name, const SrcLoc& loc) const {
    auto res = glGetUniformLocation(getId(), name.c_str());
    printDebug(loc);
    return res;
}

void CtxProgram::attach(const CtxShader& shader, const SrcLoc& loc){
    glAttachShader(getId(), shader.getId());
    printDebug(loc);
}

void CtxProgram::link(const SrcLoc& loc){
    glLinkProgram(getId());
    printDebug(loc);
}

void CtxProgram::validate(const SrcLoc& loc) const {
    glValidateProgram(getId());
    printDebug(loc);
}

void CtxProgram::use(const SrcLoc& loc) const {
    glUseProgram(getId());
    printDebug(loc);
}