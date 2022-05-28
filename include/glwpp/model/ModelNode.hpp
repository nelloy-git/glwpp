#pragma once

#include <vector>

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Vector.hpp"
#include "glwpp/model/Mesh.hpp"

struct aiNode;

namespace glwpp {

class ModelNodeTree {
friend class ModelNode;

public:
    ModelNodeTree(const wptr<Context>& wctx, 
                  const aiNode& ai_root);
    virtual ~ModelNodeTree();

    const ModelNode& getRoot() const;
    const Vector<glm::mat4>& getTransforms() const;

    void forEveryNode(const std::function<void(const ModelNode& node)>& func) const;

private:
    wptr<Context> _ctx;
    sptr<ModelNode> _root;
    std::vector<sptr<ModelNode>> _list;
    sptr<Vector<glm::mat4>> _transforms;

    sptr<ModelNode> _loadAiNode(const aiNode& ai_node,
                                size_t& transforms_size);
};

class ModelNode {
public:
    ModelNode(ModelNodeTree& tree);
    virtual ~ModelNode();

    void setParent(const wptr<ModelNode>& parent);
    const wptr<ModelNode>& getParent() const;

    const void addChild(const sptr<ModelNode>& child);
    const sptr<ModelNode>& getChild(const size_t& i) const;
    const size_t getChildrenCount() const;

    void setTransformPos(const size_t& pos);
    const size_t getTransformPos() const;

    const void addMesh(const size_t& mesh);
    const size_t& getMesh(const size_t i) const;
    const size_t getMeshesCount() const;

private:
    ModelNodeTree* _tree;
    wptr<ModelNode> _parent;
    std::vector<sptr<ModelNode>> _children;
    size_t _transform;
    std::vector<size_t> _meshes;
};

}