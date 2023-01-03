// #include "model/Mesh.hpp"

// #include "assimp/scene.h"
// #include "assimp/vector3.h"
// #include "assimp/color4.h"

// using namespace glwpp;

// const GLuint Mesh::POSITION_INDEX = 0;
// const GLuint Mesh::NORMAL_INDEX = 1;
// const GLuint Mesh::TANGENT_INDEX = 2;
// const GLuint Mesh::BITANGENT_INDEX = 3;
// const std::array<const GLuint, 8> Mesh::TEXTURE_INDEX = {4, 5, 6, 7, 8, 9, 10, 11};
// const std::array<const GLuint, 8> Mesh::COLOR_INDEX = {12, 13, 14, 15, 16, 17, 18, 19};

// Mesh::Mesh(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc) :
//     CallOptimizer(ctx),
//     vao(ctx, src_loc),
//     indices(ctx, ai_mesh.mNumFaces, ai_mesh.mFaces, src_loc.add()),
//     position(ctx, ai_mesh.mNumVertices, ai_mesh.mVertices, src_loc.add()),
//     _bindings(ctx, {}){
//     _initOptionalBuffers(ctx, ai_mesh, src_loc);
//     _linkAllAttributes(src_loc);
// }

// Mesh::~Mesh(){
// }

// // bool Mesh::bindPosition(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     _bindAttribute(POSITION_INDEX, binding, src_loc);
// //     return true;
// // }

// // bool Mesh::bindNormal(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     if (!normal){return false;}
// //     _bindAttribute(NORMAL_INDEX, binding, src_loc);
// //     return true;
// // }

// // bool Mesh::bindTangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     if (!tangent){return false;}
// //     _bindAttribute(TANGENT_INDEX, binding, src_loc);
// //     return true;
// // }

// // bool Mesh::bindBitangent(const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     if (!bitangent){return false;}
// //     _bindAttribute(BITANGENT_INDEX, binding, src_loc);
// //     return true;
// // }

// // bool Mesh::bindTextureCoord(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     if (!texture_coord[i]){return false;}
// //     _bindAttribute(TEXTURE_INDEX[i], binding, src_loc);
// //     return true;
// // }

// // bool Mesh::bindColor(const size_t& i, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
// //     if (!color[i]){return false;}
// //     _bindAttribute(COLOR_INDEX[i], binding, src_loc);
// //     return true;
// // }

// const Value<const Mesh::Bindings> Mesh::getBindings() const {
//     return _bindings;
// }

// // void Mesh::setBindings(const Value<const Bindings>& bindings, const SrcLoc& src_loc){
// //     constexpr auto F = [](Context& ctx, GL::VertexArray& vao, Bindings& dst_bindings, const Bindings& bindings, const SrcLoc& src_loc){
// //         for (unsigned int i = 0; i < bindings.size(); ++i){
// //             dst_bindings[i] = bindings[i];
// //             if (!bindings[i].has_value()){
// //                 vao.disableAttrib<IsGlThread::True>(i, src_loc);
// //                 return;
// //             }
// //             vao.enableAttrib<IsGlThread::True>(i, src_loc);
// //             vao.setAttribBinding<IsGlThread::True>(i, bindings[i].value(), src_loc);
// //         }
// //     };
// //     call<F, IsGlThread::Unknown>(vao, _bindings, bindings, src_loc);
// // }

// void Mesh::_initOptionalBuffers(Context& ctx, const aiMesh& ai_mesh, const SrcLoc& src_loc){
//     if (ai_mesh.HasNormals()){
//         normal = std::make_unique<MeshAttribute>(ctx, ai_mesh.mNumVertices, ai_mesh.mNormals, src_loc);
//     }
//     if (ai_mesh.HasTangentsAndBitangents()){
//         tangent = std::make_unique<MeshAttribute>(ctx, ai_mesh.mNumVertices, ai_mesh.mTangents, src_loc);
//         bitangent = std::make_unique<MeshAttribute>(ctx, ai_mesh.mNumVertices, ai_mesh.mBitangents, src_loc);
//     }

//     for (int i = 0; i < 8; ++i){
//         if (ai_mesh.HasTextureCoords(i)){
//             texture_coord[i] = std::make_unique<MeshAttribute>(ctx, ai_mesh.mNumVertices, ai_mesh.mTextureCoords[i], src_loc);
//         }
//     }

//     for (int i = 0; i < 8; ++i){
//         if (ai_mesh.HasVertexColors(i)){
//             color[i] = std::make_unique<MeshAttribute>(ctx, ai_mesh.mNumVertices, ai_mesh.mColors[i], src_loc);
//         }
//     }
// }

// void Mesh::_linkAllAttributes(const SrcLoc& src_loc){
//     vao.setElementBuffer(indices.buffer, src_loc);
//     _linkAttribute(POSITION_INDEX, position, src_loc);
//     if (normal){_linkAttribute(NORMAL_INDEX, *normal, src_loc);}
//     if (tangent){_linkAttribute(TANGENT_INDEX, *tangent, src_loc);}
//     if (bitangent){_linkAttribute(BITANGENT_INDEX, *bitangent, src_loc);}
//     for (size_t i = 0; i < texture_coord.size(); ++i){
//         if (texture_coord[i]){_linkAttribute(TEXTURE_INDEX[i], *texture_coord[i], src_loc);}
//     }
//     for (size_t i = 0; i < color.size(); ++i){
//         if (color[i]){_linkAttribute(COLOR_INDEX[i], *color[i], src_loc);}
//     }
    
// }

// void Mesh::_linkAttribute(const GLuint& index, const MeshAttribute& attribute, const SrcLoc& src_loc){
//     vao.setVertexBuffer(index, attribute.buffer, 0, attribute.stride, src_loc);
//     vao.setAttribFormat(index, attribute.components, static_cast<GLenum>(attribute.type), attribute.normalized, 0, src_loc);
// }

// void Mesh::_bindAttribute(const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     call<&_bindAttributeGL, IsGlThread::Unknown>(vao, _bindings, index, binding, src_loc);
// }

// void Mesh::_setBindingsGL(Context& ctx, GL::VertexArray& vao, Bindings& cur_bindings, const Bindings& trg_bindings, const SrcLoc& src_loc){
//     for (unsigned int i = 0; i < trg_bindings.size(); ++i){
//         _bindAttributeGL(ctx, vao, cur_bindings, i, trg_bindings[i], src_loc);
//     }
// }

// void Mesh::_bindAttributeGL(Context& ctx, GL::VertexArray& vao, Bindings& bindings, const GLuint& index, const std::optional<unsigned int>& binding, const SrcLoc& src_loc){
//     bindings[index] = binding;
//     if (!binding.has_value()){
//         vao.disableAttrib<IsGlThread::True>(index, src_loc);
//         return;
//     }
//     vao.enableAttrib<IsGlThread::True>(index, src_loc);
//     vao.setAttribBinding<IsGlThread::True>(index, binding.value(), src_loc);
// }