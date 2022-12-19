#pragma once

#include <memory>
#include <typeinfo>
#include <type_traits>

#include "BS_thread_pool.hpp"

#include "utils/Event.hpp"
#include "utils/Export.hpp"
#include "utils/Value.hpp"

#include "GLapi.hpp"

struct GLFWwindow;

namespace glwpp {

namespace detail {

template<typename T, typename... Ts>
constexpr bool contains()
{ return std::disjunction_v<std::is_same<T, Ts>...>; }

template<typename ... Ts>
static constexpr bool is_values(){
    return std::conjunction_v<is_instance<std::remove_const_t<std::remove_reference_t<Ts>>, Value>...>;
}

template<typename V>
constexpr bool is_val = is_instance<std::remove_const_t<std::remove_reference_t<V>>, Value>::value;

template<typename V, std::enable_if_t<(is_val<V>), bool> = true>
static auto Val(const V& val){
    return glwpp::Value<std::remove_reference_t<V>::type>(val);
}

template<typename V, std::enable_if_t<(!is_val<V>), bool> = true>
static auto Val(const V& val){
    return glwpp::Value<std::remove_reference_t<V>>(val);
}

};

class Context : public std::enable_shared_from_this<Context> {
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

    GLapi gl;

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
    inline auto addCallCustom(auto&& func, auto&&... args){
        static_assert(std::is_invocable_v<decltype(func), Context&, decltype(args)...>, "function must be invokable with (Context&, args...)");
        using R = std::invoke_result_t<decltype(func), Context&, decltype(args)...>;

        if constexpr (is_gl_thread == IsGlThread::True){
            return _addCallCustomFromGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
        } else if constexpr (is_gl_thread == IsGlThread::False){
            return _addCallCustomFromNonGlThread(Value(func), Value(args)...);
        } else {
            if (std::this_thread::get_id() == _gl_thread_id){
                return _addCallCustomFromGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
            } else {
                return _addCallCustomFromNonGlThread(Value(func), Value(args)...);
            }
        }
    }

