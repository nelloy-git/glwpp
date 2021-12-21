#include <iostream>
#include <memory>
// #include <unistd.h>
#include <chrono>

#include "glad/gl.h"

// #include "glwpp/Window.hpp"
// #include "glwpp/input/Keyboard.hpp"
// #include "glwpp/input/Mouse.hpp"
// #include "glwpp/input/System.hpp"

#include "glwpp/utils/File.hpp"

#include "glwpp/ctx/Context.hpp"
// #include "glwpp/Model.hpp"
// #include "glwpp/Renderer.hpp"

// #include "glwpp/ctx/data/Uniform.hpp"

// template<class V>
// using Model = glwpp::ctx::VertexArray<V>;


int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.gl_major_ver = 4;
    ctx_params.gl_minor_ver = 6;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.title = "Noname";

    auto win = std::make_shared<glwpp::Context>(ctx_params);

    

    // win->onFrame.pushBack()


    while (true){};













    // auto watcher = glwpp::make_sptr<glwpp::Watcher>();
    // bool running = true;

    // auto close_event = win->getSysCall().lock()->onClose();
    // close_event.push_back(watcher, [&running](){
    //     running = false;
    //     std::cout << "Closed" << std::endl;
    //     return glwpp::EventAction::Stop;
    // });

    // win->getKeyboard().lock()->onPress().push_back(watcher, [win](const glwpp::input::Key& key){
    //     std::cout << "Pressed: " << static_cast<char>(key) << std::endl;
    //     win->getKeyboard().lock()->capture(win->getContext(), false);
    //     return glwpp::EventAction::Continue;
    // });


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


    // float color[4] = {0, 0.5, 0, 0};
    // auto start_draw = [&](glwpp::Context&){
    //     glClearColor(color[0], color[1], color[2], color[3]);
    //     glClear(GL_COLOR_BUFFER_BIT);

        // std::cout << "Clear" << std::endl;
    //     return glwpp::EventAction::Continue;
    // };
    
    // auto finish_draw = [&](glwpp::Context &ctx){
    //     glfwSwapBuffers(ctx.getGlfwWindow());
    //     glfwPollEvents();

        // std::cout << "Swap" << std::endl;
    //     return glwpp::EventAction::Continue;
    // };

    // win->getContext().lock()->onLoopStart().push_back(watcher, start_draw);
    // win->getContext().lock()->onLoopEnd().push_front(watcher, finish_draw);
    // auto sec = std::chrono::seconds(1);

    // auto ctx = win->getContext().lock();
    // while (running){
    //     ctx->update();
    //     ctx->waitUpdate();

        // win->getContext().lock()->getCmdThread().lock()->push(start_draw);
        // renderer.draw(model);
        // win->getContext().lock()->getCmdThread().lock()->push(finish_draw);
    // }
}


