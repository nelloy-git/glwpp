#include "model/MeshAttribute.hpp"

#include <cstring>

#include "assimp/vector3.h"
#include "assimp/color4.h"

using namespace glwpp;

MeshAttribute::MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3D* ai_vector, const SrcLoc& src_loc) :
    type(Type::Float),
    components(3),
    buffer(GL::Buffer::New(ctx, src_loc)){
    auto size = mNumVertices * 3 * sizeof(float);
    GL::Value<void> data_copy(size);
    memcpy(data_copy.get(), ai_vector, size);
    buffer->setStorage(size, data_copy, 0, src_loc);
}

MeshAttribute::MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiColor4D* ai_color, const SrcLoc& src_loc) :
    type(Type::Float),
    components(4),
    buffer(GL::Buffer::New(ctx, src_loc)){
    auto size = mNumVertices * 4 * sizeof(float);
    GL::Value<void> data_copy(size);
    memcpy(data_copy.get(), ai_color, size);
    buffer->setStorage(size, data_copy, 0, src_loc);
}

MeshAttribute::~MeshAttribute(){
}