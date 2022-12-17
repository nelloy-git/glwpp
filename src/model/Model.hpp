#pragma once

#include <optional>
#include <vector>

#include "Context.hpp"
#include "model/Mesh.hpp"

struct aiScene;

namespace glwpp {

class Model {
public:
    EXPORT Model(const std::shared_ptr<Context>& ctx, const std::string& model_path);
    EXPORT virtual ~Model();

    std::optional<std::string> loading_error;

    std::vector<std::unique_ptr<Mesh>> meshes;

private:
    bool _loadMeshes(const std::shared_ptr<Context>& ctx, const aiScene& ai_scene);

};
    
} // namespace glwpp
