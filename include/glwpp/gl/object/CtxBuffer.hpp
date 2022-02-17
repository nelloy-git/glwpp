#pragma once

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

namespace glwpp::gl {

class CtxBuffer : public CtxObject {
public:
    CtxBuffer(const SrcLoc& loc = SrcLoc::current());

    using Data = void*;

    void data(const SizeiPtr& size, const Data data, const BufferUsage& usage, const SrcLoc& loc = SrcLoc::current());
    void storage(const SizeiPtr& size, const Data data, const BitField& flags, const SrcLoc& loc = SrcLoc::current());

    BufferMapAccess getMapAccess(const SrcLoc& loc = SrcLoc::current()) const;
    BitField getMapRangeAccess(const SrcLoc& loc = SrcLoc::current()) const;
    bool isImmutable(const SrcLoc& loc = SrcLoc::current()) const;
    bool isMapped(const SrcLoc& loc = SrcLoc::current()) const;
    Int64 getMapLength(const SrcLoc& loc = SrcLoc::current()) const;
    Int64 getMapOffset(const SrcLoc& loc = SrcLoc::current()) const;
    Int getSize(const SrcLoc& loc = SrcLoc::current()) const;
    BitField getStorageFlags(const SrcLoc& loc = SrcLoc::current()) const;
    BufferUsage getUsage(const SrcLoc& loc = SrcLoc::current()) const;

    void getSubData(const IntPtr& offset, const SizeiPtr& size, Data dst, const SrcLoc& loc = SrcLoc::current()) const;
    void setSubData(const IntPtr& offset, const SizeiPtr& size, const Data data, const SrcLoc& loc = SrcLoc::current());
    void copySubDataTo(CtxBuffer& dst, const IntPtr& read_offset, const IntPtr& write_offset,
                       const SizeiPtr& size, const SrcLoc& loc = SrcLoc::current()) const;

    using MapPtr = void*;
    MapPtr getMapPointer(const SrcLoc& loc = SrcLoc::current()) const;
    MapPtr map(const BufferMapAccess& access, const SrcLoc& loc = SrcLoc::current());
    MapPtr mapRange(const IntPtr& offset, const SizeiPtr& size, const BitField& access, const SrcLoc& loc = SrcLoc::current());
    void mapFlushRange(const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc = SrcLoc::current());
    bool unmap(const SrcLoc& loc = SrcLoc::current());

};

} // namespace glwpp::gl