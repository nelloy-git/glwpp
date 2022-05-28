#pragma once

#include <mutex>
#include <optional>
#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/obj/Vector.hpp"
#include "glwpp/model/Mesh.hpp"
#include "glwpp/model/ModelNode.hpp"

struct aiScene;

namespace glwpp {
    
class Model {
public:
    Model(const wptr<Context>& wctx, const std::string& path,
          const MeshVertexConfig& vert_config = getDefaultVertexConfig());
    virtual ~Model();

    static void setDefaultVertexConfig(const MeshVertexConfig& config);
    static MeshVertexConfig getDefaultVertexConfig();

    std::optional<std::string> getError();

    const Vector<glm::mat4> getBaseTransforms() const;
    const std::vector<Mesh>& getMeshes() const;

    void forEveryNode(const std::function<void(const ModelNode& node)>& func) const;


private:
    const wptr<Context> _ctx;
    std::optional<std::string> _last_err;

    uptr<std::vector<sptr<Mesh>>> _meshes;
    uptr<ModelNodeTree> _node_tree;

    bool _loadMeshes(const aiScene* ai_scene, const MeshVertexConfig& vert_config);
    bool _loadNodes(const aiScene* ai_scene);

    static std::mutex _default_config_lock;
    static MeshVertexConfig _default_vertex_config;
};

} // namespace glwpp
