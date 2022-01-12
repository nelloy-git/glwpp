#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class ShaderType : Enum {
    Compute = 0x91B9, // GL_COMPUTE_SHADER,
    Vertex = 0x8B31, // GL_VERTEX_SHADER,
    TessControl = 0x8E88, // GL_TESS_CONTROL_SHADER,
    TessEvaluation = 0x8E87, // GL_TESS_EVALUATION_SHADER,
    Geometry = 0x8DD9, // GL_GEOMETRY_SHADER,
    Fragment = 0x8B30, // GL_FRAGMENT_SHADER
};
    
} // namespace glwpp::gl


