#include "model/MeshAttribute.hpp"

#include "assimp/scene.h"

using namespace glwpp;

MeshAttribute::MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3D* ai_vector, const SrcLoc& src_loc) :
    buffer(ctx, src_loc){
    auto size = mNumVertices * (sizeof(decltype(ai_vector->x)));
}