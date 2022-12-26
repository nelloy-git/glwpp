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
    static const unsigned int MAX_INDEX = 4 + TEXTURE_INDEX.size() + COLOR_INDEX.size() - 1;

    Mesh(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc = SrcLoc{});
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    virtual ~Mesh();

    bool bindPosition(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindNormal(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindTangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindBitangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindTextureCoord(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
    bool bindColor(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);

    using Bindings = std::array<std::optional<unsigned int>, MAX_INDEX + 1>;
    const Value<const Bindings> getBindings();
    void setBindings(const Value<const Bindings>& bindings, const SrcLoc& src_loc = SrcLoc{});

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
};
    
} // namespace glwpp
