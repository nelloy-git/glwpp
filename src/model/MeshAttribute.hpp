#pragma once

#include "gl_object/Buffer.hpp"

template<typename T>
class aiVector3t;
template<typename T>
class aiColor4t;

namespace glwpp {

class MeshAttribute {
public:
    enum class Type {
        Float
    };
    static GL::ConstEnum TypeToEnum(const Type& type);

    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiVector3t<float>* ai_vectors);
    MeshAttribute(const std::shared_ptr<Context>& ctx, const unsigned int& mNumVertices, const aiColor4t<float>* ai_colors);
    virtual ~MeshAttribute();

    const Type type;
    const unsigned int components;
    const bool normalized;
    const GLsizei stride;
    std::shared_ptr<GL::Buffer> buffer;
};

} // namespace glwpp