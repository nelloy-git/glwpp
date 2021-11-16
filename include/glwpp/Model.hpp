#pragma once

#include "glwpp/ctx/ContextData.hpp"
#include "glwpp/ctx/data/VertexArray.hpp"

namespace glwpp {

template<class V, class I = GLubyte>
class Model {
template<class T>
friend class Renderer;

public:
    Model(std::weak_ptr<Context> wctx,
          std::weak_ptr<std::vector<V>> vertices,
          std::weak_ptr<std::vector<I>> indices = std::weak_ptr<std::vector<I>>()){

        auto &vert = *vertices.lock();
        if (indices.expired()){
            _vert_arr.init(wctx, vert);
        } else {
            auto &ind = *indices.lock();
            _vert_arr.init(wctx, vert, ind);
        }
    }

private:
    // OpenGL data
    ctx::ContextData<ctx::VertexArray<V>> _vert_arr;

};

}