#include "glwpp/model/MeshInfo.hpp"

#include <iostream>
#include <stdexcept>

#include "assimp/mesh.h"

#include "glwpp/model/MeshVertexAttribute.hpp"

using namespace glwpp;

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

static inline glm::vec4 findValueOffset(const aiVector3D* arr, size_t arr_size){
    static auto inf = std::numeric_limits<float>::infinity();
    glm::vec4 offset(inf, inf, inf, static_cast<float>(0));

    for (size_t i = 0; i < arr_size; ++i){
        offset.x = std::min(offset.x, arr[i].x);
        offset.y = std::min(offset.y, arr[i].y);
        offset.z = std::min(offset.z, arr[i].z);
    }

    return offset;
}

static inline glm::vec4 findValueOffset(const aiColor4D* arr, size_t arr_size){
    static auto inf = std::numeric_limits<float>::infinity();
    glm::vec4 offset(inf, inf, inf, inf);

    for (size_t i = 0; i < arr_size; ++i){
        offset.x = std::min(offset.x, arr[i].r);
        offset.y = std::min(offset.y, arr[i].g);
        offset.z = std::min(offset.z, arr[i].b);
        offset.w = std::min(offset.w, arr[i].a);
    }

    return offset;
}

static inline glm::vec4 getAiMeshAttribOffset(const aiMesh& ai_mesh, const MeshAttribute& attr){
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

static inline float findValueMult(const aiVector3D* arr, size_t arr_size, const glm::vec4& offset){
    float max = -std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < arr_size; ++i){
        max = std::max(max, arr[i].x - offset.x);
        max = std::max(max, arr[i].y - offset.y);
        max = std::max(max, arr[i].z - offset.z);
    }

    return max == 0 ? 1 : max;
}

static inline float findValueMult(const aiColor4D* arr, size_t arr_size, const glm::vec4& offset){
    float max = -std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < arr_size; ++i){
        max = std::max(max, arr[i].r - offset.x);
        max = std::max(max, arr[i].g - offset.y);
        max = std::max(max, arr[i].b - offset.z);
        max = std::max(max, arr[i].a - offset.w);
    }

    return max == 0 ? 1 : max;
}

