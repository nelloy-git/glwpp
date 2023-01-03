#pragma once

#include <map>
#include <memory>
#include <typeinfo>
#include <type_traits>

#include "BS_thread_pool.hpp"

#include "utils/Event.hpp"
#include "utils/Export.hpp"

#include "GLapi.hpp"

struct GLFWwindow;

namespace glwpp {

enum class IsGlThread {
    True,
    False,
    Unknown
};

class Context : public std::enable_shared_from_this<Context> {
    const std::shared_ptr<BS::thread_pool> _gl_thread;
    std::thread::id _gl_thread_id;

public:
    using ms = std::chrono::milliseconds;

    static constexpr int PRIORITY_DEFAULT = 0;
    static constexpr int PRIORITY_MIN = std::numeric_limits<int>::min();
    static constexpr int PRIORITY_MAX = std::numeric_limits<int>::max();

    struct Parameters {
        std::string title;
        int width;
        int height;
        int fps;
    };

    EXPORT Context(const Parameters& params, const SrcLoc& src_loc = SrcLoc{});
    EXPORT virtual ~Context();

    GLapi gl;
    Event<Context&, const ms&> event_on_run_gl;
    Event<Context&, const ms&> event_after_run_nongl;
    Event<Context&, const ms&> event_on_destroy_gl;
    Event<Context&, const ms&> event_on_destroy_nongl;

    EXPORT std::shared_future<void> run();
    EXPORT const std::shared_ptr<GLFWwindow>& getGlfw();
    EXPORT const std::thread::id& getGlThreadId() const;

protected:
    
private:
    static std::atomic<unsigned int>& _glfwWindowsCounter();

    std::shared_ptr<GLFWwindow> _window;
    std::unique_ptr<GLapi> _gl;

    Parameters _params;
    std::chrono::steady_clock::time_point _init_time;
    std::chrono::steady_clock::time_point _last_start_time;
    std::chrono::steady_clock::time_point _last_finish_time;

    void _initGl(const Parameters& params);
};

} // namespace nglpmt