#pragma once

#include <atomic>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/obj/VertexArray.hpp"

#include "glwpp/model/MeshIndexData.hpp"
#include "glwpp/model/MeshVertexConfig.hpp"
#include "glwpp/model/MeshVertexData.hpp"
#include "glwpp/utils/EnumContainer.hpp"

struct aiMesh;
struct aiFace;

template<class T>
class aiVector3t;

namespace glwpp {

class Mesh {

public:
    Mesh(const wptr<Context>& wctx, const aiMesh& ai_mesh, const MeshVertexConfig& vert_config);
    virtual ~Mesh();

    sptr<VertexArray> getVertexArray();

    void setAttributeBindings(const EnumContainer<MeshAttribute, gl::Int>& bindings);
    const EnumContainer<MeshAttribute, gl::Int>& getAttributeBindings() const;

private:
    wptr<Context> _ctx;
    sptr<VertexArray> _vert_arr;

    MeshIndexData _index_data;
    MeshVertexData _vert_data;

    EnumContainer<MeshAttribute, gl::Int> _attr_bindings;
};

} // namespace glwpp
