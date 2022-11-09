#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class ShaderParamInt : gl::Enum {
    Type = 0x8B4F,           // params returns GL_VERTEX_SHADER if shader is a vertex shader object, and GL_FRAGMENT_SHADER if shader is a fragment shader object.
    DeleteStatus = 0x8B80,   // params returns GL_TRUE if shader is currently flagged for deletion, and GL_FALSE otherwise.
    CompileStatus = 0x8B81,  // For implementations that support a shader compiler, params returns GL_TRUE if the last compile operation on shader was successful, and GL_FALSE otherwise.
    InfoLogLength = 0x8B84,  // For implementations that support a shader compiler, params returns the number of characters in the information log for shader including the null termination character (i.e., the size of the character buffer required to store the information log). If shader has no information log, a value of 0 is returned.
    SourceLength = 0x8B88,   // For implementations that support a shader compiler, params returns the length of the concatenation of the source strings that make up the shader source for the shader, including the null termination character. (i.e., the size of the character buffer required to store the shader source). If no source code exists, 0 is returned.
};

}