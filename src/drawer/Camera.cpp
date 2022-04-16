#include "glwpp/drawer/Camera.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace glwpp;

Camera::Camera(){
}

Camera::~Camera(){
}

const glm::mat4& Camera::getMat() const {
    return *_mat;
}

const sptr<glm::mat4>& Camera::getMatPtr() const {
    return _mat;
}

void Camera::setPosition(const glm::vec3& pos){
    _pos = pos;
    _update();
}

const glm::vec3& Camera::getPosition() const {
    return _pos;
}

void Camera::setYaw(const float& yaw){
    _yaw = yaw;
    _forward = glm::mat4_cast(glm::quat({_pitch, _yaw, _roll})) * glm::vec4(1, 0, 0, 0);
    _update();
}

const float& Camera::getYaw() const {
    return _yaw;
}

void Camera::setPitch(const float& pitch){
    _pitch = pitch;
    _forward = glm::mat4_cast(glm::quat({_pitch, _yaw, _roll})) * glm::vec4(1, 0, 0, 0);
    _update();
}

const float& Camera::getPitch() const {
    return _pitch;
}

void Camera::setRoll(const float& roll){
    _roll = roll;
    _forward = glm::mat4_cast(glm::quat({_pitch, _yaw, _roll})) * glm::vec4(1, 0, 0, 0);
    _update();
}

const float& Camera::getRoll() const {
    return _roll;
}

void Camera::usePerspective(bool perspective){
    _use_perspective = perspective;
    _update();
}

bool Camera::isPerspective() const {
    return _use_perspective;
}

void Camera::setFov(const float& fov){
    _fov = fov;
    _update();
}

const float& Camera::getFov() const {
    return _fov;
}

void Camera::setNearZ(const float& near_z){
    _near_z = near_z;
    _update();
}

const float& Camera::getNearZ() const {
    return _near_z;
}

void Camera::setFarZ(const float& far_z){
    _far_z = far_z;
    _update();
}

const float& Camera::getFarZ() const {
    return _far_z;
}

void Camera::setWidth(const int& width){
    _width = width;
    _update();
}

const int& Camera::getWidth() const {
    return _width;
}

void Camera::setHeight(const int& height){
    _height = height;
    _update();
}

const int& Camera::getHeight() const {
    return _height;
}

void Camera::_update(){
    glm::mat4 view_mat = glm::lookAt(_pos, _pos + _forward, _up);
    if (_use_perspective){
        auto proj_mat = glm::perspectiveFov(_fov, static_cast<float>(_width), static_cast<float>(_height), _near_z, _far_z);
        *_mat = proj_mat * view_mat;
    } else {
        *_mat = view_mat;
    }
}