#pragma once

#include "glwpp/ctx/Camera.hpp"

namespace glwpp {

class Renderer {
public:
    Renderer();
    virtual ~Renderer(); 

    Camera camera();

private:
    Camera _camera;
};

} // namespace glwpp