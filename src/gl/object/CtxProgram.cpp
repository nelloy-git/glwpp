#include "glwpp/gl/object/CtxProgram.hpp"

#include <unordered_map>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateProgram(const SrcLoc& loc){
    auto id = new UInt;
    *id = glCreateProgram();
    return id;
}
static void DeleteProgram(gl::UInt *id, bool is_init_thread){
    if (is_init_thread && glIsProgram(*id)){
        glDeleteProgram(*id);
    }
    delete id;
}
}

CtxProgram::CtxProgram(const Dummy&) :
    CtxObject(Dummy{}){
}

CtxProgram::CtxProgram(const SrcLoc& loc) :
    CtxObject(&CreateProgram, &DeleteProgram, loc){
    _printDebug(loc);
}

Int CtxProgram::getParamI(const Enum& param, const SrcLoc& loc) const {
    Int dst;
    glGetProgramiv(getId(), param, &dst);
    CtxObject::_printDebug(loc);
    return dst;
}

bool CtxProgram::isLinked(const SrcLoc& loc) const {
    return GL_TRUE == getParamI(GL_LINK_STATUS, loc);
}

bool CtxProgram::isValidated(const SrcLoc& loc) const {
    return GL_TRUE == getParamI(GL_VALIDATE_STATUS, loc);
}

Int CtxProgram::getAttachedShadersCount(const SrcLoc& loc) const {
    return getParamI(GL_ATTACHED_SHADERS, loc);
}

Int CtxProgram::getActiveAttributesCount(const SrcLoc& loc) const {
    return getParamI(GL_ACTIVE_ATTRIBUTES, loc);
}

Int CtxProgram::getActiveAttributeMaxNameLength(const SrcLoc& loc) const {
    return getParamI(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, loc);
}

Int CtxProgram::getActiveUniformsCount(const SrcLoc& loc) const {
    return getParamI(GL_ACTIVE_UNIFORMS, loc);
}

Int CtxProgram::getActiveUniformMaxNameLength(const SrcLoc& loc) const {
    return getParamI(GL_ACTIVE_UNIFORM_MAX_LENGTH, loc);
}

std::string CtxProgram::getInfoLog(const SrcLoc& loc) const {
    gl::Int length;
    glGetProgramiv(getId(), GL_INFO_LOG_LENGTH, &length);

    std::string log;
    log.resize(length);
    glGetProgramInfoLog(getId(), length, &length, log.data());
    _printDebug(loc);

    return log;
}

void CtxProgram::attach(const CtxShader& shader, const SrcLoc& loc){
    glAttachShader(getId(), shader.getId());
    _printDebug(loc);
}

void CtxProgram::link(const SrcLoc& loc){
    glLinkProgram(getId());
    _printDebug(loc);
}

void CtxProgram::validate(const SrcLoc& loc) const {
    glValidateProgram(getId());
    _printDebug(loc);
}

void CtxProgram::use(const SrcLoc& loc) const {
    glUseProgram(getId());
    _printDebug(loc);
}

Int CtxProgram::getAttributeLocation(const std::string &name, const SrcLoc& loc) const {
    auto res = glGetAttribLocation(getId(), name.c_str());
    _printDebug(loc);
    return res;
}

Int CtxProgram::getUniformLocation(const std::string &name, const SrcLoc& loc) const {
    auto res = glGetUniformLocation(getId(), name.c_str());
    _printDebug(loc);
    return res;
}

void CtxProgram::setUniform1F(const Int& unif_loc, const Float& val0, const SrcLoc& loc){
    glProgramUniform1f(getId(), unif_loc, val0);
    _printDebug(loc);
}

void CtxProgram::setUniform2F(const Int& unif_loc, const Float& val0, const Float& val1, const SrcLoc& loc){
    glProgramUniform2f(getId(), unif_loc, val0, val1);
    _printDebug(loc);
}

void CtxProgram::setUniform3F(const Int& unif_loc, const Float& val0, const Float& val1, const Float& val2, const SrcLoc& loc){
    glProgramUniform3f(getId(), unif_loc, val0, val1, val2);
    _printDebug(loc);
}

void CtxProgram::setUniform4F(const Int& unif_loc, const Float& val0, const Float& val1, const Float& val2, const Float& val3, const SrcLoc& loc){
    glProgramUniform4f(getId(), unif_loc, val0, val1, val2, val3);
    _printDebug(loc);
}