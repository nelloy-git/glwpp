#include "glwpp/model/MeshVertexData.hpp"

#include <iostream>
#include <stdexcept>
#include <variant>

#include "assimp/mesh.h"
#include "magic_enum.hpp"

#include "glwpp/model/MeshAttributeData.hpp"

using namespace glwpp;
using namespace glwpp::model;

namespace {

template<typename T>
constexpr size_t _getVecComponents(){
    using ClearedT = std::remove_const_t<std::remove_reference_t<T>>;

    if constexpr (is_same_any<ClearedT, aiVector3D, glm::vec3>){
        return 3;
    } else if constexpr (is_same_any<ClearedT, aiColor4D, glm::vec4>){
        return 4;
    } else {
        []<bool B = false>(){static_assert(B, "Unknown vector type");}();
    }
};

};

MeshVertexData::MeshVertexData(const wptr<Context>& wctx, const MeshVertexConfig& config, const aiMesh& ai_mesh,
                               const utils::Val<const utils::SrcLoc>& src_loc) :
    _config(config),
    _vertices(wctx, src_loc){
    _fillAttributeStates(ai_mesh);
    _fillVertexBuffer(ai_mesh);
}

MeshVertexData::~MeshVertexData(){
}

const gl::Buffer& MeshVertexData::getVertices() const {
    return _vertices;
}

const MeshVertexConfig& MeshVertexData::getConfig() const {
    return _config;
}

const gl::UInt& MeshVertexData::getBytesPerVertex() const {
    return _vertex_bytes;
}

const gl::UInt& MeshVertexData::getVertexCount() const {
    return _vertex_count;
}

const bool& MeshVertexData::isEnabled(const MeshAttribute& attribute) const {
    return _attr_state[attribute].enabled;
}

const MeshAttributeType& MeshVertexData::getType(const MeshAttribute& attribute) const {
    return _attr_state[attribute].type;
}

const MeshAttributeSize& MeshVertexData::getSize(const MeshAttribute& attribute) const {
    return _attr_state[attribute].size;
}

const gl::UInt& MeshVertexData::getByteOffset(const MeshAttribute& attribute) const {
    return _attr_state[attribute].byte_offset;
}

const glm::vec4& MeshVertexData::getValueOffset(const MeshAttribute& attribute) const {
    return _attr_state[attribute].value_offset;
}

const float& MeshVertexData::getValueMultiplier(const MeshAttribute& attribute) const {
    return _attr_state[attribute].value_mult;
}

void MeshVertexData::_fillAttributeStates(const aiMesh& ai_mesh){
    _vertex_bytes = 0;
    _vertex_count = ai_mesh.mNumVertices;

    _attr_state.for_each([&](auto attr){
        auto& info = _attr_state[attr];

        info.enabled = _config.isEnabled(attr) && _doAiMeshHasAttribute<attr>(ai_mesh);
        if (!info.enabled){
            return;
        }

        info.byte_offset = _vertex_bytes;
        info.value_offset = _findValueOffset<attr>(ai_mesh);
        info.value_mult = _findValueMultiplier<attr>(ai_mesh, info.value_offset);
        info.size = _config.getSize(attr);
        info.compression = _config.getCompression(attr);
        if (_config.getForcedType(attr)){
            info.type = _config.getForcedType(attr).value();
        } else {
            info.type = _findOptimalType<attr>(ai_mesh, info.size, info.compression, info.value_offset, info.value_mult);    
        }
        _vertex_bytes += getMeshAttributeDataBytes(info.type, info.size);
    });
}

void MeshVertexData::_fillVertexBuffer(const aiMesh& ai_mesh){
    auto tmp = utils::alloc_sptr_buffer<char>(_vertex_count * _vertex_bytes);

    _attr_state.for_each([&](auto attr){
        auto& info = _attr_state[attr];
        if (!info.enabled){
            return;
        }

        const auto arr = _getAiArray<attr>(ai_mesh);
        char* attr_ptr = tmp.get() + info.byte_offset;

        for (size_t i = 0; i < _vertex_count; ++i){
            auto vec = _normalize<decltype(arr[0]), glm::vec4>(arr[i], info.value_offset, info.value_mult);
            _fillVertexBufferAttribute(attr_ptr, vec, info.type, info.size);

            attr_ptr += _vertex_bytes;
        }
    });

    _vertices.storage(_vertex_count * _vertex_bytes, tmp, 0);
}

