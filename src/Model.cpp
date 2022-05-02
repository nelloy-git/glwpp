#include "glwpp/Model.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace glwpp;

Model::Model(const wptr<Context>& wctx) :
    _ctx(wctx){
}

Model::~Model(){
}

bool Model::loadFile(const aiScene* ai_scene, const MeshConfig& mesh_cfg){
    _mesh_cfg = mesh_cfg;
    _last_err = std::nullopt;

    // Assimp::Importer importer;
    // const aiScene *scene = importer.ReadFile(path, aiProcess_CalcTangentSpace       |
    //                                                aiProcess_Triangulate            |
    //                                                aiProcess_JoinIdenticalVertices  |
    //                                                aiProcess_SortByPType);

    if (!ai_scene){
        _last_err = "Empty aiScene pointer";
        return false;
    }

    auto ai_root = ai_scene->mRootNode;
    if (!ai_root){
        _last_err = "Empty aiScene pointer";
        return false;
    }

    _meshes = {};
    for (size_t i = 0; i < ai_scene->mNumMeshes; ++i){
        _meshes.emplace_back(_ctx, _mesh_cfg);
    }

    _transform = {};
    _transform.push_back(_ai2glm(ai_root->mTransformation));
    for (size_t i = 0; i < ai_root->)
}

std::optional<std::string> Model::getError(){
    return _last_err;
}