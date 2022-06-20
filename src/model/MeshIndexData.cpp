#include "glwpp/model/MeshIndexData.hpp"

#include "assimp/mesh.h"
#include "magic_enum.hpp"

using namespace glwpp;
using namespace glwpp::model;

MeshIndexData::MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh,
                             const utils::Val<const utils::SrcLoc>& src_loc) :
    _type(_getIndexType(ai_mesh)),
    _indices(wctx, src_loc){

    magic_enum::enum_switch([&](auto type){
        _fillIndexBuffer<MeshIndexTypeCpu_t<type>>(ai_mesh, src_loc);
    }, _type);
}

const gl::Buffer& MeshIndexData::getIndices() const {
    return _indices;
}

const MeshIndexType& MeshIndexData::getType() const {
    return _type;
}

MeshIndexData::~MeshIndexData(){
}

MeshIndexType MeshIndexData::_getIndexType(const aiMesh& ai_mesh){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    if (index_num > std::numeric_limits<MeshIndexTypeCpu_t<MeshIndexType::UInt>>::infinity()){
        throw std::runtime_error("Too many indices in mesh");
    }

     return index_num < (1 << 8)  ? MeshIndexType::UByte
          : index_num < (1 << 16) ? MeshIndexType::UShort
          : MeshIndexType::UInt;
}

template<typename T>
void MeshIndexData::_fillIndexBuffer(const aiMesh& ai_mesh,
                                     const utils::Val<const utils::SrcLoc>& src_loc){
    auto faces_num = ai_mesh.mNumFaces;
    size_t index_num = faces_num * 3;

    auto tmp = utils::alloc_sptr_buffer<T>(index_num);
    for (size_t i = 0; i < faces_num; ++i){
        auto &face = ai_mesh.mFaces[i];
        if (face.mNumIndices != 3){
            throw std::runtime_error("Only triangulated models are supported");
        }

        for (size_t j = 0; j < 3; ++j){
            tmp[3 * i + j] = face.mIndices[j];
        }
    }
    _indices.storage(index_num * sizeof(T), tmp, 0, src_loc);
}