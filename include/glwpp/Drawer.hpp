#include <string>

#include "glwpp/drawer/Camera.hpp"
#include "glwpp/model/Mesh.hpp"

#include "glwpp/gl/obj/Program.hpp"

namespace glwpp {

class Drawer {
public:
    Drawer(const Program& program);
    virtual ~Drawer();

    enum class Attribute {
        Position,
    };
    static size_t GetAttributeEnumSize();

    enum class Uniform {
        Camera,
        PositionOffset_vec3,
        PositionMult_scalar
    };
    static size_t GetUniformEnumSize();

    void bindMeshAttribute(const Attribute& attr, const std::string& name);
    void bindMeshAttribute(const Attribute& attr, const gl::Int& location);
    void bindUniform(const Uniform& uniform, const std::string& name);
    void bindUniform(const Uniform& uniform, const gl::Int& location);

    void updateCamera();
    void drawMesh(const glwpp::Mesh& mesh);
    // void setValueOffset();
    // void setVertexOffset();

    Camera camera;

private:
    Program _program;

    std::vector<sptr<gl::Int>> _attribute_location;;
    std::vector<sptr<gl::Int>> _uniform_location;

};

} // namespace glwpp