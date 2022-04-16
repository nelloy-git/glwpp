#include <string>

#include "magic_enum.hpp"

#include "glwpp/drawer/Camera.hpp"

#include "glwpp/gl/obj/Program.hpp"

namespace glwpp {

class Drawer {
public:
    Drawer(const Program& program);
    virtual ~Drawer();

    enum class Uniform {
        CameraMat4,
        PositionOffsetVec3,
        PositionMultScalar
    };

    void bindUniform(const Uniform& uniform, const std::string& name);
    void bindUniform(const Uniform& uniform, const gl::Int& location);

    void setCameraMatLocation(const std::string& unif_name);
    void setCameraMatLocation(const gl::Int& unif_loc);
    void setVertexValueOffsetLocation();

    void updateCamera();

    Camera camera;

private:
    Program _program;

    const bool v = MAGIC_ENUM_SUPPORTED;
    sptr<gl::Int> _uniform_locations[magic_enum::enum_count<Uniform>()];
    sptr<gl::Int> _camera_loc;

};

} // namespace glwpp