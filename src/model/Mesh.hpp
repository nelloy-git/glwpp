#pragma once

#include "Context.hpp"
#include "gl_object/VertexArray.hpp"
#include "gl_object/Buffer.hpp"

struct aiMesh;

namespace glwpp {

class Mesh {
public:
    Mesh(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh);
    ~Mesh();

    GL::VertexArray vao;
    GL::Buffer index;
    GL::Buffer position;
    std::optional<GL::Buffer> normal;
};
    
} // namespace glwpp
