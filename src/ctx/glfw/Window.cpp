#include "glwpp/ctx/glfw/Window.hpp"

#include <stdexcept>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "glwpp/ctx/glfw/enums/Action.hpp"
#include "glwpp/ctx/glfw/enums/Button.hpp"
#include "glwpp/ctx/glfw/enums/Key.hpp"
#include "glwpp/ctx/glfw/enums/KeyMod.hpp"

using namespace glwpp::glfw;

namespace
{

inline Window *_getWin(GLFWwindow *glfw_win){
    return (Window*)glfwGetWindowUserPointer(glfw_win);
}
    
} // namespace

Window::Window(int width, int height, const char *title,
               const std::vector<std::pair<int, int>> &hints){
    if (glfwInit() == GL_FALSE){
        throw std::runtime_error("Failed to initialize GLFW.");
    }

    for (auto &hint : hints){
        glfwWindowHint(hint.first, hint.second);
    }

    _glfw_win = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwSetWindowUserPointer(_glfw_win, this);
    glfwMakeContextCurrent(_glfw_win);
    
    auto ver = gladLoadGL(glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }
}

Window::~Window(){
    glfwDestroyWindow(_glfw_win);
}

void Window::iconify(){
    glfwIconifyWindow(_glfw_win);
}

void Window::restore(){
    glfwRestoreWindow(_glfw_win);
}

void Window::maximize(){
    glfwMaximizeWindow(_glfw_win);
}

void Window::show(){
    glfwShowWindow(_glfw_win);
}

void Window::hide(){
    glfwHideWindow(_glfw_win);
}

void Window::focus(){
    glfwFocusWindow(_glfw_win);
}

void Window::close(){
    glfwSetWindowShouldClose(_glfw_win, 1);
}

void Window::swapBuffers(){
    glfwSwapBuffers(_glfw_win);
}

void Window::setTitle(const std::string &title){
    glfwSetWindowTitle(_glfw_win, title.c_str());
}

void Window::setSizeLimits(int min_width, int min_height, int max_width, int max_height){
    glfwSetWindowSizeLimits(_glfw_win, min_width, min_height, max_width, max_height);
}

void Window::setAspectRatio(int num, int denom){
    glfwSetWindowAspectRatio(_glfw_win, num, denom);
}

std::pair<int, int> Window::getSize(){
    std::pair<int, int> res;
    glfwGetWindowSize(_glfw_win, &res.first, &res.second);
    return res;
}

std::pair<int, int> Window::getFramebufferSize(){
    std::pair<int, int> res;
    glfwGetFramebufferSize(_glfw_win, &res.first, &res.second);
    return res;
}

std::pair<float, float> Window::getContentScale(){
    std::pair<float, float> res;
    glfwGetWindowContentScale(_glfw_win, &res.first, &res.second);
    return res;
}

float Window::getOpacity(){
    return glfwGetWindowOpacity(_glfw_win);
}

void Window::setOpacity(float value){
    glfwSetWindowOpacity(_glfw_win, value);
}

std::string Window::getClipboardString(){
    return std::string(glfwGetClipboardString(_glfw_win));
}

void Window::setClipboardString(const std::string &string){
    glfwSetClipboardString(_glfw_win, string.c_str());
}

void Window::setPosCallback(const std::function<void(Window&, int, int)> &callback){
    _bindGlfwCallback<&Window::_pos_cb>(&glfwSetWindowPosCallback, callback);
}

void Window::setSizeCallback(const std::function<void(Window&, int, int)> &callback){
    _bindGlfwCallback<&Window::_size_cb>(&glfwSetWindowSizeCallback, callback);
}

void Window::setCloseCallback(const std::function<void(Window&)> &callback){
    _bindGlfwCallback<&Window::_close_cb>(&glfwSetWindowCloseCallback, callback);
}

void Window::setRefreshCallback(const std::function<void(Window&)> &callback){
    _bindGlfwCallback<&Window::_refresh_cb>(&glfwSetWindowRefreshCallback, callback);
}

