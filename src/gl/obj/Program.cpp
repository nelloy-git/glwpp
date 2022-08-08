#include "glwpp/gl/obj/Program.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::utils;

sptr<Program> Program::make(const sptr<Context>& ctx,
                            const Val<const SrcLoc>& src_loc){
    return sptr<Program>(new Program(ctx, src_loc));
}

Program::Program(const sptr<Context>& ctx,
                 const Val<const SrcLoc>& src_loc) :
    Object(ctx, &Program::_initer, &Program::_deleter, src_loc){
}

bool Program::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::getParamInt, dst, param, src_loc);
    }

    glGetProgramiv(id(), param, dst);
    debug(src_loc);
    return true;
}

bool Program::isLinked(const Val<bool>& dst,
                       const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_LINK_STATUS, src_loc);
}

bool Program::isValidated(const Val<bool>& dst,
                          const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_VALIDATE_STATUS, src_loc);
}

bool Program::getAttachedShadersCount(const Val<Int>& dst,
                                      const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ATTACHED_SHADERS, src_loc);
}

bool Program::getActiveAttributesCount(const Val<Int>& dst,
                                       const Val<const SrcLoc>& src_loc) const {

    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_ATTRIBUTES, src_loc);
}

bool Program::getActiveAttributeMaxNameLength(const Val<Int>& dst,
                                              const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, src_loc);
}

bool Program::getActiveUniformsCount(const Val<Int>& dst,
                                     const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_UNIFORMS, src_loc);
}

bool Program::getActiveUniformMaxNameLength(const Val<Int>& dst,
                                            const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_ACTIVE_UNIFORM_MAX_LENGTH, src_loc);
}

bool Program::getInfoLog(const Val<std::string>& dst,
                         const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::getInfoLog, dst, src_loc);
    }

    gl::Int length;
    glGetProgramiv(id(), GL_INFO_LOG_LENGTH, &length);
    dst->resize(length);
    glGetProgramInfoLog(id(), length, &length, dst->data());
    debug(src_loc);
    return true;
}

bool Program::getAttributeLocation(const Val<Int>& dst, const Val<const std::string>& name,
                                   const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::getAttributeLocation, dst, name, src_loc);
    }
    
    *dst = glGetAttribLocation(id(), name->c_str());
    debug(src_loc);
    return true;
}

bool Program::bindAttributeLocation(const Val<const UInt>& attr_index, const Val<const std::string>& name,
                                    const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::bindAttributeLocation, attr_index, name, src_loc);
    }
    
    glBindAttribLocation(id(), attr_index, name->data());
    debug(src_loc);
    return true;
}

bool Program::getUniformLocation(const Val<Int>& dst, const Val<const std::string>& name,
                                 const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::getUniformLocation, dst, name, src_loc);
    }

    *dst = glGetUniformLocation(id(), name->c_str());
    debug(src_loc);
    return true;
}

bool Program::getUniformBlockIndex(const Val<UInt>& dst, const Val<const std::string>& name,
                                   const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::getUniformBlockIndex, dst, name, src_loc);
    }

    glGetUniformBlockIndex(id(), name->c_str());
    debug(src_loc);
    return true;
}

bool Program::bindUniformBlockIndex(const Val<const UInt>& block_index, const Val<const std::string>& name,
                                    const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::bindUniformBlockIndex, block_index, name, src_loc);
    }
    
    glBindAttribLocation(id(), block_index, name->data());
    debug(src_loc);
    return true;
}

bool Program::attach(const Val<const Shader>& shader,
                     const Val<const SrcLoc>& src_loc) {
    if (!isContextThread()){
        return executeMethodInContext(&Program::attach, shader, src_loc);
    }

    glAttachShader(id(), shader->id());
    debug(src_loc);
    return true;
}

bool Program::link(const Val<const SrcLoc>& src_loc) {
    if (!isContextThread()){
        return executeMethodInContext(&Program::link, src_loc);
    }

    glLinkProgram(id());
    debug(src_loc);
    return true;
}

bool Program::validate(const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::validate, src_loc);
    }

    glValidateProgram(id());
    debug(src_loc);
    return true;
}

bool Program::use(const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Program::use, src_loc);
    }

    glUseProgram(id());
    debug(src_loc);
    return true;
}

// bool Program::setUniform1F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                            const Val<const Sizei>& count,
//                            const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniform1fv, id(), unif_loc, count, data);
// }

// bool Program::setUniform2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                            const Val<const Sizei>& count,
//                            const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniform2fv, id(), unif_loc, count, data);
// }

// bool Program::setUniform3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                            const Val<const Sizei>& count,
//                            const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniform3fv, id(), unif_loc, count, data);
// }

// bool Program::setUniform4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                            const Val<const Sizei>& count,
//                            const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniform4fv, id(), unif_loc, count, data);
// }

// bool Program::setUniformMat2x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix2x3fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat2x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix2x4fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat3x2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3x2fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat3x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat3x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix3x4fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat4x2F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4x2fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat4x3F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4x3fv, id(), unif_loc, count, transpose, data);
// }

// bool Program::setUniformMat4x4F(const Val<const Int>& unif_loc, const Val<const Float>& data,
//                                 const Val<const bool>& transpose, const Val<const Sizei>& count,
//                                 const Val<const SrcLoc>& src_loc){
//     return executeInContext(check_ctx, src_loc, glProgramUniformMatrix4fv, id(), unif_loc, count, transpose, data);
// }

void Program::_initer(const Val<UInt>& dst,
                      const Val<const SrcLoc>& src_loc){
    *dst = glCreateProgram();
    debug(src_loc);
}

void Program::_deleter(const UInt& id){
    glDeleteProgram(id);
}