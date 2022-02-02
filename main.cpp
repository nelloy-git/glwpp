#include <vld.h>

#include <iostream>
#include <memory>
// #include <unistd.h>
#include <chrono>
#include <filesystem>

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
#include "glwpp/gl/oop/Buffer.hpp"
#include "glwpp/gl/oop/Program.hpp"
#include "glwpp/gl/oop/Shader.hpp"
#include "glwpp/gl/oop/Texture.hpp"
#include "glwpp/gl/oop/VertexArray.hpp"

#include "glad/gl.h"

std::string loadTextFile(const std::string path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void pushKeyPrinter(std::shared_ptr<glwpp::Context> win, std::atomic<bool> *running){
    static std::function<void(glwpp::Context*, glwpp::Key)> print_func;

    print_func = [func = &print_func, running](glwpp::Context *win, glwpp::Key key){
        std::cout << "Key: " << char(key) << std::endl;
        if (key == glwpp::Key::Escape){
            *running = false;
        }
        win->onKey.push(*func);
    };
    win->onKey.push(print_func);
}

void pushTimePrinter(std::shared_ptr<glwpp::Context> win){
    static std::function<void(glwpp::Context*, std::chrono::microseconds)> frame_timer_func;

    frame_timer_func = [func = &frame_timer_func](glwpp::Context* win, std::chrono::microseconds time){
        static int total_time = 0;
        static int counter = 0;

        total_time += time.count();
        ++counter;

        if (total_time > 1000000){
            std::cout << "Time(us): " << (double)total_time / counter << std::endl;
            total_time = 0;
            counter = 0;
        }
        win->onRun.push(*func);
    };
    win->onRun.push(frame_timer_func);
}

int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.gl_major_ver = 4;
    ctx_params.gl_minor_ver = 5;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    std::atomic<bool> running = true;
    auto win = std::make_shared<glwpp::Context>(ctx_params);
    pushKeyPrinter(win, &running);
    pushTimePrinter(win);

    auto v_shader = glwpp::Shader(win, glwpp::gl::ShaderType::Vertex);
    v_shader.compile(loadTextFile("D:\\projects\\glwpp\\shaders\\vertex_2d.vs"));
    std::string v_shader_log;
    v_shader.getInfoLog(&v_shader_log);

    auto f_shader = glwpp::Shader(win, glwpp::gl::ShaderType::Fragment);
    f_shader.compile(loadTextFile("D:\\projects\\glwpp\\shaders\\vertex_2d.fs"));
    std::string f_shader_log;
    f_shader.getInfoLog(&f_shader_log);

    auto prog = glwpp::Program(win);
    prog.attach(&v_shader);
    prog.attach(&f_shader);
    prog.link();
    prog.setActive();
    std::string prog_log;
    prog.getInfoLog(&prog_log);

    float rect_vert[] = {
         0.5f,  0.5f,  // top right
         0.5f, -0.5f,  // bottom right
        -0.5f, -0.5f,  // bottom left
        -0.5f,  0.5f   // top left 
    };
    unsigned int rect_elem[] = {
        0, 1, 3,
        1, 2, 3
    };

    glwpp::Buffer elements(win);
    elements.data((glwpp::gl::SizeiPtr)sizeof(rect_elem), rect_elem, glwpp::gl::BufferUsage::DynamicDraw);
    glwpp::Buffer vertices(win);
    vertices.data((glwpp::gl::SizeiPtr)sizeof(rect_vert), rect_vert, glwpp::gl::BufferUsage::DynamicDraw);

    glwpp::VertexArray vao(win);
    glwpp::gl::UInt index = 0;
    glwpp::gl::UInt relative_offset = 0;
    vao.enableAttrib(index);
    vao.setAttribBinding(index, index);
    vao.setAttribFormat(index, 2, glwpp::gl::DataType::Float, false, relative_offset);
    vao.setElementBuffer(&elements);
    vao.setVertexBuffer(index, &vertices, 0, (glwpp::gl::UInt)(2 * sizeof(float)));

    std::function<void(glwpp::Context*, std::chrono::microseconds)> draw;
    draw = [&vao, &draw](glwpp::Context* win, std::chrono::microseconds time){
        // glVertexAttribLPointer()
        glBindVertexArray(vao.id());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        win->onRun.push(draw);
    };
    auto is_done_future = win->onRun.push(draw);

//       glVertexAttrib*Format(index, size, type, {normalized,} 0);
//   glVertexAttribBinding(index, index);

//   GLuint buffer;
//   glGetIntegerv(GL_ARRAY_BUFFER_BINDING, buffer);
//   if(buffer == 0)
//     glErrorOut(GL_INVALID_OPERATION); //Give an error.

//   if(stride == 0)
//     stride = CalcStride(size, type);

//   GLintptr offset = reinterpret_cast<GLintptr>(pointer);
//   glBindVertexBuffer(index, buffer, offset, stride);

    while (running){
        win->start();
        win->wait();

        static bool shown = false;
        if (is_done_future.wait_for(std::chrono::seconds(0)) != std::future_status::ready){
            std::cout << "Is not ready" << std::endl;
        } else {
            if (!shown){
                auto is_done = is_done_future.get();
                std::cout << "Here" << std::endl;
                std::cout << "v_shader_log:\n" << v_shader_log.c_str() << std::endl;
                std::cout << "f_shader_log:\n" << f_shader_log.c_str() << std::endl;
                std::cout << "prog_log:\n" << prog_log.c_str() << std::endl;
                
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


