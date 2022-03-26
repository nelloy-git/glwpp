#include "glwpp/Model.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace glwpp;

Model::Model(){
}

Model::~Model(){
}

bool Model::readFile(const std::string& path){
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_CalcTangentSpace       |
                                                   aiProcess_Triangulate            |
                                                   aiProcess_JoinIdenticalVertices  |
                                                   aiProcess_SortByPType);

    if (!scene){
        return false;
    }

    scene->mMeshes
}