void Window::setIconifyCallback(const std::function<void(Window&, bool)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int iconified){
        auto win = _getWin(glfw_win);
        win->_iconified_cb(*win, iconified == GLFW_TRUE);
    };

    if (callback && !_iconified_cb){
        glfwSetWindowIconifyCallback(_glfw_win, cb);
    }
    _iconified_cb = callback;
}

void Window::setMaximizeCallback(const std::function<void(Window&, bool)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int maximazed){
        auto win = _getWin(glfw_win);
        win->_maximized_cb(*win, maximazed == GLFW_TRUE);
    };

    if (callback && !_maximized_cb){
        glfwSetWindowMaximizeCallback(_glfw_win, cb);
    }
    _maximized_cb = callback;
}

void Window::setFramebufferResizeCallback(const std::function<void(Window&, int, int)> &callback){
    _bindGlfwCallback<&Window::_frame_size_cb>(&glfwSetFramebufferSizeCallback, callback);
}

void Window::setScaleCallback(const std::function<void(Window&, float, float)> &callback){
    _bindGlfwCallback<&Window::_scale_cb>(&glfwSetWindowContentScaleCallback, callback);
}

void Window::setCursorFocusCallback(const std::function<void(Window&, bool)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int focused){
        auto win = _getWin(glfw_win);
        win->_cursor_focus_cb(*win, focused == GLFW_TRUE);
    };

    if (callback && !_cursor_focus_cb){
        glfwSetWindowFocusCallback(_glfw_win, cb);
    }
    _cursor_focus_cb = callback;
}

void Window::setCursorPosCallback(const std::function<void(Window&, double, double)> &callback){
    _bindGlfwCallback<&Window::_cursor_pos_cb>(&glfwSetCursorPosCallback, callback);
}

void Window::setCursorEnterCallback(const std::function<void(Window&, bool)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int entered){
        auto win = _getWin(glfw_win);
        win->_cursor_enter_cb(*win, entered == GLFW_TRUE);
    };

    if (callback && !_cursor_enter_cb){
        glfwSetCursorEnterCallback(_glfw_win, cb);
    }
    _cursor_enter_cb = callback;
}

void Window::setCursorButtonCallback(const std::function<void(Window&, Button, Action, KeyModFlags)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int button, int action, int mods){
        auto win = _getWin(glfw_win);
        win->_cursor_btn_cb(*win, static_cast<Button>(button),
                                  static_cast<Action>(action),
                                  KeyModFlags(mods));
    };

    if (callback && !_cursor_btn_cb){
        glfwSetMouseButtonCallback(_glfw_win, cb);
    }
    _cursor_btn_cb = callback;
}

void Window::setCursorScrollCallback(const std::function<void(Window&, double, double)> &callback){
    _bindGlfwCallback<&Window::_cursor_scroll_cb>(&glfwSetScrollCallback, callback);
}

void Window::setKeyCallback(const std::function<void(Window&, Key, int, Action, KeyModFlags)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, int key, int scancode, int action, int mods){
        auto win = _getWin(glfw_win);
        win->_key_cb(*win, static_cast<Key>(key),
                           scancode,
                           static_cast<Action>(action),
                           static_cast<KeyModFlags>(mods));
    };

    if (callback && !_key_cb){
        glfwSetKeyCallback(_glfw_win, cb);
    }
    _key_cb = callback;
}

void Window::setCharCallback(const std::function<void(Window&, unsigned int, KeyModFlags)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, unsigned int codepoint, int mods){
        auto win = _getWin(glfw_win);
        win->_char_cb(*win, codepoint,
                            static_cast<KeyModFlags>(mods));
    };

    if (callback && !_char_cb){
        glfwSetCharModsCallback(_glfw_win, cb);
    }
    _char_cb = callback;
}

template<auto member, class ... Args>
void Window::_bindGlfwCallback(Window::GlfwCallbackSetter<Args...> setter,
                               const std::function<void(Window&, Args...)> &callback){
    static auto cb = [](GLFWwindow *glfw_win, Args... args){
        auto win = _getWin(glfw_win);
        (win->*member)(*win, std::forward<Args>(args)...);
    };

    if (callback && !(this->*member)){
        setter(_glfw_win, cb);
    }
    (this->*member) = callback;
}