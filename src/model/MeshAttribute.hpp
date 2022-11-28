#pragma once

#include "gl_object/Buffer.hpp"

template<typename T>
struct aiVector3t;
template<typename T>
struct aiColor4t;

namespace glwpp {

class MeshAttribute {
public:
    enum class Type {
        Float
    };

    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3t<float>* ai_vector, const SrcLoc& src_loc = SrcLoc{});
    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiColor4t<float>* ai_color, const SrcLoc& src_loc = SrcLoc{});
    ~MeshAttribute();

    const Type type;
    const unsigned int components;
    std::shared_ptr<GL::Buffer> buffer;
};

} // namespace glwpp