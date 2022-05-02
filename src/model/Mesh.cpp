#include "glwpp/model/Mesh.hpp"

#include "assimp/scene.h"
#include "magic_enum.hpp"

#include "glwpp/model/MeshVertexAttribute.hpp"

using namespace glwpp;

Mesh Mesh::Cube(const wptr<Context>& wctx, const MeshConfig& prefered_types){
    static const aiVector3D vertices[8] = {
        {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
        {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}
    };
    static const unsigned int faces_data[12][3] = {
        {0, 5, 4}, {0, 1, 5}, {0, 4, 6}, {0, 6, 2},
        {0, 1, 3}, {0, 3, 2}, {7, 6, 4}, {7, 4, 5},
        {7, 3, 2}, {7, 2, 6}, {7, 5, 1}, {7, 1, 3}
    };

    aiMesh ai_mesh;
    ai_mesh.mNumVertices = 8;
    ai_mesh.mVertices = new aiVector3D[8];
    memcpy(ai_mesh.mVertices, vertices, sizeof(vertices));

    ai_mesh.mNumFaces = 12;
    ai_mesh.mFaces = new aiFace[12];
    for (int i = 0; i < 12; ++i){
        ai_mesh.mFaces[i].mNumIndices = 3;
        ai_mesh.mFaces[i].mIndices = new unsigned int[3];
        memcpy(ai_mesh.mFaces[i].mIndices, faces_data[i], sizeof(faces_data[i]));
    }

    aiFace faces[12];
    for (int i = 0; i < 12; ++i){
        faces[i].mNumIndices = 3;
        faces[i].mIndices = new unsigned int[3];
        memcpy(faces[i].mIndices, faces_data[i], sizeof(faces_data[i]));
    }

    Mesh cube(wctx, prefered_types);
    cube.loadAssimpMesh(ai_mesh);

    return std::move(cube);
}

Mesh::Mesh(const wptr<Context>& wctx, const MeshConfig& prefered_types) :
    _ctx(wctx),
    _config(prefered_types){
}

Mesh::~Mesh(){

}

bool Mesh::loadAssimpMesh(const aiMesh& ai_mesh, const SrcLoc loc){
    _info.apply(_config, ai_mesh);
    _prepareIndexBuffer(ai_mesh);
    _prepareVertexBuffer(ai_mesh);
    _prepareVertexArray(ai_mesh);

    return true;
}

const glm::vec4& Mesh::getValueOffset(const MeshAttribute& attribute) const {
    return _info.getValueOffset(attribute);
}

const float& Mesh::getValueMultiplicator(const MeshAttribute& attribute) const {
    return _info.getValueMultiplier(attribute);
}

const sptr<VertexArray>& Mesh::getVAO() const {
    return _vao;
}

void Mesh::_prepareIndexBuffer(const aiMesh& ai_mesh){
    sptr<void> buffer;
    size_t buffer_size;
    auto count = ai_mesh.mNumVertices;
    auto type =   count < 256   ? gl::DataType::UByte 
                : count < 65536 ? gl::DataType::UShort
                                : gl::DataType::UInt;

    switch (type){
    case gl::DataType::UByte:
        buffer_size = _getIndexBufferSize<gl::DataType::UByte>(ai_mesh);
        buffer = _makeIndexBuffer<gl::DataType::UByte>(ai_mesh);
        break;
    case gl::DataType::UShort:
        buffer_size = _getIndexBufferSize<gl::DataType::UShort>(ai_mesh);
        buffer = _makeIndexBuffer<gl::DataType::UShort>(ai_mesh);
        break;
    case gl::DataType::UInt:
        buffer_size = _getIndexBufferSize<gl::DataType::UInt>(ai_mesh);
        buffer = _makeIndexBuffer<gl::DataType::UInt>(ai_mesh);
        break;
    default: break;
    }

    _faces_count = ai_mesh.mNumFaces;
    _indices = make_sptr<Buffer>(_ctx);
    _indices->storage(buffer_size, buffer, 0);
}

template<gl::DataType D>
size_t Mesh::_getIndexBufferSize(const aiMesh& ai_mesh){
    return ai_mesh.mNumFaces * 3 * sizeof(gl::RawVertexAttribType<D>::type);
}

template<gl::DataType D>
sptr<void> Mesh::_makeIndexBuffer(const aiMesh& ai_mesh){
    auto total_size = _getIndexBufferSize<D>(ai_mesh);;
    auto tmp = createTmpData(nullptr, total_size);
    auto ptr = reinterpret_cast<unsigned char*>(tmp.get());

    for (size_t i = 0; i < ai_mesh.mNumFaces; ++i){
        if (ai_mesh.mFaces->mNumIndices != 3){
            throw std::runtime_error("Only triangulated models are supported.");
        }

        for (size_t j = 0; j < 3; ++j){
            ptr[3 * i + j] = ai_mesh.mFaces[i].mIndices[j];
        }
    }
    return tmp;
}

void Mesh::_prepareVertexBuffer(const aiMesh& ai_mesh){
    auto tmp = createTmpData(nullptr, ai_mesh.mNumVertices * _info.getTotalBytes());
    auto buffer = reinterpret_cast<char*>(tmp.get());

    for (size_t i = 0; i < ai_mesh.mNumVertices; ++i){
        char* vertex_ptr = buffer + i * _info.getTotalBytes();
        _fillVertex(vertex_ptr, i, ai_mesh);
    }

    _vertices = make_sptr<Buffer>(_ctx);
    _vertices->storage(ai_mesh.mNumVertices * _info.getTotalBytes(), tmp, 0);
}

void Mesh::_fillVertex(char* vertex_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        auto attr = static_cast<MeshAttribute>(i);
        char* attr_ptr = vertex_ptr + _info.getByteOffset(attr);
        _fillAttribute(attr_ptr, vertex_pos, ai_mesh, attr);
    }
}

