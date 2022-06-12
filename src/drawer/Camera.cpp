#include "glwpp/drawer/Camera.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace glwpp;
using namespace glwpp::utils;

Camera::Camera(const wptr<Context>& wctx,
               const Val<const SrcLoc>& src_loc) :
    _buffer(wctx, 1, glm::mat4(1.0), src_loc){
}

Camera::~Camera(){
}


const gl::Buffer& Camera::getBuffer() const {
    return _buffer;
}

void Camera::apply(){
    _forward = glm::mat4_cast(glm::quat({pitch, yaw, roll})) * glm::vec4(1, 0, 0, 0);
    auto mat = glm::lookAt(pos, pos + _forward, _up);
    if (use_perspective){
        auto proj_mat = glm::perspectiveFov(fov, static_cast<float>(width), static_cast<float>(height), near_z, far_z);
        mat = proj_mat * mat;
    }
    _buffer.set(0, mat);
}