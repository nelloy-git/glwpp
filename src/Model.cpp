#include "glwpp/Model.hpp"

#include "magic_enum.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace glwpp;

Model::Model(const wptr<Context>& wctx, const std::string& path,
             const model::MeshVertexConfig& vert_config){

    Assimp::Importer importer;
    const aiScene *ai_scene = importer.ReadFile(path, aiProcess_CalcTangentSpace       |
                                                      aiProcess_Triangulate            |
                                                      aiProcess_JoinIdenticalVertices  |
                                                      aiProcess_SortByPType);

    if (!ai_scene){
        _last_err = "Empty aiScene pointer";
        return;
    }

    auto ai_root = ai_scene->mRootNode;
    if (!ai_root){
        _last_err = "Empty aiScene->mRootNode pointer";
        return;
    }

    if (!_loadMeshes(*ai_scene, wctx, vert_config)){return;}
    // if (!_loadNodes(ai_scene)){return;}
}

Model::~Model(){
}

std::optional<std::string> Model::getError(){
    return _last_err;
}

const std::vector<model::Mesh>& Model::getMeshes() const {
    return _meshes;
}

bool Model::_loadMeshes(const aiScene& ai_scene,
                        const wptr<Context>& wctx, const model::MeshVertexConfig& vert_config){
    if (ai_scene.mNumMeshes <= 0){
        _last_err = "No meshes found";
        return false;
    }

    for (size_t i = 0; i < ai_scene.mNumMeshes; ++i){
        auto ai_mesh = ai_scene.mMeshes[i];
        if (!ai_mesh){
            _last_err = "Empty ,esh pointer i = " + std::to_string(i);
            return false;
        }

        // model::Mesh mesh(wctx, *ai_mesh, vert_config);
        _meshes.emplace_back(wctx, *ai_mesh, vert_config);
    }

    return true;
}

// bool Model::_loadNodes(const aiScene* ai_scene){
//     auto ai_root = ai_scene->mRootNode;
//     if (!ai_root){
//         _last_err = "No nodes found";
//         return false;
//     }
//     _node_tree = make_uptr<ModelNodeTree>(_ctx, *ai_root);
// }