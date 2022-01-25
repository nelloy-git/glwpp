#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class VertexArrayAttribParam : gl::Enum {
    Enabled = 0x8622,        // GL_VERTEX_ATTRIB_ARRAY_ENABLED: param returns a value that is non-zero (true) if the vertex attribute array for index is enabled and 0 (false) if it is disabled. The initial value is GL_FALSE.
    Size = 0x8623,           // GL_VERTEX_ATTRIB_ARRAY_SIZE: param returns a single value, the size of the vertex attribute array for index. The size is the number of values for each element of the vertex attribute array, and it will be 1, 2, 3 or 4. The initial value is 4.
    Stride = 0x8624,         // GL_VERTEX_ATTRIB_ARRAY_STRIDE: param returns a single value, the array stride for (number of bytes between successive elements in) the vertex attribute array for index. A value of 0 indicates the array elements are stored sequentially in memory. The initial value is 0.
    Type = 0x8625,           // GL_VERTEX_ATTRIB_ARRAY_TYPE: param returns a single value, a symbolic constant indicating the array type for the vertex attribute array for index. Possible values are GL_BYTE, GL_DOUBLE, GL_FIXED, GL_FLOAT, GL_HALF_FLOAT, GL_INT, GL_INT_2_10_10_10_REV, GL_SHORT, GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, GL_UNSIGNED_INT, GL_UNSIGNED_INT_2_10_10_10_REV, and GL_UNSIGNED_INT_10F_11F_11F_REV . The initial value is GL_FLOAT.
    Normalized = 0x886A,     // GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: param returns a single value that is non-zero (true) if fixed-point data types for the vertex attribute array indicated by index are normalized when they are converted to floating-point, and 0 (false) otherwise. The initial value is GL_FALSE.
    Integer = 0x88FD,        // GL_VERTEX_ATTRIB_ARRAY_INTEGER: param returns a single value that is non-zero (true) if fixed-point data types for the vertex attribute array indicated by index have integer data type, and 0 (false) otherwise. The initial value is 0 (GL_FALSE).
    Long = 0x874E,           // GL_VERTEX_ATTRIB_ARRAY_LONG: param returns a single value that is non-zero (true) if a vertex attribute is stored as an unconverted double, and 0 (false) otherwise. The initial value is 0 (GL_FALSE).
    Divisor = 0x88FE,        // GL_VERTEX_ATTRIB_ARRAY_DIVISOR: param returns a single value that is the frequency divisor used for instanced rendering. See glVertexAttribDivisor. The initial value is 0.
    RelativeOffset = 0x82D5, // GL_VERTEX_ATTRIB_RELATIVE_OFFSET: param returns a single value that is the byte offset of the first element relative to the start of the vertex buffer binding specified attribute fetches from. The initial value is 0.
};

}