#pragma once

#include "glwpp/gl/obj/Object.hpp"

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
    Buffer(const std::weak_ptr<Context>& weak_ctx, const SrcLoc& loc = SrcLoc());

    bool data(const Val<gl::SizeiPtr>& size, const Ptr<void>& data,
              const Val<gl::BufferUsage>& usage, const SrcLoc& loc = SrcLoc());
    bool storage(const Val<gl::SizeiPtr>& size, const Ptr<void>& data,
                 const Val<gl::BitField>& flags, const SrcLoc& loc = SrcLoc());

    bool bindUniformBase(const Val<gl::UInt>& index, const SrcLoc& loc = SrcLoc()) const;
    bool bindUniformRange(const Val<gl::UInt>& index, const Val<gl::IntPtr>& offset,
                     const Val<gl::SizeiPtr>& size, const SrcLoc& loc = SrcLoc()) const;
    bool bindShaderStorageBase(const Val<gl::UInt>& index, const SrcLoc& loc = SrcLoc()) const;
    bool bindShaderStorageRange(const Val<gl::UInt>& index, const Val<gl::IntPtr>& offset,
                           const Val<gl::SizeiPtr>& size, const SrcLoc& loc = SrcLoc()) const;

    bool getMapAccess(Ptr<gl::BufferMapAccess>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getMapRangeAccess(Ptr<gl::BitField>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool isImmutable(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool isMapped(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getMapLength(Ptr<gl::Int64>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getMapOffset(Ptr<gl::Int64>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getSize(Ptr<gl::Int>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getStorageFlags(Ptr<gl::BitField>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool getUsage(Ptr<gl::BufferUsage>& dst, const SrcLoc& loc = SrcLoc()) const;

    bool getSubData(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                    Ptr<void>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool setSubData(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                    const Ptr<void>& data, const SrcLoc& loc = SrcLoc());
    bool copySubDataTo(Buffer& dst, const Val<gl::IntPtr>& read_offset,
                       const Val<gl::IntPtr>& write_offset, const Val<gl::SizeiPtr>& size,
                       const SrcLoc& loc = SrcLoc()) const;

    using MapPtr = void*;
    bool getMapPointer(Ptr<MapPtr>& dst, const SrcLoc& loc = SrcLoc()) const;
    bool map(const Val<gl::BufferMapAccess>& access, Ptr<MapPtr>& dst, const SrcLoc& loc = SrcLoc());
    bool mapRange(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                  const Val<gl::BitField>& access, Ptr<MapPtr>& dst,
                  const SrcLoc& loc = SrcLoc());
    bool mapFlushRange(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                       const SrcLoc& loc = SrcLoc());
    bool unmap(Ptr<bool>& dst, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp