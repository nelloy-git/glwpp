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
    friend class Texture;
    friend class VertexArray;
public:
    static constexpr bool DEBUG = true;
    
    Buffer(wptr<Context> ctx);
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&);
    virtual ~Buffer();

    using Data = void*;
    std::shared_future<bool> data(Vop<const gl::SizeiPtr> size, Vop<const Data> data, Vop<const gl::BufferUsage> usage);
    std::shared_future<bool> storage(Vop<const gl::SizeiPtr> size, Vop<const Data> data, Vop<const gl::BitField> flags);

    std::shared_future<bool> getParam_i64v(Vop<const gl::BufferParam> param, Ptr<gl::Int64> dst) const;
    std::shared_future<bool> getParam_iv(Vop<const gl::BufferParam> param, Ptr<gl::Int> dst) const;

    std::shared_future<bool> setSubData(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size, Vop<const Data> data);
    std::shared_future<bool> getSubData(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size, Vop<Data> dst) const;
    std::shared_future<bool> copySubData(Ptr<Buffer> dst, Vop<const gl::IntPtr> read_offset,
                                         Vop<const gl::IntPtr> write_offset, Vop<const gl::SizeiPtr> size) const;

    using MapPtr = void*;
    std::shared_future<bool> getMapPointer(Ptr<MapPtr> dst) const;
    std::shared_future<bool> map(Vop<const gl::BufferMapAccess> access, Ptr<MapPtr> dst);
    std::shared_future<bool> mapRange(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size,
                                      Vop<const gl::BitField> access, Ptr<MapPtr> dst);
    std::shared_future<bool> mapFlushRange(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size);
    std::shared_future<bool> unmap();

};

} // namespace glwpp