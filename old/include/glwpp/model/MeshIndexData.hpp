#pragma once

#include "glwpp/model/MeshEnums.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

struct aiMesh;

namespace glwpp::model {

class MeshIndexData {
public:
    MeshIndexData(const sptr<Context>& ctx, const aiMesh& ai_mesh,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    virtual ~MeshIndexData();
    const sptr<gl::Buffer>& getIndices() const;
    const gl::UInt& getIndexCount() const;
    const MeshIndexType& getType() const;

private:
    MeshIndexType _type;
    sptr<gl::Buffer> _indices; 
    gl::UInt _index_count;

    static MeshIndexType _getIndexType(const aiMesh& ai_mesh);
    template<typename T>
    void _fillIndexBuffer(const aiMesh& ai_mesh,
                          const Val<const utils::SrcLoc>& src_loc);
};

} // namespace glwpp