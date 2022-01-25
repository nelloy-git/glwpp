#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class DataType : gl::Enum {
    Byte,               // GL_BYTE
    UByte,              // GL_UNSIGNED_BYTE
    Short,              // GL_SHORT
    UShort,             // GL_UNSIGNED_SHORT
    Int,                // GL_INT
    UInt,               // GL_UNSIGNED_INT
    // HFloat,             // GL_HALF_FLOAT Unimplemented
    Float,              // GL_FLOAT
    Double,             // GL_DOUBLE
    // Fixed,              // GL_FIXED
    Int_2_10_10_10,     // GL_INT_2_10_10_10_REV
    UInt_2_10_10_10,    // GL_UNSIGNED_INT_2_10_10_10_REV
    UInt_10_11_11       // GL_UNSIGNED_INT_10F_11F_11F_RE
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
// Unimplemented
// template<>
// struct RawVertexAttribType<VertexAttribType::HFloat> {using type = short float;};
template<>
struct RawVertexAttribType<DataType::Float> {using type = float;};
template<>
struct RawVertexAttribType<DataType::Double> {using type = double;};
// Unimplemented
// template<>
// struct RawVertexAttribType<VertexAttribType::Fixed> {using type = fixed;};
template<>
struct RawVertexAttribType<DataType::Int_2_10_10_10> {using type = unsigned int;};
template<>
struct RawVertexAttribType<DataType::UInt_2_10_10_10> {using type = unsigned int;};
template<>
struct RawVertexAttribType<DataType::UInt_10_11_11> {using type = unsigned int;};

}