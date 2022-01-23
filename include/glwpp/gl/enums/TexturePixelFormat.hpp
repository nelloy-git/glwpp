#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class TexturePixelFormat : Enum {
    RED = 0x1903, // GL_RED
    RG = 0x8227, // GL_RG
    RGB = 0x1907, // GL_RGB
    BGR = 0x80E0, // GL_BGR
    RGBA = 0x1908, // GL_RGBA
    Depth = 0x1902,// GL_DEPTH_COMPONENT
    Stencil = 0x1901, // GL_STENCIL_INDEX
};
    
} // namespace glwpp::gl


