#include "glwpp/input/Keyboard.hpp"

#include "glwpp/utils/LinkMap.hpp"

using namespace glwpp::input;

namespace {
    glwpp::LinkMap<GLFWwindow, Keyboard> _links;

    void _gltfKeyCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mode){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto kb : *links){
            if (action == GLFW_PRESS){
                kb->press(static_cast<glwpp::Key>(key), mode);
            } else if (action == GLFW_RELEASE){
                kb->release(static_cast<glwpp::Key>(key), mode);
            }
        }
    }
}

Keyboard::Keyboard() {
}

Keyboard::~Keyboard(){
    _links.remove(this);
}

void Keyboard::capture(Context &ctx, bool flag){
    ctx.cmd_queue.push([&](){
        if (flag){
            auto keyboards = _links.get(ctx);
            _links.add(ctx, this);

            if (!keyboards){
                glfwSetKeyCallback(ctx, _gltfKeyCallback);
            }
        } else {
            _links.remove(this);
        }
    });
}

void Keyboard::press(Key key, KeyModeFlags mods){
    _down[key] = true;
    onPress.emit(*this, key, mods);
}

void Keyboard::release(Key key, KeyModeFlags mods){
    _down.erase(key);
    onRelease.emit(*this, key, mods);
}

bool Keyboard::isDown(Key key) const {
    return _down.find(key) != _down.end();
}