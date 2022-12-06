#pragma once

#include <array>
#include <optional>

#include "gl_object/VertexArray.hpp"

#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"

namespace glwpp {

class MeshVertexArray {
public:
    MeshVertexArray(const std::shared_ptr<Context>& ctx,
                    const MeshIndices& indices,
                    const MeshAttribute& position,
                    const std::optional<MeshAttribute>& normal,
                    const std::optional<MeshAttribute>& tangent,
                    const std::optional<MeshAttribute>& bitangent,
                    const std::array<std::optional<MeshAttribute>, 8>& texture_coord,
                    const std::array<std::optional<MeshAttribute>, 8>& color);
    virtual ~MeshVertexArray();

    std::shared_ptr<GL::VertexArray> vao;

    void bindAttributes();

    static constexpr GLuint POSITION_BINDING = 0;
    static constexpr GLuint NORMAL_BINDING = 1;
    static constexpr GLuint TANGENT_BINDING = 2;
    static constexpr GLuint BITANGENT_BINDING = 3;
    static constexpr std::array<GLuint, 8> TEXTURE_BINDING = {4, 5, 6, 7, 8, 9, 10, 11};
    static constexpr std::array<GLuint, 8> COLOR_BINDING = {12, 13, 14, 15, 16, 17, 18, 19};

private:
};

} // namespace glwpp