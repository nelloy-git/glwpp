#pragma once

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Array.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class Camera {
public:
    Camera(const wptr<Context>& wctx, const SrcLoc loc = SrcLoc());
    Camera(const Camera& other) = default;
    virtual ~Camera();

    void bindBufferIndex(const sptr<gl::UInt>& index);

    const glm::mat4& getMat() const;
    const sptr<glm::mat4>& getMatPtr() const;

    // Camera transform

    void setPosition(const glm::vec3& pos);
    const glm::vec3& getPosition() const;

    void setYaw(const float& yaw);
    const float& getYaw() const;

    void setPitch(const float& pitch);
    const float& getPitch() const;

    void setRoll(const float& roll);
    const float& getRoll() const;

    // Perspective parameters

    void usePerspective(bool perspective);
    bool isPerspective() const;

    void setFov(const float& fov);
    const float& getFov() const;

    void setNearZ(const float& near_z);
    const float& getNearZ() const;

    void setFarZ(const float& far_z);
    const float& getFarZ() const;

    void setWidth(const int& width);
    const int& getWidth() const;

    void setHeight(const int& height);
    const int& getHeight() const;

private:
    void _update();

    struct UniformBlock {
        glm::mat4 mat = glm::mat4(1.0F);
    };

    Array<UniformBlock> _gl_cam;
    sptr<glm::mat4> _mat = make_sptr<glm::mat4>(1.0f);
    glm::vec3 _forward = {1, 0, 0};
    glm::vec3 _up = {0, 1, 0};

    glm::vec3 _pos = {0, 0, 0};
    float _yaw = 0;
    float _pitch = 0;
    float _roll = 0;

    bool _use_perspective = true;
    float _fov = 2 * 3.14159265359 / 3;
    float _near_z = 0.1;
    float _far_z = 100;
    int _width = 640;
    int _height = 480;
};

}