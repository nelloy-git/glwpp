#pragma once

#include "gl_object/Buffer.hpp"

template<typename T>
class aiVector3t;
template<typename T>
class aiColor4t;

namespace glwpp {

class MeshAttribute : public CtxObj<MeshAttribute> {
public:
    enum class Type : GLenum {
        Float = GL_FLOAT
    };

    static Value<MeshAttribute> Make(Valuable<Context&> auto&& ctx,
                                   Valuable<const unsigned int&> auto&& mNumFaces,
                                   Valuable<const aiVector3t<float>*> auto&& ai_vectors,
                                   Valuable<const SrcLoc&> auto&& src_loc){
        return Value<MeshAttribute>::Make(new MeshAttribute(GetValuable(ctx), GetValuable(mNumFaces), GetValuable(ai_vectors), GetValuable(src_loc)));
    }
    static Value<MeshAttribute> Make(Valuable<Context&> auto&& ctx,
                                   Valuable<const unsigned int&> auto&& mNumFaces,
                                   Valuable<const aiColor4t<float>*> auto&& ai_colors,
                                   Valuable<const SrcLoc&> auto&& src_loc){
        return Value<MeshAttribute>::Make(new MeshAttribute(GetValuable(ctx), GetValuable(mNumFaces), GetValuable(ai_colors), GetValuable(src_loc)));
    }
    virtual ~MeshAttribute();

    const Type type;
    const unsigned int components;
    const bool normalized;
    const GLsizei stride;
    const Value<GL::Buffer> buffer;

private:
    EXPORT MeshAttribute(Context& ctx, const unsigned int& mNumVertices, const aiVector3t<float>* ai_vectors, const SrcLoc& src_loc);
    EXPORT MeshAttribute(Context& ctx, const unsigned int& mNumVertices, const aiColor4t<float>* ai_colors, const SrcLoc& src_loc);
};

} // namespace glwpp