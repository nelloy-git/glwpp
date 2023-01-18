#pragma once

#include <array>

#include "Context.hpp"
#include "model/MeshAttributeContainer.hpp"
#include "model/MeshAttribute.hpp"
#include "model/MeshIndices.hpp"

#include "gl_object/VertexArray.hpp"

struct aiMesh;

namespace glwpp {

class Mesh : public CtxObj<Mesh> {
public:
    static constexpr MeshAttributeContainer<GLuint> INDEX = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    using Bindings = MeshAttributeContainer<std::optional<GLuint>>;

    static Value<Mesh> Make(Valuable<Context&> auto&& ctx,
                            Valuable<const aiMesh&> auto&& ai_mesh,
                            Valuable<const SrcLoc&> auto&& src_loc){
        auto mesh = Value<Mesh>::Make(new Mesh(GetValuable(ctx), GetValuable(ai_mesh), GetValuable(src_loc)));
        mesh->init();
        return mesh;
    }
    virtual ~Mesh();

    Value<std::optional<const GLuint>> getAttributeBinding() const;
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setAttributeBinding(Valuable<const GLuint&> auto&& binding){

    }

    // Value<const Bindings> getBindings() const {
    //     callMember
    // }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setBindings(Valuable<const Bindings&> auto&& bindings,
                     Valuable<const SrcLoc&> auto&& src_loc){
        // call<&_setBindingsGL, is_gl_thread>(vao, _bindings, bindings, src_loc);
    }

    Value<GL::VertexArray> vao;
    Value<MeshIndices> indices;
    MeshAttributeContainer<std::optional<Value<MeshAttribute>>> attributes;

private:
    Bindings _bindings;

    Mesh(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc);
    void _init(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc);

    void _initAttributes(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc);
    void _initAttribute(Context& ctx, const MeshAttributeType& type, const Value<MeshAttribute>& attrib, const SrcLoc& src_loc);

    static void _setBindingsGL(Context& ctx, GL::VertexArray& vao, Bindings& cur_bindings, const Bindings& trg_bindings, const SrcLoc& src_loc);
    static void _bindAttributeGL(Context& ctx, GL::VertexArray& vao, Bindings& bindings, const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc);
};
    
} // namespace glwpp
