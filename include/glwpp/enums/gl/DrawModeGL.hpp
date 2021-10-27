#pragma once

#include "glad/gl.h"

namespace glwpp {

enum class DrawModeGL : GLenum {
    Points = GL_POINTS,
    Line = GL_LINE,
    LineLoop = GL_LINE_LOOP,
    LineStrip = GL_LINE_STRIP,
    Triangles = GL_TRIANGLES,
    TriangleStrip = GL_TRIANGLE_STRIP,
    TriangleFan = GL_TRIANGLE_FAN
};

inline GLenum gl(DrawModeGL usage){
    return static_cast<GLenum>(usage);
};

}