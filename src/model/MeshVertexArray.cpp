#include "model/MeshVertexArray.hpp"

using namespace glwpp;

MeshVertexArray::MeshVertexArray(const std::shared_ptr<Context>& ctx,
                                 const MeshIndices& indices,
                                 const MeshAttribute& position,
                                 const std::optional<MeshAttribute>& normal,
                                 const std::optional<MeshAttribute>& tangent,
                                 const std::optional<MeshAttribute>& bitangent,
                                 const std::array<std::optional<MeshAttribute>, 8>& texture_coord,
                                 const std::array<std::optional<MeshAttribute>, 8>& color) :
    vao(GL::VertexArray::New(ctx)){
    vao->setElementBuffer(*indices.buffer);
    vao->setVertexBuffer(POSITION_BINDING, *position.buffer, 0, position.stride);
    if (normal){
        vao->setVertexBuffer(NORMAL_BINDING, *normal.value().buffer, 0, normal.value().stride);
    }
    if (tangent){
        vao->setVertexBuffer(TANGENT_BINDING, *tangent.value().buffer, 0, tangent.value().stride);
    }
    if (bitangent){
        vao->setVertexBuffer(BITANGENT_BINDING, *bitangent.value().buffer, 0, bitangent.value().stride);
    }

    for (size_t i = 0; i < texture_coord.size(); ++i){
        if (texture_coord[i]){
            vao->setVertexBuffer(TEXTURE_BINDING[i], *texture_coord[i].value().buffer, 0, texture_coord[i].value().stride);
        }
    }

    for (size_t i = 0; i < color.size(); ++i){
        if (color[i]){
            vao->setVertexBuffer(COLOR_BINDING[i], *color[i].value().buffer, 0, color[i].value().stride);
        }
    }
}

MeshVertexArray::~MeshVertexArray(){
}