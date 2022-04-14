#pragma once

#include "glwpp/ctx/Context.hpp"

#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/gl/obj/VertexArray.hpp"

// #include "glwpp/model/MeshInfo.hpp"
#include "glwpp/model/MeshConfig.hpp"
#include "glwpp/model/MeshInfo.hpp"

struct aiMesh;
struct aiFace;

template<class T>
class aiVector3t;

namespace glwpp {

class Mesh {

public:

    static Mesh Cube(const wptr<Context>& wctx, const MeshConfig& prefered_types = Mesh::_get_default_types());

    Mesh(const wptr<Context>& wctx, const MeshConfig& prefered_types = Mesh::_get_default_types());
    virtual ~Mesh();

    bool loadAssimpMesh(const aiMesh& ai_mesh, const SrcLoc& loc = SrcLoc());
    const sptr<VertexArray>& getVAO();

private:
    wptr<Context> _ctx;
    MeshConfig _config;
    MeshInfo _info;

    size_t _faces_count;
    sptr<VertexArray> _vao;
    sptr<Buffer> _vertices;
    sptr<Buffer> _indices;

    void _prepareMeshInfo(const aiMesh& ai_mesh);
    void _prepareIndexBuffer(const aiMesh& ai_mesh);
    template<gl::DataType>
    size_t _getIndexBufferSize(const aiMesh& ai_mesh);
    template<gl::DataType>
    sptr<void> _makeIndexBuffer(const aiMesh& ai_mesh);
    void _prepareVertexBuffer(const aiMesh& ai_mesh);
    void _fillVertex(char* vertex_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh);
    void _fillAttribute(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr);
    template<size_t S>
    void _fillAttributeSized(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr);
    template<size_t S, gl::DataType D>
    void _fillAttributeSizedTyped(char* attr_ptr, const size_t& vertex_pos, const aiMesh& ai_mesh, const MeshAttribute& attr);
    void _prepareVertexArray(const aiMesh& ai_mash);

    // void _fillAttribute3D(char* dst, const MeshAttribute& attr, const aiVector3D& ai_vec3);

    
    // sptr<void> _preparePosition(const aiMesh& ai_mesh);

    static const MeshConfig& _get_default_types();

    // static sptr<void> _packIndices(const aiFace* src, const size_t& count);
    // static sptr<void> _packVec3D(const aiVector3t<float>* src, const size_t& count);

    
};

} // namespace glwpp