void Mesh::_fillAttribute(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr){
    auto size = _info.getSize(attr);
    switch (size){
    case MeshAttributeSize::Scalar: return _fillAttributeSized<1>(attr_ptr, vertex_pos, ai_mesh, attr);
    case MeshAttributeSize::Vec2: return _fillAttributeSized<2>(attr_ptr, vertex_pos, ai_mesh, attr);
    case MeshAttributeSize::Vec3: return _fillAttributeSized<3>(attr_ptr, vertex_pos, ai_mesh, attr);
    case MeshAttributeSize::Vec4: return _fillAttributeSized<4>(attr_ptr, vertex_pos, ai_mesh, attr);
    
    default: return;
    }
}

template<size_t S>
void Mesh::_fillAttributeSized(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr){
    auto type = _info.getType(attr);

    if constexpr (S == 1 || S == 2 || S == 4){
        switch (type){
        case gl::DataType::Byte: return _fillAttributeSizedTyped<S, gl::DataType::Byte>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UByte: return _fillAttributeSizedTyped<S, gl::DataType::UByte>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Short: return _fillAttributeSizedTyped<S, gl::DataType::Short>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UShort: return _fillAttributeSizedTyped<S, gl::DataType::UShort>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Int: return _fillAttributeSizedTyped<S, gl::DataType::Int>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UInt: return _fillAttributeSizedTyped<S, gl::DataType::UInt>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Float: return _fillAttributeSizedTyped<S, gl::DataType::Float>(attr_ptr, vertex_pos, ai_mesh, attr);
        default: throw std::runtime_error("Unsuported gl::DataType with size 1, 2 or 4");
        }
    } else if constexpr (S == 3){
        switch (type){
        case gl::DataType::Byte: return _fillAttributeSizedTyped<S, gl::DataType::Byte>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UByte: return _fillAttributeSizedTyped<S, gl::DataType::UByte>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Short: return _fillAttributeSizedTyped<S, gl::DataType::Short>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UShort: return _fillAttributeSizedTyped<S, gl::DataType::UShort>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Int: return _fillAttributeSizedTyped<S, gl::DataType::Int>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UInt: return _fillAttributeSizedTyped<S, gl::DataType::UInt>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Float: return _fillAttributeSizedTyped<S, gl::DataType::Float>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::Int_2_10_10_10: return _fillAttributeSizedTyped<S, gl::DataType::Int_2_10_10_10>(attr_ptr, vertex_pos, ai_mesh, attr);
        case gl::DataType::UInt_2_10_10_10: return _fillAttributeSizedTyped<S, gl::DataType::UInt_2_10_10_10>(attr_ptr, vertex_pos, ai_mesh, attr);
        default: throw std::runtime_error("Unsuported gl::DataType with size 3");
        }
    }
    throw std::runtime_error("Unsuported size");
}

