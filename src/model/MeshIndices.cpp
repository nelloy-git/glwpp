// #include "model/MeshIndices.hpp"

// #include "assimp/mesh.h"

// using namespace glwpp;

// MeshIndices::MeshIndices(const std::shared_ptr<Context>& ctx, const unsigned int& mNumFaces, const aiFace* ai_faces) :
//     type(Type::UInt),
//     buffer(GL::Buffer::New(ctx)){

//     size_t buffer_size = mNumFaces * 3 * sizeof(*aiFace::mIndices);
//     Value<void> data_copy(buffer_size);

//     char* data_ptr = static_cast<char*>(data_copy.get());
//     for (size_t i = 0; i < mNumFaces; ++i){
//         auto& face = ai_faces[i];
//         // Check is triangulated
//         if (face.mNumIndices != 3){
//             throw std::runtime_error("Meshes must be triangulated");
//         }

//         auto face_size = face.mNumIndices * sizeof(*aiFace::mIndices);
//         memcpy(data_ptr, face.mIndices, face_size);
//         data_ptr += face_size;
//     }
//     buffer->setStorage(buffer_size, data_copy, 0);
// }    
    
// MeshIndices::~MeshIndices(){
// }