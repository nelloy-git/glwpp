#pragma once

#include <typeinfo>
#include <type_traits>

#include "BS_thread_pool.hpp"

#include "glad/gl.h"

#include "utils/Event.hpp"
#include "utils/Export.hpp"
#include "utils/Value.hpp"

struct GLFWwindow;

namespace glwpp {

template<typename T, typename... Ts>
constexpr bool contains()
{ return std::disjunction_v<std::is_same<T, Ts>...>; }

class Context {
    const std::shared_ptr<BS::thread_pool> _gl_thread;
    std::thread::id _gl_thread_id;

    template<typename ... Ts>
    static constexpr bool is_values(){
        return std::conjunction_v<is_instance<std::remove_const_t<std::remove_reference_t<Ts>>, Value>...>;
    }


public:
    struct Parameters {
        std::string title;
        int width;
        int height;
        int fps;
    };

    EXPORT Context(const Parameters& params);
    virtual ~Context();

    GladGLContext gl;
    EXPORT const std::shared_ptr<GLFWwindow>& getGlfw();

    EXPORT std::future<void> run();
    EXPORT const std::thread::id& getGlThreadId() const;

    using ms = std::chrono::milliseconds;
    EXPORT Event<Context*, const ms&>& getOnStartEvent();
    EXPORT Event<Context*, const ms&>& getOnRunEvent();

    enum class IsGlThread {
        True,
        False,
        Unknown
    };

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    auto addCallCustom(const SrcLoc& src_loc, const auto& func, const auto&... args){
        static_assert(std::is_invocable_v<decltype(func), Context&, decltype(args)...>, "function must be invokable with (Contexn&, args...)");
        static_assert(is_values<decltype(args)...>(), "arguments must be glwpp::Value<T>");

        if constexpr (is_gl_thread == IsGlThread::True){
            return _addCallCustomFromGlThread(src_loc, func, args...);
        } else if constexpr (is_gl_thread == IsGlThread::False){
            return _addCallCustomFromNonGlThread(src_loc, func, args...);
        } else {
            if (std::this_thread::get_id() == _gl_thread_id){
                return _addCallCustomFromGlThread(src_loc, func, args...);
            } else {
                return _addCallCustomFromNonGlThread(src_loc, func, args...);
            }
        }
    }

    template<auto GladGLContext::*F, Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    auto addCallGl(const SrcLoc& src_loc, const auto&... args){
        static_assert(std::is_invocable_v<decltype(gl.*F), decltype(args)...>, "F must be callable member of GladGlContext");
        static_assert(is_values<decltype(args)...>(), "arguments must be glwpp::Value<T>");

        if constexpr (is_gl_thread == IsGlThread::True){
            return _addCallGlFromGlThread<F>(src_loc, args...);
        } else if constexpr (is_gl_thread == IsGlThread::False){
            return _addCallGlFromNonGlThread<F>(src_loc, args...);
        } else {
            if (std::this_thread::get_id() == _gl_thread_id){
                return _addCallGlFromGlThread<F>(src_loc, args...);
            } else {
                return _addCallGlFromNonGlThread<F>(src_loc, args...);
            }
        }
    }

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

    Event<Context*, const ms&> _on_start_gl;
    Event<Context*, const ms&> _on_run_gl;
    Event<Context*, const ms&> _on_finish_gl;

    SrcLoc _last_src_loc;

    void _initGl(const Parameters& params);

    auto _addCallCustomFromGlThread(const SrcLoc& src_loc, const auto& func, const auto&... args){
        using R = std::invoke_result_t<decltype(func), Context&, decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            func(*this, args...);
        } else {
            return Value<R>(func(*this, args...));
        }
    }

    auto _addCallCustomFromNonGlThread(const SrcLoc& src_loc, const auto& func, const auto&... args){
        using R = std::invoke_result_t<decltype(func), Context&, decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            auto pair = getOnRunEvent().addActionQueued([func, args...](Context* ctx, const ms&){
                func(*ctx, args...);
                return false;
            });
        } else {
            Value<std::remove_const_t<R>> result;
            auto pair = getOnRunEvent().addActionQueued([result, func, args...](Context *ctx, const ms&){
                *result = func(*ctx, args...);
                return false;
            });
            return result;
        }
    }

    template<auto GladGLContext::*F>
    auto _addCallGlFromGlThread(const SrcLoc& src_loc, const auto&... args){
        using R = std::invoke_result_t<decltype(gl.*F), decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            (gl.*F)(args...);
        } else {
            return Value<R>((gl.*F)(args...));
        }
    }

    template<class T, typename U>
    constexpr static std::ptrdiff_t member_offset(U T::* member){
        return reinterpret_cast<std::ptrdiff_t>(&(reinterpret_cast<T const volatile*>(nullptr)->*member));
    }

    template<auto GladGLContext::*F>
    auto _addCallGlFromNonGlThread(const SrcLoc& src_loc, const auto&... args){
        using R = std::invoke_result_t<decltype(gl.*F), decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            auto pair = getOnRunEvent().addActionQueued([src_loc = std::move(src_loc), args...](Context* ctx, const ms&){
                ctx->_last_src_loc = src_loc;
                (ctx->gl.*F)(args...);
                return false;
            });
        } else {
            Value<std::remove_const_t<R>> result;
            auto pair = getOnRunEvent().addActionQueued([src_loc = std::move(src_loc), result, args...](Context *ctx, const ms&){
                ctx->_last_src_loc = src_loc;
                *result = (ctx->gl.*F)(args...);
                return false;
            });
            return result;
        }
    }


    // template<auto setter, class ... Args>
    // void _bindGlfwCallback(Event<Context*, Args...> &event){
    //     std::function<void(glfw::Window*, Args...)> func = [this, &event](glfw::Window*, Args... args){
    //         event.emit(this, args...);
    //     };
    //     (this->_glfw_window.get()->*setter)(func);
    // };
};

} // namespace nglpmt