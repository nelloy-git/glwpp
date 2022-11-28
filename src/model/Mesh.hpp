#pragma once

#include <optional>

#include "Context.hpp"
#include "model/MeshAttribute.hpp"
#include "gl_object/VertexArray.hpp"

struct aiMesh;

namespace glwpp {

class Mesh {
public:
    Mesh(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc = SrcLoc{});
    ~Mesh();

    // GL::VertexArray vao;
    // GL::Buffer index;
    MeshAttribute position;
    std::optional<MeshAttribute> normal;
    std::optional<MeshAttribute> tangent;
    std::optional<MeshAttribute> bitangent;
    std::optional<MeshAttribute> texture_coord[8];
    std::optional<MeshAttribute> color[8];
};
    
} // namespace glwpp
