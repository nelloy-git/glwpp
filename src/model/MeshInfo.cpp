#include "glwpp/model/MeshInfo.hpp"

#include <stdexcept>

#include "assimp/mesh.h"

#include "glwpp/model/VertexAttribute.hpp"

using namespace glwpp;

using Offset = MeshInfo::Offset;

namespace {

template<size_t S>
static constexpr size_t getAttributeSize(const gl::DataType& type){
    switch (type){
        case gl::DataType::Byte: return sizeof(Attribute<gl::DataType::Byte, S>);
        case gl::DataType::UByte: return sizeof(Attribute<gl::DataType::UByte, S>);
        case gl::DataType::Short: return sizeof(Attribute<gl::DataType::Short, S>);
        case gl::DataType::UShort: return sizeof(Attribute<gl::DataType::UShort, S>);
        case gl::DataType::Int: return sizeof(Attribute<gl::DataType::Int, S>);
        case gl::DataType::UInt: return sizeof(Attribute<gl::DataType::UInt, S>);
        case gl::DataType::Float: return sizeof(Attribute<gl::DataType::Float, S>);
    }

    if constexpr (S == 3){
        switch (type){
            case gl::DataType::Int_2_10_10_10: return sizeof(Attribute<gl::DataType::Int_2_10_10_10, S>);
            case gl::DataType::UInt_2_10_10_10: return sizeof(Attribute<gl::DataType::UInt_2_10_10_10, S>);
            
            default: throw std::runtime_error("Unsuported gl::DataType");
        }
    }

    throw std::runtime_error("Unsuported gl::DataType");
}

static constexpr size_t getAttributeSize(const gl::DataType& type, const MeshAttributeSize& size){
    switch (size){
        case MeshAttributeSize::Scalar: return getAttributeSize<1>(type);
        case MeshAttributeSize::Vec2: return getAttributeSize<2>(type);
        case MeshAttributeSize::Vec3: return getAttributeSize<3>(type);
        case MeshAttributeSize::Vec4: return getAttributeSize<4>(type);
    
        default: return 0;
    }
}

static bool doAiMeshHasAttrib(const aiMesh& ai_mesh, const MeshAttribute& attr){
    switch (attr){
    case MeshAttribute::Position: return ai_mesh.HasPositions();
    case MeshAttribute::Normal: return ai_mesh.HasNormals();
    case MeshAttribute::Tangent: return ai_mesh.HasTangentsAndBitangents();
    case MeshAttribute::Bitangent: return ai_mesh.HasTangentsAndBitangents();
    case MeshAttribute::TexCoord_0: return ai_mesh.HasTextureCoords(0);
    case MeshAttribute::TexCoord_1: return ai_mesh.HasTextureCoords(1);
    case MeshAttribute::TexCoord_2: return ai_mesh.HasTextureCoords(2);
    case MeshAttribute::TexCoord_3: return ai_mesh.HasTextureCoords(3);
    case MeshAttribute::TexCoord_4: return ai_mesh.HasTextureCoords(4);
    case MeshAttribute::TexCoord_5: return ai_mesh.HasTextureCoords(5);
    case MeshAttribute::TexCoord_6: return ai_mesh.HasTextureCoords(6);
    case MeshAttribute::TexCoord_7: return ai_mesh.HasTextureCoords(7);
    case MeshAttribute::Color_0: return ai_mesh.HasVertexColors(0);
    case MeshAttribute::Color_1: return ai_mesh.HasVertexColors(1);
    case MeshAttribute::Color_2: return ai_mesh.HasVertexColors(2);
    case MeshAttribute::Color_3: return ai_mesh.HasVertexColors(3);
    default: throw std::runtime_error("Unsuported MeshAttribute");
    }
}

static inline Offset findValueOffset(const aiVector3D* arr, size_t arr_size){
    static auto inf = std::numeric_limits<float>::infinity();
    static Offset min_template(inf, inf, inf, static_cast<float>(0));
    Offset offset = min_template;

    for (size_t i = 0; i < arr_size; ++i){
        std::get<0>(offset) = std::min(std::get<0>(offset), arr[i].x);
        std::get<1>(offset) = std::min(std::get<1>(offset), arr[i].y);
        std::get<2>(offset) = std::min(std::get<2>(offset), arr[i].z);
    }

    return offset;
}

static inline Offset findValueOffset(const aiColor4D* arr, size_t arr_size){
    static auto inf = std::numeric_limits<float>::infinity();
    Offset offset{inf, inf, inf, inf};

    for (size_t i = 0; i < arr_size; ++i){
        std::get<0>(offset) = std::min(std::get<0>(offset), arr[i].r);
        std::get<1>(offset) = std::min(std::get<1>(offset), arr[i].g);
        std::get<2>(offset) = std::min(std::get<2>(offset), arr[i].b);
        std::get<3>(offset) = std::min(std::get<3>(offset), arr[i].a);
    }

    return offset;
}

static inline Offset getAiMeshAttribOffset(const aiMesh& ai_mesh, const MeshAttribute& attr){
    switch (attr){
    case MeshAttribute::Position: return findValueOffset(ai_mesh.mVertices, ai_mesh.mNumVertices);
    case MeshAttribute::Normal: return findValueOffset(ai_mesh.mNormals, ai_mesh.mNumVertices);
    case MeshAttribute::Tangent: return findValueOffset(ai_mesh.mTangents, ai_mesh.mNumVertices);
    case MeshAttribute::Bitangent: return findValueOffset(ai_mesh.mBitangents, ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_0: return findValueOffset(ai_mesh.mTextureCoords[0], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_1: return findValueOffset(ai_mesh.mTextureCoords[1], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_2: return findValueOffset(ai_mesh.mTextureCoords[2], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_3: return findValueOffset(ai_mesh.mTextureCoords[3], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_4: return findValueOffset(ai_mesh.mTextureCoords[4], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_5: return findValueOffset(ai_mesh.mTextureCoords[5], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_6: return findValueOffset(ai_mesh.mTextureCoords[6], ai_mesh.mNumVertices);
    case MeshAttribute::TexCoord_7: return findValueOffset(ai_mesh.mTextureCoords[7], ai_mesh.mNumVertices);
    case MeshAttribute::Color_0: return findValueOffset(ai_mesh.mColors[0], ai_mesh.mNumVertices);
    case MeshAttribute::Color_1: return findValueOffset(ai_mesh.mColors[1], ai_mesh.mNumVertices);
    case MeshAttribute::Color_2: return findValueOffset(ai_mesh.mColors[2], ai_mesh.mNumVertices);
    case MeshAttribute::Color_3: return findValueOffset(ai_mesh.mColors[3], ai_mesh.mNumVertices);
    default: throw std::runtime_error("Unsuported MeshAttribute");
    }
}

static inline float findValueMult(const aiVector3D* arr, size_t arr_size, const Offset& offset){
    float max = -std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < arr_size; ++i){
        max = std::max(max, arr[i].x - std::get<0>(offset));
        max = std::max(max, arr[i].y - std::get<1>(offset));
        max = std::max(max, arr[i].z - std::get<2>(offset));
    }

    return max == 0 ? 1 : max;
}

static inline float findValueMult(const aiColor4D* arr, size_t arr_size, const Offset& offset){
    float max = -std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < arr_size; ++i){
        max = std::max(max, arr[i].r - std::get<0>(offset));
        max = std::max(max, arr[i].g - std::get<1>(offset));
        max = std::max(max, arr[i].b - std::get<2>(offset));
        max = std::max(max, arr[i].a - std::get<3>(offset));
    }

    return max == 0 ? 1 : max;
}

static inline float getAiMeshAttribMult(const aiMesh& ai_mesh, const MeshAttribute& attr, const Offset& offset){
    switch (attr){
    case MeshAttribute::Position: return findValueMult(ai_mesh.mVertices, ai_mesh.mNumVertices, offset);
    case MeshAttribute::Normal: return findValueMult(ai_mesh.mNormals, ai_mesh.mNumVertices, offset);
    case MeshAttribute::Tangent: return findValueMult(ai_mesh.mTangents, ai_mesh.mNumVertices, offset);
    case MeshAttribute::Bitangent: return findValueMult(ai_mesh.mBitangents, ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_0: return findValueMult(ai_mesh.mTextureCoords[0], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_1: return findValueMult(ai_mesh.mTextureCoords[1], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_2: return findValueMult(ai_mesh.mTextureCoords[2], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_3: return findValueMult(ai_mesh.mTextureCoords[3], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_4: return findValueMult(ai_mesh.mTextureCoords[4], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_5: return findValueMult(ai_mesh.mTextureCoords[5], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_6: return findValueMult(ai_mesh.mTextureCoords[6], ai_mesh.mNumVertices, offset);
    case MeshAttribute::TexCoord_7: return findValueMult(ai_mesh.mTextureCoords[7], ai_mesh.mNumVertices, offset);
    case MeshAttribute::Color_0: return findValueMult(ai_mesh.mColors[0], ai_mesh.mNumVertices, offset);
    case MeshAttribute::Color_1: return findValueMult(ai_mesh.mColors[1], ai_mesh.mNumVertices, offset);
    case MeshAttribute::Color_2: return findValueMult(ai_mesh.mColors[2], ai_mesh.mNumVertices, offset);
    case MeshAttribute::Color_3: return findValueMult(ai_mesh.mColors[3], ai_mesh.mNumVertices, offset);
    default: throw std::runtime_error("Unsuported MeshAttribute");
    }
}

}

MeshInfo::MeshInfo(){
    for (size_t i = 0; i < MESH_ATTRIBUTE_COUNT; ++i){
        _value_mult[i] = 1;
    }
}

MeshInfo::~MeshInfo(){
}

#include <iostream>

void MeshInfo::apply(const MeshConfig& cfg, const aiMesh& ai_mesh){
    _total_bytes = 0;

    for (size_t i = 0; i < MESH_ATTRIBUTE_COUNT; ++i){
        auto attr = static_cast<MeshAttribute>(i);

        _enabled[i] = doAiMeshHasAttrib(ai_mesh, attr) && cfg.getSize(attr) != MeshAttributeSize::None;
        _type[i] = _enabled[i] ? cfg.getType(attr) : static_cast<gl::DataType>(0);
        _size[i] = _enabled[i] ? cfg.getSize(attr) : MeshAttributeSize::None;
        _offset[i] = _total_bytes;
        _value_offset[i] = _enabled[i] ? getAiMeshAttribOffset(ai_mesh, attr) : Offset{float(0), float(0), float(0), float(0)};
        _value_mult[i] = _enabled[i] ? getAiMeshAttribMult(ai_mesh, attr, _value_offset[i]) : 1;

        _total_bytes += getAttributeSize(_type[i], _size[i]);
    }

    for (size_t i = 0; i < MESH_ATTRIBUTE_COUNT; ++i){
        _stride[i] = _total_bytes;
    }
}

const size_t& MeshInfo::getTotalBytes() const {
    return _total_bytes;
}

const bool& MeshInfo::isEnabled(const MeshAttribute& attribute) const {
    return _enabled[static_cast<size_t>(attribute)];
}

const gl::DataType& MeshInfo::getType(const MeshAttribute& attribute) const {
    return _type[static_cast<size_t>(attribute)];
}

const MeshAttributeSize& MeshInfo::getSize(const MeshAttribute& attribute) const {
    return _size[static_cast<size_t>(attribute)];
}

const size_t& MeshInfo::getOffset(const MeshAttribute& attribute) const {
    return _offset[static_cast<size_t>(attribute)];
}

const size_t& MeshInfo::getStride(const MeshAttribute& attribute) const {
    return _stride[static_cast<size_t>(attribute)];
}

const float MeshInfo::getValueOffset(const MeshAttribute& attribute, size_t i) const {
    switch (i){
    case 0: return -std::get<0>(_value_offset[static_cast<size_t>(attribute)]);
    case 1: return -std::get<1>(_value_offset[static_cast<size_t>(attribute)]);
    case 2: return -std::get<2>(_value_offset[static_cast<size_t>(attribute)]);
    case 3: return -std::get<3>(_value_offset[static_cast<size_t>(attribute)]);
    
    default: throw std::runtime_error("Unsuported i");
    }
}

const float& MeshInfo::getValueMultiplier(const MeshAttribute& attribute) const {
    return _value_mult[static_cast<size_t>(attribute)];
}

aiVector3D MeshInfo::norm(const MeshAttribute& attribute, const aiVector3D& vec) const {
    size_t i = static_cast<size_t>(attribute);
    return {
        (vec.x - std::get<0>(_value_offset[i])) / _value_mult[i],
        (vec.y - std::get<1>(_value_offset[i])) / _value_mult[i],
        (vec.z - std::get<2>(_value_offset[i])) / _value_mult[i],
    };
}

aiColor4D MeshInfo::norm(const MeshAttribute& attribute, const aiColor4D& vec) const {
    size_t i = static_cast<size_t>(attribute);
    return {
        (vec.r - std::get<0>(_value_offset[i])) / _value_mult[i],
        (vec.g - std::get<1>(_value_offset[i])) / _value_mult[i],
        (vec.b - std::get<2>(_value_offset[i])) / _value_mult[i],
        (vec.a - std::get<3>(_value_offset[i])) / _value_mult[i],
    };
}