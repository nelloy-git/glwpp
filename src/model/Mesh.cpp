#include "model/Mesh.hpp"

#include "assimp/scene.h"
#include "assimp/vector3.h"
#include "assimp/color4.h"

using namespace glwpp;

Mesh::Mesh(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc) :
    CtxObj(ctx),
    vao(GL::VertexArray::Make(ctx, src_loc)),
    indices(MeshIndices::Make(ctx, ai_mesh.mNumFaces, ai_mesh.mFaces, src_loc.add())),
    _bindings({}){
    _initAttributes(ctx, ai_mesh, src_loc);
    // _linkAttributes(src_loc);
}

Mesh::~Mesh(){
}

void Mesh::_init(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc){
    // _initAttributes(src_loc);

}

// bool Mesh::bindPosition(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     _bindAttribute(POSITION_INDEX, binding, src_loc);
//     return true;
// }

// bool Mesh::bindNormal(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     if (!normal){return false;}
//     _bindAttribute(NORMAL_INDEX, binding, src_loc);
//     return true;
// }

// bool Mesh::bindTangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     if (!tangent){return false;}
//     _bindAttribute(TANGENT_INDEX, binding, src_loc);
//     return true;
// }

// bool Mesh::bindBitangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     if (!bitangent){return false;}
//     _bindAttribute(BITANGENT_INDEX, binding, src_loc);
//     return true;
// }

// bool Mesh::bindTextureCoord(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     if (!texture_coord[i]){return false;}
//     _bindAttribute(TEXTURE_INDEX[i], binding, src_loc);
//     return true;
// }

// bool Mesh::bindColor(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     if (!color[i]){return false;}
//     _bindAttribute(COLOR_INDEX[i], binding, src_loc);
//     return true;
// }

// const Value<const Mesh::Bindings> Mesh::getBindings() const {
//     return _bindings;
// }

// void Mesh::setBindings(const Value<const Bindings>& bindings, const SrcLoc& src_loc){
//     constexpr auto F = [](Context& ctx, GL::VertexArray& vao, Bindings& dst_bindings, const Bindings& bindings, const SrcLoc& src_loc){
//         for (unsigned int i = 0; i < bindings.size(); ++i){
//             dst_bindings[i] = bindings[i];
//             if (!bindings[i].has_value()){
//                 vao->disableAttrib<IsGlThread::True>(i, src_loc);
//                 return;
//             }
//             vao->enableAttrib<IsGlThread::True>(i, src_loc);
//             vao->setAttribBinding<IsGlThread::True>(i, bindings[i].value(), src_loc);
//         }
//     };
//     call<F, IsGlThread::Unknown>(vao, _bindings, bindings, src_loc);
// }

void Mesh::_initAttributes(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc){
    using Type = MeshAttributeType;

    if (ai_mesh.HasPositions()){
        _initAttribute(ctx, Type::Position, MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mVertices, src_loc), src_loc);
    }
    // if (ai_mesh.HasNormals()){
    //     attributes[Type::Normal] = MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mNormals, src_loc);
    // }
    // if (ai_mesh.HasTangentsAndBitangents()){
    //     attributes[Type::Tangent] = MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mTangents, src_loc);
    //     attributes[Type::Bitangent] = MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mBitangents, src_loc);
    // }

    // for (unsigned int i = 0; i < attributes.textures(); ++i){
    //     if (ai_mesh.HasTextureCoords(i)){
    //         attributes.setTexture(i, MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mTextureCoords[i], src_loc));
    //     }
    // }

    // for (unsigned int i = 0; i < attributes.textures(); ++i){
    //     if (ai_mesh.HasVertexColors(i)){
    //         attributes.setColor(i, MeshAttribute::Make(ctx, ai_mesh.mNumVertices, ai_mesh.mColors[i], src_loc));
    //     }
    // }
}

void Mesh::_initAttribute(Context& ctx, const MeshAttributeType& type, const Value<MeshAttribute>& attrib, const SrcLoc& src_loc){
    attributes[type] = attrib;
    vao->setVertexBuffer<TState::Unknown>(INDEX[type], attrib->buffer, 0, attrib->stride, src_loc.add());
    vao->setAttribBinding<TState::Unknown>(INDEX[type], INDEX[type], src_loc.add());
    vao->setAttribFormat<TState::Unknown>(INDEX[type], attrib->components, static_cast<GLenum>(attrib->type), attrib->normalized, 0, src_loc.add());
    vao->enableAttrib<TState::Unknown>(INDEX[type], src_loc.add());
}

void Mesh::_setBindingsGL(Context& ctx, GL::VertexArray& vao, Bindings& cur_bindings, const Bindings& trg_bindings, const SrcLoc& src_loc){
    // for (unsigned int i = 0; i < trg_bindings.size(); ++i){
    //     _bindAttributeGL(ctx, vao, cur_bindings, i, trg_bindings[i], src_loc);
    // }
}

void Mesh::_bindAttributeGL(Context& ctx, GL::VertexArray& vao, Bindings& bindings, const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
    // bindings[index] = binding;
    // if (!binding.has_value()){
    //     vao->disableAttrib<IsGlThread::True>(index, src_loc);
    //     return;
    // }
    // vao->enableAttrib<IsGlThread::True>(index, src_loc);
    // vao->setAttribBinding<IsGlThread::True>(index, binding.value(), src_loc);
}