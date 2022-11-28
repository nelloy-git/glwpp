#pragma once

#include "BS_thread_pool.hpp"

#include "gl/GlDirect.hpp"
#include "gl/GlIndirect.hpp"
#include "utils/Event.hpp"
#include "utils/Export.hpp"

struct GLFWwindow;

namespace glwpp {

class Context {
    const std::shared_ptr<BS::thread_pool> _gl_thread;
    std::thread::id _gl_thread_id;
public:
    struct Parameters {
        std::string title;
        int width;
        int height;
        int fps;
    };

    EXPORT Context(const Parameters& params);
    virtual ~Context();

    const std::shared_ptr<GLFWwindow>& getGlfw();

    EXPORT std::future<void> run();
    EXPORT const std::thread::id& getGlThreadId() const;

    enum class IsGlThread {
        True,
        False,
        Unknown
    };

    template<IsGlThread status = IsGlThread::Unknown>
    EXPORT GL::Gl& gl(){
        if constexpr (status == IsGlThread::True){
            return _gl_direct;
        } else if constexpr (status == IsGlThread::False){
            return _gl_indirect;
        } else {
            if (std::this_thread::get_id() == _gl_thread_id){
                return _gl_direct;
            } else {
                return _gl_indirect;
            }
        }
    }

    using ms = std::chrono::milliseconds;
    EXPORT Event<Context*, const ms&>& getOnStartEvent();
    EXPORT Event<Context*, const ms&>& getOnRunEvent();

    // Event<Context*> onDetsroy;

    // Non-gl thread
    // Event<Context*, int, int> onWindowMove;
    // Event<Context*, int, int> onWinResize;
    // Event<Context*> onWinClose;
    // Event<Context*> onWinRefresh;
    // Event<Context*, bool> onWinIconify;
    // Event<Context*, bool> onWinMaximize;
    // Event<Context*, float, float> onWinScale;
    // Event<Context*, int, int> onFramebufferResize;

    // Event<Context*, bool> onCursorFocus;
    // Event<Context*, bool> onCursorEnter;
    // Event<Context*, double, double> onCursorMove;
    // Event<Context*, Button, Action, ModFlags> onCursorButton;
    // Event<Context*, double, double> onCursorScroll;

    // const std::shared_ptr<Event<const std::shared_ptr<Context>, const int, const int, const int, const int>> onKey;
    // Event<Context*, unsigned int, ModFlags> onChar;
protected:
    
private:
    static std::atomic<unsigned int>& _glfwWindowsCounter();

    std::shared_ptr<GLFWwindow> _window;

    Parameters _params;
    std::chrono::steady_clock::time_point _init_time;
    std::chrono::steady_clock::time_point _last_start_time;
    std::chrono::steady_clock::time_point _last_finish_time;

    GL::GlDirect _gl_direct;
    GL::GlIndirect _gl_indirect;
    Event<Context*, const ms&> _on_start_gl;
    Event<Context*, const ms&> _on_run_gl;
    Event<Context*, const ms&> _on_finish_gl;

    void _initGl(const Parameters& params);

    // template<auto setter, class ... Args>
    // void _bindGlfwCallback(Event<Context*, Args...> &event){
    //     std::function<void(glfw::Window*, Args...)> func = [this, &event](glfw::Window*, Args... args){
    //         event.emit(this, args...);
    //     };
    //     (this->_glfw_window.get()->*setter)(func);
    // };
};



} // namespace nglpmt