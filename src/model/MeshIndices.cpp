#include "model/MeshIndices.hpp"

#include "assimp/mesh.h"

using namespace glwpp;

MeshIndices::MeshIndices(Context& ctx, const unsigned int& mNumFaces, const aiFace* ai_faces, const SrcLoc& src_loc) :
    CtxObj(ctx),
    type(Type::UInt),
    buffer(GL::Buffer::Make(ctx, src_loc.add())){

    size_t buffer_size = mNumFaces * 3 * sizeof(*aiFace::mIndices);
    auto data_copy = Value<void>::Malloc(buffer_size);

    char* data_ptr = static_cast<char*>(data_copy.value());
    for (size_t i = 0; i < mNumFaces; ++i){
        auto& face = ai_faces[i];
        // Check is triangulated
        if (face.mNumIndices != 3){
            throw std::runtime_error("Meshes must be triangulated");
        }

        auto face_size = face.mNumIndices * sizeof(*aiFace::mIndices);
        memcpy(data_ptr, face.mIndices, face_size);
        data_ptr += face_size;
    }

    if (ctx.gl().VersionMajor() >= 4 && ctx.gl().VersionMinor() >= 4){
        buffer->setStorage<TState::Unknown>(buffer_size, data_copy, 0, src_loc.add());
    } else {
        buffer->setData<TState::Unknown>(buffer_size, data_copy, GL_DYNAMIC_DRAW, src_loc.add());
    }

    
}    
    
MeshIndices::~MeshIndices(){
}