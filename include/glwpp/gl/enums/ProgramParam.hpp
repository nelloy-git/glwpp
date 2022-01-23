#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class ProgramParam : Enum {
    DeleteStatus = 0x8B80,              // GL_DELETE_STATUS params returns GL_TRUE if program is currently flagged for deletion, and GL_FALSE otherwise.
    LinkStatus = 0x8B82,                // GL_LINK_STATUS params returns GL_TRUE if the last link operation on program was successful, and GL_FALSE otherwise.
    ValidateStatus = 0x8B83,            // GL_VALIDATE_STATUS params returns GL_TRUE or if the last validation operation on program was successful, and GL_FALSE otherwise.
    InfoLogLength = 0x8B84,             // GL_INFO_LOG_LENGTH params returns the number of characters in the information log for program including the null termination character (i.e., the size of the character buffer required to store the information log). If program has no information log, a value of 0 is returned.
    AttachedShaders = 0x8B85,           // GL_ATTACHED_SHADERS params returns the number of shader objects attached to program.
    ActiveAttributes = 0x8B89,          // GL_ACTIVE_ATTRIBUTES params returns the number of active attribute variables for program.
    ActiveAttributeMaxLength = 0x8B8A,  // GL_ACTIVE_ATTRIBUTE_MAX_LENGTH params returns the length of the longest active attribute name for program, including the null termination character (i.e., the size of the character buffer required to store the longest attribute name). If no active attributes exist, 0 is returned.
    ActiveUniforms = 0x8B86,            // GL_ACTIVE_UNIFORMS params returns the number of active uniform variables for program.
    ActiveUniformMaxLenfth = 0x8B87,    // GL_ACTIVE_UNIFORM_MAX_LENGTH params returns the length of the longest active uniform variable name for program, including the null termination character (i.e., the size of the character buffer required to store the longest uniform variable name). If no active uniform variables exist, 0 is returned.
};

}