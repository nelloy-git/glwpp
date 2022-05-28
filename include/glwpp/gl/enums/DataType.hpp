#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class DataType : gl::Enum {
    Byte = 0x1400,                  // GL_BYTE
    UByte = 0x1401,                 // GL_UNSIGNED_BYTE
    UByte_3_3_2 = 0x8032,           // GL_UNSIGNED_BYTE_3_3_2
    Short = 0x1402,                 // GL_SHORT
    UShort = 0x1403,                // GL_UNSIGNED_SHORT
    UShort_5_5_5_1 = 0x8034,        // GL_UNSIGNED_SHORT_5_5_5_1
    UShort_4_4_4_4 = 0x8033,        // GL_UNSIGNED_SHORT_4_4_4_4
    UShort_5_6_5 = 0x8363,          // GL_UNSIGNED_SHORT_5_6_5
    Int = 0x1404,                   // GL_INT
    UInt = 0x1405,                  // GL_UNSIGNED_INT
    Int_2_10_10_10_Rev = 0x8D9F,    // GL_INT_2_10_10_10_REV
    UInt_10_11_11_Rev = 0x8C3B,     // GL_UNSIGNED_INT_2_10_10_10_REV
    UInt_2_10_10_10_Rev = 0x8368,   // GL_UNSIGNED_INT_2_10_10_10_REV
    UInt_5_9_9_9_Rev = 0x8C3E,      // GL_UNSIGNED_INT_5_9_9_9_REV
    UInt_8_8_8_8 = 0x8035,          // GL_UNSIGNED_INT_8_8_8_8
    Float = 0x1406,                 // GL_FLOAT
    Double = 0x140A,                // GL_DOUBLE
};

template<DataType T>
struct DataTypeCpu {};

template<>
struct DataTypeCpu<DataType::Byte> {using type = char;};

template<>
struct DataTypeCpu<DataType::UByte> {using type = unsigned char;};

template<>
struct DataTypeCpu<DataType::UByte_3_3_2> {using type = unsigned char;};

template<>
struct DataTypeCpu<DataType::Short> {using type = short int;};

template<>
struct DataTypeCpu<DataType::UShort> {using type = unsigned short int;};

template<>
struct DataTypeCpu<DataType::UShort_5_5_5_1> {using type = unsigned short int;};

template<>
struct DataTypeCpu<DataType::UShort_4_4_4_4> {using type = unsigned short int;};

template<>
struct DataTypeCpu<DataType::UShort_5_6_5> {using type = unsigned short int;};

template<>
struct DataTypeCpu<DataType::Int> {using type = int;};

template<>
struct DataTypeCpu<DataType::UInt> {using type = unsigned int;};

template<>
struct DataTypeCpu<DataType::Float> {using type = float;};

template<>
struct DataTypeCpu<DataType::Double> {using type = double;};

template<>
struct DataTypeCpu<DataType::Int_2_10_10_10_Rev> {using type = int;};

template<>
struct DataTypeCpu<DataType::UInt_2_10_10_10_Rev> {using type = unsigned int;};

template<>
struct DataTypeCpu<DataType::UInt_10_11_11_Rev> {using type = unsigned int;};

template<>
struct DataTypeCpu<DataType::UInt_5_9_9_9_Rev> {using type = unsigned int;};

template<>
struct DataTypeCpu<DataType::UInt_8_8_8_8> {using type = unsigned int;};

template<DataType T>
using DataTypeCpu_t = DataTypeCpu<T>::type;

}