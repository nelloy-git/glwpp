#pragma once

#include <string>
#include <unordered_map>
#include <atomic>
#include <thread>
#include <mutex>

#include "glwpp/utils/CmdLoop.hpp"
#include "glwpp/utils/event/Event.hpp"

class GLFWwindow;

namespace glwpp {

class Context {
public:
    struct Parameters {
        int gl_major_ver;
        int gl_minor_ver;

        size_t width;
        size_t height;
        std::string title;
    };

    Context(const Parameters &params);
    virtual ~Context();

    GLFWwindow *getGlfwWindow(){return _glfw_window;}
    static GLFWwindow *getGlfwWindow(Context& ctx){return ctx.getGlfwWindow();}
    static Context *getContext(GLFWwindow *win){
        auto iter = _linked.find(win);
        return iter == _linked.end() ? nullptr : iter->second;
    };

    WEvent<Context&> onLoopStart();
    WEvent<Context&> onLoopRun();
    WEvent<Context&> onLoopEnd();
    WEvent<Context&> onDestroy();
    
private:
    std::function<void(CmdLoop&)> _init_gl_thread;
    std::function<void(CmdLoop&)> _final_gl_thread;

    CmdLoop _loop;
    sptr<Watcher> _watcher;
    SEvent<Context&> _onLoopStart;
    SEvent<Context&> _onLoopRun;
    SEvent<Context&> _onLoopEnd;
    SEvent<Context&> _onDestroy;

    GLFWwindow *_glfw_window;
    Parameters _params;

    void _glInit();
    void _glFinal();

    static std::unordered_map<GLFWwindow*, Context*> _linked;
};



}