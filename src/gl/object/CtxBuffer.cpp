#include "glwpp/gl/object/CtxBuffer.hpp"

#include <iostream>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateBufferId(const SrcLoc& loc){
    auto id = new UInt;
    glCreateBuffers(1, id);
    CtxObject::printDebug(loc);
    return id;
};
static void DeleteBufferId(gl::UInt* id, bool is_init_thread){
    if (is_init_thread && glIsBuffer(*id)){
        glDeleteBuffers(1, id);
    }    
    delete id;
};
static Int GetParamI(UInt id, Enum param, const SrcLoc& loc){
    Int dst;
    glGetBufferParameteriv(id, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
};
static Int64 GetParamI64(UInt id, Enum param, const SrcLoc& loc){
    Int64 dst;
    glGetBufferParameteri64v(id, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
};
};

CtxBuffer::CtxBuffer(const SrcLoc& loc) :
    CtxObject(&CreateBufferId, &DeleteBufferId, loc){
}

void CtxBuffer::data(const gl::SizeiPtr& size, const Data data, const gl::BufferUsage& usage, const SrcLoc& loc){
    float *d = static_cast<float*>(data);

    std::cout << d[0] << " " << d[1] << std::endl;

    glNamedBufferData(getId(), size, data, static_cast<Enum>(usage));
    printDebug(loc);
}

void CtxBuffer::storage(const gl::SizeiPtr& size, const Data data, const gl::BitField& flags, const SrcLoc& loc){
    glNamedBufferStorage(getId(), size, data, flags);
    printDebug(loc);
}

BufferMapAccess CtxBuffer::getMapAccess(const SrcLoc& loc) const {
    return static_cast<BufferMapAccess>(GetParamI(getId(), GL_BUFFER_ACCESS, loc));
}

BitField CtxBuffer::getMapRangeAccess(const SrcLoc& loc) const {
    return static_cast<BitField>(GetParamI(getId(), GL_BUFFER_ACCESS_FLAGS, loc));
}

bool CtxBuffer::isImmutable(const SrcLoc& loc) const {
    return GL_TRUE == GetParamI(getId(), GL_BUFFER_IMMUTABLE_STORAGE, loc);
}

bool CtxBuffer::isMapped(const SrcLoc& loc) const {
    return GL_TRUE == GetParamI(getId(), GL_BUFFER_MAPPED, loc);
}

Int64 CtxBuffer::getMapLength(const SrcLoc& loc) const {
    return GetParamI64(getId(), GL_BUFFER_MAP_LENGTH, loc);
}

Int64 CtxBuffer::getMapOffset(const SrcLoc& loc) const {
    return GetParamI64(getId(), GL_BUFFER_MAP_OFFSET, loc);
}

Int CtxBuffer::getSize(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_BUFFER_SIZE, loc);
}

BitField CtxBuffer::getStorageFlags(const SrcLoc& loc) const {
    return GetParamI(getId(), GL_BUFFER_STORAGE_FLAGS, loc);
}

BufferUsage CtxBuffer::getUsage(const SrcLoc& loc) const {
    return static_cast<BufferUsage>(GetParamI(getId(), GL_BUFFER_USAGE, loc));
}

void CtxBuffer::getSubData(const IntPtr& offset, const SizeiPtr& size, Data dst, const SrcLoc& loc) const {
    glGetNamedBufferSubData(getId(), offset, size, dst);
    printDebug(loc);
}

void CtxBuffer::setSubData(const IntPtr& offset, const SizeiPtr& size, const Data data, const SrcLoc& loc){
    glNamedBufferSubData(getId(), offset, size, data);
    printDebug(loc);
}

void CtxBuffer::copySubDataTo(CtxBuffer& dst, const IntPtr& read_offset, const IntPtr& write_offset,
                           const SizeiPtr& size, const SrcLoc& loc) const {
    glCopyBufferSubData(getId(), dst.getId(), read_offset, write_offset, size);
    printDebug(loc);
}

CtxBuffer::MapPtr CtxBuffer::getMapPointer(const SrcLoc& loc) const {
    MapPtr dst;
    glGetNamedBufferPointerv(getId(), GL_BUFFER_MAP_POINTER, &dst);
    printDebug(loc);
    return dst;
}

CtxBuffer::MapPtr CtxBuffer::map(const BufferMapAccess& access, const SrcLoc& loc){
    auto dst = glMapNamedBuffer(getId(), static_cast<Enum>(access));
    printDebug(loc);
    return dst;
}

CtxBuffer::MapPtr CtxBuffer::mapRange(const IntPtr& offset, const SizeiPtr& size, const BitField& access, const SrcLoc& loc){
    auto dst = glMapNamedBufferRange(getId(), offset, size, static_cast<Enum>(access));
    printDebug(loc);
    return dst;
}

void CtxBuffer::mapFlushRange(const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc){
    glFlushMappedNamedBufferRange(getId(), offset, size);
    printDebug(loc);
}

bool CtxBuffer::unmap(const SrcLoc& loc){
    auto res = glUnmapNamedBuffer(getId());
    printDebug(loc);
    return res;
}