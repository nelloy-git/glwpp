#include "glwpp/input/System.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/utils/LinkMap.hpp"

using namespace glwpp::input;

namespace {
    glwpp::LinkMap<GLFWwindow, SystemCall> _links;

    void _gltfCloseCallback(GLFWwindow* glfw_win){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto system : *links){
            system->close();
        }
    }
}

SystemCall::SystemCall(){
    _watcher = std::make_shared<Watcher>();
}

SystemCall::~SystemCall(){
    _links.remove(this);
}

bool SystemCall::capture(std::weak_ptr<Context> wctx, bool flag){
    auto ctx = wctx.lock();
    if (!ctx) return false;

    ctx->onLoopStart().push_back(_watcher, [this, wctx, flag](){
        auto ctx = wctx.lock();
        if (!ctx) return EventAction::Stop;

        if (flag){
            auto systems = _links.get(ctx->getGlfwWindow());
            _links.add(ctx->getGlfwWindow(), this);
            
            if (!systems){
                glfwSetWindowCloseCallback(ctx->getGlfwWindow(), _gltfCloseCallback);
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

void SystemCall::close(){
    _onClose.emit(true, *this);
}

glwpp::WEvent<SystemCall&> SystemCall::onClose(){
    return _onClose;
}