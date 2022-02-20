#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferMapRangeAccess.hpp"
#include "glwpp/gl/enums/BufferParam.hpp"
#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/enums/BufferType.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class Buffer : public Object {
    friend class Texture;
    friend class VertexArray;

public:    
    Buffer(std::weak_ptr<Context> weak_ctx, const SrcLoc& loc = SrcLoc());

    using Data = void*;

    std::shared_future<bool> data(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                                  const Vop<gl::BufferUsage>& usage, const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> storage(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                                     const Vop<gl::BitField>& flags, const SrcLoc& loc = SrcLoc());

    std::shared_future<bool> getMapAccess(Ptr<gl::BufferMapAccess>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getMapRangeAccess(Ptr<gl::BitField>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> isImmutable(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> isMapped(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getMapLength(Ptr<gl::Int64>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getMapOffset(Ptr<gl::Int64>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getSize(Ptr<gl::Int>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getStorageFlags(Ptr<gl::BitField>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getUsage(Ptr<gl::BufferUsage>& dst, const SrcLoc& loc = SrcLoc()) const;

    std::shared_future<bool> getSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                        Ptr<Data>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> setSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                        const Vop<Data>& data, const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> copySubDataTo(Buffer& dst, const Vop<gl::IntPtr>& read_offset,
                                           const Vop<gl::IntPtr>& write_offset, const Vop<gl::SizeiPtr>& size,
                                           const SrcLoc& loc = SrcLoc()) const;

    using MapPtr = void*;
    std::shared_future<bool> getMapPointer(Ptr<MapPtr>& dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> map(const Vop<gl::BufferMapAccess>& access, Ptr<MapPtr>& dst, const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> mapRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                      const Vop<gl::BitField>& access, Ptr<MapPtr>& dst,
                                      const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> mapFlushRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                           const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> unmap(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp