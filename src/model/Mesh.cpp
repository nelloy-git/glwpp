#include "glwpp/model/Mesh.hpp"

#include "assimp/scene.h"

#include "glwpp/model/Attrubute.hpp"

using namespace glwpp;

Mesh::Mesh(const wptr<Context>& ctx, const MeshInfo& info) :
    _ctx(ctx),
    _info(info){
}

Mesh::~Mesh(){

}

bool Mesh::loadAssimpMesh(const aiMesh& ai_mesh, const SrcLoc& loc){
    _calcMeshInfo(ai_mesh);

    size_t vert_buffer_size = _info.size();
    _vertices = std::make_unique<Buffer>(_ctx, loc);

    gl::BufferStorageFlagBitfield flags(gl::BufferStorageFlag::Dynamic);
    _vertices->storage(vert_buffer_size, nullptr, flags.fields, loc);
    _vertices->setSubData(_info.position.offset,
                          _info.position.size,
                          _packVec3D(ai_mesh.mVertices, ai_mesh.mNumVertices, _info.position.type),
                          loc);

    return true;
}

template<class T>
static size_t getVertexAttributeSize(const gl::DataType& type){
    if constexpr (std::is_same_v<std::remove_reference_t<T>, aiVector3D>){
        switch (type){
            case gl::DataType::Byte: return sizeof(Attribute3D<gl::DataType::Byte>);
            case gl::DataType::UByte: return sizeof(Attribute3D<gl::DataType::UByte>);
            case gl::DataType::Short: return sizeof(Attribute3D<gl::DataType::Short>);
            case gl::DataType::UShort: return sizeof(Attribute3D<gl::DataType::UShort>);
            case gl::DataType::Int: return sizeof(Attribute3D<gl::DataType::Int>);
            case gl::DataType::UInt: return sizeof(Attribute3D<gl::DataType::UInt>);
            case gl::DataType::Float: return sizeof(Attribute3D<gl::DataType::Float>);
            case gl::DataType::Int_2_10_10_10: return sizeof(Attribute3D<gl::DataType::Int_2_10_10_10>);
            case gl::DataType::UInt_2_10_10_10: return sizeof(Attribute3D<gl::DataType::UInt_2_10_10_10>);
            
            default: throw std::runtime_error("Unsuported gl::DataType");
        }
    } else if constexpr (std::is_same_v<std::remove_reference_t<T>, aiColor4D>){
        []<bool B = false>(){static_assert(B, "Unknown ai_Vector");}();
    } else {
        []<bool B = false>(){static_assert(B, "Unknown ai_Vector");}();
    }
}

void Mesh::_calcMeshInfo(const aiMesh& ai_mesh){
    size_t offset = 0;
    size_t count = ai_mesh.mNumVertices;

    _info.position.enabled = ai_mesh.HasPositions();
    if (_info.position.enabled){
        _info.position.size = count * getVertexAttributeSize<decltype(*aiMesh::mVertices)>(_info.position.type);
        _info.position.offset = offset;
        offset += _info.position.size;
    }

    _info.normal.enabled = ai_mesh.HasNormals();
    if (_info.normal.enabled){
        _info.normal.size = count * getVertexAttributeSize<decltype(*aiMesh::mNormals)>(_info.normal.type);
        _info.normal.offset = offset;
        offset += _info.normal.size;
    }

    _info.tangent.enabled = ai_mesh.HasTangentsAndBitangents();
    _info.bitangent.enabled = _info.tangent.enabled;
    if (_info.tangent.enabled){
        _info.tangent.size = count * getVertexAttributeSize<decltype(*aiMesh::mTangents)>(_info.tangent.type);
        _info.tangent.offset = offset;
        offset += _info.tangent.size;
        
        _info.bitangent.size = count * getVertexAttributeSize<decltype(*aiMesh::mBitangents)>(_info.bitangent.type);
        _info.bitangent.offset = offset;
        offset += _info.bitangent.size;
    }

    for (int i = 0; i < MESH_MAX_TEX_COORDS; ++i){
        _info.texture_coord->enabled = ai_mesh.HasTextureCoords(i);
        if (_info.texture_coord->enabled){
            _info.texture_coord[i].size = count * getVertexAttributeSize<decltype(*aiMesh::mTextureCoords[i])>(_info.texture_coord[i].type);
            _info.texture_coord[i].offset = offset;
            offset += _info.texture_coord[i].size;
        }
    }

    for (int i = 0; i < MESH_MAX_VERT_COLORS; ++i){
        _info.color[i].enabled = ai_mesh.HasVertexColors(i);
        if (_info.color[i].enabled){
            // _info.color[i].size = count * getVertexAttributeSize<decltype(*aiMesh::mColors[i])>(_info.color[i].type);
            _info.color[i].offset = offset;
            offset += _info.color[i].size;
        }
    }
}

namespace {

static inline std::pair<float, float> findMinMaxAiVector3D(const aiVector3D* arr, size_t size){
    static auto inf = std::numeric_limits<float>::infinity();
    static auto ninf = -std::numeric_limits<float>::infinity();

    float min = inf;
    float max = ninf;
    for (unsigned int i = 0; i < size; ++i){
        min = std::min(min, arr[i].x);
        min = std::min(min, arr[i].y);
        min = std::min(min, arr[i].z);

        max = std::max(max, arr[i].x);
        max = std::max(max, arr[i].y);
        max = std::max(max, arr[i].z);
    }
    return std::make_pair(min, max);
}

template<gl::DataType T>
static inline sptr<void> copy_attrib(const aiVector3D* src, float mult, float offset, size_t count){
    auto tmp_data = createTmpData(nullptr, count * sizeof(Attribute3D<T>));
    auto data_ptr = reinterpret_cast<Attribute3D<T>*>(tmp_data.get());

    for (size_t i = 0; i < count; ++i){
        auto& cur = src[i];
        
        float x = (cur.x + offset) / mult;
        float y = (cur.y + offset) / mult;
        float z = (cur.z + offset) / mult;

        data_ptr[i].set(x, y, z);
    }

    return tmp_data;
}

}

sptr<void> Mesh::_packVec3D(const aiVector3D* src, const size_t& count, const gl::DataType& target){
    auto min_max = findMinMaxAiVector3D(src, count);
    float offset = -min_max.first;
    float mult = min_max.second - min_max.first;

    _info.position.value_offset = offset;
    _info.position.value_mult = mult;
    
    switch (_info.position.type){
        case gl::DataType::Byte: return copy_attrib<gl::DataType::Byte>(src, mult, offset, count);
        case gl::DataType::UByte: return copy_attrib<gl::DataType::UByte>(src, mult, offset, count);
        case gl::DataType::Short: return copy_attrib<gl::DataType::Short>(src, mult, offset, count);
        case gl::DataType::UShort: return copy_attrib<gl::DataType::UShort>(src, mult, offset, count);
        case gl::DataType::Int: return copy_attrib<gl::DataType::Int>(src, mult, offset, count);
        case gl::DataType::UInt: return copy_attrib<gl::DataType::UInt>(src, mult, offset, count);
        case gl::DataType::Float: return copy_attrib<gl::DataType::Float>(src, mult, offset, count);
        case gl::DataType::Int_2_10_10_10: return copy_attrib<gl::DataType::Int_2_10_10_10>(src, mult, offset, count);
        case gl::DataType::UInt_2_10_10_10: return copy_attrib<gl::DataType::UInt_2_10_10_10>(src, mult, offset, count);
        default: throw std::runtime_error("Unsuported gl::DataType");
    }
}