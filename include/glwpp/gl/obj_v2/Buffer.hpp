#pragma once

#include <iostream>

#include "glwpp/gl/ctx_only/CtxBuffer.hpp"
#include "glwpp/gl/obj_v2/Object.hpp"

#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl::v2 {

class Buffer : public Object {
public:
    Buffer(const wptr<Context>& wctx, const Val<const SrcLoc>& src_loc = SrcLoc{});
    
    bool data(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BufferUsage>& usage,
              const Val<const SrcLoc>& src_loc = SrcLoc{});
    bool storage(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BitField>& flags,
                 const Val<const SrcLoc>& src_loc = SrcLoc{});

    bool bindUniformBase(const Val<const UInt>& index,
                         const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool bindUniformRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                          const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool bindShaderStorageBase(const Val<const UInt>& index,
                               const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool bindShaderStorageRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                                const Val<const SrcLoc>& src_loc = SrcLoc{}) const;

    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getParamInt64(const Val<Int64>& dst, const Val<const Enum>& param,
                       const Val<const SrcLoc>& src_loc = SrcLoc{}) const;

    bool getMapAccess(const Val<BufferMapAccess>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getMapRangeAccess(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool isImmutable(const Val<bool>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool isMapped(const Val<bool>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getMapLength(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getMapOffset(const Val<Int64>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getSize(const Val<Int>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getStorageFlags(const Val<BitField>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool getUsage(const Val<BufferUsage>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;

    bool getSubData(const Val<void>& dst, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool setSubData(const Val<const void>& data, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                    const Val<const SrcLoc>& src_loc = SrcLoc{});
    bool copySubDataTo(const Buffer& dst, const Val<const IntPtr>& read_offset,
                       const Val<const IntPtr>& write_offset, const Val<const SizeiPtr>& size,
                       const Val<const SrcLoc>& src_loc = SrcLoc{}) const;

    using MapPtr = void*;
    bool getMapPointer(const Val<MapPtr>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{}) const;
    bool map(const Val<MapPtr>& dst, const Val<const BufferMapAccess>& access, const Val<const SrcLoc>& src_loc = SrcLoc{});
    bool mapRange(const Val<MapPtr>& dst, const Val<const IntPtr>& offset,
                  const Val<const SizeiPtr>& size, const Val<const BitField>& access, 
                  const Val<const SrcLoc>& src_loc = SrcLoc{});
    bool mapFlushRange(const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                       const Val<const SrcLoc>& src_loc = SrcLoc{});
    bool unmap(const Val<bool>& dst, const Val<const SrcLoc>& src_loc = SrcLoc{});

private:
    static void _initer(UInt& dst);
    static void _deleter(const UInt& id);
};

} // namespace glwpp