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

    void set(const float& x, const float& y, const float& z, const float& w){
        if constexpr (Packed){
            _raw[0] = _convert(x, y, z, w);
        } else {
            _raw[0] = _convert(x);
            if constexpr (S > 1){_raw[1] = _convert(y);}
            if constexpr (S > 2){_raw[2] = _convert(z);}
            if constexpr (S > 3){_raw[3] = _convert(w);}
        }
    }
private:
    Attribute(){};
    std::array<ComponentType, Packed ? 1 : S> _raw;

    static ComponentType _convert(const float& v){
        if constexpr (T == gl::DataType::Byte){
            return v * 255.0 - 128.0;
        } else if constexpr (T == gl::DataType::UByte){
            return v * 255.0;
        } else if constexpr (T == gl::DataType::Short){
            return v * 65535.0 - 32768.0;
        } else if constexpr (T == gl::DataType::UShort){
            return v * 65535.0;
        } else if constexpr (T == gl::DataType::Int){
            return v * 4294967295.0 - 2147483648.0;
        } else if constexpr (T == gl::DataType::UInt){
            return v * 4294967295.0;
        } else if constexpr (T == gl::DataType::Float){
            return v;
        } else {
            []<bool B = false>(){static_assert(B, "Unknown gl::DataType");}();
        }
    };

    static ComponentType _convert(const float& x, const float& y, const float& z, const float& w){
        if constexpr (T == gl::DataType::Int_2_10_10_10){
            const uint32_t xs = x < 0 ? 1 : 0;
            const uint32_t ys = y < 0 ? 1 : 0;
            const uint32_t zs = z < 0 ? 1 : 0;
            return 0 | xs <<  9 |  ((uint32_t)(x * 511 + (xs << 9)) & 511)
                     | ys << 19 | (((uint32_t)(y * 511 + (ys << 9)) & 511) << 10)
                     | zs << 29 | (((uint32_t)(z * 511 + (zs << 9)) & 511) << 20);
        } else if constexpr (T == gl::DataType::UInt_2_10_10_10){
            return 0 | ((uint32_t)(x * 1023) & 1023)
                     | (((uint32_t)(y * 1023) & 1023) << 10)
                     | (((uint32_t)(z * 1023) & 1023) << 20);
        } else {
            []<bool B = false>(){static_assert(B, "Unknown gl::DataType");}();
        }
    };
};

} // namespace glwpp
