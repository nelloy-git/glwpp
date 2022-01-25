#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferMapRangeAccess.hpp"
#include "glwpp/gl/enums/BufferParam.hpp"
#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/enums/BufferType.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

namespace glwpp {

class Buffer : public ContextData {
public:
    static constexpr bool AUTOCLEAR = true;

    Buffer(wptr<Context> ctx);
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&);
    virtual ~Buffer();

    std::shared_future<bool> data(sptr<gl::SizeiPtr> size, sptr<const void> data, sptr<gl::BufferUsage> usage);
    std::shared_future<bool> storage(sptr<gl::SizeiPtr> size, sptr<const void> data, sptr<gl::BitField> flags);

    std::shared_future<bool> getParam_i64v(sptr<gl::BufferParam> param, sptr<gl::Int64> dst) const;
    std::shared_future<bool> getParam_iv(sptr<gl::BufferParam> param, sptr<gl::Int> dst) const;

    std::shared_future<bool> setSubData(sptr<gl::SizeiPtr> size, sptr<gl::IntPtr> offset, sptr<const void> data);
    std::shared_future<bool> getSubData(sptr<gl::SizeiPtr> size, sptr<gl::IntPtr> offset, sptr<void> dst) const;
    std::shared_future<bool> copySubData(sptr<Buffer> dst, sptr<gl::IntPtr> read_offset, sptr<gl::IntPtr> write_offset, sptr<gl::SizeiPtr> size) const;

    std::shared_future<bool> getMapPointer(sptr<void*> dst) const;
    std::shared_future<bool> map(sptr<gl::BufferMapAccess> access, sptr<void*> dst);
    std::shared_future<bool> mapRange(sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size, sptr<gl::BitField> access, sptr<void*> dst);
    std::shared_future<bool> mapFlushRange(sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size);
    std::shared_future<bool> unmap();

};

}