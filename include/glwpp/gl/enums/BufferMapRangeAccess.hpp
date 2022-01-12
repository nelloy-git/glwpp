#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class BufferMapRangeAccess : gl::Enum {    
    Read = 0x0001,              // GL_MAP_READ_BIT indicates that the returned pointer may be used to read buffer object data. No GL error is generated if the pointer is used to query a mapping which excludes this flag, but the result is undefined and system errors (possibly including program termination) may occur.
    Write = 0x0002,             // GL_MAP_WRITE_BIT indicates that the returned pointer may be used to modify buffer object data. No GL error is generated if the pointer is used to modify a mapping which excludes this flag, but the result is undefined and system errors (possibly including program termination) may occur.
    Persistent = 0x0040,        // GL_MAP_PERSISTENT_BIT indicates that the mapping is to be made in a persistent fashion and that the client intends to hold and use the returned pointer during subsequent GL operation. It is not an error to call drawing commands (render) while buffers are mapped using this flag. It is an error to specify this flag if the buffer's data store was not allocated through a call to the glBufferStorage command in which the GL_MAP_PERSISTENT_BIT was also set.
    Coherent = 0x0080,          // GL_MAP_COHERENT_BIT indicates that a persistent mapping is also to be coherent. Coherent maps guarantee that the effect of writes to a buffer's data store by either the client or server will eventually become visible to the other without further intervention from the application. In the absence of this bit, persistent mappings are not coherent and modified ranges of the buffer store must be explicitly communicated to the GL, either by unmapping the buffer, or through a call to glFlushMappedBufferRange or glMemoryBarrier.
    InvalidateRange = 0x0004,   // GL_MAP_INVALIDATE_RANGE_BIT indicates that the previous contents of the specified range may be discarded. Data within this range are undefined with the exception of subsequently written data. No GL error is generated if subsequent GL operations access unwritten data, but the result is undefined and system errors (possibly including program termination) may occur. This flag may not be used in combination with GL_MAP_READ_BIT.
    InvalidateBuffer = 0x0008,  // GL_MAP_INVALIDATE_BUFFER_BIT indicates that the previous contents of the entire buffer may be discarded. Data within the entire buffer are undefined with the exception of subsequently written data. No GL error is generated if subsequent GL operations access unwritten data, but the result is undefined and system errors (possibly including program termination) may occur. This flag may not be used in combination with GL_MAP_READ_BIT.
    FlushExplicit = 0x0010,     // GL_MAP_FLUSH_EXPLICIT_BIT indicates that one or more discrete subranges of the mapping may be modified. When this flag is set, modifications to each subrange must be explicitly flushed by calling glFlushMappedBufferRange. No GL error is set if a subrange of the mapping is modified and not flushed, but data within the corresponding subrange of the buffer are undefined. This flag may only be used in conjunction with GL_MAP_WRITE_BIT. When this option is selected, flushing is strictly limited to regions that are explicitly indicated with calls to glFlushMappedBufferRange prior to unmap; if this option is not selected glUnmapBuffer will automatically flush the entire mapped range when called.
    Unsynchronized = 0x0020,    // GL_MAP_UNSYNCHRONIZED_BIT indicates that the GL should not attempt to synchronize pending operations on the buffer prior to returning from glMapBufferRange or glMapNamedBufferRange. No GL error is generated if pending operations which source or modify the buffer overlap the mapped region, but the result of such previous and any subsequent operations is undefined. 
};

struct BufferMapRangeAccessBitfield {
    gl::BitField fields;

    BufferMapRangeAccessBitfield() : fields(0){};
    BufferMapRangeAccessBitfield(const BufferMapRangeAccess& access) : fields(static_cast<gl::BitField>(access)){};
    BufferMapRangeAccessBitfield(const BufferMapRangeAccessBitfield& access) : fields(access.fields){};

    BufferMapRangeAccessBitfield operator|(BufferMapRangeAccess rhs){
        BufferMapRangeAccessBitfield res;
        res.fields = static_cast<gl::BitField>(fields) | static_cast<gl::Enum>(rhs);
        return res;
    }

    friend BufferMapRangeAccessBitfield operator|(BufferMapRangeAccess lhs, BufferMapRangeAccess rhs){
        BufferMapRangeAccessBitfield res;
        res.fields = static_cast<gl::Enum>(lhs) | static_cast<gl::Enum>(rhs);
        return res;
    }

    friend BufferMapRangeAccessBitfield operator|(BufferMapRangeAccess lhs, BufferMapRangeAccessBitfield rhs){
        BufferMapRangeAccessBitfield res;
        res.fields = static_cast<gl::Enum>(lhs) | static_cast<gl::BitField>(rhs.fields);
        return res;
    }
};

}