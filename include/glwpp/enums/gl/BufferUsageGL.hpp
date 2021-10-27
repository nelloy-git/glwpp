#pragma once

#include "glad/gl.h"

namespace glwpp {

enum class BufferUsageGL : GLenum {
    STREAM = GL_STREAM_DRAW,
    STATIC = GL_STATIC_DRAW,
    DYNAMIC = GL_DYNAMIC_DRAW,
};

inline GLenum gl(BufferUsageGL usage){
    return static_cast<GLenum>(usage);
}

}