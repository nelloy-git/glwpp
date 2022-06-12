#pragma once

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Array.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class Camera {
public:
    Camera(const wptr<Context>& wctx,
           const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    Camera(const Camera& other) = default;
    virtual ~Camera();

    const gl::Buffer& getBuffer() const;
    void apply();

    glm::vec3 pos = {0, 0, 0};
    float yaw = 0;
    float pitch = 0;
    float roll = 0;

    bool use_perspective = true;
    float fov = 2 * 3.14159265359 / 3;
    float near_z = 0.1;
    float far_z = 100;
    int width = 640;
    int height = 480;

private:
    // 1 element array
    gl::Array<glm::mat4> _buffer;

    glm::vec3 _forward = {1, 0, 0};
    glm::vec3 _up = {0, 1, 0};
};

}