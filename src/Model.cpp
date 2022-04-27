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

bool Model::loadFile(const std::string& path, const MeshConfig& mesh_cfg){
    _mesh_cfg = mesh_cfg;
    _last_err = std::nullopt;

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_CalcTangentSpace       |
                                                   aiProcess_Triangulate            |
                                                   aiProcess_JoinIdenticalVertices  |
                                                   aiProcess_SortByPType);

    if (!scene){
        _last_err = importer.GetErrorString();
        return false;
    }

    _meshes = {};
    for (size_t i = 0; i < scene->mNumMeshes; ++i){
        _meshes.emplace_back(_ctx, _mesh_cfg);
    }


}

std::optional<std::string> Model::getError(){
    return _last_err;
}