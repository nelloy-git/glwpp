#pragma once

#include "glad/gl.h"

namespace glwpp {

enum class DataTypeGL : GLenum {
    _byte = GL_BYTE, 
    _ubyte = GL_UNSIGNED_BYTE,
    _short = GL_SHORT,
    _ushort = GL_UNSIGNED_SHORT,
    _int = GL_INT,
    _uint = GL_UNSIGNED_INT,
    _float = GL_FLOAT,
    _double = GL_DOUBLE,
    _uint_2_10_10_10 = GL_UNSIGNED_INT_2_10_10_10_REV,
    _int_2_10_10_10 = GL_INT_2_10_10_10_REV,
    _uint_10_11_11 = GL_UNSIGNED_INT_10F_11F_11F_REV
};

inline GLenum gl(DataTypeGL data_type){
    return static_cast<GLenum>(data_type);
};

namespace detailed {
    template<DataTypeGL DT> struct DataTypeCpu_enum;
    template<> struct DataTypeCpu_enum<DataTypeGL::_byte>{using type = GLbyte;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_ubyte>{using type = GLubyte;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_short>{using type = GLshort;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_ushort>{using type = GLushort;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_int>{using type = GLint;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_uint>{using type = GLuint;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_float>{using type = GLfloat;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_uint_2_10_10_10>{using type = uint32_t;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_uint_10_11_11>{using type = uint32_t;};
    template<> struct DataTypeCpu_enum<DataTypeGL::_int_2_10_10_10>{using type = uint32_t;};
};

template<DataTypeGL DT>
using DataTypeCpu = typename detailed::DataTypeCpu_enum<DT>::type;

}