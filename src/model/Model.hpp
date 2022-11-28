#pragma once

#include <optional>
#include <vector>

#include "Context.hpp"
#include "model/Mesh.hpp"

struct aiScene;

namespace glwpp {

class Model {
public:
    Model(const std::shared_ptr<Context>& ctx, const std::string& model_path, const SrcLoc& src_loc = SrcLoc{});
    ~Model();

    std::optional<std::string> loading_error;

    std::vector<Mesh> meshes;

private:
    bool _loadMeshes(const std::shared_ptr<Context>& ctx, const aiScene& ai_scene, const SrcLoc& src_loc);

};
    
} // namespace glwpp
