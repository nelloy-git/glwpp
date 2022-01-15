#include <vld.h>

#include <iostream>
#include <memory>
// #include <unistd.h>
#include <chrono>

// #include "glad/gl.h"

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
#include "glwpp/gl/api/gl_46.hpp"
#include "glwpp/gl/enums/BufferType.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

// #include "glwpp/gl/vertex/VertexAttribData.hpp"


int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.gl_major_ver = 4;
    ctx_params.gl_minor_ver = 6;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto win = std::make_shared<glwpp::Context>(ctx_params);

    // auto w = win->onRun.push([&win](){
    //     std::cout << "Frame" << std::endl;
    // });

    // auto fut = win->onRun.push([](){
    //     return 1;
    // });

    // auto w = win->onKey.push([&win](glwpp::Key key, int, glwpp::Action act){
    //     if (act == glwpp::Action::Release){
    //         std::cout << int(key) << std::endl;
    //     }
        
    //     if (key == glwpp::Key::Escape){
    //         win.reset();
    //     }
    // });

    // constexpr glwpp::gl::VertexAttrib attrib(glwpp::gl::DataType::Float, 3, false);
    // constexpr glwpp::gl::VertexAttribData<attrib> data{};

    // using Pos = glwpp::gl::VertexAttrib<glwpp::gl::DataType::Float, 3, false>;
    // Pos attr;
    // attr.set(1.2, 3.2, 12);

    // using Vert = glwpp::gl::Vertex<Pos>;
    // Vert v;
    // v.set<0>(2.1, 3, 1);
    // Vert::bindAttributes();

    std::atomic<bool> runnig = true;

    std::function<void(glwpp::Context *win, glwpp::Key)> print_func;
    print_func = [&print_func, &runnig](glwpp::Context *win, glwpp::Key key){
        std::cout << "Key: " << char(key) << std::endl;
        if (key == glwpp::Key::Escape){
            runnig = false;
        }
        win->onKey.push(print_func);
    };
    win->onKey.push(print_func);
    
    std::function<void(glwpp::Context*, std::chrono::microseconds)> frame_timer_func;
    frame_timer_func = [&frame_timer_func](glwpp::Context* win, std::chrono::microseconds time){
        static int total_time = 0;
        static int counter = 0;

        total_time += time.count();
        ++counter;

        if (total_time > 1000000){
            std::cout << "Time(us): " << (double)total_time / counter << std::endl;
            total_time = 0;
            counter = 0;
        }
        win->onRun.push(frame_timer_func);
    };
    win->onRun.push(frame_timer_func);

    glwpp::Buffer buffer(win);
    auto is_done_future = buffer.data(nullptr, 1024, glwpp::gl::BufferUsage::StaticDraw);

    while (runnig){
        win->start();
        win->wait();

        static bool shown = false;
        if (is_done_future.wait_for(std::chrono::seconds(0)) != std::future_status::ready){
            std::cout << "Is not ready" << std::endl;
        } else {
            if (!shown){
                auto is_done = is_done_future.get();
                std::cout << "Allocated buffer: " << (is_done ? "true" : "false") << std::endl;
                shown = true;
            }
        }
    };



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


