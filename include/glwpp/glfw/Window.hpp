#pragma once

#include <functional>
#include <string>
#include <utility>
#include <vector>

struct GLFWwindow;

namespace glwpp::glfw {

enum class Action;
enum class Key;
struct ModFlags;
enum class Button;

class Window {
public:
    Window(int width, int height, const char *title,
           const std::vector<std::pair<int, int>> &hints);
    Window(Window&) = delete;
    Window(Window&&) = delete;
    Window(const Window&) = delete;
    Window(const Window&&) = delete;
    virtual ~Window();

    void iconify();
    void restore();
    void maximize();
    void show();
    void hide();
    void focus();
    void close();
    void swapBuffers();

    void setTitle(const std::string &title);
    void setSizeLimits(int min_width, int min_height, int max_width, int max_height);
    void setAspectRatio(int num, int denom);

    std::pair<int, int> getSize();
    std::pair<int, int> getFramebufferSize();
    std::pair<float, float> getContentScale();

    float getOpacity();
    void setOpacity(float value);

    std::string getClipboardString();
    void setClipboardString(const std::string &string);
    
    void setCursorPos(double x, double y);
    std::pair<double, double> getCursorPos();

    int getInputMode(int node);
    void setInputMode(int mode, int value);

    int getAttrib(int attrib);
    void setAttrib(int attrib, int value);

    bool isKeyPressed(Key key);
    bool isButtonPressed(Button btn);

    void setPos(int x, int y);
    std::pair<int, int> getPos();

    // Callbacks

    void setPosCallback(const std::function<void(Window&, int x, int y)> &callback);
    void setSizeCallback(const std::function<void(Window&, int, int)> &callback);
    void setCloseCallback(const std::function<void(Window&)> &callback);
    void setRefreshCallback(const std::function<void(Window&)> &callback);
    void setIconifyCallback(const std::function<void(Window&, bool)> &callback);
    void setMaximizeCallback(const std::function<void(Window&, bool)> &callback);
    void setFramebufferResizeCallback(const std::function<void(Window&, int, int)> &callback);
    void setScaleCallback(const std::function<void(Window&, float, float)> &callback);

    void setCursorFocusCallback(const std::function<void(Window&, bool)> &callback);
    void setCursorPosCallback(const std::function<void(Window&, double, double)> &callback);
    void setCursorEnterCallback(const std::function<void(Window&, bool)> &callback);
    void setCursorButtonCallback(const std::function<void(Window&, Button, Action, ModFlags)> &callback);
    void setCursorScrollCallback(const std::function<void(Window&, double, double)> &callback);

    void setKeyCallback(const std::function<void(Window&, Key, int, Action, ModFlags)> &callback);
    void setCharCallback(const std::function<void(Window&, unsigned int, ModFlags)> &callback);

    // void setCursor() // TODO

    // GLFWMonitor *getMonitor(); TODO
    // void setMonitor(GLFWMonitor *monitor, int xpos, int ypos, int width, int height, int refreshRate); TODO

    // void setIcon(int count, const GLFWimage* images) // TODO

private:
    GLFWwindow *_glfw_win;

    std::function<void(Window&, int, int)> _pos_cb;
    std::function<void(Window&, int, int)> _size_cb;
    std::function<void(Window&)> _close_cb;
    std::function<void(Window&)> _refresh_cb;
    std::function<void(Window&, bool)> _iconified_cb;
    std::function<void(Window&, bool)> _maximized_cb;
    std::function<void(Window&, int, int)> _frame_size_cb;
    std::function<void(Window&, float, float)> _scale_cb;

    std::function<void(Window&, bool)> _cursor_focus_cb;
    std::function<void(Window&, double, double)> _cursor_pos_cb;
    std::function<void(Window&, bool)> _cursor_enter_cb;
    std::function<void(Window&, double, double)> _cursor_scroll_cb;
    std::function<void(Window&, Button, Action, ModFlags)> _cursor_btn_cb; 

    std::function<void(Window&, Key, int, Action, ModFlags)> _key_cb;
    std::function<void(Window&, unsigned int, ModFlags)> _char_cb;

    template <class ... Args>
    using GlfwCallback = void (*)(GLFWwindow*, Args...);

    template <class ... Args>
    using GlfwCallbackSetter = GlfwCallback<Args...> (*)(GLFWwindow*, GlfwCallback<Args...>);

template<auto member, class ... ArgsGlfw, class ... ArgsCb>
    void _bindGlfwCallback(GlfwCallbackSetter<ArgsGlfw...> setter,
                           const std::function<void(Window&, ArgsCb...)> &callback);
};

}