template<size_t S, gl::DataType D>
void Mesh::_fillAttributeSizedTyped(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr){
    auto ptr = reinterpret_cast<Attribute<D, S>*>(attr_ptr);

    if (attr != MeshAttribute::Color_0
        && attr != MeshAttribute::Color_1
        && attr != MeshAttribute::Color_2
        && attr != MeshAttribute::Color_3){
        
        glm::vec3 normed;
        switch (attr){
        case MeshAttribute::Position: normed = _info.norm(attr, ai_mesh.mVertices[vertex_pos]); break;
        case MeshAttribute::Normal: normed = _info.norm(attr, ai_mesh.mNormals[vertex_pos]); break;
        case MeshAttribute::Tangent: normed = _info.norm(attr, ai_mesh.mTangents[vertex_pos]); break;
        case MeshAttribute::Bitangent: normed = _info.norm(attr, ai_mesh.mBitangents[vertex_pos]); break;
        case MeshAttribute::TexCoord_0: normed = _info.norm(attr, ai_mesh.mTextureCoords[0][vertex_pos]); break;
        case MeshAttribute::TexCoord_1: normed = _info.norm(attr, ai_mesh.mTextureCoords[1][vertex_pos]); break;
        case MeshAttribute::TexCoord_2: normed = _info.norm(attr, ai_mesh.mTextureCoords[2][vertex_pos]); break;
        case MeshAttribute::TexCoord_3: normed = _info.norm(attr, ai_mesh.mTextureCoords[3][vertex_pos]); break;
        case MeshAttribute::TexCoord_4: normed = _info.norm(attr, ai_mesh.mTextureCoords[4][vertex_pos]); break;
        case MeshAttribute::TexCoord_5: normed = _info.norm(attr, ai_mesh.mTextureCoords[5][vertex_pos]); break;
        case MeshAttribute::TexCoord_6: normed = _info.norm(attr, ai_mesh.mTextureCoords[6][vertex_pos]); break;
        case MeshAttribute::TexCoord_7: normed = _info.norm(attr, ai_mesh.mTextureCoords[7][vertex_pos]); break;
        
        default: throw std::runtime_error("Unknown attribute");
        }
        ptr->set(normed.x, normed.y, normed.z, 0);
    } else {
        glm::vec4 normed;
        switch (attr){
        case MeshAttribute::Color_0: normed = _info.norm(attr, ai_mesh.mColors[0][vertex_pos]); break;
        case MeshAttribute::Color_1: normed = _info.norm(attr, ai_mesh.mColors[1][vertex_pos]); break;
        case MeshAttribute::Color_2: normed = _info.norm(attr, ai_mesh.mColors[2][vertex_pos]); break;
        case MeshAttribute::Color_3: normed = _info.norm(attr, ai_mesh.mColors[3][vertex_pos]); break;
        
        default: throw std::runtime_error("Unknown attribute");
        }
        ptr->set(normed.r, normed.b, normed.g, normed.a);
    }
}

void Mesh::_prepareVertexArray(const aiMesh& ai_mesh){
    _vao = make_sptr<VertexArray>(_ctx);
    _vao->setElementBuffer(*_indices);
    _vao->setVertexBuffer(0, *_vertices, 0, _info.getTotalBytes());

    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        auto attr = static_cast<MeshAttribute>(i);
        if (!_info.isEnabled(attr)){
            continue;
        }

        _vao->enableAttrib(i);
        _vao->setAttribBinding(i, _config.getLocation(attr));
        _vao->setAttribFormat(i, static_cast<size_t>(_info.getSize(attr)), _info.getType(attr), true, _info.getByteOffset(attr));
    }
}

const MeshConfig& Mesh::_get_default_types(){
    static const MeshConfig default_types = [](){
        MeshConfig types;
        // types.setType(MeshAttribute::Position, gl::DataType::UByte);
        // types.setType(MeshAttribute::Normal, gl::DataType::UByte);
        // types.setType(MeshAttribute::Tangent, gl::DataType::UByte);
        // types.setType(MeshAttribute::Bitangent, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_0, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_1, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_2, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_3, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_4, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_5, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_6, gl::DataType::UByte);
        // types.setType(MeshAttribute::TexCoord_7, gl::DataType::UByte);
        // types.setType(MeshAttribute::Color_0, gl::DataType::UByte);
        // types.setType(MeshAttribute::Color_1, gl::DataType::UByte);
        // types.setType(MeshAttribute::Color_2, gl::DataType::UByte);
        // types.setType(MeshAttribute::Color_3, gl::DataType::UByte);
        
        types.setSize(MeshAttribute::Position, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::Normal, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::Tangent, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::Bitangent, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_0, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_1, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_2, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_3, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_4, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_5, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_6, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::TexCoord_7, MeshAttributeSize::Vec3);
        types.setSize(MeshAttribute::Color_0, MeshAttributeSize::Vec4);
        types.setSize(MeshAttribute::Color_1, MeshAttributeSize::Vec4);
        types.setSize(MeshAttribute::Color_2, MeshAttributeSize::Vec4);
        types.setSize(MeshAttribute::Color_3, MeshAttributeSize::Vec4);

        return types;
    }();
    return default_types;
}