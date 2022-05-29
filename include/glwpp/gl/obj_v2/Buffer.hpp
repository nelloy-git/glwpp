#pragma once

#include <iostream>

#include "glwpp/gl/ctx_only/CtxBuffer.hpp"
#include "glwpp/gl/obj_v2/Object.hpp"

#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl::v2 {

class Buffer : public Object {
public:
    Buffer(const wptr<Context>& wctx, const Val<SrcLoc>& src_loc = SrcLoc());
    
    bool data(const Val<SizeiPtr>& size, const Ptr<void>& data, const Val<BufferUsage>& usage,
              const Val<SrcLoc>& src_loc = SrcLoc());
    bool storage(const Val<SizeiPtr>& size, const Ptr<void>& data,
                 const Val<BitField>& flags, const Val<SrcLoc>& src_loc = SrcLoc());

    bool bindUniformBase(const Val<UInt>& index, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool bindUniformRange(const Val<UInt>& index, const Val<IntPtr>& offset,
                     const Val<SizeiPtr>& size, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool bindShaderStorageBase(const Val<UInt>& index, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool bindShaderStorageRange(const Val<UInt>& index, const Val<IntPtr>& offset,
                           const Val<SizeiPtr>& size, const Val<SrcLoc>& src_loc = SrcLoc()) const;

    bool getParamInt(Ptr<Int>& dst, const Val<Enum>& param,
                     const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getParamInt64(Ptr<Int64>& dst, const Val<Enum>& param,
                       const Val<SrcLoc>& src_loc = SrcLoc()) const;

    bool getMapAccess(Ptr<BufferMapAccess>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getMapRangeAccess(Ptr<BitField>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool isImmutable(Ptr<bool>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool isMapped(Ptr<bool>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getMapLength(Ptr<Int64>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getMapOffset(Ptr<Int64>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getSize(Ptr<Int>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getStorageFlags(Ptr<BitField>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool getUsage(Ptr<BufferUsage>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;

    bool getSubData(Ptr<void>& dst, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                    const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool setSubData(const Ptr<void>& data, const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                    const Val<SrcLoc>& src_loc = SrcLoc());
    bool copySubDataTo(Val<Buffer>& dst, const Val<IntPtr>& read_offset,
                       const Val<IntPtr>& write_offset, const Val<SizeiPtr>& size,
                       const Val<SrcLoc>& src_loc = SrcLoc()) const;

    using MapPtr = void*;
    bool getMapPointer(Ptr<MapPtr>& dst, const Val<SrcLoc>& src_loc = SrcLoc()) const;
    bool map(Ptr<MapPtr>& dst, const Val<BufferMapAccess>& access, const Val<SrcLoc>& src_loc = SrcLoc());
    bool mapRange(Ptr<MapPtr>& dst, const Val<IntPtr>& offset,
                  const Val<SizeiPtr>& size, const Val<BitField>& access, 
                  const Val<SrcLoc>& src_loc = SrcLoc());
    bool mapFlushRange(const Val<IntPtr>& offset, const Val<SizeiPtr>& size,
                       const Val<SrcLoc>& src_loc = SrcLoc());
    bool unmap(Ptr<bool>& dst, const Val<SrcLoc>& src_loc = SrcLoc());

private:
    static void _initer(UInt& dst);
    static void _deleter(const UInt& id);
};

} // namespace glwpp