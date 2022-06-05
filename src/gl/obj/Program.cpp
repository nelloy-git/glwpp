#include "glwpp/gl/obj/Program.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::util;

Program::Program(const wptr<Context>& wctx,
                 const Val<const SrcLoc> src_loc) :
    Object(wctx, src_loc, &_initer, &_deleter){
}

bool Program::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glGetProgramiv, id(), param, dst);
}

bool Program::isLinked(const Val<bool> dst,
                       const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_LINK_STATUS, src_loc, check_ctx);
}

bool Program::isValidated(const Val<bool> dst,
                          const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_VALIDATE_STATUS, src_loc, check_ctx);
}

bool Program::getAttachedShadersCount(const Val<Int> dst,
                                      const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ATTACHED_SHADERS, src_loc, check_ctx);
}

bool Program::getActiveAttributesCount(const Val<Int> dst,
                                       const Val<const SrcLoc> src_loc, const bool check_ctx) const {

    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_ATTRIBUTES, src_loc, check_ctx);
}

bool Program::getActiveAttributeMaxNameLength(const Val<Int> dst,
                                              const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, src_loc, check_ctx);
}

bool Program::getActiveUniformsCount(const Val<Int> dst,
                                     const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_UNIFORMS, src_loc, check_ctx);
}

bool Program::getActiveUniformMaxNameLength(const Val<Int> dst,
                                            const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_UNIFORM_MAX_LENGTH, src_loc, check_ctx);
}

namespace {
    void _glGetProgramInfoLog(const UInt& prog, std::string& dst){
        gl::Int length;
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &length);
        dst.resize(length);
        glGetProgramInfoLog(prog, length, &length, dst.data());
    }
};

bool Program::getInfoLog(const Val<std::string> dst,
                         const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, _glGetProgramInfoLog, id(), dst);
}

namespace {
    void _glGetAttribLocation(const UInt& prog, Int& dst, const std::string& name){
        dst = glGetAttribLocation(prog, name.c_str());
    }
};

bool Program::getAttributeLocation(const Val<Int> dst, const Val<const std::string>& name,
                                   const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, _glGetAttribLocation, id(), dst, name);
}

namespace {
    void _glGetUniformLocation(const UInt& prog, Int& dst, const std::string& name){
        dst = glGetUniformLocation(prog, name.c_str());
    }
};

bool Program::getUniformLocation(const Val<Int> dst, const Val<const std::string>& name,
                                 const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, _glGetUniformLocation, id(), dst, name);
}

namespace {
    void _glGetUniformBlockIndex(const UInt& prog, UInt& dst, const std::string& name){
        dst = glGetUniformBlockIndex(prog, name.c_str());
    }
};

bool Program::getUniformBlockIndex(const Val<UInt>& dst, const Val<const std::string>& name,
                                   const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, _glGetUniformBlockIndex, id(), dst, name);
}

bool Program::attach(const Shader& shader,
                     const Val<const SrcLoc> src_loc, const bool check_ctx) {
    return executeInContext(check_ctx, src_loc, glAttachShader, id(), shader.id());
}

bool Program::link(const Val<const SrcLoc> src_loc, const bool check_ctx) {
    return executeInContext(check_ctx, src_loc, glLinkProgram, id());
}

bool Program::validate(const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glValidateProgram, id());
}

bool Program::use(const Val<const SrcLoc> src_loc, const bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glUseProgram, id());
}

bool Program::setUniform1F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                           const Val<const Sizei>& count,
                           const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniform1fv, id(), unif_loc, count, data);
}

bool Program::setUniform2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                           const Val<const Sizei>& count,
                           const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniform2fv, id(), unif_loc, count, data);
}

bool Program::setUniform3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                           const Val<const Sizei>& count,
                           const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniform3fv, id(), unif_loc, count, data);
}

bool Program::setUniform4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                           const Val<const Sizei>& count,
                           const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniform4fv, id(), unif_loc, count, data);
}

bool Program::setUniformMat2x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix2x3fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat2x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix2x4fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat3x2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3x2fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat3x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat3x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3x4fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat4x2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4x2fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat4x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4x3fv, id(), unif_loc, count, transpose, data);
}

bool Program::setUniformMat4x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
                                const Val<const bool>& transpose, const Val<const Sizei>& count,
                                const Val<const SrcLoc> src_loc, const bool check_ctx){
    return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4fv, id(), unif_loc, count, transpose, data);
}

void Program::_initer(UInt& dst){
    dst = glCreateProgram();
}

void Program::_deleter(const UInt& id){
    glDeleteProgram(id);
}