#pragma once

#include "glm/glm.hpp"

#include "Context.hpp"
#include "gl_object/BufferStruct.hpp"

namespace glwpp {

class Camera {
public:
    Camera(Context& ctx, const SrcLoc& src_loc = SrcLoc{});
    Camera(const Camera& other) = default;
    virtual ~Camera();

    Value<GL::BufferStruct<glm::mat4>> buffer;

    void apply();
    void applyLookAt(const glm::vec3& dst);

    glm::vec3 pos = {0, 0, 0};
    float yaw = 0;
    float pitch = 0;
    float roll = 0;

    bool use_perspective = true;
    float fov = float(2 * 3.14159265359 / 3);
    float near_z = float(0.01);
    float far_z = 10000;
    int width = 640;
    int height = 480;

private:
    glm::vec3 _forward = {1, 0, 0};
    glm::vec3 _up = {0, 1, 0};
};

}