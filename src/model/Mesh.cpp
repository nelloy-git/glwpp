#include "glwpp/model/Mesh.hpp"

#include "assimp/scene.h"

#include "glwpp/model/MeshAttributeData.hpp"

using namespace glwpp;
using namespace glwpp::model;

// Mesh Mesh::Cube(const wptr<Context>& wctx, const MeshVertexConfig& vertex_config){
//     static const aiVector3D vertices[8] = {
//         {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
//         {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}
//     };
//     static const unsigned int faces_data[12][3] = {
//         {0, 5, 4}, {0, 1, 5}, {0, 4, 6}, {0, 6, 2},
//         {0, 1, 3}, {0, 3, 2}, {7, 6, 4}, {7, 4, 5},
//         {7, 3, 2}, {7, 2, 6}, {7, 5, 1}, {7, 1, 3}
//     };

//     aiMesh ai_mesh;
//     ai_mesh.mNumVertices = 8;
//     ai_mesh.mVertices = new aiVector3D[8];
//     memcpy(ai_mesh.mVertices, vertices, sizeof(vertices));

//     ai_mesh.mNumFaces = 12;
//     ai_mesh.mFaces = new aiFace[12];
//     for (int i = 0; i < 12; ++i){
//         ai_mesh.mFaces[i].mNumIndices = 3;
//         ai_mesh.mFaces[i].mIndices = new unsigned int[3];
//         memcpy(ai_mesh.mFaces[i].mIndices, faces_data[i], sizeof(faces_data[i]));
//     }

//     aiFace faces[12];
//     for (int i = 0; i < 12; ++i){
//         faces[i].mNumIndices = 3;
//         faces[i].mIndices = new unsigned int[3];
//         memcpy(faces[i].mIndices, faces_data[i], sizeof(faces_data[i]));
//     }

//     Mesh cube(wctx, ai_mesh, vertex_config);

//     return std::move(cube);
// }

Mesh::Mesh(const wptr<Context>& wctx, const aiMesh& ai_mesh, const MeshVertexConfig& vertex_config,
           const utils::Val<const utils::SrcLoc>& src_loc) :
    _vert_arr(wctx, src_loc),
    _index_data(wctx, ai_mesh, src_loc),
    _vert_data(wctx, vertex_config, ai_mesh, src_loc){

    _vert_arr.setElementBuffer(_index_data.getIndices(), src_loc);
    _vert_arr.setVertexBuffer(0, _vert_data.getVertices(), 0, _vert_data.getBytesPerVertex(), src_loc);

    magic_enum::enum_for_each<MeshAttribute>([&](auto attr){
        constexpr gl::UInt index = magic_enum::enum_index<MeshAttribute>(attr).value();

        if (!_vert_data.isEnabled(attr)){
            std::cout << "Index: "<< index << std::endl;
            _vert_arr.disableAttrib(index, src_loc);
            return;
        }

        _vert_arr.enableAttrib(index, src_loc);
        _vert_arr.setAttribBinding(index, 0);

        auto size = getMeshAttributeSizeComponents(_vert_data.getSize(attr));
        auto type = getMeshAttributeTypeGlType(_vert_data.getType(attr));
        auto offset = _vert_data.getByteOffset(attr);
        _vert_arr.setAttribFormat(index, size, type, true, offset);
    });
}

Mesh::~Mesh(){

}

const gl::VertexArray& Mesh::getVertexArray() const {
    return _vert_arr;
}

const MeshIndexData& Mesh::getIndexData() const {
    return _index_data;
}

const MeshVertexData& Mesh::getVertexData() const {
    return _vert_data;
}