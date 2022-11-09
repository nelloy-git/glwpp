#pragma once

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Vector.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class ModelState {
public:
    ModelState(const sptr<Context>& ctx,
               const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    virtual ~ModelState();

    const gl::Buffer& buffer() const;
    void apply();

    void setNodeN(int node_n);
    void setNodeTransform(unsigned int i, const glm::mat4& transform);

private:
    int node_n;
    gl::Vector<glm::mat4> node_transforms;
};

}