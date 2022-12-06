#include "model/Mesh.hpp"

#include "assimp/scene.h"
#include "assimp/vector3.h"
#include "assimp/color4.h"

using namespace glwpp;

Mesh::Mesh(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh) :
    indices(ctx, ai_mesh.mNumFaces, ai_mesh.mFaces),
    position(ctx, ai_mesh.mNumVertices, ai_mesh.mVertices){
    if (ai_mesh.HasNormals()){
        normal.emplace(ctx, ai_mesh.mNumVertices, ai_mesh.mNormals);
    }
    if (ai_mesh.HasTangentsAndBitangents()){
        tangent.emplace(ctx, ai_mesh.mNumVertices, ai_mesh.mTangents);
        bitangent.emplace(ctx, ai_mesh.mNumVertices, ai_mesh.mBitangents);
    }

    for (int i = 0; i < 8; ++i){
        if (ai_mesh.HasTextureCoords(i)){
            texture_coord[i].emplace(ctx, ai_mesh.mNumVertices, ai_mesh.mTextureCoords[i]);
        }
    }

    for (int i = 0; i < 8; ++i){
        if (ai_mesh.HasVertexColors(i)){
            color[i].emplace(ctx, ai_mesh.mNumVertices, ai_mesh.mColors[i]);
        }
    }
}

Mesh::~Mesh(){
}