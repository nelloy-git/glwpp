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
    template<typename T>
    using Val = utils::Val<T>;
    using SrcLoc = utils::SrcLoc;
    using MeshAttributeBindings = EnumContainer<model::MeshAttribute, std::string>;
    using UniformBlockBindings = EnumContainer<DrawerUniformBlock, std::string>;

    Drawer(const wptr<Context>& wctx,
           const Val<const SrcLoc> src_loc = SrcLoc{});
    virtual ~Drawer();

    Camera& camera();
    const Camera& camera() const;

    bool bindMeshAttributes(const utils::Val<const MeshAttributeBindings>& bindings,
                            const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}, bool check_ctx = true);

    bool bindUniformBlocks(const utils::Val<const UniformBlockBindings>& bindings,
                           const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}, bool check_ctx = true);

    // bool bindMeshAttribute(const utils::Val<model::MeshAttribute>& attr, const utils::Val<std::string>& name,
    //                        const utils::Val<const utils::SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true);
    // void bindUniform(const Uniform& uniform, const std::string& name);
    // void bindUniform(const Uniform& uniform, const gl::Int& location);

    // void updateCamera();
    // void drawModel(const Model& model);
    // // void drawMesh(const glwpp::Mesh& mesh);
    // void setValueOffset();
    // void setVertexOffset();


private:
    struct DrawerData {
        DrawerData(const wptr<Context>& wctx,
                   const Val<const SrcLoc> src_loc = SrcLoc{}) :
            camera(wctx, src_loc){
        };

        Camera camera;
        MeshAttributeBindings attr_bindings;
        UniformBlockBindings uniform_block_bindings;
    };
    sptr<DrawerData> _data;

    static void _bindMeshAttributes(const MeshAttributeBindings& bindings,
                                    const gl::UInt& id, DrawerData& data);
                                    
    static void _bindUniformBlocks(const utils::Val<const UniformBlockBindings>& bindings,
                                   const gl::UInt& id, DrawerData& data);

    template<DrawerUniformBlock U>
    static const gl::Buffer& _getUniformBlockBuffer(DrawerData& data);

    // EnumContainer<model::MeshAttribute, sptr<gl::Int>> _attr_binding;
    // EnumContainer<Uniform, gl::Int> _uniform_binding;
};

} // namespace glwpp