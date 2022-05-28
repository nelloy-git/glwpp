#include "glwpp/model/Mesh.hpp"

#include "assimp/scene.h"

#include "glwpp/model/MeshAttributeData.hpp"

using namespace glwpp;

Mesh Mesh::Cube(const wptr<Context>& wctx, const MeshVertexConfig& vertex_config){
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

    Mesh cube(wctx, ai_mesh, vertex_config);

    return std::move(cube);
}

Mesh::Mesh(const wptr<Context>& wctx, const aiMesh& ai_mesh, const MeshVertexConfig& vertex_config) :
    _ctx(wctx),
    _index_data(wctx, ai_mesh),
    _vert_data(wctx, vertex_config, ai_mesh){

    _vert_arr = make_sptr<VertexArray>(wctx);
    _vert_arr->setElementBuffer(*_index_data.getIndices());
    _vert_arr->setVertexBuffer(0, *_vert_data.getVertices(), 0, _vert_data.getBytesPerVertex());

    for (auto attr : _attr_bindings.enum_values()){
        if (!_vert_data.isEnabled(attr)){
            continue;
        }
        _vert_arr->setAttribBinding(_attr_bindings.enum_index(attr), 0);
    }
}

Mesh::~Mesh(){

}

sptr<VertexArray> Mesh::getVertexArray(){
    return _vert_arr;
}

void Mesh::setAttributeBindings(const EnumContainer<MeshAttribute, gl::Int>& bindings){
    for (auto attr : _attr_bindings.enum_values()){
        if (_attr_bindings[attr] == bindings[attr]){
            continue;
        }

        auto attr_i = _attr_bindings.enum_index(attr);
        if (!_vert_data.isEnabled(attr) or _attr_bindings[attr] < 0){
            _vert_arr->disableAttrib(attr_i);
            continue;
        }

        auto size = getMeshAttributeSizeComponents(_vert_data.getSize(attr));
        auto type = getMeshAttributeTypeGlType(_vert_data.getType(attr));
        auto offset = _vert_data.getByteOffset(attr);

        _vert_arr->enableAttrib(attr_i);
        _vert_arr->setAttribFormat(attr_i, size, type, true, offset);
    }
    _attr_bindings = bindings;
}