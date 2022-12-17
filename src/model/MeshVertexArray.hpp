#pragma once

#include <array>

#include "gl_object/VertexArray.hpp"

#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"

namespace glwpp {

class MeshVertexArray {
public:
    template<typename T>
    struct Attributes {
        T position;
        std::optional<T>& normal;
        std::optional<T>& tangent;
        std::optional<T>& bitangent;
        std::array<std::optional<T>, 8>& texture_coord;
        std::array<std::optional<T>, 8>& color;
    };

    MeshVertexArray(const std::shared_ptr<Context>& ctx,
                    const MeshIndices& indices,
                    const Attributes<MeshAttribute*>& buffers,
                    const SrcLoc src_loc = SrcLoc{});
    virtual ~MeshVertexArray();

    GL::VertexArray vao;

    void bindAttributes(const Attributes<int>& bindings, const SrcLoc src_loc = SrcLoc{});

private:
    template<typename T, void(MeshVertexArray::*F)(const GL::ConstUint&, const T&, const SrcLoc src_loc)>
    void _iterateAttributes(const Attributes<T>& attr_data, const SrcLoc src_loc);

    void _linkBuffer(const GL::ConstUint& index, MeshAttribute* const& attr_buffer, const SrcLoc src_loc);
    void _bindAttribute(const GL::ConstUint& index, const int& binding, const SrcLoc src_loc);

    static const GL::ConstUint POSITION_INDEX;
    static const GL::ConstUint NORMAL_INDEX;
    static const GL::ConstUint TANGENT_INDEX;
    static const GL::ConstUint BITANGENT_INDEX;
    static const std::array<GL::ConstUint, 8> TEXTURE_INDEX;
    static const std::array<GL::ConstUint, 8> COLOR_INDEX;
};

} // namespace glwpp