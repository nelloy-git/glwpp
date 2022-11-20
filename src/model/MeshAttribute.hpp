#pragma once

#include "gl_object/Buffer.hpp"

struct aiVector3D;
struct aiVector4D;

namespace glwpp {

class MeshAttribute {
public:
    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3D* ai_vector, const SrcLoc& src_loc = SrcLoc{});
    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector4D* ai_vector, const SrcLoc& src_loc = SrcLoc{});
    ~MeshAttribute();

    GL::Buffer buffer;
};

} // namespace glwpp