void MeshVertexData::_fillVertexBufferAttribute(void* dst, const glm::vec4& vec,
                                                const MeshAttributeType& type, const MeshAttributeSize& size){
    using namespace magic_enum;
    using T = MeshAttributeType;
    using S = MeshAttributeSize;

    switch (type){
    case T::UInt_11_11_10:
        switch (size){
        case S::Vec3: reinterpret_cast<MeshAttributeData<T::UInt_11_11_10, S::Vec3>*>(dst)->set(vec); break;
        default: throw std::logic_error("Invalid MeshAttributeSize for UInt_11_11_10");
    }; break;
    case T::UInt_10_10_10_2:
        switch (size){
        case S::Vec4: reinterpret_cast<MeshAttributeData<T::UInt_10_10_10_2, S::Vec4>*>(dst)->set(vec); break;
        default: throw std::logic_error("Invalid MeshAttributeSize for UInt_10_10_10_2");
    }; break;
    case T::UByte:
        switch (size){
        case S::Scalar: reinterpret_cast<MeshAttributeData<T::UByte, S::Scalar>*>(dst)->set(vec); break;
        case S::Vec2: reinterpret_cast<MeshAttributeData<T::UByte, S::Vec2>*>(dst)->set(vec); break;
        case S::Vec3: reinterpret_cast<MeshAttributeData<T::UByte, S::Vec3>*>(dst)->set(vec); break;
        case S::Vec4: reinterpret_cast<MeshAttributeData<T::UByte, S::Vec4>*>(dst)->set(vec); break;
        default: throw std::logic_error("Invalid MeshAttributeSize for UByte");
    }; break;
    case T::UShort:
        switch (size){
        case S::Scalar: reinterpret_cast<MeshAttributeData<T::UShort, S::Scalar>*>(dst)->set(vec); break;
        case S::Vec2: reinterpret_cast<MeshAttributeData<T::UShort, S::Vec2>*>(dst)->set(vec); break;
        case S::Vec3: reinterpret_cast<MeshAttributeData<T::UShort, S::Vec3>*>(dst)->set(vec); break;
        case S::Vec4: reinterpret_cast<MeshAttributeData<T::UShort, S::Vec4>*>(dst)->set(vec); break;
        default: throw std::logic_error("Invalid MeshAttributeSize for UShort");
    }; break;
    case T::Float:
        switch (size){
        case S::Scalar: reinterpret_cast<MeshAttributeData<T::Float, S::Scalar>*>(dst)->set(vec); break;
        case S::Vec2: reinterpret_cast<MeshAttributeData<T::Float, S::Vec2>*>(dst)->set(vec); break;
        case S::Vec3: reinterpret_cast<MeshAttributeData<T::Float, S::Vec3>*>(dst)->set(vec); break;
        case S::Vec4: reinterpret_cast<MeshAttributeData<T::Float, S::Vec4>*>(dst)->set(vec); break;
        default: throw std::logic_error("Invalid MeshAttributeSize for Float");
    }; break;
    
    default:
        switch (size){
        case S::Scalar: throw std::logic_error("Invalid MeshAttributeType for Scalar");
        case S::Vec2: throw std::logic_error("Invalid MeshAttributeType for Vec2");
        case S::Vec3: throw std::logic_error("Invalid MeshAttributeType for Vec3");
        case S::Vec4: throw std::logic_error("Invalid MeshAttributeType for Vec4");
        default: throw std::logic_error("Invalid MeshAttributeType and MeshAttributeSize");
    }; break;
    }
}

template<typename In, typename Out>
Out MeshVertexData::_normalize(const In& vec, const glm::vec4& value_offset, const float& value_mult){
    static constexpr size_t In_S = _getVecComponents<In>();
    static constexpr size_t Out_S = _getVecComponents<Out>();

    Out res;
    for (size_t i = 0; i < Out_S; ++i){
        if (i < In_S){
            res[i] = (vec[i] - value_offset[i]) / value_mult;
        } else {
            res[i] = 0;
        }
    }
    return res;
}

