#pragma once

#include <mutex>
#include <optional>
#include <string>
#include <vector>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/model/Mesh.hpp"
#include "glwpp/model/Node.hpp"

struct aiScene;

namespace glwpp {
    
class Model {
public:
    Model(const sptr<Context>& ctx, const std::string& path,
          const model::MeshVertexConfig& vert_config);
    virtual ~Model();

    std::optional<std::string> getError();

    const std::vector<sptr<model::Mesh>>& getMeshes() const;
    const std::vector<sptr<model::Node>>& getNodes() const;

    // void forEveryNode(const std::function<void(const ModelNode& node)>& func) const;


private:
    std::optional<std::string> _last_err;

    std::vector<sptr<model::Mesh>> _meshes;
    std::vector<sptr<model::Node>> _nodes;

    bool _loadMeshes(const aiScene& ai_scene,
                     const sptr<Context>& ctx, const model::MeshVertexConfig& vert_config);
    bool _loadNodes(const aiNode& ai_root_node);
    sptr<model::Node> _loadOneNode(const aiNode& ai_node);
};

} // namespace glwpp
