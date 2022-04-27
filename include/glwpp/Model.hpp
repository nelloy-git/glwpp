#pragma once

#include <optional>
#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/model/Mesh.hpp"

#include "glwpp/gl/obj/Vector.hpp"

namespace glwpp {
    
class Model {
public:
    Model(const wptr<Context>& wctx);
    virtual ~Model();

    bool loadFile(const std::string& path, const MeshConfig& mesh_cfg);
    std::optional<std::string> getError();

private:
    const wptr<Context> _ctx;
    MeshConfig _mesh_cfg;
    std::optional<std::string> _last_err;

    std::vector<Mesh> _meshes;
    std::vector<glm::mat4> _transform;

    sptr<Vector<glm::mat4>> _base_transform_list;
};

} // namespace glwpp
