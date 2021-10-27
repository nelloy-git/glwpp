#pragma once

#include <any>
#include <memory>

#include "glwpp/ctx/data/VertexArray.hpp"
#include "glwpp/ctx/Window.hpp"

namespace glwpp {

template<class V>
class Model {
friend class Renderer;

public:
    template<class I>
    Model(const ctx::Window &window,
          const std::vector<V> &vertices,
          const std::vector<I> &indices) :
        _window(window){
        window.gl_context.push([&_vert_arr](){
            _vert_arr = std::make_unique<std::unique_ptr<ctx::VertexArray<V>>>(vertices, indices);
        });
    }

    // inline void draw(DrawModeGL mode){
    //     _window.gl_context.push([&_vert_arr, &mode](){
    //         _vert_arr->draw(mode);
    //     });
    // }

private:
    const ctx::Window &_window;
    std::unique_ptr<ctx::VertexArray<V>> _vert_arr;

};

}