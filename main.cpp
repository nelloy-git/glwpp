#include <vld.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <filesystem>

#include "glwpp/utils/File.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/ctx/FreeType/Font.hpp"

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

glwpp::Program loadProgram(std::shared_ptr<glwpp::Context> win){
    auto v_shader = glwpp::Shader(win, glwpp::gl::ShaderType::Vertex);
    v_shader.compile(loadTextFile("D:\\projects\\glwpp\\shaders\\vertex_2d.vs"));
    win->onRun.push([v_shader](){
        bool compiled = false;
        v_shader.isCompiled(&compiled);
        if (!compiled){
            std::string log;
            v_shader.getInfoLog(&log);
            std::cout << "v_shader failed: " << log.c_str() << std::endl;
        }
    });
    
    auto f_shader = glwpp::Shader(win, glwpp::gl::ShaderType::Fragment);
    f_shader.compile(loadTextFile("D:\\projects\\glwpp\\shaders\\vertex_2d.fs"));
    win->onRun.push([f_shader](){
        bool compiled = false;
        f_shader.isCompiled(&compiled);
        if (!compiled){
            std::string log;
            f_shader.getInfoLog(&log);
            std::cout << "f_shader failed: " << log.c_str() << std::endl;
        }
    });

    auto prog = glwpp::Program(win);
    prog.attach(v_shader);
    prog.attach(f_shader);
    prog.link();
    win->onRun.push([prog](){
        bool linked = false;
        prog.isLinked(&linked);
        if (!linked){
            std::string log;
            prog.getInfoLog(&log);
            std::cout << "prog failed: " << log.c_str() << std::endl;
        }
    });
    prog.use();

    return prog;
}

glwpp::VertexArray loadRect(std::shared_ptr<glwpp::Context> win){
    static float rect_vert[] = {
        0.5f,  0.5f, 1.0f, 1.0f,  // top right
        0.5f, -0.5f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f   // top left 
    };
    static unsigned int rect_elem[] = {
        0, 1, 3,
        1, 2, 3
    };

    static glwpp::Buffer elements(win);
    elements.data((glwpp::gl::SizeiPtr)sizeof(rect_elem), rect_elem, glwpp::gl::BufferUsage::DynamicDraw);
    static glwpp::Buffer vertices(win);
    vertices.data((glwpp::gl::SizeiPtr)sizeof(rect_vert), rect_vert, glwpp::gl::BufferUsage::DynamicDraw);

    glwpp::VertexArray vao(win);
    glwpp::gl::UInt index = 0;
    glwpp::gl::UInt relative_offset = 0;
    glwpp::gl::UInt relative_offset_1 = 2 * sizeof(float);
    vao.enableAttrib(index);
    vao.setAttribBinding(index, index);
    vao.setAttribFormat(index, 2, glwpp::gl::DataType::Float, false, relative_offset);
    
    vao.enableAttrib(index + 1);
    vao.setAttribBinding(index + 1, index);
    vao.setAttribFormat(index + 1, 2, glwpp::gl::DataType::Float, false, relative_offset_1);

    vao.setElementBuffer(elements);
    vao.setVertexBuffer(index, vertices, 0, (glwpp::gl::Sizei)(4 * sizeof(float)));

    return vao;
}

struct Glyph {
    Glyph(const glwpp::wptr<glwpp::Context>& ctx) :
        elems(ctx),
        verts(ctx),
        vao(ctx){
    }
    glwpp::Buffer elems;
    glwpp::Buffer verts;
    glwpp::VertexArray vao;
};

