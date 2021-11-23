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
                mouse->enter();
            } else {
                mouse->leave();
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
                mouse->press(static_cast<MouseBtn>(btn), mode);
            } else if (pressed == GLFW_RELEASE) {
                mouse->release(static_cast<MouseBtn>(btn), mode);
            } 
        }
    };
}

Mouse::Mouse(){
    _watcher = make_sptr<Watcher>();
}

Mouse::~Mouse(){
    _links.remove(this);
}

bool Mouse::capture(std::weak_ptr<Context> wctx, bool flag){
    auto ctx = wctx.lock();
    if (!ctx) return false;

    ctx->onLoopStart().push_back(_watcher, [this, wctx, flag](){
        auto ctx = wctx.lock();
        if (!ctx) return EventAction::Stop;

        if (flag){
            auto mouses = _links.get(ctx->getGlfwWindow());
            _links.add(ctx->getGlfwWindow(), this);

            if (!mouses){
                glfwSetCursorEnterCallback(ctx->getGlfwWindow(), _glfwMouseEnterCallback);
                glfwSetCursorPosCallback(ctx->getGlfwWindow(), _glfwMouseMoveCallback);
                glfwSetMouseButtonCallback(ctx->getGlfwWindow(), _glfwMouseBtnCallback);
            }
        } else {
            _links.remove(ctx->getGlfwWindow(), this);
        }
        
        return EventAction::Stop;
    });

    ctx->onDestroy().push_back(_watcher, [](Context& ctx){
        _links.remove(ctx.getGlfwWindow());
        return EventAction::Stop;
    });

    return true;
}

void Mouse::press(MouseBtn btn, KeyModeFlags modes){
    _down[btn] = true;
    _onPress.emit(true, *this, btn, modes);
}

void Mouse::release(MouseBtn btn, KeyModeFlags modes){
    _down.erase(btn);
    _onRelease.emit(true, *this, btn, modes);
}

void Mouse::move(double x, double y){
    _x = x;
    _y = y;
    _onMove.emit(true, *this, x, y);
}

void Mouse::enter(){
    _onEnter.emit(true, *this);
}

void Mouse::leave(){
    _onLeave.emit(true, *this);
}

bool Mouse::is_down(MouseBtn btn) const {
    return _down.find(btn) != _down.end();
}

glwpp::WEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> Mouse::onPress(){
    return _onPress;
}

glwpp::WEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> Mouse::onRelease(){
    return _onRelease;
}

glwpp::WEvent<const Mouse&, const double&, const double&> Mouse::onMove(){
    return _onMove;
}

glwpp::WEvent<const Mouse&> Mouse::onEnter(){
    return _onEnter;
}

glwpp::WEvent<const Mouse&> Mouse::onLeave(){
    return _onLeave;
}
