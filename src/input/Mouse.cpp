#include "glwpp/input/Mouse.hpp"

#include "glwpp/utils/LinkMap.hpp"

using namespace glwpp::input;

namespace {
    glwpp::LinkMap<GLFWwindow, Mouse> _links;

    void _glfwMouseEnterCallback(GLFWwindow* glfw_win, int entered){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto mouse : *links){
            if (entered == GLFW_TRUE){
                mouse->onEnter.emit(*mouse);
            } else {
                mouse->onLeave.emit(*mouse);
            }
        }
    };

    void _glfwMouseMoveCallback(GLFWwindow* glfw_win, double x, double y){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto mouse : *links){
            mouse->move(x, y);
        }
    };

    void _glfwMouseBtnCallback(GLFWwindow* glfw_win, int btn, int pressed, int mode){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto mouse : *links){
            if (pressed == GLFW_PRESS){
                mouse->press(static_cast<glwpp::MouseBtn>(btn), mode);
            } else if (pressed == GLFW_RELEASE) {
                mouse->release(static_cast<glwpp::MouseBtn>(btn), mode);
            } 
        }
    };
}

Mouse::Mouse(){
}

Mouse::~Mouse(){
    _links.remove(this);
}

void Mouse::capture(Context &ctx, bool flag){
    ctx.cmd_queue.push([&](){
        if (flag){
            auto mouses = _links.get(ctx);
            _links.add(ctx, this);

            if (!mouses){
                glfwSetCursorEnterCallback(ctx, _glfwMouseEnterCallback);
                glfwSetCursorPosCallback(ctx, _glfwMouseMoveCallback);
                glfwSetMouseButtonCallback(ctx, _glfwMouseBtnCallback);
            }
        } else {
            _links.remove(this);
        }
    });
}

void Mouse::press(MouseBtn btn, KeyModeFlags modes){
    _down[btn] = true;
    onPress.emit(*this, btn, modes);
}

void Mouse::release(MouseBtn btn, KeyModeFlags modes){
    _down.erase(btn);
    onRelease.emit(*this, btn, modes);
}

void Mouse::move(double x, double y){
    _x = x;
    _y = y;
    onMove.emit(*this, x, y);
}

bool Mouse::isDown(MouseBtn btn) const {
    return _down.find(btn) != _down.end();
}