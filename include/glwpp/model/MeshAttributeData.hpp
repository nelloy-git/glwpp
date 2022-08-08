#pragma once

#include <array>
#include <stdexcept>

#include "glwpp/model/MeshEnums.hpp"

namespace glwpp::model {

static constexpr uint32_t packMeshAttributeDataValue(const float& value, unsigned int bits){
    uint32_t mult = (1 << bits) - 1;
    return ((uint32_t)(value * mult)) & mult;
};

static constexpr float unpackMeshAttributeDataValue(const uint32_t& value, unsigned int bits){
    uint32_t mult = (1 << bits) - 1;
    return (float)value / (float)mult;
};

unsigned int getMeshAttributeDataBytes(const MeshAttributeType& T, const MeshAttributeSize& S);

template<MeshAttributeType T, MeshAttributeSize S>
class MeshAttributeData final {
public:
    using ComponentType = MeshAttributeTypeCpu_t<T>;

    static constexpr unsigned int Components = S == MeshAttributeSize::Scalar ? 1 
                                         : S == MeshAttributeSize::Vec2 ? 2
                                         : S == MeshAttributeSize::Vec3 ? 3
                                         : S == MeshAttributeSize::Vec4 ? 4
                                         : 0;

    static constexpr bool Packed = T == MeshAttributeType::UInt_11_11_10
                                || T == MeshAttributeType::UInt_10_10_10_2;

    static constexpr bool Unpacked = T == MeshAttributeType::UByte
                                  || T == MeshAttributeType::UShort
                                  || T == MeshAttributeType::Float;

    static_assert(Packed != Unpacked, "Invalid MeshAttributeType");
    static_assert(Components != 0, "Invalid MeshAttributeSize");
    static_assert(!(Components != 3 && T == MeshAttributeType::UInt_11_11_10), "Used UInt_11_11_10 with non Vec3");
    static_assert(!(Components != 4 && T == MeshAttributeType::UInt_10_10_10_2), "Used UInt_10_10_10_2 with non Vec4");

    inline void set(const float& x, const float& y, const float& z, const float& w){
        if constexpr (Packed){
            _raw[0] = _convertPacked(x, y, z, w);
        } else {
            _raw[0] = _convertUnpacked(x);
            if constexpr (Components > 1){_raw[1] = _convertUnpacked(y);}
            if constexpr (Components > 2){_raw[2] = _convertUnpacked(z);}
            if constexpr (Components > 3){_raw[3] = _convertUnpacked(w);}
        }
    }

    inline void set(const auto& vec){
        set(vec.x, vec.y, vec.z, vec.w);
    }

private:
    MeshAttributeData(){};
    std::array<ComponentType, Packed ? 1 : Components> _raw;

    static ComponentType _convertUnpacked(const float& v){
        if constexpr (T == MeshAttributeType::UByte){
            return packMeshAttributeDataValue(v, 8);
        } else if constexpr (T == MeshAttributeType::UShort){
            return packMeshAttributeDataValue(v, 16);
        } else if constexpr (T == MeshAttributeType::Float){
            return v;
        } else {
            []<bool B = false>(){static_assert(B, "Unknown MeshAttributeType");}();
        }
    };

    static ComponentType _convertPacked(const float& x, const float& y, const float& z, const float& w){
        if constexpr (T == MeshAttributeType::UInt_11_11_10){
            return 0 | (packMeshAttributeDataValue(x, 11))
                     | (packMeshAttributeDataValue(y, 11) << 11)
                     | (packMeshAttributeDataValue(z, 10) << 22);
        } else

        if constexpr (T == MeshAttributeType::UInt_10_10_10_2){
            return 0 | (packMeshAttributeDataValue(x, 10))
                     | (packMeshAttributeDataValue(y, 10) << 10)
                     | (packMeshAttributeDataValue(z, 10) << 20)
                     | (packMeshAttributeDataValue(w,  2) << 30);
        } else
        
        {
            []<bool B = false>(){static_assert(B, "Unknown MeshAttributeType");}();
        }
    };
};

} // namespace glwpp
