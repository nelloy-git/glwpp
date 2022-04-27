#include "glwpp/gl/ctx_only/CtxBuffer.hpp"

#include <iostream>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

UInt CtxBuffer::_createGlBuffer(const SrcLoc& loc){
    UInt id;
    glCreateBuffers(1, &id);
    return id;
}

void CtxBuffer::_deleteGlBuffer(const UInt& id){
    glDeleteBuffers(1, &id);
    _printDebug(SrcLoc{});
}

CtxBuffer::CtxBuffer(const SrcLoc& loc) :
    CtxObject(CtxObject::create<&_deleteGlBuffer>(_createGlBuffer(loc))){
    _printDebug(loc);
}

void CtxBuffer::data(const gl::SizeiPtr& size, const void* data, const gl::BufferUsage& usage, const SrcLoc& loc){
    glNamedBufferData(getId(), size, data, static_cast<Enum>(usage));
    _printDebug(loc);
}

void CtxBuffer::storage(const gl::SizeiPtr& size, const void* data, const gl::BitField& flags, const SrcLoc& loc){
    glNamedBufferStorage(getId(), size, data, flags);
    _printDebug(loc);
}

void CtxBuffer::bindUniformBase(const UInt& index, const SrcLoc& loc) const{
    glBindBufferBase(GL_UNIFORM_BUFFER, index, getId());
    _printDebug(loc);
}

void CtxBuffer::bindUniformRange(const UInt& index, const IntPtr& offset,
                                 const SizeiPtr& size, const SrcLoc& loc) const{
    glBindBufferRange(GL_UNIFORM_BUFFER, index, getId(), offset, size);
    _printDebug(loc);
}

void CtxBuffer::bindShaderStorageBase(const UInt& index, const SrcLoc& loc) const{
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, getId());
    _printDebug(loc);
}

void CtxBuffer::bindShaderStorageRange(const UInt& index, const IntPtr& offset,
                                       const SizeiPtr& size, const SrcLoc& loc) const{
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, index, getId(), offset, size);
    _printDebug(loc);
}

Int CtxBuffer::getParamI(Enum param, const SrcLoc& loc) const {
    Int dst;
    glGetBufferParameteriv(getId(), param, &dst);
    CtxObject::_printDebug(loc);
    return dst;
};

Int64 CtxBuffer::getParamI64(Enum param, const SrcLoc& loc) const {
    Int64 dst;
    glGetBufferParameteri64v(getId(), param, &dst);
    CtxObject::_printDebug(loc);
    return dst;
};

BufferMapAccess CtxBuffer::getMapAccess(const SrcLoc& loc) const {
    return static_cast<BufferMapAccess>(getParamI(GL_BUFFER_ACCESS, loc));
}

BitField CtxBuffer::getMapRangeAccess(const SrcLoc& loc) const {
    return static_cast<BitField>(getParamI(GL_BUFFER_ACCESS_FLAGS, loc));
}

bool CtxBuffer::isImmutable(const SrcLoc& loc) const {
    return GL_TRUE == getParamI(GL_BUFFER_IMMUTABLE_STORAGE, loc);
}

bool CtxBuffer::isMapped(const SrcLoc& loc) const {
    return GL_TRUE == getParamI(GL_BUFFER_MAPPED, loc);
}

Int64 CtxBuffer::getMapLength(const SrcLoc& loc) const {
    return getParamI64(GL_BUFFER_MAP_LENGTH, loc);
}

Int64 CtxBuffer::getMapOffset(const SrcLoc& loc) const {
    return getParamI64(GL_BUFFER_MAP_OFFSET, loc);
}

Int CtxBuffer::getSize(const SrcLoc& loc) const {
    return getParamI(GL_BUFFER_SIZE, loc);
}

BitField CtxBuffer::getStorageFlags(const SrcLoc& loc) const {
    return getParamI(GL_BUFFER_STORAGE_FLAGS, loc);
}

BufferUsage CtxBuffer::getUsage(const SrcLoc& loc) const {
    return static_cast<BufferUsage>(getParamI(GL_BUFFER_USAGE, loc));
}

void CtxBuffer::getSubData(const IntPtr& offset, const SizeiPtr& size, void* dst, const SrcLoc& loc) const {
    glGetNamedBufferSubData(getId(), offset, size, dst);
    _printDebug(loc);
}

void CtxBuffer::setSubData(const IntPtr& offset, const SizeiPtr& size, const void* data, const SrcLoc& loc){
    glNamedBufferSubData(getId(), offset, size, data);
    _printDebug(loc);
}

void CtxBuffer::copySubDataTo(CtxBuffer& dst, const IntPtr& read_offset, const IntPtr& write_offset,
                              const SizeiPtr& size, const SrcLoc& loc) const {
    glCopyNamedBufferSubData(getId(), dst.getId(), read_offset, write_offset, size);
    _printDebug(loc);
}

CtxBuffer::MapPtr CtxBuffer::getMapPointer(const SrcLoc& loc) const {
    MapPtr dst;
    glGetNamedBufferPointerv(getId(), GL_BUFFER_MAP_POINTER, &dst);
    _printDebug(loc);
    return dst;
}

CtxBuffer::MapPtr CtxBuffer::map(const BufferMapAccess& access, const SrcLoc& loc){
    auto dst = glMapNamedBuffer(getId(), static_cast<Enum>(access));
    _printDebug(loc);
    return dst;
}

CtxBuffer::MapPtr CtxBuffer::mapRange(const IntPtr& offset, const SizeiPtr& size, const BitField& access, const SrcLoc& loc){
    auto dst = glMapNamedBufferRange(getId(), offset, size, static_cast<Enum>(access));
    _printDebug(loc);
    return dst;
}

void CtxBuffer::mapFlushRange(const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc){
    glFlushMappedNamedBufferRange(getId(), offset, size);
    _printDebug(loc);
}

bool CtxBuffer::unmap(const SrcLoc& loc){
    auto res = glUnmapNamedBuffer(getId());
    _printDebug(loc);
    return res;
}