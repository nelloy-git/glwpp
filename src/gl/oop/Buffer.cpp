#include "glwpp/gl/oop/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt GenBufferId(){
        gl::UInt id;
        glGenBuffers(1, &id);
        return id;
    };
    static void DeleteBufferId(gl::UInt* id){
        glDeleteBuffers(1, id);
        delete id;
    };
};

Buffer::Buffer(wptr<Context> ctx) :
    ContextData(ctx, &GenBufferId, &DeleteBufferId){
}

Buffer::Buffer(const Buffer&& other) :
    ContextData(std::move(other)){
}

Buffer::~Buffer(){
}

std::shared_future<bool> Buffer::data(sptr<gl::SizeiPtr> size, sptr<const void> data, sptr<gl::BufferUsage> usage){
    if constexpr (AUTOCLEAR) _clear(size, data, usage);
    return _lockCtx()->onRun.push([id = idPtr(), size, data, usage](){
        glBufferData(*id, *size, data.get(), static_cast<gl::Enum>(*usage));
    });
}

std::shared_future<bool> Buffer::storage(sptr<gl::SizeiPtr> size, sptr<const void> data, sptr<gl::BitField> flags){
    if constexpr (AUTOCLEAR) _clear(size, data, flags);
    return _lockCtx()->onRun.push([id = idPtr(), size, data, flags](){
        glBufferStorage(*id, *size, data.get(), *flags);
    });
}

std::shared_future<bool> Buffer::getParam_i64v(sptr<gl::BufferParam> param, sptr<gl::Int64> dst) const {
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetNamedBufferParameteri64v(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Buffer::getParam_iv(sptr<gl::BufferParam> param, sptr<gl::Int> dst) const {
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetNamedBufferParameteriv(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Buffer::setSubData(sptr<gl::SizeiPtr> size, sptr<gl::IntPtr> offset, sptr<const void> data){
    if constexpr (AUTOCLEAR) _clear(size, offset, data);
    return _lockCtx()->onRun.push([id = idPtr(), size, offset, data](){
        glNamedBufferSubData(*id, *size, *offset, data.get());
    });
}

std::shared_future<bool> Buffer::getSubData(sptr<gl::SizeiPtr> size, sptr<gl::IntPtr> offset, sptr<void> dst) const {
    if constexpr (AUTOCLEAR) _clear(size, offset, dst);
    return _lockCtx()->onRun.push([id = idPtr(), size, offset, dst](){
        glGetNamedBufferSubData(*id, *size, *offset, dst.get());
    });
}

std::shared_future<bool> Buffer::copySubData(sptr<Buffer> dst, sptr<gl::IntPtr> read_offset, sptr<gl::IntPtr> write_offset, sptr<gl::SizeiPtr> size) const {
    if constexpr (AUTOCLEAR) _clear(dst, read_offset, write_offset, size);
    return _lockCtx()->onRun.push([id = idPtr(), dst_id = dst->idPtr(), read_offset, write_offset, size](){
        glCopyNamedBufferSubData(*id, *dst_id, *read_offset, *write_offset, *size);
    });
}

std::shared_future<bool> Buffer::getMapPointer(sptr<void*> dst) const {
    if constexpr (AUTOCLEAR) _clear(dst);
    return _lockCtx()->onRun.push([id = idPtr(), dst](){
        glGetNamedBufferPointerv(*id, GL_BUFFER_MAP_POINTER, dst.get());
    });
}

std::shared_future<bool> Buffer::map(sptr<gl::BufferMapAccess> access, sptr<void*> dst){
    if constexpr (AUTOCLEAR) _clear(access, dst);
    return _lockCtx()->onRun.push([id = idPtr(), access, dst](){
        *dst = glMapNamedBuffer(*id, static_cast<gl::Enum>(*access));
    });
}

std::shared_future<bool> Buffer::mapRange(sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size, sptr<gl::BitField> access, sptr<void*> dst){
    if constexpr (AUTOCLEAR) _clear(offset, size, access, dst);
    return _lockCtx()->onRun.push([id = idPtr(), offset, size, access, dst](){
        *dst = glMapNamedBufferRange(*id, *offset, *size, *access);
    });
}

std::shared_future<bool> Buffer::mapFlushRange(sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size){
    if constexpr (AUTOCLEAR) _clear(offset, size);
    return _lockCtx()->onRun.push([id = idPtr(), offset, size](){
        glFlushMappedBufferRange(*id, *offset, *size);
    });
}

std::shared_future<bool> Buffer::unmap(){
    return _lockCtx()->onRun.push([id = idPtr()](){
        glUnmapNamedBuffer(*id);
    });
}