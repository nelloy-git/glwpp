#pragma once

#include <optional>
#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/model/Mesh.hpp"

#include "glwpp/gl/obj/MappedVector.hpp"

struct aiMatrix4x4;
struct aiNode;
struct aiScene;

namespace glwpp {
    
class Model {
public:
    Model(const wptr<Context>& wctx);
    virtual ~Model();

    bool loadFile(const aiScene* ai_scene, const MeshConfig& mesh_cfg);
    std::optional<std::string> getError();

private:
    const wptr<Context> _ctx;
    MeshConfig _mesh_cfg;
    std::optional<std::string> _last_err;

    std::vector<Mesh> _meshes;
    std::vector<glm::mat4> _transform;

    sptr<MappedVector<glm::mat4>> _base_transform_list;

    void _recurseAiNodes(const aiNode* ai_node);
    glm::mat4 _ai2glm(const aiMatrix4x4& ai_mat);
};

} // namespace glwpp
