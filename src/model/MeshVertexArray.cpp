#include "model/MeshVertexArray.hpp"

using namespace glwpp;

const GL::ConstUint MeshVertexArray::POSITION_INDEX = 0;
const GL::ConstUint MeshVertexArray::NORMAL_INDEX = 1;
const GL::ConstUint MeshVertexArray::TANGENT_INDEX = 2;
const GL::ConstUint MeshVertexArray::BITANGENT_INDEX = 3;
const std::array<GL::ConstUint, 8> MeshVertexArray::TEXTURE_INDEX = {4, 5, 6, 7, 8, 9, 10, 11};
const std::array<GL::ConstUint, 8> MeshVertexArray::COLOR_INDEX = {12, 13, 14, 15, 16, 17, 18, 19};

MeshVertexArray::MeshVertexArray(const std::shared_ptr<Context>& ctx,
                                 const MeshIndices& indices,
                                 const Attributes<MeshAttribute*>& buffers,
                                 const SrcLoc src_loc) :
    vao(ctx){
    vao.setElementBuffer(indices.buffer);
    _iterateAttributes<MeshAttribute*, &MeshVertexArray::_linkBuffer>(buffers, src_loc);
}

MeshVertexArray::~MeshVertexArray(){
}

void MeshVertexArray::bindAttributes(const Attributes<int>& bindings, const SrcLoc src_loc){
    _iterateAttributes<int, &MeshVertexArray::_bindAttribute>(bindings, src_loc);
}

template<typename T, void(MeshVertexArray::*F)(const GL::ConstUint&, const T&, const SrcLoc src_loc)>
void MeshVertexArray::_iterateAttributes(const Attributes<T>& attr_data, const SrcLoc src_loc){
    (this->*F)(POSITION_INDEX, attr_data.position, src_loc);
    if (attr_data.normal){
        (this->*F)(NORMAL_INDEX, attr_data.normal.value(), src_loc);
    }
    if (attr_data.tangent){
        (this->*F)(TANGENT_INDEX, attr_data.tangent.value(), src_loc);
    }
    if (attr_data.bitangent){
        (this->*F)(BITANGENT_INDEX, attr_data.bitangent.value(), src_loc);
    }

    for (size_t i = 0; i < attr_data.texture_coord.size(); ++i){
        if (attr_data.texture_coord[i]){
            (this->*F)(TEXTURE_INDEX[i], attr_data.texture_coord[i].value(), src_loc);
        }
    }

    for (size_t i = 0; i < attr_data.color.size(); ++i){
        if (attr_data.color[i]){
            (this->*F)(COLOR_INDEX[i], attr_data.color[i].value(), src_loc);
        }
    }
}

void MeshVertexArray::_linkBuffer(const GL::ConstUint& index, MeshAttribute* const& attr_buffer, const SrcLoc src_loc){
    if (!attr_buffer){
        return;
    }
    vao.setVertexBuffer(index, attr_buffer->buffer, 0, attr_buffer->stride);
    vao.setAttribFormat(index,
                        attr_buffer->components,
                        MeshAttribute::TypeToEnum(attr_buffer->type),
                        attr_buffer->normalized,
                        0,
                        src_loc);
}

void MeshVertexArray::_bindAttribute(const GL::ConstUint& index, const int& binding, const SrcLoc src_loc){
    if (binding >= 0){
        vao.enableAttrib(binding, src_loc);
        vao.setAttribBinding(binding, index, src_loc);
    } else {
        vao.disableAttrib(binding, src_loc);
    }
}