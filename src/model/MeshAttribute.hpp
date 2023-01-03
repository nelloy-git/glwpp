#pragma once

#include "gl_object/Buffer.hpp"

template<typename T>
class aiVector3t;
template<typename T>
class aiColor4t;

namespace glwpp {

class MeshAttribute {
public:
    enum class Type : GLenum {
        Float = GLapi::GL_FLOAT
    };

    MeshAttribute(Context& ctx,
                  const unsigned int& mNumVertices,
                  const aiVector3t<float>* ai_vectors,
                  const SrcLoc& src_loc = SrcLoc{});
    MeshAttribute(Context& ctx,
                  const unsigned int& mNumVertices,
                  const aiColor4t<float>* ai_colors,
                  const SrcLoc& src_loc = SrcLoc{});
    virtual ~MeshAttribute();

    const Type type;
    const unsigned int components;
    const bool normalized;
    const GLsizei stride;
    GL::Buffer buffer;
};

} // namespace glwpp