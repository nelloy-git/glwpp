#pragma once

#include "glwpp/model/MeshEnums.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

struct aiMesh;

namespace glwpp::model {

class MeshIndexData {
public:
    MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh,
                  const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    virtual ~MeshIndexData();
    const gl::Buffer& getIndices() const;
    const MeshIndexType& getType() const;

private:
    MeshIndexType _type;
    gl::Buffer _indices; 

    static MeshIndexType _getIndexType(const aiMesh& ai_mesh);
    template<typename T>
    void _fillIndexBuffer(const aiMesh& ai_mesh,
                          const utils::Val<const utils::SrcLoc>& src_loc);
};

} // namespace glwpp