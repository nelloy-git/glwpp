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
    _captures = std::make_shared<CmdWatcher>();
}

Mouse::~Mouse(){
    _links.remove(this);
}

bool Mouse::capture(std::weak_ptr<Context> wctx, bool flag){
    auto ctx = wctx.lock();
    if (!ctx) return false;

    // ctx->push(_captures, [this, wctx, flag](){
    //     auto ctx = wctx.lock();
    //     if (!ctx) return CmdAct::Stop;

    //     if (flag){
    //         auto mouses = _links.get(ctx->getGlfwWindow());
    //         _links.add(ctx->getGlfwWindow(), this);

    //         if (!mouses){
    //             glfwSetCursorEnterCallback(ctx->getGlfwWindow(), _glfwMouseEnterCallback);
    //             glfwSetCursorPosCallback(ctx->getGlfwWindow(), _glfwMouseMoveCallback);
    //             glfwSetMouseButtonCallback(ctx->getGlfwWindow(), _glfwMouseBtnCallback);
    //         }
    //     } else {
    //         _links.remove(ctx->getGlfwWindow(), this);
    //     }
        
    //     return CmdAct::Stop;
    // });

    // ctx->onDestroy.pushBack(_captures, [](Context& ctx){
    //     _links.remove(ctx.getGlfwWindow());
    //     return CmdAct::Stop;
    // });

    return true;
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