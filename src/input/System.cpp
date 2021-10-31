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
            system->onClose.emit(*system);
        }
    }
}

SystemCall::SystemCall() {
}

SystemCall::~SystemCall(){
    _links.remove(this);
}

void SystemCall::capture(Context &ctx, bool flag){
    ctx.cmd_queue.push([&](){
        if (flag){
            auto systems = _links.get(ctx);
            _links.add(ctx, this);
            
            if (!systems){
                glfwSetWindowCloseCallback(ctx, _gltfCloseCallback);
            }
        } else {
            _links.remove(this);
        }
    });
}