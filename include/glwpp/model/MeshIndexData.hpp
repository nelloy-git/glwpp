#pragma once

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

struct aiMesh;

namespace glwpp {

class MeshIndexData {
public:
    MeshIndexData(const wptr<Context>& wctx, const aiMesh& ai_mesh);
    virtual ~MeshIndexData();
    sptr<Buffer> getIndices();
    const sptr<Buffer> getIndices() const;
    const gl::DataType& getType() const;

private:
    wptr<Context> _ctx;
    gl::DataType _type;
    sptr<Buffer> _indices; 

    void _fillIndexType(const aiMesh& ai_mesh);
    template<typename T>
    void _fillIndexBuffer(const aiMesh& ai_mesh);
};

} // namespace glwpp