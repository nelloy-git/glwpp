#include "glwpp/gl/obj/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::utils;

sptr<Buffer> Buffer::make(const sptr<Context>& ctx,
                          const Val<const SrcLoc>& src_loc){
    return sptr<Buffer>(new Buffer(ctx, src_loc));
}

Buffer::Buffer(const sptr<Context>& ctx,
                 const Val<const SrcLoc>& src_loc) :
    Object(ctx, &Buffer::_initer, &Buffer::_deleter, src_loc){
}

bool Buffer::data(const Val<const SizeiPtr>& size, const Val<const void>& data,
                  const Val<const BufferUsage>& usage, const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::data, size, data, usage, src_loc);
    }

    glNamedBufferData(id(), size, data, usage.cast_reinterpret<const Enum>());
    debug(src_loc);
    return true;
}

bool Buffer::storage(const Val<const SizeiPtr>& size, const Val<const void>& data,
                     const Val<const BitField>& flags, const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::storage, size, data, flags, src_loc);
    }

    glNamedBufferStorage(id(), size, data, flags);
    debug(src_loc);
    return true;
}

bool Buffer::bindUniformBase(const Val<const UInt>& index,
                             const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::bindUniformBase, index, src_loc);
    }

    glBindBufferBase(GL_UNIFORM_BUFFER, index, id());
    debug(src_loc);
    return true;
}

bool Buffer::bindUniformRange(const Val<const UInt>& index, const Val<const IntPtr>& offset,
                              const Val<const SizeiPtr>& size, const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::bindUniformRange, index, offset, size, src_loc);
    }

    glBindBufferRange(GL_UNIFORM_BUFFER, index, id(), offset, size);
    debug(src_loc);
    return true;
}

bool Buffer::bindShaderStorageBase(const Val<const UInt>& index,
                                   const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::bindShaderStorageBase, index, src_loc);
    }

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, id());
    debug(src_loc);
    return true;
}

bool Buffer::bindShaderStorageRange(const Val<const UInt>& index, const Val<const IntPtr>& offset,
                                    const Val<const SizeiPtr>& size, const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::bindShaderStorageRange, index, offset, size, src_loc);
    }

    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, index, id(), offset, size);
    debug(src_loc);
    return true;
}

bool Buffer::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                         const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::getParamInt, dst, param, src_loc);
    }

    glGetBufferParameteriv(id(), param, dst);
    debug(src_loc);
    return true;
}

bool Buffer::getParamInt64(const Val<Int64>& dst, const Val<const Enum>& param,
                           const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::getParamInt64, dst, param, src_loc);
    }

    glGetBufferParameteri64v(id(), param, dst);
    debug(src_loc);
    return true;
}

bool Buffer::getMapAccess(const Val<BufferMapAccess>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_ACCESS, src_loc);
}

bool Buffer::getMapRangeAccess(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_ACCESS_FLAGS, src_loc);
}

bool Buffer::isImmutable(const Val<bool>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_IMMUTABLE_STORAGE, src_loc);
}

bool Buffer::isMapped(const Val<bool>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_MAPPED, src_loc);
}

bool Buffer::getMapLength(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt64(dst.cast_reinterpret<Int64>(), GL_BUFFER_MAP_LENGTH, src_loc);
}

bool Buffer::getMapOffset(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt64(dst.cast_reinterpret<Int64>(), GL_BUFFER_MAP_OFFSET, src_loc);
}

bool Buffer::getSize(const Val<Int>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_SIZE, src_loc);
}

bool Buffer::getStorageFlags(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_STORAGE_FLAGS, src_loc);
}

bool Buffer::getUsage(const Val<BufferUsage>& dst, const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_BUFFER_USAGE, src_loc);
}

bool Buffer::getSubData(const Val<void>& dst, const Val<const IntPtr>& offset,
                        const Val<const SizeiPtr>& size, const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::getSubData, dst, offset, size, src_loc);
    }

    glGetNamedBufferSubData(id(), offset, size, dst);
    debug(src_loc);
    return true;
}

bool Buffer::setSubData(const Val<const void>& data, const Val<const IntPtr>& offset,
                        const Val<const SizeiPtr>& size, const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::setSubData, data, offset, size, src_loc);
    }
    
    glNamedBufferSubData(id(), offset, size, data);
    debug(src_loc);
    return true;
}

bool Buffer::copySubData(const Val<const Buffer>& src, const Val<const IntPtr>& read_offset,
                         const Val<const IntPtr>& write_offset, const Val<const SizeiPtr>& size,
                         const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::copySubData, src, read_offset, write_offset, size, src_loc);
    }

    glCopyNamedBufferSubData(src->id(), id(), read_offset, write_offset, size);
    debug(src_loc);
    return true;
}

bool Buffer::getMapPointer(const Val<void*>& dst, const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::getMapPointer, dst, src_loc);
    }

    glGetNamedBufferPointerv(id(), GL_BUFFER_MAP_POINTER, dst);
    debug(src_loc);
    return true;
}

bool Buffer::map(const Val<void*>& dst, const Val<const BufferMapAccess>& access,
                 const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::map, dst, access, src_loc);
    }

    *dst = glMapNamedBuffer(id(), static_cast<GLenum>(*access));
    debug(src_loc);
    return true;
}

bool Buffer::mapRange(const Val<void*>& dst, const Val<const IntPtr>& offset,
                      const Val<const SizeiPtr>& size, const Val<const BitField>& access, 
                      const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::mapRange, dst, offset, size, access, src_loc);
    }

    *dst = glMapNamedBufferRange(id(), offset, size, access);
    debug(src_loc);
    return true;
}

bool Buffer::mapFlushRange(const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                           const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::mapFlushRange, offset, size, src_loc);
    }

    glFlushMappedNamedBufferRange(id(), offset, size);
    debug(src_loc);
    return true;
}

bool Buffer::unmap(const Val<bool>& dst, const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Buffer::unmap, dst, src_loc);
    }

    *dst = glUnmapNamedBuffer(id());
    debug(src_loc);
    return true;
}

void Buffer::_initer(const Val<UInt>& dst, const Val<const utils::SrcLoc>& src_loc){
    glCreateBuffers(1, dst);
    debug(src_loc);
}

void Buffer::_deleter(const UInt& id){
    glDeleteBuffers(1, &id);
}