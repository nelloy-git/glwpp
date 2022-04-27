#include "glwpp/gl/ctx_only/CtxProgram.hpp"

#include <unordered_map>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

UInt CtxProgram::_createGlProgram(const SrcLoc& loc){
    UInt id = glCreateProgram();
    _printDebug(loc);
    return id;
}

void CtxProgram::_deleteGlProgram(const UInt& id){
    glDeleteProgram(id);
    _printDebug(SrcLoc{});
}

CtxProgram::CtxProgram(const SrcLoc& loc) :
    CtxObject(CtxObject::create<&_deleteGlProgram>(_createGlProgram(loc))){
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

UInt CtxProgram::getUniformBlockLocation(const std::string &name, const SrcLoc& loc) const {
    auto res = glGetUniformBlockIndex(getId(), name.c_str());
    _printDebug(loc);
    return res;
}

void CtxProgram::setUniform1F(const Int& unif_loc, const Float* data, const Sizei& count, const SrcLoc& loc){
    glProgramUniform1fv(getId(), unif_loc, count, data);
    _printDebug(loc);
}

void CtxProgram::setUniform2F(const Int& unif_loc, const Float* data, const Sizei& count, const SrcLoc& loc){
    glProgramUniform2fv(getId(), unif_loc, count, data);
    _printDebug(loc);
}

void CtxProgram::setUniform3F(const Int& unif_loc, const Float* data, const Sizei& count, const SrcLoc& loc){
    glProgramUniform3fv(getId(), unif_loc, count, data);
    _printDebug(loc);
}

void CtxProgram::setUniform4F(const Int& unif_loc, const Float* data, const Sizei& count, const SrcLoc& loc){
    glProgramUniform4fv(getId(), unif_loc, count, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat2x2F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix2fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat2x3F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix2x3fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat2x4F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix2x4fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat3x2F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix3x2fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat3x3F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix3fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat3x4F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix3x4fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat4x2F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix4x2fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat4x3F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix4x3fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}

void CtxProgram::setUniformMat4x4F(const Int& unif_loc, const Float* data, const bool& transpose, 
                                   const Sizei& count, const SrcLoc& loc){
    glProgramUniformMatrix4fv(getId(), unif_loc, count, transpose, data);
    _printDebug(loc);
}
