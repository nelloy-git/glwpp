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

    bool startUpdate();
    void waitUpdate();

    WEvent<Context&> onLoopStart();
    WEvent<Context&> onLoopRun();
    WEvent<Context&> onLoopEnd();
    WEvent<Context&> onDestroy();
    
private:
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
};



}