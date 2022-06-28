#pragma once

#include <stdexcept>
#include <string_view>

#include "glwpp/gl/enums/DataType.hpp"

namespace glwpp::model {

enum class MeshAttributeSize : size_t {
    Scalar,
    Vec2,
    Vec3,
    Vec4
};

constexpr gl::UInt getMeshAttributeSizeComponents(const MeshAttributeSize& size){
    switch(size){
    case MeshAttributeSize::Scalar: return 1;
    case MeshAttributeSize::Vec2: return 2;
    case MeshAttributeSize::Vec3: return 3;
    case MeshAttributeSize::Vec4: return 4;
    default: throw std::runtime_error("Unknown MeshAttributeSize");
    }
};

enum class MeshIndexType {
    UByte,
    UShort,
    UInt
};

constexpr gl::DataType getMeshIndexTypeGlType(const MeshIndexType& type){
    switch (type){
    case MeshIndexType::UByte: return gl::DataType::UByte;
    case MeshIndexType::UShort: return gl::DataType::UShort;
    case MeshIndexType::UInt: return gl::DataType::UInt;
    default: throw std::runtime_error("Unknown MeshIndexType");
    }
};

constexpr std::string_view getMeshIndexTypeString(const MeshIndexType& type){
    switch (type){
    case MeshIndexType::UByte: return {"UByte"};
    case MeshIndexType::UShort: return {"UShort"};
    case MeshIndexType::UInt: return {"UInt"};
    default: throw std::runtime_error("Unknown MeshIndexType");
    }
};

template<MeshIndexType T>
struct MeshIndexTypeCpu {
    using type = gl::DataTypeCpu_t<getMeshIndexTypeGlType(T)>;
};

template<MeshIndexType T>
using MeshIndexTypeCpu_t = gl::DataTypeCpu_t<getMeshIndexTypeGlType(T)>;

enum class MeshAttributeType {
    UInt_11_11_10,
    UInt_10_10_10_2,
    UByte,
    UShort,
    UInt,
    Float,
};

constexpr gl::DataType getMeshAttributeTypeGlType(const MeshAttributeType& type){
    switch (type){
    case MeshAttributeType::UByte: return gl::DataType::UByte;
    case MeshAttributeType::UInt_11_11_10: return gl::DataType::UInt_10_11_11_Rev;
    case MeshAttributeType::UInt_10_10_10_2: return gl::DataType::UInt_2_10_10_10_Rev;
    case MeshAttributeType::UShort: return gl::DataType::UShort;
    case MeshAttributeType::UInt: return gl::DataType::UInt;
    case MeshAttributeType::Float: return gl::DataType::Float;
    default: throw std::runtime_error("Unknown MeshAttributeType");
    }
};

template<MeshAttributeType T>
struct MeshAttributeTypeCpu {
    using type = gl::DataTypeCpu_t<getMeshAttributeTypeGlType(T)>;
};

template<MeshAttributeType T>
using MeshAttributeTypeCpu_t = gl::DataTypeCpu_t<getMeshAttributeTypeGlType(T)>;

enum class MeshAttribute : size_t {
    Position = 0,
    Normal,
    Tangent,
    Bitangent,
    TexCoord_0,
    TexCoord_1,
    TexCoord_2,
    TexCoord_3,
    TexCoord_4,
    TexCoord_5,
    TexCoord_6,
    TexCoord_7,
    Color_0,
    Color_1,
    Color_2,
    Color_3,
    // Color_4,
    // Color_5,
    // Color_6,
    // Color_7
};

} // namespace glwpp