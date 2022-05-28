#include "glwpp/Model.hpp"

#include "magic_enum.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace glwpp;

MeshVertexConfig Model::_default_vertex_config = [](){
    auto ATTRIBUTES = magic_enum::enum_values<MeshAttribute>();
    MeshVertexConfig config;

    size_t i = 0;
    for (auto attr : ATTRIBUTES){
        config.enable(attr, true);
        config.setCompression(attr, 1);
        config.setSize(attr, MeshAttributeSize::Vec3);

        ++i;
    }

    return config;
}();

Model::Model(const wptr<Context>& wctx, const std::string& path,
             const MeshVertexConfig& vert_config) :
    _ctx(wctx){

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

    if (!_loadMeshes(ai_scene, vert_config)){return;}
    if (!_loadNodes(ai_scene)){return;}
}

Model::~Model(){
}

std::optional<std::string> Model::getError(){
    return _last_err;
}

bool Model::_loadMeshes(const aiScene* ai_scene, const MeshVertexConfig& vert_config){
    if (ai_scene->mNumMeshes <= 0){
        _last_err = "No meshes found";
        return false;
    }
        
    _meshes = make_uptr<std::vector<sptr<Mesh>>>();
    for (size_t i = 0; i < ai_scene->mNumMeshes; ++i){
        _meshes->emplace_back(_ctx, ai_scene->mMeshes[i], vert_config);
    }

    return true;
}

bool Model::_loadNodes(const aiScene* ai_scene){
    auto ai_root = ai_scene->mRootNode;
    if (!ai_root){
        _last_err = "No nodes found";
        return false;
    }
    _node_tree = make_uptr<ModelNodeTree>(_ctx, *ai_root);
}

MeshVertexConfig Model::_init_default_config(){
    auto ATTRIBUTES = magic_enum::enum_values<MeshAttribute>();
    MeshVertexConfig config;

    size_t i = 0;
    for (auto attr : ATTRIBUTES){
        config.enable(attr, true);
        config.setCompression(attr, 1);
        config.setSize(attr, MeshAttributeSize::Vec3);

        ++i;
    }

    return config;
}