Glyph loadGlyph(glwpp::wptr<glwpp::Context> ctx, const glwpp::Font& font, size_t code){
    Glyph glyph(ctx);
    auto glyph_data = font.getGlyphInfo(code);

    float w = (float)glyph_data->width / glyph_data->height;
    float verts[] = {
        w, 1, glyph_data->tex_x2, glyph_data->tex_y2,
        w, 0, glyph_data->tex_x2, glyph_data->tex_y1,
        0, 0, glyph_data->tex_x1, glyph_data->tex_y1,
        0, 1, glyph_data->tex_x1, glyph_data->tex_y2,
    };
    auto v = glwpp::createTmpData(verts, sizeof(verts));

    unsigned int elems[] = {
        0, 1, 3,
        1, 2, 3
    };
    auto e = glwpp::createTmpData(elems, sizeof(elems));
    
    glyph.elems.data((glwpp::gl::SizeiPtr)sizeof(elems), e, glwpp::gl::BufferUsage::DynamicDraw);
    glyph.verts.data((glwpp::gl::SizeiPtr)sizeof(verts), v, glwpp::gl::BufferUsage::DynamicDraw);

    glwpp::gl::UInt index = 0;
    glwpp::gl::UInt relative_offset = 0;
    glwpp::gl::UInt relative_offset_1 = 2 * sizeof(float);
    glyph.vao.enableAttrib(index);
    glyph.vao.setAttribBinding(index, index);
    glyph.vao.setAttribFormat(index, 2, glwpp::gl::DataType::Float, false, relative_offset);
    
    glyph.vao.enableAttrib(index + 1);
    glyph.vao.setAttribBinding(index + 1, index);
    glyph.vao.setAttribFormat(index + 1, 2, glwpp::gl::DataType::Float, false, relative_offset_1);

    glyph.vao.setElementBuffer(glyph.elems);
    glyph.vao.setVertexBuffer(index, glyph.verts, 0, (glwpp::gl::Sizei)(4 * sizeof(float)));

    return glyph;
};

void setProgUniform1F(glwpp::Program& prog, const std::string& name, const float& val){
    auto loc = glwpp::make_sptr<glwpp::gl::Int>();
    prog.getUniformLocation(loc, name);
    prog.setUniform1F(loc, val);
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
    auto prog = loadProgram(win);

    // auto vao = loadRect(win);
    auto font = glwpp::Font(win, "D:\\projects\\glwpp\\3rdparty\\fonts\\jungle_tribe\\JungleTribeDemoRegular.ttf", 100);
    auto glyph = loadGlyph(win, font, (size_t)'G');
    font.getTex()->setUnit((unsigned int)0);

    setProgUniform1F(prog, "offset_x", 0);
    setProgUniform1F(prog, "offset_y", 0);
    setProgUniform1F(prog, "scale_x", 0.25);
    setProgUniform1F(prog, "scale_y", 0.25);

    std::function<void(glwpp::Context*, std::chrono::microseconds)> draw;
    draw = [glyph, &draw](glwpp::Context* win, std::chrono::microseconds time){
        // glVertexAttribLPointer()
        glwpp::gl::UInt id;
        glyph.vao.getId(&id);

        glBindVertexArray(id);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glwpp::gl::Enum err = glGetError();
        while (err != GL_NO_ERROR){
            std::string err_name;
            switch (err){
                case GL_INVALID_ENUM: err_name = "GL_INVALID_ENUM";
                case GL_INVALID_VALUE: err_name = "GL_INVALID_VALUE";
                case GL_INVALID_OPERATION: err_name = "GL_INVALID_OPERATION";
                case GL_STACK_OVERFLOW: err_name = "GL_STACK_OVERFLOW";
                case GL_STACK_UNDERFLOW: err_name = "GL_STACK_UNDERFLOW";
                case GL_OUT_OF_MEMORY: err_name = "GL_OUT_OF_MEMORY";
                case GL_INVALID_FRAMEBUFFER_OPERATION: err_name = "GL_INVALID_FRAMEBUFFER_OPERATION";
                case GL_CONTEXT_LOST: err_name = "GL_CONTEXT_LOST";
                default: err_name = "UNKNOWN";
            }

            std::cout << " Err: " << err_name << "(" << err << ")" << std::endl;
            err = glGetError();
        }
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        win->onRun.push(draw);
    };
    auto is_done_future = win->onRun.push(draw);

    while (running){
        win->start();
        win->wait();

        // static bool shown = false;
        // if (!shown){            
        //     shown = true;
        // }
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


