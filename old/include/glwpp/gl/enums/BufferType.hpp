#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class BufferType : gl::Enum {
    Array = 0x8892,             // Vertex attributes
    AtomicCounter = 0x92C0,     // Atomic counter storage
    CopyRead = 0x8F36,          // Buffer copy source
    CopyWrite = 0x8F37,         // Buffer copy destination
    DispatchIndirect = 0x90EE,  // Indirect compute dispatch commands
    DrawIndirect = 0x8F3F,      // Indirect command arguments
    ElementArray = 0x8893,      // Vertex array indices
    PixelPack = 0x88EB,         // Pixel read target
    PixelUnpack = 0x88EC,       // Texture data source
    Query = 0x9192,             // Query result buffer
    ShaderStorage = 0x90D2,     // Read-write storage for shaders
    Texture = 0x8C2A,           // Texture data buffer
    TransformFeedback = 0x8C8E, // Transform feedback buffer
    Uniform = 0x8A11,           // Uniform block storage
};

}