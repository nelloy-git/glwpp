#include "glwpp/gl/obj/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

Buffer::Buffer(const wptr<Context>& wctx, const Val<const SrcLoc>& src_loc) :
    Object(wctx, src_loc, &Buffer::_initer, &Buffer::_deleter){
}

bool Buffer::data(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BufferUsage>& usage,
                  const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glNamedBufferData, id(), size, data, usage.cast_reinterpret<const Enum>());
}

bool Buffer::storage(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BitField>& flags,
                     const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glNamedBufferStorage, id(), size, data, flags);
}

bool Buffer::bindUniformBase(const Val<const UInt>& index,
                             const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glBindBufferBase, GL_UNIFORM_BUFFER, index, id());
}

bool Buffer::bindUniformRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                              const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glBindBufferRange, GL_UNIFORM_BUFFER, index, id(), offset, size);
}

bool Buffer::bindShaderStorageBase(const Val<const UInt>& index,
                                   const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glBindBufferBase, GL_SHADER_STORAGE_BUFFER, index, id());
}

bool Buffer::bindShaderStorageRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                                    const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glBindBufferRange, GL_SHADER_STORAGE_BUFFER, index, id(), offset, size);
}

bool Buffer::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                         const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), param, dst);
}

bool Buffer::getParamInt64(const Val<Int64>& dst, const Val<const Enum>& param,
                           const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteri64v, id(), param, dst);
}

bool Buffer::getMapAccess(const Val<BufferMapAccess>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_ACCESS, dst.cast_reinterpret<Int>());
}

bool Buffer::getMapRangeAccess(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_ACCESS_FLAGS, dst.cast_reinterpret<Int>());
}

bool Buffer::isImmutable(const Val<bool>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_IMMUTABLE_STORAGE, dst.cast_reinterpret<Int>());
}

bool Buffer::isMapped(const Val<bool>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_MAPPED, dst.cast_reinterpret<Int>());
}

bool Buffer::getMapLength(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteri64v, id(), GL_BUFFER_MAP_LENGTH, dst);
}

bool Buffer::getMapOffset(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteri64v, id(), GL_BUFFER_MAP_OFFSET, dst);
}

bool Buffer::getSize(const Val<Int>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_SIZE, dst.cast_reinterpret<Int>());
}

bool Buffer::getStorageFlags(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_STORAGE_FLAGS, dst.cast_reinterpret<Int>());
}

bool Buffer::getUsage(const Val<BufferUsage>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetBufferParameteriv, id(), GL_BUFFER_USAGE, dst.cast_reinterpret<Int>());
}

bool Buffer::getSubData(const Val<void>& dst, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                        const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetNamedBufferSubData, id(), offset, size, dst);
}

bool Buffer::setSubData(const Val<const void>& data, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                        const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glNamedBufferSubData, id(), offset, size, data);
}

bool Buffer::copySubDataTo(Buffer& dst, const Val<const IntPtr>& read_offset,
                           const Val<const IntPtr>& write_offset, const Val<const SizeiPtr>& size,
                           const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glCopyNamedBufferSubData, id(), dst.id(), read_offset, write_offset, size);
}

bool Buffer::getMapPointer(const Val<void*>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetNamedBufferPointerv, id(), GL_BUFFER_MAP_POINTER, dst);
}

namespace {
static void _glMapNamedBuffer(void** dst, GLuint buffer, GLenum access){
    *dst = glMapNamedBuffer(buffer, access);
};
}

bool Buffer::map(const Val<void*>& dst, const Val<const BufferMapAccess>& access, const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, &_glMapNamedBuffer, dst, id(), access.cast_reinterpret<const Enum>());
}

namespace {
static void _glMapNamedBufferRange(void** dst, GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access){
    *dst = glMapNamedBufferRange(buffer, offset, length, access);
};
}

bool Buffer::mapRange(const Val<void*>& dst, const Val<const IntPtr>& offset,
                      const Val<const SizeiPtr>& size, const Val<const BitField>& access, 
                      const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, &_glMapNamedBufferRange, dst, id(), offset, size, access);
}

bool Buffer::mapFlushRange(const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                           const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glFlushMappedNamedBufferRange, id(), offset, size);
}

namespace {
static void _glUnmapNamedBuffer(bool* dst, GLuint buffer){
    *dst = glUnmapNamedBuffer(buffer);
};
}

bool Buffer::unmap(const Val<bool>& dst, const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, &_glUnmapNamedBuffer, dst, id());
}

void Buffer::_initer(UInt& dst){
    glCreateBuffers(1, &dst);
}

void Buffer::_deleter(const UInt& id){
    glDeleteBuffers(1, &id);
}