static inline float getAiMeshAttribMult(const aiMesh& ai_mesh, const MeshAttribute& attr, const glm::vec4& offset){
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

static inline gl::DataType nextGlDataType(const gl::DataType& type){
    switch (type){
    case gl::DataType::UByte: return gl::DataType::UInt_2_10_10_10;
    case gl::DataType::UInt_2_10_10_10: return gl::DataType::UShort;
    default: return gl::DataType::Float;
    }
}

static inline float getGlDataTypeValue(const gl::DataType& type, const float& value){
    static constexpr double ubyte = 1.0 / (double)(1 << 8);
    static constexpr double uint_2_10_10_10 = 1.0 / (double)(1 << 10);
    static constexpr double ushort = 1.0 / (double)(1 << 16);

    switch (type){
    case gl::DataType::UByte: return int(value / ubyte) * ubyte;
    case gl::DataType::UInt_2_10_10_10: return int(value / uint_2_10_10_10) * uint_2_10_10_10;
    case gl::DataType::UShort: return int(value / ushort) * ushort;
    default: return value;
    }
}

static inline gl::DataType getGlDataType(const aiVector3D* arr, size_t arr_size, const float& epsilon){
    auto type = gl::DataType::UByte;
    for (size_t i = 0; i < arr_size; ++i){
        for (size_t j = 0; j < 3; ++j){
            auto v = arr[i][j];
            if (std::abs(v - getGlDataTypeValue(type, v)) > epsilon){
                type = nextGlDataType(type);
            }
        }
    }
    return type;
}

static inline gl::DataType getGlDataType(const aiColor4D* arr, size_t arr_size, const float& epsilon){
    auto type = gl::DataType::UByte;
    for (size_t i = 0; i < arr_size; ++i){
        for (size_t j = 0; j < 4; ++j){
            auto v = arr[i][j];
            if (std::abs(v - getGlDataTypeValue(type, v)) > epsilon){
                type = nextGlDataType(type);
            }
        }
    }
    return type;
}

static inline gl::DataType getGlDataType(const aiMesh& ai_mesh, const MeshAttribute& attr, const float& epsilon){
    switch (attr){
    case MeshAttribute::Position: return getGlDataType(ai_mesh.mVertices, ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Normal: return getGlDataType(ai_mesh.mNormals, ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Tangent: return getGlDataType(ai_mesh.mTangents, ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Bitangent: return getGlDataType(ai_mesh.mBitangents, ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_0: return getGlDataType(ai_mesh.mTextureCoords[0], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_1: return getGlDataType(ai_mesh.mTextureCoords[1], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_2: return getGlDataType(ai_mesh.mTextureCoords[2], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_3: return getGlDataType(ai_mesh.mTextureCoords[3], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_4: return getGlDataType(ai_mesh.mTextureCoords[4], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_5: return getGlDataType(ai_mesh.mTextureCoords[5], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_6: return getGlDataType(ai_mesh.mTextureCoords[6], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::TexCoord_7: return getGlDataType(ai_mesh.mTextureCoords[7], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Color_0: return getGlDataType(ai_mesh.mColors[0], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Color_1: return getGlDataType(ai_mesh.mColors[1], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Color_2: return getGlDataType(ai_mesh.mColors[2], ai_mesh.mNumVertices, epsilon);
    case MeshAttribute::Color_3: return getGlDataType(ai_mesh.mColors[3], ai_mesh.mNumVertices, epsilon);
    default: throw std::runtime_error("Unsuported MeshAttribute");
    }
}

}

MeshInfo::MeshInfo(){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        _attrib_info.push_back({
            .enabled = false,
            .type = gl::DataType::Float,
            .size = MeshAttributeSize::None,
            .byte_offset = 0,
            .byte_stride = 0,
            .value_offset = {0, 0, 0, 0},
            .value_mult = 1,
        });
    }
}

MeshInfo::~MeshInfo(){
}

void MeshInfo::apply(const MeshConfig& cfg, const aiMesh& ai_mesh){
    static const size_t enum_size = GetMeshAttributeEnumSize();

    _bytes_total = 0;
    for (size_t i = 0; i < enum_size; ++i){
        MeshAttribute attr = static_cast<MeshAttribute>(i);
        AttribInfo& attr_info = _get_info(attr);

        attr_info.enabled = doAiMeshHasAttrib(ai_mesh, attr) && cfg.getSize(attr) != MeshAttributeSize::None;
        attr_info.size = attr_info.enabled ? cfg.getSize(attr) : MeshAttributeSize::None;
        attr_info.byte_offset = _bytes_total;
        attr_info.value_offset = attr_info.enabled ? getAiMeshAttribOffset(ai_mesh, attr) : glm::vec4(0);
        attr_info.value_mult = attr_info.enabled ? getAiMeshAttribMult(ai_mesh, attr, attr_info.value_offset) : 1;
        attr_info.type = attr_info.enabled ? getGlDataType(ai_mesh, attr, attr_info.value_mult * cfg.getCompression(attr)) : static_cast<gl::DataType>(0);

        std::cout << "Attr: " << i << " - " << static_cast<size_t>(attr_info.type) << std::endl;

        _bytes_total += getAttributeSize(attr_info.type, attr_info.size);
    }

    for (size_t i = 0; i < enum_size; ++i){
        MeshAttribute attr = static_cast<MeshAttribute>(i);
        AttribInfo& attr_info = _get_info(attr);
        attr_info.byte_stride = _bytes_total;
    }
}

const size_t& MeshInfo::getTotalBytes() const {
    return _bytes_total;
}

const bool& MeshInfo::isEnabled(const MeshAttribute& attribute) const {
    return _get_info(attribute).enabled;
}

const gl::DataType& MeshInfo::getType(const MeshAttribute& attribute) const {
    return _get_info(attribute).type;
}

const MeshAttributeSize& MeshInfo::getSize(const MeshAttribute& attribute) const {
    return _get_info(attribute).size;
}

const size_t& MeshInfo::getByteOffset(const MeshAttribute& attribute) const {
    return _get_info(attribute).byte_offset;
}

const size_t& MeshInfo::getByteStride(const MeshAttribute& attribute) const {
    return _get_info(attribute).byte_stride;
}

const glm::vec4& MeshInfo::getValueOffset(const MeshAttribute& attribute) const {
    return _get_info(attribute).value_offset;
}

const float& MeshInfo::getValueMultiplier(const MeshAttribute& attribute) const {
    return _get_info(attribute).value_mult;
}

glm::vec3 MeshInfo::norm(const MeshAttribute& attribute, const aiVector3D& vec) const {
    auto attr_info = _get_info(attribute);
    auto& offset = attr_info.value_offset;
    auto& mult = attr_info.value_mult;

    return {
        (vec.x - offset.x) / mult,
        (vec.y - offset.y) / mult,
        (vec.z - offset.z) / mult
    };
}

glm::vec3 MeshInfo::norm(const MeshAttribute& attribute, const glm::vec3& vec) const {
    auto attr_info = _get_info(attribute);
    auto& offset = attr_info.value_offset;
    auto& mult = attr_info.value_mult;

    return {
        (vec.x - offset.x) / mult,
        (vec.y - offset.y) / mult,
        (vec.z - offset.z) / mult
    };
}

glm::vec4 MeshInfo::norm(const MeshAttribute& attribute, const aiColor4D& vec) const {
    auto attr_info = _get_info(attribute);
    auto& offset = attr_info.value_offset;
    auto& mult = attr_info.value_mult;

    return {
        (vec.r - offset.x) / mult,
        (vec.g - offset.y) / mult,
        (vec.b - offset.z) / mult,
        (vec.a - offset.w) / mult
    };
}

glm::vec4 MeshInfo::norm(const MeshAttribute& attribute, const glm::vec4& vec) const {
    auto attr_info = _get_info(attribute);
    auto& offset = attr_info.value_offset;
    auto& mult = attr_info.value_mult;

    return {
        (vec.x - offset.x) / mult,
        (vec.y - offset.y) / mult,
        (vec.z - offset.z) / mult,
        (vec.w - offset.w) / mult
    };
}

MeshInfo::AttribInfo& MeshInfo::_get_info(const MeshAttribute& attribute){
    auto i = static_cast<size_t>(attribute);
    return _attrib_info[i];
}

const MeshInfo::AttribInfo& MeshInfo::_get_info(const MeshAttribute& attribute) const {
    auto i = static_cast<size_t>(attribute);
    return _attrib_info[i];
}