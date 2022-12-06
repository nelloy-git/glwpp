#pragma once

#include <array>
#include <optional>

#include "Context.hpp"
#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"
#include "gl_object/VertexArray.hpp"

struct aiMesh;

namespace glwpp {

class Mesh {
public:
    Mesh(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh);
    virtual ~Mesh();

    // GL::VertexArray vao;
    MeshIndices indices;
    MeshAttribute position;
    std::optional<MeshAttribute> normal;
    std::optional<MeshAttribute> tangent;
    std::optional<MeshAttribute> bitangent;
    std::array<std::optional<MeshAttribute>, 8> texture_coord;
    std::array<std::optional<MeshAttribute>, 8> color;
};
    
} // namespace glwpp
