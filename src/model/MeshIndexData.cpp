#include "glwpp/model/MeshIndexData.hpp"

#include "assimp/mesh.h"
#include "magic_enum.hpp"

using namespace glwpp;

MeshIndexData::MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh) :
    _ctx(wctx){
    _indices = make_sptr<Buffer>(_ctx);
    _fillIndexType(ai_mesh);
    switch(_type){
    case gl::DataType::UByte: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UByte>>(ai_mesh); break;
    case gl::DataType::UShort: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UShort>>(ai_mesh); break;
    case gl::DataType::UInt: _fillIndexBuffer<gl::DataTypeCpu_t<gl::DataType::UInt>>(ai_mesh); break;
    default: throw std::runtime_error("Unknown index type");
    }
}

sptr<Buffer> MeshIndexData::getIndices(){
    return _indices;
}

const sptr<Buffer> MeshIndexData::getIndices() const {
    return _indices;
}

void MeshIndexData::_fillIndexType(const aiMesh& ai_mesh){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    if (index_num > std::numeric_limits<gl::DataTypeCpu_t<gl::DataType::UInt>>::infinity()){
        throw std::runtime_error("Too many indices in mesh");
    }

     _type = index_num < (1 << 8)  ? gl::DataType::UByte
           : index_num < (1 << 16) ? gl::DataType::UShort
           : gl::DataType::UInt;
}

template<typename T>
void MeshIndexData::_fillIndexBuffer(const aiMesh& ai_mesh){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    auto tmp = createTmpData(index_num * sizeof(T));
    auto ptr = reinterpret_cast<T*>(tmp.get());
    for (size_t i = 0; i < faces_num; ++i){
        auto &face = ai_mesh.mFaces[i];
        if (face.mNumIndices != 3){
            throw std::runtime_error("Only triangulated models are supported");
        }

        for (size_t j = 0; j < 3; ++j){
            ptr[3 * i + j] = face.mIndices[j];
        }
    }
    _indices->storage(index_num * sizeof(T), tmp, 0);
}