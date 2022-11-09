#pragma once

#include <vector>
#include <cstdlib>

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Vector.hpp"

namespace glwpp {

class MeshTransform {
public:
    MeshTransform(const sptr<Context>& ctx,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) :
        _buffer(gl::Vector<glm::mat4>::make1(ctx, 0, gl::BufferUsage::DynamicDraw, glm::mat4(1.F), src_loc)){
    }

    bool apply(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}){
        auto ptr = std::make_shared<glm::mat4[]>(transforms.size());
        memcpy(ptr.get(), transforms.data(), transforms.size() * sizeof(glm::mat4));

        _buffer->reserve(transforms.size());
        _buffer->setSubData(ptr, 0, transforms.size() * sizeof(glm::mat4), src_loc);

        // std::cout << transforms[0][0][0] << std::endl;

        return true;
    };

    sptr<gl::Vector<glm::mat4>> buffer(){return _buffer;}

    std::vector<glm::mat4> transforms;

private:
    sptr<gl::Vector<glm::mat4>> _buffer;

};

} // namespace glwpp