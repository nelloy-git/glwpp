#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

// /The frequency of access may be one of these:
// Dynamic - The data store contents will be modified repeatedly and used many times.
// Static  - The data store contents will be modified once and used many times.
// Stream  - The data store contents will be modified once and used at most a few times.
// The nature of access may be one of these:
// Copy - The data store contents are modified by reading data from the GL, and used as the source for GL drawing and image specification commands.
// Draw - The data store contents are modified by the application, and used as the source for GL drawing and image specification commands.
// Read - The data store contents are modified by reading data from the GL, and used to return that data when queried by the application.
enum class BufferUsage : Enum {
    DynamicCopy = 0x88EA,
    DynamicDraw = 0x88E8,
    DynamicRead = 0x88E9,

    StaticCopy = 0x88E6,
    StaticDraw = 0x88E4,
    StaticRead = 0x88E5,

    StreamCopy = 0x88E2,
    StreamDraw = 0x88E0,
    StreamRead = 0x88E1,
};

}