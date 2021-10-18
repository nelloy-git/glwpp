#include <iostream>
#include <unistd.h>
#include <chrono>

#include "glad/gl.h"
#include "glwpp/ctx/Window.hpp"

#include "glwpp/utils/CmdQueue.hpp"

// #include "glwpp/enums/Capability.hpp"

int main(int argc, char **argv){
    auto win = glwpp::Window({
        .gl_major_ver = 4,
        .gl_minor_ver = 6,

        .width = 640,
        .height = 480,
        .title = "Noname"
    });

    bool running = true;
    auto close_cb = std::make_shared<glwpp::Window::onCloseCB>([&running](const glwpp::Window& win){
        running = false;
    });
    win.onClose.push_back(close_cb);

    auto press_cb = std::make_shared<glwpp::Keyboard::onPressCB>([](const glwpp::Keyboard&, const glwpp::Key& key, const glwpp::KeyModeFlags&){
        std::cout << static_cast<char>(key) << std::endl;
    });
    win.keyboard.onPress.push_back(press_cb);

    float color[4] = {0, 0, 0, 0};

    auto draw_loop = [&win, &color](){
        glClearColor(color[0], color[1], color[2], color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < 4; ++i) color[i] += (1 - color[i]) / 100000;
        glfwPollEvents();
    };

    while (running){
        win.pushCmd(draw_loop);
        win.swapBuffers();
        win.wait();
    }
}


