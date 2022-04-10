#pragma once

#include <array>

#include "glwpp/gl/enums/DataType.hpp"

namespace glwpp {

template<gl::DataType T, size_t S>
class Attribute final {

public:
    using ComponentType = gl::RawVertexAttribType<T>::type;
    static constexpr bool Packed = T == gl::DataType::Int_2_10_10_10
                                   || T == gl::DataType::UInt_2_10_10_10;
    static constexpr bool Unpacked = T == gl::DataType::Byte
                                     || T == gl::DataType::UByte
                                     || T == gl::DataType::Short
                                     || T == gl::DataType::UShort
                                     || T == gl::DataType::Int
                                     || T == gl::DataType::UInt
                                     || T == gl::DataType::Float;
    static_assert(Packed != Unpacked, "Invalid gl::DataType");

    void set(float x, float y, float z, float w);

private:
    Attribute(){};

    std::array<ComponentType, Packed ? 1 : S> _raw;
    
    static inline char toByte(float v){return static_cast<ComponentType>(v * 255.0 - 128.0);}
    static inline unsigned char toUByte(float v){return static_cast<ComponentType>(v * 255.0);}
    static inline short int toShort(float v){return static_cast<ComponentType>(v * 65535.0 - 32768.0);}
    static inline unsigned short int toUShort(float v){return static_cast<ComponentType>(v * 65535.0);}
    static inline int toInt(float v){return static_cast<ComponentType>(v * 4294967295.0 - 2147483648.0);}
    static inline unsigned int toUInt(float v){return static_cast<ComponentType>(v * 4294967295.0);}
    static inline float toFloat(float v){return v;}
    static inline int toInt_2_10_10_10(float x, float y, float z){
        const uint32_t xs = x < 0 ? 1 : 0;
        const uint32_t ys = y < 0 ? 1 : 0;
        const uint32_t zs = z < 0 ? 1 : 0;
        int result = 0 | xs <<  9 |  ((uint32_t)(x * 511 + (xs << 9)) & 511) |
                         ys << 19 | (((uint32_t)(y * 511 + (ys << 9)) & 511) << 10) |
                         zs << 29 | (((uint32_t)(z * 511 + (zs << 9)) & 511) << 20);
        return result;
    }
    static inline int toUInt_2_10_10_10(float x, float y, float z){
        int result = 0 | ((uint32_t)(x * 1023) & 1023) |
                        (((uint32_t)(y * 1023) & 1023) << 10) |
                        (((uint32_t)(z * 1023) & 1023) << 20);
        return result;
    }
};

// =======
//  S = 1
// =======

template<>
inline void Attribute<gl::DataType::Byte, 1>::set(float x, float y, float z, float w){
    _raw[0] = toByte(x);
}

template<>
inline void Attribute<gl::DataType::UByte, 1>::set(float x, float y, float z, float w){
    _raw[0] = toUByte(x);
}

template<>
inline void Attribute<gl::DataType::Short, 1>::set(float x, float y, float z, float w){
    _raw[0] = toShort(x);
}

template<>
inline void Attribute<gl::DataType::UShort, 1>::set(float x, float y, float z, float w){
    _raw[0] = toUShort(x);
}

template<>
inline void Attribute<gl::DataType::Int, 1>::set(float x, float y, float z, float w){
    _raw[0] = toInt(x);
}

template<>
inline void Attribute<gl::DataType::UInt, 1>::set(float x, float y, float z, float w){
    _raw[0] = toUInt(x);
}

template<>
inline void Attribute<gl::DataType::Float, 1>::set(float x, float y, float z, float w){
    _raw[0] = toFloat(x);
}

// =======
//  S = 2
// =======

template<>
inline void Attribute<gl::DataType::Byte, 2>::set(float x, float y, float z, float w){
    _raw[0] = toByte(x); _raw[1] = toByte(y);
}

template<>
inline void Attribute<gl::DataType::UByte, 2>::set(float x, float y, float z, float w){
    _raw[0] = toUByte(x); _raw[1] = toUByte(y);
}

template<>
inline void Attribute<gl::DataType::Short, 2>::set(float x, float y, float z, float w){
    _raw[0] = toShort(x); _raw[1] = toShort(y);
}

template<>
inline void Attribute<gl::DataType::UShort, 2>::set(float x, float y, float z, float w){
    _raw[0] = toUShort(x); _raw[1] = toUShort(y);
}

template<>
inline void Attribute<gl::DataType::Int, 2>::set(float x, float y, float z, float w){
    _raw[0] = toInt(x); _raw[1] = toInt(y);
}

template<>
inline void Attribute<gl::DataType::UInt, 2>::set(float x, float y, float z, float w){
    _raw[0] = toUInt(x); _raw[1] = toUInt(y);
}

template<>
inline void Attribute<gl::DataType::Float, 2>::set(float x, float y, float z, float w){
    _raw[0] = toFloat(x); _raw[1] = toFloat(y);
}

// =======
//  S = 3
// =======

template<>
inline void Attribute<gl::DataType::Byte, 3>::set(float x, float y, float z, float w){
    _raw[0] = toByte(x); _raw[1] = toByte(y); _raw[2] = toByte(z);
}

template<>
inline void Attribute<gl::DataType::UByte, 3>::set(float x, float y, float z, float w){
    _raw[0] = toUByte(x); _raw[1] = toUByte(y); _raw[2] = toUByte(z);
}

template<>
inline void Attribute<gl::DataType::Short, 3>::set(float x, float y, float z, float w){
    _raw[0] = toShort(x); _raw[1] = toShort(y); _raw[2] = toShort(z);
}

template<>
inline void Attribute<gl::DataType::UShort, 3>::set(float x, float y, float z, float w){
    _raw[0] = toUShort(x); _raw[1] = toUShort(y); _raw[2] = toUShort(z);
}

template<>
inline void Attribute<gl::DataType::Int, 3>::set(float x, float y, float z, float w){
    _raw[0] = toInt(x); _raw[1] = toInt(y); _raw[2] = toInt(z);
}

template<>
inline void Attribute<gl::DataType::UInt, 3>::set(float x, float y, float z, float w){
    _raw[0] = toUInt(x); _raw[1] = toUInt(y); _raw[2] = toUInt(z);
}

template<>
inline void Attribute<gl::DataType::Float, 3>::set(float x, float y, float z, float w){
    _raw[0] = toFloat(x); _raw[1] = toFloat(y); _raw[2] = toFloat(z);
}

template<>
inline void Attribute<gl::DataType::Int_2_10_10_10, 3>::set(float x, float y, float z, float w){
    _raw[0] = toInt_2_10_10_10(x, y, z);
}

template<>
inline void Attribute<gl::DataType::UInt_2_10_10_10, 3>::set(float x, float y, float z, float w){
    _raw[0] = toUInt_2_10_10_10(x, y, z);
}

// =======
//  S = 4
// =======

template<>
inline void Attribute<gl::DataType::Byte, 4>::set(float x, float y, float z, float w){
    _raw[0] = toByte(x); _raw[1] = toByte(y); _raw[2] = toByte(z); _raw[3] = toByte(z);
}

template<>
inline void Attribute<gl::DataType::UByte, 4>::set(float x, float y, float z, float w){
    _raw[0] = toUByte(x); _raw[1] = toUByte(y); _raw[2] = toUByte(z); _raw[3] = toUByte(z);
}

template<>
inline void Attribute<gl::DataType::Short, 4>::set(float x, float y, float z, float w){
    _raw[0] = toShort(x); _raw[1] = toShort(y); _raw[2] = toShort(z); _raw[3] = toShort(z);
}

template<>
inline void Attribute<gl::DataType::UShort, 4>::set(float x, float y, float z, float w){
    _raw[0] = toUShort(x); _raw[1] = toUShort(y); _raw[2] = toUShort(z); _raw[3] = toUShort(z);
}

template<>
inline void Attribute<gl::DataType::Int, 4>::set(float x, float y, float z, float w){
    _raw[0] = toInt(x); _raw[1] = toInt(y); _raw[2] = toInt(z); _raw[3] = toInt(z);
}

template<>
inline void Attribute<gl::DataType::UInt, 4>::set(float x, float y, float z, float w){
    _raw[0] = toUInt(x); _raw[1] = toUInt(y); _raw[2] = toUInt(z); _raw[3] = toUInt(z);
}

template<>
inline void Attribute<gl::DataType::Float, 4>::set(float x, float y, float z, float w){
    _raw[0] = toFloat(x); _raw[1] = toFloat(y); _raw[2] = toFloat(z); _raw[3] = toFloat(z);
}

} // namespace glwpp
