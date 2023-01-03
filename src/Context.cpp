#include "Context.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "utils/GlobalThreadPool.hpp"

using namespace glwpp;

namespace {
const char* glGetErrorString(GLenum error){
    switch (error)
    {
    case GLapi::GL_NO_ERROR:          return "No Error";
    case GLapi::GL_INVALID_ENUM:      return "Invalid Enum";
    case GLapi::GL_INVALID_VALUE:     return "Invalid Value";
    case GLapi::GL_INVALID_OPERATION: return "Invalid Operation";
    case GLapi::GL_INVALID_FRAMEBUFFER_OPERATION: return "Invalid Framebuffer Operation";
    case GLapi::GL_OUT_OF_MEMORY:     return "Out of Memory";
    case GLapi::GL_STACK_UNDERFLOW:   return "Stack Underflow";
    case GLapi::GL_STACK_OVERFLOW:    return "Stack Overflow";
    case GLapi::GL_CONTEXT_LOST:      return "Context Lost";
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
        case GLapi::GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
        case GLapi::GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
        case GLapi::GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
        case GLapi::GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
        case GLapi::GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
        case GLapi::GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type){
        case GLapi::GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
        case GLapi::GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
        case GLapi::GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break; 
        case GLapi::GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
        case GLapi::GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
        case GLapi::GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
        case GLapi::GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
        case GLapi::GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
        case GLapi::GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;
    
    switch (severity){
        case GLapi::GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
        case GLapi::GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
        case GLapi::GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
        case GLapi::GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << gl.getLastSrcLoc().to_string_full().c_str() << std::endl;
    std::cout << std::endl;
}
}

std::atomic<unsigned int>& Context::_glfwWindowsCounter(){
    static std::atomic<unsigned int> counter(0);
    return counter;
}

Context::Context(const Parameters& params, const SrcLoc& src_loc) :
    _gl_thread(new BS::thread_pool(1)),

    event_on_run_gl(_gl_thread),
    event_after_run_nongl(GlobalThreadPool::get()),
    event_on_destroy_gl(_gl_thread),
    event_on_destroy_nongl(GlobalThreadPool::get()),

    _init_time(std::chrono::steady_clock::now()),
    _last_start_time(std::chrono::steady_clock::now()),
    _last_finish_time(std::chrono::steady_clock::now()){

    _gl_thread->submit([this, &params](){
        try {
            _initGl(params);
        } catch (const std::exception& err){
            std::cout << "Critical ERROR: " << err.what() << std::endl;
        }
    }).wait();

    event_on_run_gl.add<[](Context& ctx, const ms&){
        glfwPollEvents();
        glfwSwapBuffers(ctx._window.get());
        ctx.gl.Clear(GLapi::GL_COLOR_BUFFER_BIT);
        return true;
    }>(PRIORITY_MAX, src_loc);
}

Context::~Context(){
    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(now - _init_time);

    static constexpr auto CONV = [](const std::tuple<Context*, const ms>& input){
        return std::forward_as_tuple<Context&, const Context::ms&>(*std::get<0>(input), std::get<1>(input));
    };

    auto future_gl = event_on_destroy_gl.emit_convertable<CONV>(this, dt);
    auto future_nongl = event_on_destroy_nongl.emit_convertable<CONV>(this, dt);

    future_gl.wait();
    future_nongl.wait();
}

std::shared_future<void> Context::run(){
    static constexpr auto CONV = [](const std::tuple<std::shared_ptr<Context>, const ms>& input){
        return std::forward_as_tuple<Context&, const Context::ms&>(*std::get<0>(input), std::get<1>(input));
    };

    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(now - _last_start_time);
    _last_start_time = now;

    std::shared_future<void> run_gl_future = event_on_run_gl.emit_convertable<CONV>(this->shared_from_this(), dt);
    event_after_run_nongl.lock();
    event_after_run_nongl.add<true>(PRIORITY_MAX, [run_gl_future](Context&, const ms&){
        run_gl_future.wait();
        return false;
    });
    event_after_run_nongl.emit_convertable<CONV, true>(this->shared_from_this(), dt);
    event_after_run_nongl.unlock();

    return run_gl_future;
}

const std::shared_ptr<GLFWwindow>& Context::getGlfw(){
    return _window;
}

const std::thread::id& Context::getGlThreadId() const {
    return _gl_thread_id;
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
        {GLFW_OPENGL_DEBUG_CONTEXT, true}
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
    glfwSwapInterval(0); // Enable vsync
    
    auto ver = gl.loadGladGLContext(glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }
    std::cout << "GL thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Version: " << ver << std::endl;

    int flags;
    gl.GetIntegerv(GLapi::GL_CONTEXT_FLAGS, &flags);
    if (flags & GLapi::GL_CONTEXT_FLAG_DEBUG_BIT){
        std::cout << "glDebugOutput enabled" << std::endl;
        gl.Enable(GLapi::GL_DEBUG_OUTPUT);
        gl.Enable(GLapi::GL_DEBUG_OUTPUT_SYNCHRONOUS); 
        gl.DebugMessageCallback(glDebugOutput, &gl);
        gl.DebugMessageControl(GLapi::GL_DONT_CARE, GLapi::GL_DONT_CARE, GLapi::GL_DONT_CARE, 0, nullptr, GLapi::GL_TRUE);
    }
    
    gl.ClearColor(0.2f, 0.9f, 0.2f, 1.f);
    gl.Clear(GLapi::GL_COLOR_BUFFER_BIT);
    
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

