#pragma once

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Vector.hpp"

namespace glwpp {

class ModelNode {
public:
    ModelNode(const sptr<Vector<glm::mat4>>& transform_list, size_t pos) :
        _base_transform_list(transform_list),
        _base_transform_pos(pos){
    }

    void setTransform(const glm::mat4& value, const SrcLoc& loc = SrcLoc()){
        _base_transform_list->set(_base_transform_pos, value, loc);
    };

private:
    sptr<Vector<glm::mat4>> _base_transform_list;
    size_t _base_transform_pos;

};

}