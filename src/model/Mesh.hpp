#pragma once

#include <array>

#include "Context.hpp"
#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"
#include "model/MeshVertexArray.hpp"

#include "gl_object/VertexArray.hpp"

struct aiMesh;

namespace glwpp {

class Mesh {
public:
    template<typename T>
    struct AllAttributes {
        T position;
        std::optional<T>& normal;
        std::optional<T>& tangent;
        std::optional<T>& bitangent;
        std::array<std::optional<T>, 8>& texture_coord;
        std::array<std::optional<T>, 8>& color;
    };

    Mesh(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh);
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    virtual ~Mesh();

    MeshIndices indices;
    MeshAttribute position;
    std::unique_ptr<MeshAttribute> normal;
    std::unique_ptr<MeshAttribute> tangent;
    std::unique_ptr<MeshAttribute> bitangent;
    std::array<std::unique_ptr<MeshAttribute>, 8> texture_coord;
    std::array<std::unique_ptr<MeshAttribute>, 8> color;

    void bindAllAttributes(const AllAttributes<int>& bindings, const SrcLoc src_loc = SrcLoc{});

private:
    GL::VertexArray _vao;

    template<typename T, void(MeshVertexArray::*F)(const GL::ConstUint&, const T&, const SrcLoc src_loc)>
    void _iterateAllAttributes(const AllAttributes<T>& attr_data, const SrcLoc src_loc);

    void _initBuffers(const std::shared_ptr<Context>& ctx, const aiMesh& ai_mesh);
    void _linkBuffer(const GL::ConstUint& index, const MeshAttribute& attr_buffer, const SrcLoc src_loc);
    void _bindAttribute(const GL::ConstUint& index, const int& binding, const SrcLoc src_loc);

    static const GL::ConstUint POSITION_INDEX;
    static const GL::ConstUint NORMAL_INDEX;
    static const GL::ConstUint TANGENT_INDEX;
    static const GL::ConstUint BITANGENT_INDEX;
    static const std::array<GL::ConstUint, 8> TEXTURE_INDEX;
    static const std::array<GL::ConstUint, 8> COLOR_INDEX;

};
    
} // namespace glwpp
