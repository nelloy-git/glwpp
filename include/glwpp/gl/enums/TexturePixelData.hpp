#pragma once

#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

enum class TexturePixelData : gl::Enum {
    UByte = 0x1401, // GL_UNSIGNED_BYTE
    Byte = 0x1400, // GL_BYTE
    UShort = 0x1403, // GL_UNSIGNED_SHORT
    Short = 0x1402, // GL_SHORT
    UInt = 0x1405, // GL_UNSIGNED_INT
    Int = 0x1404, // GL_INT
    Float = 0x1406, // GL_FLOAT
    UByte_3_3_2 = 0x8032, // GL_UNSIGNED_BYTE_3_3_2
    Byte_2_3_3_Rev = 0x8362, // GL_UNSIGNED_BYTE_2_3_3_REV
    Short_5_6_5 = 0x8363, // GL_UNSIGNED_SHORT_5_6_5
    Short_5_6_5_Rev = 0x8364, // GL_UNSIGNED_SHORT_5_6_5_REV
    UShort_4_4_4_4 = 0x8033, // GL_UNSIGNED_SHORT_4_4_4_4
    UShort_4_4_4_4_Rev = 0x8365, // GL_UNSIGNED_SHORT_4_4_4_4_REV
    UShort_5_5_5_1 = 0x8034, // GL_UNSIGNED_SHORT_5_5_5_1
    UShort_1_5_5_5_Rev = 0x8366, // GL_UNSIGNED_SHORT_1_5_5_5_REV
    UInt_8_8_8_8 = 0x8035, // GL_UNSIGNED_INT_8_8_8_8
    UInt_8_8_8_8_Rev = 0x8367, // GL_UNSIGNED_INT_8_8_8_8_REV
    UInt_10_10_10_2 = 0x8036, // GL_UNSIGNED_INT_10_10_10_2
    UInt_2_10_10_10_Rev = 0x8368 // GL_UNSIGNED_INT_2_10_10_10_REV
};
    
} // namespace glwpp::gl


