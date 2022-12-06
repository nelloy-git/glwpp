#include "model/Model.hpp"

#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"

using namespace glwpp;

Model::Model(const std::shared_ptr<Context>& ctx, const std::string& model_path){
    static auto ai_process_flags = aiProcess_CalcTangentSpace 
                                 | aiProcess_Triangulate
                                 | aiProcess_JoinIdenticalVertices
                                 | aiProcess_SortByPType;

    Assimp::Importer importer;
    const aiScene *ai_scene = importer.ReadFile(model_path, ai_process_flags);
    
    if (!ai_scene || importer.GetErrorString()[0] != '\0'){
        loading_error = importer.GetErrorString();
        return;
    }

    if (!_loadMeshes(ctx, *ai_scene)){
        return;
    }
}

Model::~Model(){
}

bool Model::_loadMeshes(const std::shared_ptr<Context>& ctx, const aiScene& ai_scene){
    if (ai_scene.mNumMeshes == 0){
        loading_error = "No meshes found";
        return false;
    }

    for (size_t i = 0; i < ai_scene.mNumMeshes; ++i){
        auto ai_mesh = ai_scene.mMeshes[i];
        if (!ai_mesh){
            loading_error = "Empty mesh pointer i = " + std::to_string(i);
            return false;
        }

        meshes.emplace_back(ctx, *ai_mesh);
    }

    return true;
}