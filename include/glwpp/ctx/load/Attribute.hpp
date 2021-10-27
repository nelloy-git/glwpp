#pragma once

#include <array>

#include "glwpp/ctx/load/AttributeMeta.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::ctx {

template<class AM>
class Attribute {
public:
    using Meta = AM; 
    using ElemT = DataTypeCpu<Meta::Type>;
    using T = std::array<ElemT, Meta::Packed ? 1 : Meta::Size>;

    T raw;

    // Direct

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 1 && !P && !N)>* = nullptr> 
    inline void set(const ElemT &x){
        raw = {x};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 2 && !P && !N)>* = nullptr>
    inline void set(const ElemT &x, const ElemT &y){
        raw = {x, y};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 3 && !P && !N)>* = nullptr>
    inline void set(const ElemT &x, const ElemT &y, const ElemT &z){
        raw = {x, y, z};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 4 && !P && !N)>* = nullptr>
    inline void set(const ElemT &x, const ElemT &y,
                    const ElemT &z, const ElemT &w){
        raw = {x, y, z, w};
    }

    // Normalized

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 1 && !P && N)>* = nullptr>
    inline void set(float x){
        raw = {_norm(x)};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 2 && !P && N)>* = nullptr>
    inline void set(float x, float y){
        raw = {_norm(x), _norm(y)};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 3 && !P && N)>* = nullptr>
    inline void set(float x, float y, float z){
        raw = {_norm(x), _norm(y), _norm(z)};
    }

    template<size_t S = Meta::Size, bool P = Meta::Packed, bool N = Meta::Norm, 
             std::enable_if_t<(S == 4 && !P && N)>* = nullptr>
    inline void set(float x, float y, float z, float w){
        raw = {_norm(x), _norm(y), _norm(z), _norm(w)};
    }

    // Packed

    template<DataTypeGL T = Meta::Type, bool N = Meta::Norm,
             std::enable_if_t<(T == DataTypeGL::_int_2_10_10_10 && N)>* = nullptr>
    inline void set(float x, float y, float z, float w){
        x = _normBorder(x);
        y = _normBorder(y);
        z = _normBorder(z);
        w = _normBorder(w);

        const uint32_t xs = x < 0 ? 1 : 0;
        const uint32_t ys = y < 0 ? 1 : 0;
        const uint32_t zs = z < 0 ? 1 : 0;
        const uint32_t ws = w < 0 ? 1 : 0; 
        raw = {xs << 9 | ((uint32_t)(x * 511 + (xs << 9)) & 511)
               | ys << 19 | (((uint32_t)(y * 511 + (ys << 9)) & 511) << 10)
               | zs << 29 | (((uint32_t)(z * 511 + (zs << 9)) & 511) << 20)
               | ws << 31 | (((uint32_t)(w + (ws << 1)) & 1) << 30)};
    }


    // template<DataTypeGL::_ Meta::Type, bool N = Meta::Norm,
    //          std::enable_if_t<(T == DataTypeGL::_nt_2_10_10_10 && N)>* = nullptr>
    // inline void set(float x, float y, float z, float w){
    //     static_assert(false, "TODO");
    // }

    // template<DataTypeGL::_ Meta::Type, bool N = Meta::Norm,
    //          std::enable_if_t<(T == DataTypeGL::_nt_10_11_11 && N)>* = nullptr>
    // inline void set(float x, float y, float z){
    //     static_assert(false, "TODO");
    // }

private:

    template<bool N = Meta::Norm, std::enable_if_t<(N)>* = nullptr>
    inline float _normBorder(float v){
        if constexpr (Meta::Signed){
            return (v > 1) ? 1 : (v < -1) ? -1 : v;
        } else {
            return (v > 1) ? 1 : (v < 0) ? 0 : v;
        }
    }

    template<bool N = Meta::Norm, std::enable_if_t<(N)>* = nullptr>
    inline ElemT _norm(float v){
        v = _normBorder(v);

        if constexpr (Meta::Type == DataTypeGL::_ubyte){
            return v * 255.0;
        } else if constexpr (Meta::Type == DataTypeGL::_byte){
            return v * 127.0;
        } else if constexpr (Meta::Type == DataTypeGL::_ushort){
            return v * 65535.0;
        } else if constexpr (Meta::Type == DataTypeGL::_short){
            return v * 32767.0;
        } else if constexpr (Meta::Type == DataTypeGL::_float){
            return v;
        } else {
            []<bool F = false>(){static_assert(F, "Type can not be normalized.");}();
        }
    }
};

}