template<MeshAttribute A>
glm::vec4 MeshVertexData::_findValueOffset(const aiMesh& ai_mesh) const {
    static auto inf = std::numeric_limits<float>::infinity();
    auto arr = _getAiArray<A>(ai_mesh);
    const size_t S = std::is_same_v<decltype(arr), aiVector3D*> ? 3 : 4;
    glm::vec4 offset(inf, inf, inf, inf);

    for (size_t i = 0; i < ai_mesh.mNumVertices; ++i){
        for (size_t j = 0; j < S; ++j){
            offset[j] = std::min(offset[j], arr[i][j]);    
        }
    }
    return offset;
}

template<MeshAttribute A>
float MeshVertexData::_findValueMultiplier(const aiMesh& ai_mesh, const glm::vec4& value_offset){
    auto arr = _getAiArray<A>(ai_mesh);
    const size_t S = std::is_same_v<decltype(arr), aiVector3D*> ? 3 : 4;
    float max = -std::numeric_limits<float>::infinity();

    for (size_t i = 0; i < ai_mesh.mNumVertices; ++i){
        for (size_t j = 0; j < S; ++j){
            max = std::max(max, arr[i][j] - value_offset[j]);    
        }
    }
    return max;
}

template<MeshAttribute A>
MeshAttributeType MeshVertexData::_findOptimalType(const aiMesh& ai_mesh, const MeshAttributeSize& size, const float& compression,
                                                   const glm::vec4& value_offset, const float& value_mult){
    constexpr auto nextType = [](const MeshAttributeType& type, const MeshAttributeSize& size){
        switch (type){
        case MeshAttributeType::UByte: return size == MeshAttributeSize::Vec3
                                                ? MeshAttributeType::UInt_11_11_10
                                                : MeshAttributeType::UInt_10_10_10_2;
        case MeshAttributeType::UInt_11_11_10: return MeshAttributeType::UShort;
        case MeshAttributeType::UInt_10_10_10_2: return MeshAttributeType::UShort;          
        case MeshAttributeType::UShort: return MeshAttributeType::Float;            
        default: return MeshAttributeType::Float;
        }
    };

    constexpr auto isCompessable = [](const MeshAttributeType& type, const auto& original,
                                      const float& compression, const glm::vec4& value_offset, const float& value_mult){
        static constexpr size_t S = _getVecComponents<decltype(original)>();

        auto normed = _normalize(original, value_offset, value_mult);
        for (size_t i = 0; i < S; ++i){
            size_t bits;
            switch (type){
            case MeshAttributeType::UByte: bits = 8; break;
            case MeshAttributeType::UInt_11_11_10: bits = i < 2 ? 11 : 10; break;
            case MeshAttributeType::UInt_10_10_10_2: bits = i < 3 ? 10 : 2; break;
            case MeshAttributeType::UShort: bits = 16; break;
            case MeshAttributeType::Float: return true; // to float is always campressable
            default: throw std::runtime_error("Wrong MeshAttributeType");
            }

            auto optimized = unpackMeshAttributeDataValue(packMeshAttributeDataValue(normed[i], bits), bits);
            if (std::abs(normed[i] - optimized) > compression){
                return false;
            }
        }
        return true;
    };

    auto arr = _getAiArray<A>(ai_mesh);
    auto type = MeshAttributeType::UByte;
    for (size_t i = 0; i < ai_mesh.mNumVertices; ++i){
        if (!isCompessable(type, arr[i], compression, value_offset, value_mult)){
            type = nextType(type, size);
        }
                
        if (type == MeshAttributeType::Float){
            break;
        }
    }
    return type;
}

