#pragma once

#include "gl_object/Buffer.hpp"

struct aiFace;

namespace glwpp {

class MeshIndices {
public:
    enum class Type {
        UInt
    };

    MeshIndices(const std::shared_ptr<Context>& ctx, const unsigned int& mNumFaces, const aiFace* ai_faces);
    virtual ~MeshIndices();
    
    const Type type;
    GL::Buffer buffer;

};

} // namespace glwpp