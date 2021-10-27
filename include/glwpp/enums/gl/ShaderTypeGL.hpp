#pragma once

#include "glad/gl.h"

namespace glwpp {

enum class ShaderTypeGL : GLenum {
    Vertex = GL_VERTEX_SHADER,
    Geometry = GL_GEOMETRY_SHADER,
    Fragment = GL_FRAGMENT_SHADER
};

inline GLenum gl(ShaderTypeGL type){
    return static_cast<GLenum>(type);
}

}
