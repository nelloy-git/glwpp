// #include "drawer/Camera.hpp"

// #include "glm/gtc/matrix_transform.hpp"
// #include "glm/gtc/type_ptr.hpp"

// using namespace glwpp;

// Camera::Camera(Context& ctx, const SrcLoc& src_loc) :
//     buffer(ctx, glm::mat4(1.f), src_loc){

//     constexpr bool b = std::is_convertible_v<Context&, Context&>;
//     constexpr bool v = IsValuable<decltype(ctx), Context>();

// }

// Camera::~Camera(){
// }

// void Camera::apply(){
//     _forward = glm::mat4_cast(glm::quat({pitch, yaw, roll})) * glm::vec4(1, 0, 0, 0);
//     auto mat = glm::lookAt(pos, pos + _forward, _up);
//     if (use_perspective){
//         auto proj_mat = glm::perspectiveFov(fov, static_cast<float>(width), static_cast<float>(height), near_z, far_z);
//         mat = proj_mat * mat;
//     }
//     buffer.setValue(mat);
// }

// // TODO angles
// void Camera::applyLookAt(const glm::vec3& dst){
//     auto mat = glm::lookAt(pos, dst, _up);
//     if (use_perspective){
//         auto proj_mat = glm::perspectiveFov(fov, static_cast<float>(width), static_cast<float>(height), near_z, far_z);
//         mat = proj_mat * mat;
//     }
//     buffer.setValue(mat);
// }