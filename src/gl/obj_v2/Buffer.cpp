#include "glwpp/gl/obj_v2/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::gl::v2;

Buffer::Buffer(const wptr<Context>& wctx, const Val<SrcLoc>& src_loc) :
    Object(wctx, src_loc, &Buffer::_initer, &Buffer::_deleter){
}

bool Buffer::data(const Val<SizeiPtr>& size, const Ptr<void>& data, const Val<BufferUsage>& usage,
                  const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, glNamedBufferData, id(), size, data, usage.reinterpret<Enum>());
}

bool Buffer::storage(const Val<SizeiPtr>& size, const Ptr<void>& data, const Val<BitField>& flags,
                     const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, glNamedBufferStorage, id(), size, data, flags);
}

bool Buffer::bindUniformBase(const Val<UInt>& index,
                             const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glBindBufferBase, GL_UNIFORM_BUFFER, index, id());
}

bool Buffer::bindUniformRange(const Val<UInt>& index, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                              const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glBindBufferRange, GL_UNIFORM_BUFFER, index, id(), offset, size);
}

bool Buffer::bindShaderStorageBase(const Val<UInt>& index,
                                   const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glBindBufferBase, GL_SHADER_STORAGE_BUFFER, index, id());
}

bool Buffer::bindShaderStorageRange(const Val<UInt>& index, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                                    const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glBindBufferRange, GL_SHADER_STORAGE_BUFFER, index, id(), offset, size);
}

bool Buffer::getParamInt(Ptr<Int>& dst, const Val<Enum>& param,
                         const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glGetBufferParameteriv, id(), param, dst);
}

bool Buffer::getParamInt64(Ptr<Int64>& dst, const Val<Enum>& param,
                           const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glGetBufferParameteri64v, id(), param, dst);
}

bool Buffer::getMapAccess(Ptr<BufferMapAccess>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_ACCESS, src_loc);
}

bool Buffer::getMapRangeAccess(Ptr<BitField>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_ACCESS_FLAGS, src_loc);
}

bool Buffer::isImmutable(Ptr<bool>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_IMMUTABLE_STORAGE, src_loc);
}

bool Buffer::isMapped(Ptr<bool>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_MAPPED, src_loc);
}

bool Buffer::getMapLength(Ptr<Int64>& dst, const Val<SrcLoc>& src_loc) const {
    return getParamInt64(dst, GL_BUFFER_MAP_LENGTH, src_loc);
}

bool Buffer::getMapOffset(Ptr<Int64>& dst, const Val<SrcLoc>& src_loc) const {
    return getParamInt64(dst, GL_BUFFER_MAP_OFFSET, src_loc);
}

bool Buffer::getSize(Ptr<Int>& dst, const Val<SrcLoc>& src_loc) const {
    return getParamInt(dst, GL_BUFFER_SIZE, src_loc);
}

bool Buffer::getStorageFlags(Ptr<BitField>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_STORAGE_FLAGS, src_loc);
}

bool Buffer::getUsage(Ptr<BufferUsage>& dst, const Val<SrcLoc>& src_loc) const {
    auto r_dst = dst.reinterpret<Int>();
    return getParamInt(r_dst, GL_BUFFER_USAGE, src_loc);
}

bool Buffer::getSubData(Ptr<void>& dst, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                        const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glGetNamedBufferSubData, id(), offset, size, dst);
}

bool Buffer::setSubData(const Ptr<void>& data, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                        const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, glNamedBufferSubData, id(), offset, size, data);
}

bool Buffer::copySubDataTo(Val<Buffer>& dst, const Val<IntPtr>& read_offset,
                           const Val<IntPtr>& write_offset, const Val<SizeiPtr>& size,
                           const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glCopyNamedBufferSubData, id(), dst.getVal().id(), read_offset, write_offset, size);
}

bool Buffer::getMapPointer(Ptr<MapPtr>& dst, const Val<SrcLoc>& src_loc) const {
    return executeInContext(src_loc, glGetNamedBufferPointerv, id(), GL_BUFFER_MAP_POINTER, dst);
}

namespace {
static void getGlMapNamedBuffer(void** dst, GLuint buffer, GLenum access){
    *dst = glMapNamedBuffer(buffer, access);
};
}

bool Buffer::map(Ptr<MapPtr>& dst, const Val<BufferMapAccess>& access, const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, &getGlMapNamedBuffer, dst, id(), access.reinterpret<Enum>());
}

namespace {
static void getGlMapNamedBufferRange(void** dst, GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access){
    *dst = glMapNamedBufferRange(buffer, offset, length, access);
};
}

bool Buffer::mapRange(Ptr<MapPtr>& dst, const Val<IntPtr>& offset,
                      const Val<SizeiPtr>& size, const Val<BitField>& access, 
                      const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, &getGlMapNamedBufferRange, dst, id(), offset, size, access);
}

bool Buffer::mapFlushRange(const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                           const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, glFlushMappedNamedBufferRange, id(), offset, size);
}

namespace {
static void getGlUnmapNamedBuffer(bool* dst, GLuint buffer){
    *dst = glUnmapNamedBuffer(buffer);
};
}

bool Buffer::unmap(Ptr<bool>& dst, const Val<SrcLoc>& src_loc){
    return executeInContext(src_loc, &getGlUnmapNamedBuffer, dst, id());
}

void Buffer::_initer(UInt& dst){
    glCreateBuffers(1, &dst);
}

void Buffer::_deleter(const UInt& id){
    glDeleteBuffers(1, &id);
}