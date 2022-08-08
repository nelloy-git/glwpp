#include <string>

#include "glwpp/gl/obj/Program.hpp"

#include "glwpp/drawer/Camera.hpp"
#include "glwpp/utils/EnumContainer.hpp"
#include "glwpp/model/MeshEnums.hpp"
// #include "glwpp/Model.hpp"

namespace glwpp {

enum class DrawerUniformBlock {
    Camera,
    BaseTransform,
    Mesh,
};

class Drawer : public gl::Program {
public:
    using MeshAttributeBindings = EnumContainer<model::MeshAttribute, std::string>;
    using UniformBlockBindings = EnumContainer<DrawerUniformBlock, std::string>;

    static sptr<Drawer> make(const sptr<Context>& ctx,
                             const Val<const utils::SrcLoc> src_loc = utils::SrcLoc{});
    virtual ~Drawer();

    Camera& camera();
    const Camera& camera() const;

    bool bindMeshAttributes(const Val<const MeshAttributeBindings>& bindings,
                            const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool bindUniformBlocks(const Val<const UniformBlockBindings>& bindings,
                           const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    // bool bindMeshAttribute(const Val<model::MeshAttribute>& attr, const Val<std::string>& name,
    //                        const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    // void bindUniform(const Uniform& uniform, const std::string& name);
    // void bindUniform(const Uniform& uniform, const gl::Int& location);

    // void updateCamera();
    // void drawModel(const Model& model);
    // // void drawMesh(const glwpp::Mesh& mesh);
    // void setValueOffset();
    // void setVertexOffset();

protected:
    Drawer(const sptr<Context>& ctx,
           const Val<const utils::SrcLoc> src_loc);

private:
    Camera _camera;
    MeshAttributeBindings _attr_bindings;
    UniformBlockBindings _uniform_block_bindings;

    template<DrawerUniformBlock U>
    const sptr<gl::Buffer> _getUniformBlockBuffer();

    // EnumContainer<model::MeshAttribute, sptr<gl::Int>> _attr_binding;
    // EnumContainer<Uniform, gl::Int> _uniform_binding;
};

} // namespace glwpp