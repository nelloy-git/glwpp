#pragma once

#include "glwpp/ctx/Context.hpp"

#include "glwpp/gl/oop/Buffer.hpp"
#include "glwpp/gl/oop/VertexArray.hpp"

#include "glwpp/model/MeshInfo.hpp"

struct aiMesh;

template<class T>
class aiVector3t;

namespace glwpp {

class Mesh {
    static const size_t MAX_TEX_COORD = 8;
    static const size_t MAX_VERTEX_COLOR = 8;

public:
    Mesh(const wptr<Context>& wctx, const MeshInfo& info);
    virtual ~Mesh();

    bool loadAssimpMesh(const aiMesh& ai_mesh, const SrcLoc& loc = SrcLoc());

private:
    wptr<Context> _ctx;
    MeshInfo _info;

    uptr<VertexArray> _vao;
    uptr<Buffer> _vertices;
    uptr<Buffer> _elements;

    bool _has_bones;
    bool _has_faces;

    void _calcMeshInfo(const aiMesh& ai_mesh);
    
    sptr<void> _preparePosition(const aiMesh& ai_mesh);

    sptr<void> _packVec3D(const aiVector3t<float>* src, const size_t& count, const gl::DataType& target);

    
};

} // namespace glwpp
