#include "model/MeshAttribute.hpp"

#include <cstring>

#include "assimp/vector3.h"
#include "assimp/color4.h"

using namespace glwpp;

MeshAttribute::MeshAttribute(Context& ctx,
                             const unsigned int& mNumVertices,
                             const aiVector3D* ai_vector,
                             const SrcLoc& src_loc) :
    CtxObj(ctx),
    type(Type::Float),
    components(3),
    normalized(false),
    stride(sizeof(float) * components),
    buffer(GL::Buffer::Make(ctx, src_loc)){
    auto size = mNumVertices * 3 * sizeof(float);
    auto data_copy = Value<void>::Malloc(size);
    memcpy(data_copy.value(), ai_vector, size);
    buffer->setStorage<TState::Unknown>(size, data_copy, 0, src_loc);
}

MeshAttribute::MeshAttribute(Context& ctx,
                             const unsigned int& mNumVertices,
                             const aiColor4D* ai_color,
                             const SrcLoc& src_loc) :
    CtxObj(ctx),
    type(Type::Float),
    components(4),
    normalized(false),
    stride(sizeof(float) * components),
    buffer(GL::Buffer::Make(ctx, src_loc)){
    auto size = mNumVertices * 4 * sizeof(float);
    auto data_copy = Value<void>::Malloc(size);
    memcpy(data_copy.value(), ai_color, size);
    buffer->setStorage<TState::Unknown>(size, data_copy, 0, src_loc);
}

MeshAttribute::~MeshAttribute(){
}