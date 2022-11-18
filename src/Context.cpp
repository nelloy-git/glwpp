#include "Context.hpp"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "gl/GlBase.hpp"
#include "utils/GlobalThreadPool.hpp"

using namespace glwpp;

std::atomic<unsigned int>& Context::_glfwWindowsCounter(){
    static std::atomic<unsigned int> counter(0);
    return counter;
}

namespace {
    void debugGl(const SrcLoc& src_loc){
        while (auto err = glGetError()){
            std::string s_err = "UNKNOWN";
            switch (err){
            case GL_INVALID_ENUM: s_err = "GL_INVALID_ENUM"; break;
            case GL_INVALID_OPERATION : s_err = "GL_INVALID_OPERATION "; break;
            case GL_OUT_OF_MEMORY : s_err = "GL_OUT_OF_MEMORY "; break;            
            default: break;
            }
            std::cout << "ERROR " << s_err.c_str() << " " << err << std::endl << src_loc.to_string().c_str() << std::endl;
        }
    }
}

Context::Context(const Parameters& params) :
    _gl_thread(new BS::thread_pool(1)),

    _init_time(std::chrono::steady_clock::now()),
    _last_start_time(std::chrono::steady_clock::now()),
    _last_finish_time(std::chrono::steady_clock::now()),

    _gl_direct(&debugGl),
    _gl_indirect(*this, &debugGl),
    _on_start_gl(_gl_thread),
    _on_run_gl(_gl_thread),
    _on_finish_gl(_gl_thread){

    _gl_thread->submit([this, &params](){
        try {
            _initGl(params);
        } catch (const std::exception& err){
            std::cout << "Critical ERROR: " << err.what() << std::endl;
        }
    }).wait();

    _on_start_gl.addActionQueued([window = _window](){
        glfwPollEvents();
        glfwSwapBuffers(window.get());
        return true;
    });
    
}

Context::~Context(){
}

std::future<void> Context::run(){
    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(now - _last_start_time);
    _last_start_time = now;

    _on_start_gl.emitQueued(this, dt);
    _on_run_gl.emitQueued(this, dt);
    return _on_finish_gl.emitQueued(this, dt);
}

const std::thread::id& Context::getGlThreadId() const {
    return _gl_thread_id;
}

Event<Context*, const Context::ms&>& Context::getOnStartEvent(){
    return _on_start_gl;
}

Event<Context*, const Context::ms&>& Context::getOnRunEvent(){
    return _on_run_gl;
}

void Context::_initGl(const Parameters& params){
    _gl_thread_id = std::this_thread::get_id();

    if (_glfwWindowsCounter() == 0 && !glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    ++_glfwWindowsCounter();

    std::vector<std::pair<int, int>> hints = {
        // {GLFW_VERSION_MAJOR, 3},
        // {GLFW_VERSION_MINOR, 0},
        {GLFW_CONTEXT_VERSION_MAJOR, 4},
        {GLFW_CONTEXT_VERSION_MINOR, 6},
        {GLFW_REFRESH_RATE, params.fps},
    };

    for (auto& hint : hints){
        glfwWindowHint(hint.first, hint.second);
    }

    _window = std::shared_ptr<GLFWwindow>(
        glfwCreateWindow(params.width, params.height, params.title.c_str(), NULL, NULL),
        [](GLFWwindow* window){
            glfwDestroyWindow(window);
            --_glfwWindowsCounter();
            if (_glfwWindowsCounter() == 0){
                glfwTerminate();
            }
        }
    );
    glfwSetWindowUserPointer(_window.get(), this);
    glfwMakeContextCurrent(_window.get());
    
    auto ver = gladLoadGL(glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }
    std::cout << "GL thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Version: " << ver << std::endl;
    
    glfwSetWindowPosCallback(_window.get(), [](GLFWwindow* window, int x, int y){
        auto ctx = static_cast<Context*>(glfwGetWindowUserPointer(window));
        // ctx->onWindowMove.emit(ctx, x, y);
    });

    glfwSetKeyCallback(_window.get(), [](GLFWwindow* window, int key, int scancode, int action, int mods){
        auto ctx = static_cast<Context*>(glfwGetWindowUserPointer(window));
        // ctx->onKey->emitQueued(ctx->shared_from_this(), key, scancode, action, mods);
    });


    // _bindGlfwCallback<&glfw::Window::setMoveCallback>(onWinMove);
    // _bindGlfwCallback<&glfw::Window::setResizeCallback>(onWinResize);
    // _bindGlfwCallback<&glfw::Window::setCloseCallback>(onWinClose);
    // _bindGlfwCallback<&glfw::Window::setRefreshCallback>(onWinRefresh);
    // _bindGlfwCallback<&glfw::Window::setIconifyCallback>(onWinIconify);
    // _bindGlfwCallback<&glfw::Window::setMaximizeCallback>(onWinMaximize);
    // _bindGlfwCallback<&glfw::Window::setScaleCallback>(onWinScale);
    // _bindGlfwCallback<&glfw::Window::setFramebufferResizeCallback>(onFramebufferResize);

    // _bindGlfwCallback<&glfw::Window::setCursorFocusCallback>(onCursorFocus);
    // _bindGlfwCallback<&glfw::Window::setCursorMoveCallback>(onCursorMove);
    // _bindGlfwCallback<&glfw::Window::setCursorEnterCallback>(onCursorEnter);
    // _bindGlfwCallback<&glfw::Window::setCursorButtonCallback>(onCursorButton);
    // _bindGlfwCallback<&glfw::Window::setCursorScrollCallback>(onCursorScroll);
    // _bindGlfwCallback<&glfw::Window::setKeyCallback>(onKey);
    // _bindGlfwCallback<&glfw::Window::setCharCallback>(onChar);
}