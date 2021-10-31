#include <iostream>
#include <memory>
#include <unistd.h>
#include <chrono>

#include "glad/gl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "glwpp/Window.hpp"
#include "glwpp/input/Keyboard.hpp"
#include "glwpp/input/Mouse.hpp"
#include "glwpp/input/System.hpp"

// #include "glwpp/ctx/Context.hpp"

// #include "glwpp/utils/CmdQueue.hpp"

#include "glwpp/Model.hpp"

// #include "glwpp/ctx/data/Uniform.hpp"

// template<class V>
// using Model = glwpp::ctx::VertexArray<V>;


int main(int argc, char **argv){
    auto win = std::make_shared<glwpp::Window>(glwpp::Context::Params{
        .gl_major_ver = 4,
        .gl_minor_ver = 6,

        .width = 640,
        .height = 480,
        .title = "Noname"
    });

    bool running = true;
    auto &close_event = win->sys_call().onClose;
    // auto close_cb = std::make_shared<std::function<void(const glwpp::input::SystemCall&)>>(
    //     [&running](const glwpp::input::SystemCall&){
    //         std::cout << "Closed\n" << std::endl;
    //         running = false;
    //     }
    // );
    auto close_cb = close_event.prepare(
        [&running](){
            std::cout << "Closed\n" << std::endl;
            running = false;
        }
    );
    close_event.push_back(close_cb);

    // auto press_cb = std::make_shared<glwpp::input::Keyboard::onPressCB>([](const glwpp::input::Keyboard&, const glwpp::Key& key, const glwpp::KeyModeFlags&){
    //     std::cout << static_cast<char>(key) << std::endl;
    // });
    // win.keyboard().onPress.push_back(press_cb);

    float color[4] = {0, 1, 0, 0};

    using PosMeta = glwpp::ctx::AttributeMeta<glwpp::DataTypeGL::_float, 2, false>;
    using Pos = glwpp::ctx::Attribute<PosMeta>;
    using Vert = glwpp::ctx::Vertex<Pos>;

    Vert v1 {{{0.0, 0.0}}};
    Vert v2 {{{0.0, 1.0}}};
    Vert v3 {{{1.0, 1.0}}};
    auto v = std::make_shared<std::vector<Vert>>(std::vector{v1, v2, v3});
    // std::vector<Vert> v {v1, v2, v3};
    glwpp::Model<Vert> model(win, v);

    auto draw_loop = [&](){
        glClearColor(color[0], color[1], color[2], color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        // for (int i = 0; i < 4; ++i) color[i] += (1 - color[i]) / 100000;

        // model._vert_arr->draw(glwpp::DrawModeGL::Triangles);

        // auto sec = std::chrono::seconds(1);
        // std::this_thread::sleep_for(sec);

        glfwSwapBuffers(win->context());
        glfwPollEvents();
    };


    auto sec = std::chrono::seconds(1);
    while (running){
        win->context().cmd_queue.push(draw_loop);
        win->context().cmd_queue.execute();
        win->context().cmd_queue.waitFor(0.25 * sec);
        // win.gl_context.execute();
    }
}