template<MeshAttribute A>
bool MeshVertexData::_doAiMeshHasAttribute(const aiMesh& ai_mesh){
    if constexpr (A == MeshAttribute::Position){
        return ai_mesh.HasPositions();
    } else if constexpr (A == MeshAttribute::Normal){
        return ai_mesh.HasNormals();
    } else if constexpr (A == MeshAttribute::Tangent){
        return ai_mesh.HasTangentsAndBitangents();
    } else if constexpr (A == MeshAttribute::Bitangent){
        return ai_mesh.HasTangentsAndBitangents();
    } else if constexpr (A == MeshAttribute::TexCoord_0){
        return ai_mesh.HasTextureCoords(0);
    } else if constexpr (A == MeshAttribute::TexCoord_1){
        return ai_mesh.HasTextureCoords(1);
    } else if constexpr (A == MeshAttribute::TexCoord_2){
        return ai_mesh.HasTextureCoords(2);
    } else if constexpr (A == MeshAttribute::TexCoord_3){
        return ai_mesh.HasTextureCoords(3);
    } else if constexpr (A == MeshAttribute::TexCoord_4){
        return ai_mesh.HasTextureCoords(4);
    } else if constexpr (A == MeshAttribute::TexCoord_5){
        return ai_mesh.HasTextureCoords(5);
    } else if constexpr (A == MeshAttribute::TexCoord_6){
        return ai_mesh.HasTextureCoords(6);
    } else if constexpr (A == MeshAttribute::TexCoord_7){
        return ai_mesh.HasTextureCoords(7);
    } else if constexpr (A == MeshAttribute::Color_0){
        return ai_mesh.HasVertexColors(0);
    } else if constexpr (A == MeshAttribute::Color_1){
        return ai_mesh.HasVertexColors(1);
    } else if constexpr (A == MeshAttribute::Color_2){
        return ai_mesh.HasVertexColors(2);
    } else if constexpr (A == MeshAttribute::Color_3){
        return ai_mesh.HasVertexColors(3);
    } else if constexpr (A == MeshAttribute::Color_4){
        return ai_mesh.HasVertexColors(4);
    } else if constexpr (A == MeshAttribute::Color_5){
        return ai_mesh.HasVertexColors(5);
    } else if constexpr (A == MeshAttribute::Color_6){
        return ai_mesh.HasVertexColors(6);
    } else if constexpr (A == MeshAttribute::Color_7){
        return ai_mesh.HasVertexColors(7);
    } else {
        []<bool B = false>(){static_assert(B, "Unknown MeshAttribute");}();
    }
}

template<MeshAttribute A>
auto MeshVertexData::_getAiArray(const aiMesh& ai_mesh){
    if constexpr (A == MeshAttribute::Position){
        return ai_mesh.mVertices;
    } else if constexpr (A == MeshAttribute::Normal){
        return ai_mesh.mNormals;
    } else if constexpr (A == MeshAttribute::Tangent){
        return ai_mesh.mTangents;
    } else if constexpr (A == MeshAttribute::Bitangent){
        return ai_mesh.mBitangents;
    } else if constexpr (A == MeshAttribute::TexCoord_0){
        return ai_mesh.mTextureCoords[0];
    } else if constexpr (A == MeshAttribute::TexCoord_1){
        return ai_mesh.mTextureCoords[1];
    } else if constexpr (A == MeshAttribute::TexCoord_2){
        return ai_mesh.mTextureCoords[2];
    } else if constexpr (A == MeshAttribute::TexCoord_3){
        return ai_mesh.mTextureCoords[3];
    } else if constexpr (A == MeshAttribute::TexCoord_4){
        return ai_mesh.mTextureCoords[4];
    } else if constexpr (A == MeshAttribute::TexCoord_5){
        return ai_mesh.mTextureCoords[5];
    } else if constexpr (A == MeshAttribute::TexCoord_6){
        return ai_mesh.mTextureCoords[6];
    } else if constexpr (A == MeshAttribute::TexCoord_7){
        return ai_mesh.mTextureCoords[7];
    } else if constexpr (A == MeshAttribute::Color_0){
        return ai_mesh.mColors[0];
    } else if constexpr (A == MeshAttribute::Color_1){
        return ai_mesh.mColors[1];
    } else if constexpr (A == MeshAttribute::Color_2){
        return ai_mesh.mColors[2];
    } else if constexpr (A == MeshAttribute::Color_3){
        return ai_mesh.mColors[3];
    } else if constexpr (A == MeshAttribute::Color_4){
        return ai_mesh.mColors[4];
    } else if constexpr (A == MeshAttribute::Color_5){
        return ai_mesh.mColors[5];
    } else if constexpr (A == MeshAttribute::Color_6){
        return ai_mesh.mColors[6];
    } else if constexpr (A == MeshAttribute::Color_7){
        return ai_mesh.mColors[7];
    } else {
        []<bool B = false>(){static_assert(B, "Unknown MeshAttribute");}();
    }
};