#pragma once

#include "glad/gl.h"

namespace glwpp {

enum class BufferTypeGL : GLenum {
    Data = GL_ARRAY_BUFFER,
    Index = GL_ELEMENT_ARRAY_BUFFER,
    Storage = GL_SHADER_STORAGE_BUFFER
};

inline GLenum gl(BufferTypeGL usage){
    return static_cast<GLenum>(usage);
};

}