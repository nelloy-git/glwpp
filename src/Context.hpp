#pragma once

#include <map>
#include <memory>
#include <typeinfo>
#include <type_traits>

#include "BS_thread_pool.hpp"

#include "utils/Event.hpp"
#include "utils/Export.hpp"
#include "utils/Value.hpp"

struct GLFWwindow;

namespace glwpp {

class GLapi;

enum class IsGlThread {
    True,
    False,
    Unknown
};

class Context : public std::enable_shared_from_this<Context> {
    const std::shared_ptr<BS::thread_pool> _gl_thread;
    std::thread::id _gl_thread_id;

public:    
    using time = std::chrono::milliseconds;

    struct Config {
        std::string title;
        int width;
        int height;
        int fps;
    };

    static constexpr int PRIORITY_DEFAULT = 0;
    static constexpr int PRIORITY_MIN = std::numeric_limits<int>::min() + 1;
    static constexpr int PRIORITY_MAX = std::numeric_limits<int>::max() - 1;

    EXPORT static Value<Context> Make(const Config& config, const SrcLoc src_loc = SrcLoc{});
    Context(const Context&) = delete;
    Context(Context&&) = delete;
    EXPORT virtual ~Context();

    EXPORT GLapi& gl() const;

    Event<Context&, const time&> event_on_run_gl;
    Event<Context&, const time&> event_after_run_nongl;
    Event<Context&, const time&> event_on_destroy_gl;
    Event<Context&, const time&> event_on_destroy_nongl;

    EXPORT std::shared_future<void> run();
    EXPORT GLFWwindow& getGlfw();
    EXPORT const std::thread::id& getGlThreadId() const;

protected:
    EXPORT Context(const Config& params, const SrcLoc& src_loc = SrcLoc{});
    
private:
    std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> _window;
    std::shared_ptr<GLapi> _gl_api;

    Config _config;
    std::chrono::steady_clock::time_point _init_time;
    std::chrono::steady_clock::time_point _last_start_time;
    std::chrono::steady_clock::time_point _last_finish_time;

    void _init();
    void _initGlfwWindow();
    void _initGLapi();
    void _initDebug();

    static std::atomic<unsigned int>& _glfwWindowsCounter();
};

} // namespace nglpmt