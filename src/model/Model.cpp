#include "model/Model.hpp"

#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"

using namespace glwpp;

Model::Model(Context& ctx, const std::string& model_path, const SrcLoc& src_loc){
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

    if (loading_error = _loadMeshes(ctx, *ai_scene, src_loc)){
        return;
    }
}

Model::~Model(){
}

std::optional<std::string> Model::_loadMeshes(Context& ctx, const aiScene& ai_scene, const SrcLoc& src_loc){
    if (ai_scene.mNumMeshes == 0){
        return "No meshes found";
    }

    for (size_t i = 0; i < ai_scene.mNumMeshes; ++i){
        auto ai_mesh = ai_scene.mMeshes[i];
        if (!ai_mesh){
            return "Empty pointer aiMesh[" + std::to_string(i) + "]";
        }

        meshes.emplace_back(Mesh::Make(ctx, *ai_mesh, src_loc));
    }

    return std::nullopt;
}