// #include "glwpp/model/ModelNode.hpp"

// #include "assimp/scene.h"

// using namespace glwpp;

// namespace {

// glm::mat4 _ai2glm(const aiMatrix4x4& mat){
//     return glm::mat4(
//         *mat[0],  *mat[1],  *mat[2],  *mat[3],
//         *mat[4],  *mat[5],  *mat[6],  *mat[7],
//         *mat[8],  *mat[9],  *mat[10], *mat[11],
//         *mat[12], *mat[13], *mat[14], *mat[15]
//     );
// }

// }

// ModelNodeTree::ModelNodeTree(const sptr<Context>& ctx,
//                              const aiNode& ai_root) :
//     _ctx(wctx){
//     _transforms = make_sptr<Vector<glm::mat4>>(wctx);
//     size_t transforms_size = 0;
//     _root = _loadAiNode(ai_root, transforms_size);
// }

// void ModelNodeTree::forEveryNode(const std::function<void(const ModelNode& node)>& func) const {
//     for (auto& node : _list){
//         func(*node);
//     }
// }

// sptr<ModelNode> ModelNodeTree::_loadAiNode(const aiNode& ai_node,
//                                            size_t& transforms_size){
//     auto node = make_sptr<ModelNode>(*this);
//     _list.push_back(node);
//     _transforms->push_back(_ai2glm(ai_node.mTransformation));
//     node->setTransformPos(transforms_size);
//     ++transforms_size;

//     for (size_t i = 0; i < ai_node.mNumMeshes; ++i){
//         node->addMesh(ai_node.mMeshes[i]);
//     }

//     for (size_t i = 0; i < ai_node.mNumChildren; ++i){
//         auto child = _loadAiNode(*ai_node.mChildren[i], transforms_size);
//         child->setParent(node);
//         node->addChild(child);
//     }

//     return node;
// }

// ModelNode::ModelNode(ModelNodeTree& tree) :
//     _tree(&tree){
// }

// void ModelNode::setParent(const wptr<ModelNode>& parent){
//     _parent = parent;
// }

// const wptr<ModelNode>& ModelNode::getParent() const {
//     return _parent;
// }