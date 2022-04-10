#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class DataType : gl::Enum {
    Byte = 0x1400,                  // GL_BYTE
    UByte = 0x1401,                 // GL_UNSIGNED_BYTE
    Short = 0x1402,                 // GL_SHORT
    UShort = 0x1403,                // GL_UNSIGNED_SHORT
    Int = 0x1404,                   // GL_INT
    UInt = 0x1405,                  // GL_UNSIGNED_INT
    Float = 0x1406,                 // GL_FLOAT
    Double = 0x140A,                // GL_DOUBLE
    Int_2_10_10_10 = 0x8D9F,        // GL_INT_2_10_10_10_REV
    UInt_2_10_10_10 = 0x8368,       // GL_UNSIGNED_INT_2_10_10_10_REV
};

template<DataType T>
struct RawVertexAttribType {    
};

template<>
struct RawVertexAttribType<DataType::Byte> {using type = char;};
template<>
struct RawVertexAttribType<DataType::UByte> {using type = unsigned char;};
template<>
struct RawVertexAttribType<DataType::Short> {using type = short int;};
template<>
struct RawVertexAttribType<DataType::UShort> {using type = unsigned short int;};
template<>
struct RawVertexAttribType<DataType::Int> {using type = int;};
template<>
struct RawVertexAttribType<DataType::UInt> {using type = unsigned int;};
template<>
struct RawVertexAttribType<DataType::Float> {using type = float;};
template<>
struct RawVertexAttribType<DataType::Double> {using type = double;};
template<>
struct RawVertexAttribType<DataType::Int_2_10_10_10> {using type = int;};
template<>
struct RawVertexAttribType<DataType::UInt_2_10_10_10> {using type = unsigned int;};

}