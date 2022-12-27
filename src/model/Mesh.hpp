#pragma once

#include <array>

#include "Context.hpp"
#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"

#include "gl_object/VertexArray.hpp"

struct aiMesh;

namespace glwpp {

class Mesh : protected CallOptimizer {
public:
    static const GLuint POSITION_INDEX;
    static const GLuint NORMAL_INDEX;
    static const GLuint TANGENT_INDEX;
    static const GLuint BITANGENT_INDEX;
    static const std::array<const GLuint, 8> TEXTURE_INDEX;
    static const std::array<const GLuint, 8> COLOR_INDEX;
    static const unsigned int INDEX_COUNT = 4 + TEXTURE_INDEX.size() + COLOR_INDEX.size();

    Mesh(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc = SrcLoc{});
    Mesh(Mesh&& other) = default;
    virtual ~Mesh();

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    bool bindPosition(Valuable<const std::optional<unsigned int>&> auto&& binding,
                      Valuable<const SrcLoc&> auto&& src_loc){
        call<&_bindAttributeGL, is_gl_thread>(vao, _bindings, POSITION_INDEX, binding, GetValuable(src_loc).add());
    }

    bool bindNormal(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindTangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindBitangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindTextureCoord(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindColor(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);

    using Bindings = std::array<std::optional<unsigned int>, INDEX_COUNT>;
    const Value<const Bindings> getBindings() const;
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setBindings(Valuable<const Bindings&> auto&& bindings,
                     Valuable<const SrcLoc&> auto&& src_loc){
        call<&_setBindingsGL, is_gl_thread>(vao, _bindings, bindings, src_loc);
    }

    GL::VertexArray vao;
    MeshIndices indices;
    MeshAttribute position;
    std::unique_ptr<MeshAttribute> normal;
    std::unique_ptr<MeshAttribute> tangent;
    std::unique_ptr<MeshAttribute> bitangent;
    std::array<std::unique_ptr<MeshAttribute>, 8> texture_coord;
    std::array<std::unique_ptr<MeshAttribute>, 8> color;

private:
    Value<Bindings> _bindings;

    void _initOptionalBuffers(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc);
    void _linkAllAttributes(const SrcLoc& src_loc);
    void _linkAttribute(const GLuint& index, const MeshAttribute& attribute, const SrcLoc& src_loc);
    void _bindAttribute(const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);

    static void _setBindingsGL(Context& ctx, GL::VertexArray& vao, Bindings& cur_bindings, const Bindings& trg_bindings, const SrcLoc& src_loc);
    static void _bindAttributeGL(Context& ctx, GL::VertexArray& vao, Bindings& bindings, const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
};
    
} // namespace glwpp
