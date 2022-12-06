#include "model/MeshAttribute.hpp"

#include <cstring>

#include "assimp/vector3.h"
#include "assimp/color4.h"

using namespace glwpp;

MeshAttribute::MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3D* ai_vector) :
    type(Type::Float),
    components(3),
    stride(sizeof(float) * components),
    buffer(GL::Buffer::New(ctx)){
    auto size = mNumVertices * 3 * sizeof(float);
    Value<void> data_copy(size);
    memcpy(data_copy.get(), ai_vector, size);
    buffer->setStorage(size, data_copy, 0);
}

MeshAttribute::MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiColor4D* ai_color) :
    type(Type::Float),
    components(4),
    stride(sizeof(float) * components),
    buffer(GL::Buffer::New(ctx)){
    auto size = mNumVertices * 4 * sizeof(float);
    Value<void> data_copy(size);
    memcpy(data_copy.get(), ai_color, size);
    buffer->setStorage(size, data_copy, 0);
}

MeshAttribute::~MeshAttribute(){
}