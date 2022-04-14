#pragma once

#include "glwpp/gl/ctx_only/CtxObject.hpp"

#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

namespace glwpp::gl {

class CtxBuffer : public CtxObject {
public:
    // Dummy object. Can be used for preallocation.
    CtxBuffer(const Dummy&);
    CtxBuffer(const SrcLoc& loc);

    using Data = void*;

    void data(const SizeiPtr& size, const Data data, const BufferUsage& usage, const SrcLoc& loc = SrcLoc());
    void storage(const SizeiPtr& size, const Data data, const BitField& flags, const SrcLoc& loc = SrcLoc());

    void bindUniformBase(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    void bindUniformRange(const UInt& index, const IntPtr& offset,
                          const SizeiPtr& size, const SrcLoc& loc = SrcLoc()) const;
    void bindShaderStorageBase(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    void bindShaderStorageRange(const UInt& index, const IntPtr& offset,
                                const SizeiPtr& size, const SrcLoc& loc = SrcLoc()) const;

    Int getParamI(Enum param, const SrcLoc& loc = SrcLoc()) const;
    Int64 getParamI64(Enum param, const SrcLoc& loc = SrcLoc()) const;
    BufferMapAccess getMapAccess(const SrcLoc& loc = SrcLoc()) const;
    BitField getMapRangeAccess(const SrcLoc& loc = SrcLoc()) const;
    bool isImmutable(const SrcLoc& loc = SrcLoc()) const;
    bool isMapped(const SrcLoc& loc = SrcLoc()) const;
    Int64 getMapLength(const SrcLoc& loc = SrcLoc()) const;
    Int64 getMapOffset(const SrcLoc& loc = SrcLoc()) const;
    Int getSize(const SrcLoc& loc = SrcLoc()) const;
    BitField getStorageFlags(const SrcLoc& loc = SrcLoc()) const;
    BufferUsage getUsage(const SrcLoc& loc = SrcLoc()) const;

    void getSubData(const IntPtr& offset, const SizeiPtr& size, Data dst, const SrcLoc& loc = SrcLoc()) const;
    void setSubData(const IntPtr& offset, const SizeiPtr& size, const Data data, const SrcLoc& loc = SrcLoc());
    void copySubDataTo(CtxBuffer& dst, const IntPtr& read_offset, const IntPtr& write_offset,
                       const SizeiPtr& size, const SrcLoc& loc = SrcLoc()) const;

    using MapPtr = void*;
    MapPtr getMapPointer(const SrcLoc& loc = SrcLoc()) const;
    MapPtr map(const BufferMapAccess& access, const SrcLoc& loc = SrcLoc());
    MapPtr mapRange(const IntPtr& offset, const SizeiPtr& size, const BitField& access, const SrcLoc& loc = SrcLoc());
    void mapFlushRange(const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc = SrcLoc());
    bool unmap(const SrcLoc& loc = SrcLoc());

};

} // namespace glwpp::gl