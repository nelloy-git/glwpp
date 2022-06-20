#pragma once

#include <mutex>
#include <optional>
#include <string>
#include <vector>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/model/Mesh.hpp"

struct aiScene;

namespace glwpp {
    
class Model {
public:
    Model(const wptr<Context>& wctx, const std::string& path,
          const model::MeshVertexConfig& vert_config);
    virtual ~Model();

    std::optional<std::string> getError();

    const std::vector<model::Mesh>& getMeshes() const;

    // void forEveryNode(const std::function<void(const ModelNode& node)>& func) const;


private:
    std::optional<std::string> _last_err;

    std::vector<model::Mesh> _meshes;

    bool _loadMeshes(const aiScene& ai_scene,
                     const wptr<Context>& wctx, const model::MeshVertexConfig& vert_config);
    // bool _loadNodes(const aiScene* ai_scene);
};

} // namespace glwpp
