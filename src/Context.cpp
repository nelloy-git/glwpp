#include "Context.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "utils/GlobalThreadPool.hpp"
#include "utils/Metrics.hpp"

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
    auto& last_src_loc = *static_cast<const SrcLoc*>(userParam);
                                
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
    std::cout << last_src_loc.to_string().c_str() << std::endl;
    std::cout << std::endl;
}
}

std::atomic<unsigned int>& Context::_glfwWindowsCounter(){
    static std::atomic<unsigned int> counter(0);
    return counter;
}

Context::Context(const Parameters& params) :
    _gl_thread(new BS::thread_pool(1)),

    _init_time(std::chrono::steady_clock::now()),
    _last_start_time(std::chrono::steady_clock::now()),
    _last_finish_time(std::chrono::steady_clock::now()),

    _on_start_gl(_gl_thread),
    _on_run_gl(_gl_thread),
    _on_finish_gl(_gl_thread){
        
    std::cout << "Ctor thread: " << std::this_thread::get_id() << std::endl;

    _gl_thread->submit([this, &params](){
        try {
            _initGl(params);
        } catch (const std::exception& err){
            std::cout << "Critical ERROR: " << err.what() << std::endl;
        }
    }).wait();

    _on_start_gl.addActionQueued([window = _window](Context* ctx){
        glfwPollEvents();
        glfwSwapBuffers(window.get());
        ctx->gl.Clear(GL_COLOR_BUFFER_BIT);
        return true;
    });  
}

Context::~Context(){
}

const std::shared_ptr<GLFWwindow>& Context::getGlfw(){
    return _window;
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
    
    auto ver = gladLoadGLContext(&gl, glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }
    std::cout << "GL thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Version: " << ver << std::endl;

    int flags;
    gl.GetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT){
        std::cout << "glDebugOutput enabled" << std::endl;
        gl.Enable(GL_DEBUG_OUTPUT);
        gl.Enable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
        gl.DebugMessageCallback(glDebugOutput, &_last_src_loc);
        gl.DebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }
    
    gl.Clear(GL_COLOR_BUFFER_BIT);
    
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