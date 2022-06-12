#include <string>

#include "glwpp/gl/obj/Program.hpp"

#include "glwpp/drawer/Camera.hpp"
#include "glwpp/utils/EnumContainer.hpp"
#include "glwpp/Model.hpp"

namespace glwpp {

enum DrawerUniform {
    Camera_mat4,
    BaseTransform,
    Mesh,
};

class Drawer {
public:
    template<typename T>
    using Val = utils::Val<T>;
    using SrcLoc = utils::SrcLoc;
    using MeshAttributeBinding = EnumContainer<model::MeshAttribute, std::string>;

    Drawer(const gl::Program& program);
    virtual ~Drawer();

    bool bindMeshAttributes(const utils::Val<const MeshAttributeBinding>& bindings,
                            const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}, bool check_ctx = true);
    bool bindMeshAttribute(const utils::Val<model::MeshAttribute>& attr, const utils::Val<std::string>& name,
                           const utils::Val<const utils::SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true);
    // void bindUniform(const Uniform& uniform, const std::string& name);
    // void bindUniform(const Uniform& uniform, const gl::Int& location);

    // void updateCamera();
    // void drawModel(const Model& model);
    // // void drawMesh(const glwpp::Mesh& mesh);
    // void setValueOffset();
    // void setVertexOffset();

    Camera camera;

private:
    
    gl::Program _program;

    sptr<MeshAttributeBinding> _attr_bindings;
    static void _bindMeshAttributes(const MeshAttributeBinding& dst, );

    // EnumContainer<model::MeshAttribute, sptr<gl::Int>> _attr_binding;
    // EnumContainer<Uniform, gl::Int> _uniform_binding;
};

} // namespace glwpp