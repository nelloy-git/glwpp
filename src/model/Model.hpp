#pragma once

#include <optional>
#include <vector>

#include "Context.hpp"
#include "model/Mesh.hpp"

struct aiScene;

namespace glwpp {

class Model {
public:
    EXPORT Model(Context& ctx, const std::string& model_path, const SrcLoc& src_loc = SrcLoc{});
    EXPORT virtual ~Model();

    std::optional<std::string> loading_error;

    std::vector<Mesh> meshes;

private:
    std::optional<std::string> _loadMeshes(Context& ctx, const aiScene& ai_scene, const SrcLoc& src_loc);

};
    
} // namespace glwpp
