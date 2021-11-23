#pragma once

#include "glwpp/ctx/ContextData.hpp"
#include "glwpp/ctx/data/VertexArray.hpp"

namespace glwpp {

template<class V, class I = GLubyte>
class Model : public ctx::ContextData<ctx::VertexArray<V>> {

public:
    Model(std::weak_ptr<Context> wctx,
          std::weak_ptr<std::vector<V>> vertices,
          std::weak_ptr<std::vector<I>> indices = std::weak_ptr<std::vector<I>>()) :
        ctx::ContextData<ctx::VertexArray<V>>(wctx){

        auto p_vert = vertices.lock();
        auto p_ind = indices.lock();

        if (!p_vert) return;

        if (!p_ind){
            ctx::ContextData<ctx::VertexArray<V>>::_initSimply(*p_vert);
        } else {
            ctx::ContextData<ctx::VertexArray<V>>::_initSimply(*p_vert, *p_ind);
        }
    }
};

}