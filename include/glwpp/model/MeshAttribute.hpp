#pragma once

namespace glwpp {

enum class MeshAttributeSize : size_t {
    None,
    Scalar,
    Vec2,
    Vec3,
    Vec4
};

enum class MeshAttribute : size_t {
    Position = 0,
    Normal,
    Tangent,
    Bitangent,
    TexCoord_0,
    TexCoord_1,
    TexCoord_2,
    TexCoord_3,
    TexCoord_4,
    TexCoord_5,
    TexCoord_6,
    TexCoord_7,
    Color_0,
    Color_1,
    Color_2,
    Color_3
};

// Linter fills bad because of magic_enum
size_t GetMeshAttributeEnumSize();

} // namespace glwpp