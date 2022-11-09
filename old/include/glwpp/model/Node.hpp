#pragma once

#include <vector>

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Vector.hpp"
#include "glwpp/model/Mesh.hpp"

struct aiNode;

namespace glwpp::model {

class Node {
public:
    Node(){};
    virtual ~Node(){};

    glm::mat4 mat;
    wptr<Node> parent;
    std::vector<sptr<Node>> children;
    std::vector<sptr<Mesh>> meshes;
};

}