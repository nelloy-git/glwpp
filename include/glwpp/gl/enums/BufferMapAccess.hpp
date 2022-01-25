#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class BufferMapAccess : gl::Enum {
    ReadOnly = 0x88B8,  // GL_READ_ONLY
    WriteOnly = 0x88B9, // GL_WRITE_ONLY
    ReadWrite = 0x88BA, // GL_READ_WRITE
};

}