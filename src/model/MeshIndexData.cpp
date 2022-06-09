#include "glwpp/model/MeshIndexData.hpp"

#include "assimp/mesh.h"
#include "magic_enum.hpp"

using namespace glwpp;
using namespace glwpp::model;

MeshIndexData::MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh) :
    _type(_getIndexType(ai_mesh)),
    _indices(new gl::Buffer(wctx)){

    switch(_type){
    case gl::DataType::UByte: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UByte>>(ai_mesh); break;
    case gl::DataType::UShort: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UShort>>(ai_mesh); break;
    case gl::DataType::UInt: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UInt>>(ai_mesh); break;
    default: throw std::runtime_error("Unknown index type");
    }
}

const sptr<gl::Buffer> MeshIndexData::getIndices() const {
    return _indices;
}

gl::DataType MeshIndexData::_getIndexType(const aiMesh& ai_mesh){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    if (index_num > std::numeric_limits<gl::DataTypeCpu_t<gl::DataType::UInt>>::infinity()){
        throw std::runtime_error("Too many indices in mesh");
    }

     return index_num < (1 << 8)  ? gl::DataType::UByte
          : index_num < (1 << 16) ? gl::DataType::UShort
          : gl::DataType::UInt;
}

template<typename T>
void MeshIndexData::_fillIndexBuffer(const aiMesh& ai_mesh){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    auto tmp = alloc_sptr_buffer<T>(index_num);
    for (size_t i = 0; i < faces_num; ++i){
        auto &face = ai_mesh.mFaces[i];
        if (face.mNumIndices != 3){
            throw std::runtime_error("Only triangulated models are supported");
        }

        for (size_t j = 0; j < 3; ++j){
            tmp[3 * i + j] = face.mIndices[j];
        }
    }
    _indices->storage(index_num * sizeof(T), tmp, 0);
}