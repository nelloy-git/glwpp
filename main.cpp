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

#include "glwpp/utils/File.hpp"

// #include "glwpp/ctx/Context.hpp"

// #include "glwpp/utils/CmdQueue.hpp"

// #include "glwpp/Model.hpp"
// #include "glwpp/Renderer.hpp"

// #include "glwpp/ctx/data/Uniform.hpp"

// template<class V>
// using Model = glwpp::ctx::VertexArray<V>;


int main(int argc, char **argv){
    auto win = std::make_shared<glwpp::Window>(glwpp::Context::Parameters{
        .gl_major_ver = 4,
        .gl_minor_ver = 6,

        .width = 640,
        .height = 480,
        .title = "Noname"
    });
    auto watcher = std::make_shared<glwpp::CmdWatcher>();
    bool running = true;

    auto &close_event = win->getSysCall().lock()->onClose;
    close_event.pushBack(watcher, [&running](){
        running = false;
        std::cout << "Closed" << std::endl;
        return glwpp::CmdAct::Stop;
    });

    win->getKeyboard().lock()->onPress.pushBack(watcher, [](const glwpp::Key& key){
        std::cout << "Pressed: " << static_cast<char>(key) << std::endl;
        return glwpp::CmdAct::Repeat;
    });


    // using PosMeta = glwpp::ctx::AttributeMeta<glwpp::DataTypeGL::_float, 2, false>;
    // using Pos = glwpp::ctx::Attribute<PosMeta>;
    // using Vert = glwpp::ctx::Vertex<Pos>;

    // Vert v1 {{{0.0, 0.0}}};
    // Vert v2 {{{0.0, 1.0}}};
    // Vert v3 {{{1.0, 1.0}}};
    // auto v = std::make_shared<std::vector<Vert>>(std::vector{v1, v2, v3});
    // glwpp::Model<Vert> model(win->getContext(), v);

    // std::shared_ptr<std::string> code_vshader(glwpp::readTextFile("vertex_2d.vs"));
    // std::shared_ptr<std::string> code_fshader(glwpp::readTextFile("vertex_2d.fs"));

    // glwpp::Renderer<Vert> renderer(win->getContext(), code_vshader, code_fshader);
    // renderer.use();


    float color[4] = {0, 0.5, 0, 0};
    auto start_draw = [&](glwpp::Context&){
        glClearColor(color[0], color[1], color[2], color[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        // std::cout << "Clear" << std::endl;
        return glwpp::CmdAct::Repeat;
    };
    
    auto finish_draw = [&](glwpp::Context &ctx){
        glfwSwapBuffers(ctx.getGlfwWindow());
        glfwPollEvents();

        // std::cout << "Swap" << std::endl;
        return glwpp::CmdAct::Repeat;
    };

    // win->getContext().lock()->push(watcher, start_draw);
    // win->getContext().lock()->push(watcher, finish_draw);
    // auto sec = std::chrono::seconds(1);



    while (running){
        watcher->waitAll();

        // win->getContext().lock()->getCmdThread().lock()->push(start_draw);
        // renderer.draw(model);
        // win->getContext().lock()->getCmdThread().lock()->push(finish_draw);
    }
}


