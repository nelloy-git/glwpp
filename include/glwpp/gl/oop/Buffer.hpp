#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/api/gl_46.hpp"
#include "glwpp/gl/enums/BufferBindTarget.hpp"
#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferMapRangeAccess.hpp"
#include "glwpp/gl/enums/BufferParam.hpp"
#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/enums/BufferType.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

namespace glwpp {

class Buffer : public ContextData {
public:
    Buffer(wptr<Context> ctx);
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&);
    virtual ~Buffer();

    std::shared_future<bool> storage(const void *data, gl::SizeiPtr size, gl::BufferStorageFlagBitfield flags);
    std::shared_future<bool> data(const void *data, gl::SizeiPtr size, gl::BufferUsage usage);

    std::shared_future<bool> setSubData(const void *data, gl::SizeiPtr size, gl::IntPtr offset);
    std::shared_future<bool> getSubData(void *dst, gl::SizeiPtr size, gl::IntPtr offset) const;
    std::shared_future<bool> copySubData(Buffer &dst, gl::IntPtr read_offset, gl::IntPtr write_offset, gl::SizeiPtr size) const;

    std::shared_future<void*> getMapPointer() const;
    std::shared_future<void*> map(gl::BufferMapAccess access);
    std::shared_future<void*> mapRange(gl::IntPtr offset, gl::SizeiPtr size, gl::BufferMapRangeAccessBitfield access);
    std::shared_future<bool> mapFlushRange(gl::IntPtr offset, gl::SizeiPtr size);
    std::shared_future<bool> unmap();

    std::shared_future<gl::Int64> getParamInt64(gl::BufferParamInt param) const;
    std::shared_future<gl::Int> getParamInt(gl::BufferParamInt param) const;
};

}