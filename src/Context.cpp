#include "Context.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "GLapi.hpp"
#include "utils/GlobalThreadPool.hpp"

using namespace glwpp;

namespace {

const char* glGetErrorString(GLenum error){
    switch (error)
    {
    case GL_NO_ERROR:          return "No Error";
    case GL_INVALID_ENUM:      return "Invalid Enum";
    case GL_INVALID_VALUE:     return "Invalid Value";
    case GL_INVALID_OPERATION: return "Invalid Operation";
    case GL_INVALID_FRAMEBUFFER_OPERATION: return "Invalid Framebuffer Operation";
    case GL_OUT_OF_MEMORY:     return "Out of Memory";
    case GL_STACK_UNDERFLOW:   return "Stack Underflow";
    case GL_STACK_OVERFLOW:    return "Stack Overflow";
    case GL_CONTEXT_LOST:      return "Context Lost";
    default:                   return "Unknown Error";
    }
}

static void APIENTRY glDebugOutput(GLenum source, 
                                   GLenum type, 
                                   unsigned int id, 
                                   GLenum severity, 
                                   GLsizei length, 
                                   const char *message, 
                                   const void *userParam){
    auto& gl = *static_cast<const GLapi*>(userParam);
                                
    // ignore non-significant error/warning codes
    if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; 

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message "<< glGetErrorString(id) << "(" << id << "): " <<  message << std::endl;

    switch (source){
        case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
        case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
        case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type){
        case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break; 
        case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
        case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
        case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;
    
    switch (severity){
        case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
        case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
        case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << gl.getLastSrcLoc().to_string_full().c_str() << std::endl;
    std::cout << std::endl;
}

}

Value<Context> Context::Make(const Config& config, const SrcLoc src_loc){
    static constexpr auto CONV = [](const std::tuple<Context*, const time>& input){
        return std::forward_as_tuple<Context&, const Context::time&>(*std::get<0>(input), std::get<1>(input));
    };

    auto ctx = Value<Context>::Make(new Context(config, src_loc));
    ctx->event_on_run_gl.add<[](Context& ctx, const time& ms){
        try {
            ctx._init();
        } catch (const std::exception& err){
            std::cout << "Critical ERROR: " << err.what() << std::endl;
        }
        return false;
    }>(std::numeric_limits<int>::max(), src_loc);
    ctx->event_on_run_gl.emit_convertable<CONV>(ctx.get(), time(0)).wait();
    ctx->event_on_run_gl.add<[](Context& ctx, const time&){
        glfwPollEvents();
        glfwSwapBuffers(ctx._window.get());
        ctx.gl().Clear<TState::True>(GL_COLOR_BUFFER_BIT, SrcLoc{});
        return true;
    }>(std::numeric_limits<int>::max(), src_loc);

    return ctx;
}

Context::Context(const Config& params, const SrcLoc& src_loc) :
    _gl_thread(new BS::thread_pool(1)),

    event_on_run_gl(_gl_thread),
    event_after_run_nongl(GlobalThreadPool::get()),
    event_on_destroy_gl(_gl_thread),
    event_on_destroy_nongl(GlobalThreadPool::get()),

    _config(params),
    _window(nullptr, [](GLFWwindow*){}),

    _init_time(std::chrono::steady_clock::now()),
    _last_start_time(std::chrono::steady_clock::now()),
    _last_finish_time(std::chrono::steady_clock::now()){
}

Context::~Context(){
    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<time>(now - _init_time);

    static constexpr auto CONV = [](const std::tuple<Context*, const time>& input){
        return std::forward_as_tuple<Context&, const Context::time&>(*std::get<0>(input), std::get<1>(input));
    };

    auto future_gl = event_on_destroy_gl.emit_convertable<CONV>(this, dt);
    auto future_nongl = event_on_destroy_nongl.emit_convertable<CONV>(this, dt);

    future_gl.wait();
    future_nongl.wait();
}

GLapi& Context::gl() const {
    return *_gl_api;
}

std::shared_future<void> Context::run(){
    static constexpr auto CONV = [](const std::tuple<std::shared_ptr<Context>, const time>& input){
        return std::forward_as_tuple<Context&, const Context::time&>(*std::get<0>(input), std::get<1>(input));
    };

    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<time>(now - _last_start_time);
    _last_start_time = now;

    std::shared_future<void> run_gl_future = event_on_run_gl.emit_convertable<CONV>(this->shared_from_this(), dt);
    event_after_run_nongl.lock();
    event_after_run_nongl.add<true>(std::numeric_limits<int>::max(), [run_gl_future](Context&, const time&){
        run_gl_future.wait();
        return false;
    });
    auto run_nongl_future = event_after_run_nongl.emit_convertable<CONV, true>(this->shared_from_this(), dt);
    event_after_run_nongl.unlock();

    return run_nongl_future;
}

GLFWwindow& Context::getGlfw(){
    return *_window;
}

const std::thread::id& Context::getGlThreadId() const {
    return _gl_thread_id;
}


void Context::_init(){
    _gl_thread_id = std::this_thread::get_id();
    _initGlfwWindow();
    _initGLapi();
    _initDebug();
}

void Context::_initGlfwWindow(){
    if (_glfwWindowsCounter() == 0 && !glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    ++_glfwWindowsCounter();

    std::vector<std::pair<int, int>> hints = {
        // {GLFW_VERSION_MAJOR, 3},
        // {GLFW_VERSION_MINOR, 0},
        {GLFW_CONTEXT_VERSION_MAJOR, 4},
        {GLFW_CONTEXT_VERSION_MINOR, 6},
        {GLFW_REFRESH_RATE, _config.fps},
        {GLFW_OPENGL_DEBUG_CONTEXT, true}
    };

    for (auto& hint : hints){
        glfwWindowHint(hint.first, hint.second);
    }

    _window = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>(
        glfwCreateWindow(_config.width, _config.height, _config.title.c_str(), NULL, NULL),
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
    glfwSwapInterval(0); // Disable vsync
}

void Context::_initGLapi(){
    _gl_api = std::make_shared<GLapi>(*this);
    if (!_gl_api->loadGladGLContext<TState::True>(glfwGetProcAddress)){
        throw std::runtime_error("Failed to initialize GLapi.");
    }
}

void Context::_initDebug(){
    std::cout << "GL thread: " << std::this_thread::get_id() << std::endl;
    // std::cout << "Version: " << ver << std::endl;
    int flags;
    _gl_api->GetIntegerv<TState::True>(GL_CONTEXT_FLAGS, &flags, SrcLoc{});
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT){
        std::cout << "glDebugOutput enabled" << std::endl;
        _gl_api->Enable<TState::True>(GL_DEBUG_OUTPUT, SrcLoc{});
        _gl_api->Enable<TState::True>(GL_DEBUG_OUTPUT_SYNCHRONOUS, SrcLoc{}); 
        _gl_api->DebugMessageCallback<TState::True>(glDebugOutput, _gl_api.get(), SrcLoc{});
        _gl_api->DebugMessageControl<TState::True>(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE, SrcLoc{});
    }
    
    _gl_api->ClearColor<TState::True>(0.2f, 0.9f, 0.2f, 1.f, SrcLoc{});
    _gl_api->Clear<TState::True>(GL_COLOR_BUFFER_BIT, SrcLoc{});
}

std::atomic<unsigned int>& Context::_glfwWindowsCounter(){
    static std::atomic<unsigned int> counter(0);
    return counter;
}