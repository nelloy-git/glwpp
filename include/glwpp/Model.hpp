#pragma once

#include <memory>

#include "glwpp/ctx/data/VertexArray.hpp"
#include "glwpp/WindowData.hpp"

namespace glwpp {

template<class V, class I = GLubyte>
class Model : public WindowData {
public:
    Model(std::weak_ptr<Window> window,
          std::weak_ptr<std::vector<V>> vertices,
          std::weak_ptr<std::vector<I>> indices = std::weak_ptr<std::vector<I>>()) :
        WindowData(window),
        _vert_ptr(_isValidPtr(vertices) ? vertices.lock() : nullptr),
        _index_ptr(_isValidPtr(indices) ? indices.lock() : nullptr){
    }

protected:
    virtual bool _initialize(){
        if (!_vert_ptr){
            return false;
        }

        if (_index_ptr)
            _vert_arr = std::make_shared<ctx::VertexArray<V>>(*_vert_ptr);
        else
            _vert_arr = std::make_shared<ctx::VertexArray<V>>(*_vert_ptr, *_index_ptr);
        
        _vert_ptr.reset();
        _index_ptr.reset();

        return true;
    }

    virtual void _finalize(){
        _vert_arr.reset();
    }

private:
    // Temporary data
    std::shared_ptr<std::vector<V>> _vert_ptr;
    std::shared_ptr<std::vector<I>> _index_ptr;

    // OpenGL data
    std::shared_ptr<ctx::VertexArray<V>> _vert_arr;
};

}