#include <string>

#include "glwpp/gl/obj/Program.hpp"

#include "glwpp/drawer/Camera.hpp"
#include "glwpp/Model.hpp"
#include "glwpp/utils/EnumContainer.hpp"

namespace glwpp {

class Drawer {
public:
    Drawer(const Program& program);
    virtual ~Drawer();

    enum class Uniform {
        Camera,
        BaseTransform,
        Mesh,
    };
    static size_t GetUniformEnumSize();

    void bindMeshAttribute(const MeshAttribute& attr, const std::string& name);
    void bindMeshAttribute(const MeshAttribute& attr, const gl::Int& location);
    void bindUniform(const Uniform& uniform, const std::string& name);
    void bindUniform(const Uniform& uniform, const gl::Int& location);

    void updateCamera();
    void drawModel(const Model& model);
    // void drawMesh(const glwpp::Mesh& mesh);
    // void setValueOffset();
    // void setVertexOffset();

    Camera camera;

private:
    Program _program;

    EnumContainer<MeshAttribute, sptr<gl::Int>> _attr_binding;
    EnumContainer<Uniform, gl::Int> _uniform_binding;
};

} // namespace glwpp