#pragma once

#include <iostream>

#include "glwpp/gl/enums/BufferMapAccess.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"
#include "glwpp/gl/obj/Object.hpp"

namespace glwpp::gl {

class Buffer : public Object {
public:
    static sptr<Buffer> make(const sptr<Context>& ctx,
                             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    
    bool data(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BufferUsage>& usage,
              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storage(const Val<const SizeiPtr>& size, const Val<const void>& data, const Val<const BitField>& flags,
                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool bindUniformBase(const Val<const UInt>& index,
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool bindUniformRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                          const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool bindShaderStorageBase(const Val<const UInt>& index,
                               const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool bindShaderStorageRange(const Val<const UInt>& index, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getParamInt64(const Val<Int64>& dst, const Val<const Enum>& param,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getMapAccess(const Val<BufferMapAccess>& dst,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getMapRangeAccess(const Val<BitField>& dst,
                           const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isImmutable(const Val<bool>& dst,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isMapped(const Val<bool>& dst,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getMapLength(const Val<Int64>& dst,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getMapOffset(const Val<Int64>& dst,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getSize(const Val<Int>& dst,
                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getStorageFlags(const Val<BitField>& dst,
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getUsage(const Val<BufferUsage>& dst,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getSubData(const Val<void>& dst, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setSubData(const Val<const void>& data, const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool copySubData(const Val<const Buffer>& src, const Val<const IntPtr>& read_offset,
                     const Val<const IntPtr>& write_offset, const Val<const SizeiPtr>& size,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool getMapPointer(const Val<void*>& dst,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool map(const Val<void*>& dst, const Val<const BufferMapAccess>& access,
             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool mapRange(const Val<void*>& dst, const Val<const IntPtr>& offset,
                  const Val<const SizeiPtr>& size, const Val<const BitField>& access, 
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool mapFlushRange(const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool unmap(const Val<bool>& dst,
               const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

protected:
    Buffer(const sptr<Context>& ctx,
           const Val<const utils::SrcLoc>& src_loc);

private:
    // Hide parent's make
    using Object::make;

    static void _initer(const Val<UInt>& dst, const Val<const utils::SrcLoc>& src_loc);
    static void _deleter(const UInt& id);
};

} // namespace glwpp