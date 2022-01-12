#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class BufferParamInt : Enum {
    MapAccess = 0x88BB, // GL_BUFFER_ACCESS params returns the access policy set while mapping the buffer object (the value of the access parameter enum passed to glMapBuffer). If the buffer was mapped with glMapBufferRange, the access policy is determined by translating the bits in that access parameter to one of the supported enums for glMapBuffer as described in the OpenGL Specification.
    MapAccessRange = 0x911F, // GL_BUFFER_ACCESS_FLAGS params returns the access policy set while mapping the buffer object (the value of the access parameter bitfield passed to glMapBufferRange). If the buffer was mapped with glMapBuffer, the access policy is determined by translating the enums in that access parameter to the corresponding bits for glMapBufferRange as described in the OpenGL Specification. The initial value is zero.
    Immutable = 0x821F, // GL_BUFFER_IMMUTABLE_STORAGE params returns a boolean flag indicating whether the buffer object is immutable. The initial value is GL_FALSE.
    Mapped = 0x88BC, // GL_BUFFER_MAPPED params returns a flag indicating whether the buffer object is currently mapped. The initial value is GL_FALSE.
    MapLength = 0x9120, // GL_BUFFER_MAP_LENGTH params returns the length of the mapping into the buffer object established with glMapBuffer*. The i64v versions of these queries should be used for this parameter. The initial value is zero.
    MapOffset = 0x9121, // GL_BUFFER_MAP_OFFSET params returns the offset of the mapping into the buffer object established with glMapBuffer*. The i64v versions of these queries should be used for this parameter. The initial value is zero.
    Size = 0x8764, // GL_BUFFER_SIZE params returns the size of the buffer object, measured in bytes. The initial value is 0.
    StorageFlags = 0x8220, // GL_BUFFER_STORAGE_FLAGS params returns a bitfield indicating the storage flags for the buffer object. If the buffer object is immutable, the value returned will be that specified when the data store was established with glBufferStorage. If the data store was established with glBufferData, the value will be GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT | GL_MAP_WRITE_BIT. The initial value is zero.
    Usage = 0x8765, // GL_BUFFER_USAGE params returns the buffer object's usage pattern. The initial value is GL_STATIC_DRAW. 
};

}