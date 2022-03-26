#pragma once

#include <array>

#include "glwpp/gl/enums/DataType.hpp"

namespace glwpp {

template<gl::DataType T>
class Attribute3D final {

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

    void set(float x, float y, float z);

private:
    Attribute3D(){};

    std::array<ComponentType, Packed ? 1 : 3> _raw;
//2147483647
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

template<>
void Attribute3D<gl::DataType::Byte>::set(float x, float y, float z){
    _raw[0] = toByte(x); _raw[1] = toByte(y); _raw[2] = toByte(z);
}

template<>
void Attribute3D<gl::DataType::UByte>::set(float x, float y, float z){
    _raw[0] = toUByte(x); _raw[1] = toUByte(y); _raw[2] = toUByte(z);
}

template<>
void Attribute3D<gl::DataType::Short>::set(float x, float y, float z){
    _raw[0] = toShort(x); _raw[1] = toShort(y); _raw[2] = toShort(z);
}

template<>
void Attribute3D<gl::DataType::UShort>::set(float x, float y, float z){
    _raw[0] = toUShort(x); _raw[1] = toUShort(y); _raw[2] = toUShort(z);
}

template<>
void Attribute3D<gl::DataType::Int>::set(float x, float y, float z){
    _raw[0] = toInt(x); _raw[1] = toInt(y); _raw[2] = toInt(z);
}

template<>
void Attribute3D<gl::DataType::UInt>::set(float x, float y, float z){
    _raw[0] = toUInt(x); _raw[1] = toUInt(y); _raw[2] = toUInt(z);
}

template<>
void Attribute3D<gl::DataType::Float>::set(float x, float y, float z){
    _raw[0] = toFloat(x); _raw[1] = toFloat(y); _raw[2] = toFloat(z);
}

template<>
void Attribute3D<gl::DataType::Int_2_10_10_10>::set(float x, float y, float z){
    _raw[0] = toInt_2_10_10_10(x, y, z);
}

template<>
void Attribute3D<gl::DataType::UInt_2_10_10_10>::set(float x, float y, float z){
    _raw[0] = toUInt_2_10_10_10(x, y, z);
}

} // namespace glwpp


//     // Packed

//     template<gpu_data_type T = Meta::Type, bool N = Meta::Norm,
//              std::enable_if_t<(T == gpu_data_type::GLint_2_10_10_10 && N)>* = nullptr>
//     inline void set(float x, float y, float z, float w){
//         x = _normBorder(x);
//         y = _normBorder(y);
//         z = _normBorder(z);
//         w = _normBorder(w);

//         const uint32_t xs = x < 0 ? 1 : 0;
//         const uint32_t ys = y < 0 ? 1 : 0;
//         const uint32_t zs = z < 0 ? 1 : 0;
//         const uint32_t ws = w < 0 ? 1 : 0; 
//         raw[0] = xs << 9 | ((uint32_t)(x * 511 + (xs << 9)) & 511)
//                  | ys << 19 | (((uint32_t)(y * 511 + (ys << 9)) & 511) << 10)
//                  | zs << 29 | (((uint32_t)(z * 511 + (zs << 9)) & 511) << 20)
//                  | ws << 31 | (((uint32_t)(w + (ws << 1)) & 1) << 30);
//     }


//     // template<gpu_data_type T = Meta::Type, bool N = Meta::Norm,
//     //          std::enable_if_t<(T == gpu_data_type::UInt_2_10_10_10 && N)>* = nullptr>
//     // inline void set(float x, float y, float z, float w){
//     //     static_assert(false, "TODO");
//     // }

//     // template<gpu_data_type T = Meta::Type, bool N = Meta::Norm,
//     //          std::enable_if_t<(T == gpu_data_type::UInt_10_11_11 && N)>* = nullptr>
//     // inline void set(float x, float y, float z){
//     //     static_assert(false, "TODO");
//     // }

// private:

//     template<bool N = Meta::Norm, std::enable_if_t<(N)>* = nullptr>
//     inline float _normBorder(float v){
//         if constexpr (Meta::Signed){
//             return (v > 1) ? 1 : (v < -1) ? -1 : v;
//         } else {
//             return (v > 1) ? 1 : (v < 0) ? 0 : v;
//         }
//     }

//     template<bool N = Meta::Norm, std::enable_if_t<(N)>* = nullptr>
//     inline ComponentType _norm(float v){
//         v = _normBorder(v);

//         if constexpr (Meta::Type == gpu_data_type::GLubyte){
//             return v * 255.0;
//         } else if constexpr (Meta::Type == gpu_data_type::GLbyte){
//             return v * 127.0;
//         } else if constexpr (Meta::Type == gpu_data_type::GLushort){
//             return v * 65535.0;
//         } else if constexpr (Meta::Type == gpu_data_type::GLshort){
//             return v * 32767.0;
//         } else if constexpr (Meta::Type == gpu_data_type::GLfloat){
//             return v;
//         } else {
//             []<bool F = false>(){static_assert(F, "type can not be normalized.");}();
//         }
//     }
// };

// }