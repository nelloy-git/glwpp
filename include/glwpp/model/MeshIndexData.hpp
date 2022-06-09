#pragma once

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

struct aiMesh;

namespace glwpp::model {

class MeshIndexData {
public:
    MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh);
    virtual ~MeshIndexData();
    const sptr<gl::Buffer> getIndices() const;
    const gl::DataType& getType() const;

private:
    gl::DataType _type;
    sptr<gl::Buffer> _indices; 

    static gl::DataType _getIndexType(const aiMesh& ai_mesh);
    template<typename T>
    void _fillIndexBuffer(const aiMesh& ai_mesh);
};

} // namespace glwpp