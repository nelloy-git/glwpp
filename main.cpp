#include <iostream>
#include <unistd.h>
#include <chrono>

#include "glad/gl.h"
#include "glwpp/ctx/Window.hpp"

#include "glwpp/utils/CmdQueue.hpp"

#include "glwpp/ctx/data/VertexArray.hpp"

#include "glwpp/ctx/data/Uniform.hpp"

template<class V>
using Model = glwpp::ctx::VertexArray<V>;

int main(int argc, char **argv){
    auto win = glwpp::ctx::Window({
        .gl_major_ver = 4,
        .gl_minor_ver = 6,

        .width = 640,
        .height = 480,
        .title = "Noname"
    });

    bool running = true;
    auto close_cb = std::make_shared<glwpp::ctx::Window::onCloseCB>([&running](const glwpp::ctx::Window& win){
        running = false;
    });
    win.onClose.push_back(close_cb);

    auto press_cb = std::make_shared<glwpp::ctx::Keyboard::onPressCB>([](const glwpp::ctx::Keyboard&, const glwpp::Key& key, const glwpp::KeyModeFlags&){
        std::cout << static_cast<char>(key) << std::endl;
    });
    win.keyboard.onPress.push_back(press_cb);

    float color[4] = {0, 0, 0, 0};

    using PosMeta = glwpp::ctx::AttributeMeta<glwpp::DataTypeGL::_float, 3, false>;
    using Pos = glwpp::ctx::Attribute<PosMeta>;
    using Vert = glwpp::ctx::Vertex<Pos>;

    std::shared_ptr<std::any> model;

    auto draw_loop = [&win, &color, &model](){
        glClearColor(color[0], color[1], color[2], color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < 4; ++i) color[i] += (1 - color[i]) / 100000;
        glfwPollEvents();

        std::vector<Vert> v;
        std::vector<unsigned char> i;

        // if (!model){
        //     model = std::make_shared<std::any>(new Model<Vert>(v, i));
        // }

        auto sec = std::chrono::seconds(1);
        std::this_thread::sleep_for(sec);

        glfwSwapBuffers(win);
    };

    auto sec = std::chrono::seconds(1);
    while (running){
        win.gl_context.push(draw_loop);
        std::cout << "Azaza1" << std::endl;
        if (!win.gl_context.isExecuting())
            win.gl_context.execute();
        std::cout << "Azaza2" << std::endl;
        win.gl_context.waitFor(0.25 * sec);
        std::cout << "Azaza3" << std::endl;
        // win.gl_context.execute();
    }
}


