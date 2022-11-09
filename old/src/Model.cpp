#include "glwpp/Model.hpp"

#include "magic_enum.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace glwpp;

namespace {

glm::mat4 _ai2glm(const aiMatrix4x4& mat){
    return glm::mat4({
        mat[0][0], mat[0][1], mat[0][2], mat[0][3],
        mat[1][0], mat[1][1], mat[1][2], mat[1][3],
        mat[2][0], mat[2][1], mat[2][2], mat[2][3],
        mat[3][0], mat[3][1], mat[3][2], mat[3][3],
    });
}

}

Model::Model(const sptr<Context>& ctx, const std::string& path,
             const model::MeshVertexConfig& vert_config){

    Assimp::Importer importer;
    const aiScene *ai_scene = importer.ReadFile(path, aiProcess_CalcTangentSpace       |
                                                      aiProcess_Triangulate            |
                                                      aiProcess_JoinIdenticalVertices  |
                                                      aiProcess_SortByPType);

    if (importer.GetErrorString()[0] != '\0'){
        _last_err = importer.GetErrorString();
        return;
    }
    if (!_loadMeshes(*ai_scene, ctx, vert_config)){return;}

    auto ai_root = ai_scene->mRootNode;
    if (!ai_root){
        _last_err = "Empty aiScene->mRootNode pointer";
        return;
    }
    if (!_loadNodes(*ai_root)){return;}
}

Model::~Model(){
}

std::optional<std::string> Model::getError(){
    return _last_err;
}

const std::vector<sptr<model::Mesh>>& Model::getMeshes() const {
    return _meshes;
}

const std::vector<sptr<model::Node>>& Model::getNodes() const {
    return _nodes;
}

bool Model::_loadMeshes(const aiScene& ai_scene,
                        const sptr<Context>& ctx, const model::MeshVertexConfig& vert_config){
    if (ai_scene.mNumMeshes <= 0){
        _last_err = "No meshes found";
        return false;
    }

    for (size_t i = 0; i < ai_scene.mNumMeshes; ++i){
        auto ai_mesh = ai_scene.mMeshes[i];
        if (!ai_mesh){
            _last_err = "Empty mesh pointer i = " + std::to_string(i);
            return false;
        }

        _meshes.emplace_back(new model::Mesh(ctx, *ai_mesh, vert_config));
    }

    return true;
}

bool Model::_loadNodes(const aiNode& ai_root){
    _loadOneNode(ai_root);
    return true;
}

#include "glm/gtx/string_cast.hpp"

sptr<model::Node> Model::_loadOneNode(const aiNode& ai_node){
    auto node = _nodes.emplace_back(new model::Node);
    node->mat = _ai2glm(ai_node.mTransformation);
    std::cout << glm::to_string(node->mat) << std::endl;

    for (size_t i = 0; i < ai_node.mNumMeshes; ++i){
        node->meshes.push_back(_meshes[ai_node.mMeshes[i]]);
    }

    for (size_t i = 0; i < ai_node.mNumChildren; ++i){
        auto child = _loadOneNode(*ai_node.mChildren[i]);
        child->parent = node;
        node->children.emplace_back(child);
    }

    return node;
}