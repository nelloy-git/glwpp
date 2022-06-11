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

namespace glwpp::model {

class Mesh {

public:
    Mesh(const wptr<Context>& wctx, const aiMesh& ai_mesh, const MeshVertexConfig& vert_config,
         const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    virtual ~Mesh();

    const gl::VertexArray& getVertexArray() const;
    const MeshIndexData& getIndexData() const;
    const MeshVertexData& getVertexData() const;

private:
    gl::VertexArray _vert_arr;
    MeshIndexData _index_data;
    MeshVertexData _vert_data;
};

} // namespace glwpp
