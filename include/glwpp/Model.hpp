#pragma once

#include "glwpp/ctx/ContextData.hpp"
#include "glwpp/ctx/data/VertexArray.hpp"

namespace glwpp {

template<class V>
class Model : public ctx::ContextData<ctx::VertexArray<V>> {

public:
    Model(std::weak_ptr<Context> wctx,
          std::weak_ptr<std::vector<V>> vertices) :
        ctx::ContextData<ctx::VertexArray<V>>(wctx, _init, vertices.lock(), nullptr){
    }

    template<class I>
    Model(std::weak_ptr<Context> wctx,
          std::weak_ptr<std::vector<V>> vertices,
          std::weak_ptr<std::vector<I>> indices) :
        ctx::ContextData<ctx::VertexArray<V>>(wctx, _init, vertices.lock(), indices.lock()){
    }

private:
    template<class I = GLubyte>
    static sptr<ctx::VertexArray<V>> _init(sptr<std::vector<V>> vert,
                                           sptr<std::vector<I>> ind){
        if (!vert) return nullptr;

        if (!ind) 
            return make_sptr<ctx::VertexArray<V>>(*vert);
        else
            return make_sptr<ctx::VertexArray<V>>(*vert, *ind);
    }
};

}