    template<auto F, Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    inline auto addCallGl(auto&&... args){
        if constexpr (is_gl_thread == IsGlThread::True){
            return _addCallGlFromGlThread<F>(std::forward<decltype(args)>(args)...);
        } else if constexpr (is_gl_thread == IsGlThread::False){
            return _addCallGlFromNonGlThread<F>(Value(args)...);
        } else {
            if (std::this_thread::get_id() == _gl_thread_id){
                return _addCallGlFromGlThread<F>(std::forward<decltype(args)>(args)...);
            } else {
                return _addCallGlFromNonGlThread<F>(Value(args)...);
            }
        }
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    inline auto addition(auto&&... args){
        return addCallGl<[](GLapi&, auto&&... args){return (args + ...);}>(std::forward<decltype(args)>(args)...);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    inline auto multiplication(auto&&... args){
        return addCallGl<[](GLapi&, auto&&... args){return (args * ...);}>(std::forward<decltype(args)>(args)...);
    }

protected:
    
private:
    static std::atomic<unsigned int>& _glfwWindowsCounter();

    std::shared_ptr<GLFWwindow> _window;
    std::unique_ptr<GLapi> _gl;

    Parameters _params;
    std::chrono::steady_clock::time_point _init_time;
    std::chrono::steady_clock::time_point _last_start_time;
    std::chrono::steady_clock::time_point _last_finish_time;

    Event<Context*, const ms&> _on_start_gl;
    Event<Context*, const ms&> _on_run_gl;
    Event<Context*, const ms&> _on_finish_gl;

    void _initGl(const Parameters& params);

    inline auto _addCallCustomFromGlThread(auto&& func, auto&&... args){
        using R = std::invoke_result_t<decltype(func), Context&, decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            func(*this, std::forward<decltype(args)>(args)...);
        } else {
            return Value<R>(func(*this, std::forward<decltype(args)>(args)...));
        }
    }

    inline auto _addCallCustomFromNonGlThread(auto&& func, auto&&... args){
        static_assert(detail::is_values<decltype(func)>(), "function must be glwpp::Value<F>");
        static_assert(detail::is_values<decltype(args)...>(), "arguments must be glwpp::Value<T>");

        using R = std::invoke_result_t<decltype(*func), Context&, decltype(args)...>;
        if constexpr (std::is_same_v<R, void>){
            auto pair = getOnRunEvent().addActionQueued([func, args...](Context* ctx, const ms&){
                (*func)(*ctx, args...);
                return false;
            });
        } else {
            Value<std::remove_const_t<R>> result;
            auto pair = getOnRunEvent().addActionQueued([result, func, args...](Context *ctx, const ms&){
                *result = (*func)(*ctx, args...);
                return false;
            });
            return result;
        }
    }

    template<auto F>
    inline auto _addCallGlFromGlThread(auto&&... args){
        static constexpr bool first_is_gl_api = std::is_invocable_v<decltype(F), GLapi&, decltype(args)...>;
        static constexpr bool first_is_context = std::is_invocable_v<decltype(F), Context&, decltype(args)...>;

        if constexpr (first_is_gl_api){
            using R = std::invoke_result_t<decltype(F), GLapi&, decltype(args)...>;
            if constexpr (std::is_member_function_pointer_v<decltype(F)>){
                if constexpr (std::is_same_v<R, void>){
                    (gl.*F)(std::forward<decltype(args)>(args)...);
                } else {
                    return Value<R>((gl.*F)(std::forward<decltype(args)>(args)...));
                }
            } else {
                if constexpr (std::is_same_v<R, void>){
                    F(gl, std::forward<decltype(args)>(args)...);
                } else {
                    return Value<R>(F(gl, std::forward<decltype(args)>(args)...));
                }
            }
        } else if constexpr (first_is_context){
            using R = std::invoke_result_t<decltype(F), Context&, decltype(args)...>;
            if constexpr (std::is_same_v<R, void>){
                F(*this, std::forward<decltype(args)>(args)...);
            } else {
                return Value<R>(F(*this, std::forward<decltype(args)>(args)...));
            }
        } else {
            static_assert(false, "F must be callable member of glwpp::GLapi or callable F(GLapi&, ...) or F(Context&, ...)");
        }
    }

    template<auto F>
    inline auto _addCallGlFromNonGlThread(auto&&... args){
        static constexpr bool first_is_gl_api = std::is_invocable_v<decltype(F), GLapi&, decltype(args)...>;
        static constexpr bool first_is_context = std::is_invocable_v<decltype(F), Context&, decltype(args)...>;
        
        static_assert(detail::is_values<decltype(args)...>(), "arguments must be glwpp::Value<T>");
        
        if constexpr (first_is_gl_api){
            using R = std::invoke_result_t<decltype(F), GLapi&, decltype(args)...>;
            if constexpr (std::is_member_function_pointer_v<decltype(F)>){
                if constexpr (std::is_same_v<R, void>){
                    auto pair = getOnRunEvent().addActionQueued([args...](Context* ctx, const ms&){
                        (ctx->gl.*F)(args...);
                        return false;
                    });
                } else {
                    Value<std::remove_const_t<R>> result;
                    auto pair = getOnRunEvent().addActionQueued([result, args...](Context *ctx, const ms&){
                        *result = (ctx->gl.*F)(args...);
                        return false;
                    });
                    return result;
                }
            } else {
                if constexpr (std::is_same_v<R, void>){
                    auto pair = getOnRunEvent().addActionQueued([args...](Context* ctx, const ms&){
                        F(ctx->gl, args...);
                        return false;
                    });
                } else {
                    Value<std::remove_const_t<R>> result;
                    auto pair = getOnRunEvent().addActionQueued([result, args...](Context *ctx, const ms&){
                        *result = F(ctx->gl, args...);
                        return false;
                    });
                    return result;
                }
            }
        } else if constexpr (first_is_context){
            using R = std::invoke_result_t<decltype(F), Context&, decltype(args)...>;
            if constexpr (std::is_same_v<R, void>){
                auto pair = getOnRunEvent().addActionQueued([args...](Context* ctx, const ms&){
                    F(*ctx, args...);
                    return false;
                });
            } else {
                Value<std::remove_const_t<R>> result;
                auto pair = getOnRunEvent().addActionQueued([result, args...](Context *ctx, const ms&){
                    *result = F(*ctx, args...);
                    return false;
                });
                return result;
            }
        } else {
            static_assert(false, "F must be callable member of glwpp::GLapi or callable F(GLapi&, ...) or F(Context&, ...)");
        }
    }
};

} // namespace nglpmt