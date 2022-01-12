#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class DrawMode : Enum {
    Points = 0x0000,                // GL_POINTS
    LineStrip = 0x0003,             // GL_LINE_STRIP
    LineLoop = 0x0002,              // GL_LINE_LOOP
    Lines = 0x0001,                 // GL_LINES
    LineStripAdjency = 0x000B,      // GL_LINE_STRIP_ADJACENCY
    LinesAdjency = 0x000A,          // GL_LINES_ADJACENCY
    TriangleStrip = 0x0005,         // GL_TRIANGLE_STRIP
    TriangleFan = 0x0006,           // GL_TRIANGLE_FAN
    Triangles = 0x0004,             // GL_TRIANGLES
    TriangleStripAdjancy = 0x000D,  // GL_TRIANGLE_STRIP_ADJACENCY
    TrianglesAdjency = 0x000C,      // GL_TRIANGLES_ADJACENCY
    Patches = 0x000E,               // GL_PATCHES
};
    
} // namespace glwpp::gl
