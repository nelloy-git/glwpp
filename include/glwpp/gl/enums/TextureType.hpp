#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class TextureType : Enum {
    Normal1D = 0x0DE0, // GL_TEXTURE_1D,
    Normal2D = 0x0DE1, // GL_TEXTURE_2D,
    Normal3D = 0x806F, // GL_TEXTURE_3D,
    Array1D = 0x8C18, // GL_TEXTURE_1D_ARRAY,
    Array2D = 0x8C1A, // GL_TEXTURE_2D_ARRAY,
    Rectangle = 0x84F5, // GL_TEXTURE_RECTANGLE,
    CubeMap = 0x8513, // GL_TEXTURE_CUBE_MAP,
    CubeMapArray = 0x9009, // GL_TEXTURE_CUBE_MAP_ARRAY,
    Buffer = 0x8C2A, // GL_TEXTURE_BUFFER,
    Multisample2D = 0x9100, // GL_TEXTURE_2D_MULTISAMPLE,
    ArrayMultisample2D = 0x9102, // GL_TEXTURE_2D_MULTISAMPLE_ARRAY
};
    
} // namespace glwpp::gl


