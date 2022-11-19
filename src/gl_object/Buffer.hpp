#pragma once

#include "gl_object/Object.hpp"

namespace glwpp {

namespace GL {

class Buffer : public Object {
public:
    EXPORT Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    EXPORT ~Buffer();

    EXPORT void setData(const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void clearData(const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorage(const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc = SrcLoc{});

    EXPORT void setSubData(const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void getSubData(const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void copySubDataFrom(const Buffer& readBuffer, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void clearSubData(const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc = SrcLoc{});

    EXPORT void bindBase(const Enum& target, const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void bindRange(const Enum& target, const Uint& index, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    
    EXPORT void getPointerv(const Enum& pname, const DataPtr& params, const SrcLoc& src_loc = SrcLoc{});
    EXPORT DataPtr map(const Enum& access, const SrcLoc& src_loc = SrcLoc{});
    EXPORT DataPtr mapRange(const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean unmap(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void flushRange(const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc = SrcLoc{});

    EXPORT Enum getMapAccess(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Bitfield getMapRangeAccess(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isImmutableStorage(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isMapped(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getSize(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Bitfield getStorageFlags(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Enum getUsage(const SrcLoc& src_loc = SrcLoc{});

    EXPORT Int64 getMapLength(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int64 getMapOffset(const SrcLoc& src_loc = SrcLoc{});

};

} // namespace GL

} // namespace glwpp