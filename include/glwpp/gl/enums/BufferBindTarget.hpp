#pragma once

namespace glwpp::gl {

enum class BufferBindTarget {
    Array = 0x8892,              // GL_ARRAY_BUFFER 	Vertex attributes
    AtomicCounter = 0x92C0,      // GL_ATOMIC_COUNTER_BUFFER 	Atomic counter storage
    CopyRead = 0x8F36,           // GL_COPY_READ_BUFFER 	Buffer copy source
    CopyWrite = 0x8F37,          // GL_COPY_WRITE_BUFFER 	Buffer copy destination
    DispatchIndirect = 0x90EE,   // GL_DISPATCH_INDIRECT_BUFFER 	Indirect compute dispatch commands
    DrawIndirect = 0x8F3F,       // GL_DRAW_INDIRECT_BUFFER 	Indirect command arguments
    ElementArray = 0x8893,       // GL_ELEMENT_ARRAY_BUFFER 	Vertex array indices
    PixelPack = 0x88EB,          // GL_PIXEL_PACK_BUFFER 	Pixel read target
    PixelUnpack = 0x88EC,        // GL_PIXEL_UNPACK_BUFFER 	Texture data source
    Query = 0x9192,              // GL_QUERY_BUFFER 	Query result buffer
    ShaderStorage = 0x90D2,      // GL_SHADER_STORAGE_BUFFER 	Read-write storage for shaders
    Texture = 0x8C2A,            // GL_TEXTURE_BUFFER 	Texture data buffer
    TransformFeedback = 0x8C8E,  // GL_TRANSFORM_FEEDBACK_BUFFER 	Transform feedback buffer
    Uniform = 0x8A11             // GL_UNIFORM_BUFFER 	Uniform block storage
};

}
