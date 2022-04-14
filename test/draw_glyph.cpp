#include <vld.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <filesystem>

#include "glwpp/utils/File.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/ctx/FreeType/Font.hpp"

#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/gl/obj/Program.hpp"
#include "glwpp/gl/obj/Shader.hpp"
#include "glwpp/gl/obj/Texture.hpp"
#include "glwpp/gl/obj/VertexArray.hpp"

#include "glad/gl.h"

std::string loadTextFile(const std::string path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void pushKeyPrinter(std::shared_ptr<glwpp::Context> win, std::atomic<bool> &running){
    win->onKey.push([&running](const glwpp::Key& key){
        std::cout << "Key: " << char(key) << std::endl;
        if (key == glwpp::Key::Escape){
            running = false;
        }
    }, []{return true;});
}

void printTime(const std::chrono::microseconds& dt){
    static int total_time = 0;
    static int counter = 0;

    total_time += dt.count();
    ++counter;

    if (total_time > 1000000){
        std::cout << "Time(us): " << (double)total_time / counter << std::endl;
        total_time = 0;
        counter = 0;
    }
}

static void pushTimePrinter(std::shared_ptr<glwpp::Context> win){
    win->onRun.push<&printTime, []{return true;}>();
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
    elements.data(sizeof(rect_elem), rect_elem, glwpp::gl::BufferUsage::DynamicDraw);
    static glwpp::Buffer vertices(win);
    vertices.data(sizeof(rect_vert), rect_vert, glwpp::gl::BufferUsage::DynamicDraw);

    glwpp::VertexArray vao(win);
    glwpp::gl::UInt index = 0;
    vao.enableAttrib(0);
    vao.setAttribBinding(0, 0);
    vao.setAttribFormat(0, 2, glwpp::gl::DataType::Float, false, 0);
    
    vao.enableAttrib(1);
    vao.setAttribBinding(1, 0);
    vao.setAttribFormat(1, 2, glwpp::gl::DataType::Float, false, 2 * sizeof(float));

    vao.setElementBuffer(elements);
    vao.setVertexBuffer(0, vertices, 0, 4 * sizeof(float));

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
    
    glyph.elems.data(sizeof(elems), e, glwpp::gl::BufferUsage::DynamicDraw);
    glyph.verts.data(sizeof(verts), v, glwpp::gl::BufferUsage::DynamicDraw);

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
    glyph.vao.setVertexBuffer(index, glyph.verts, 0, 4 * sizeof(float));

    return glyph;
};

void setProgUniform1F(glwpp::Program& prog, const std::string& name, const float& val){
    auto loc = glwpp::make_sptr<glwpp::gl::Int>();
    prog.getUniformLocation(loc, name);
    prog.setUniform1F(loc, val);
}

void func(int a){
    std::cout << a << std::endl;
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
    pushKeyPrinter(win, running);
    pushTimePrinter(win);
    auto prog = loadProgram(win);

    auto vao = loadRect(win);
    auto font = glwpp::Font(win, "D:\\projects\\glwpp\\3rdparty\\fonts\\jungle_tribe\\JungleTribeDemoRegular.ttf", 100);
    auto glyph = loadGlyph(win, font, (size_t)'G');
    font.getTex()->setUnit((unsigned int)0);

    setProgUniform1F(prog, "offset_x", 0);
    setProgUniform1F(prog, "offset_y", 0);
    setProgUniform1F(prog, "scale_x", 0.25);
    setProgUniform1F(prog, "scale_y", 0.25);

    std::function<void(glwpp::Context*, std::chrono::microseconds)> draw;
    draw = [glyph, &draw](glwpp::Context* win, std::chrono::microseconds time){
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
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        win->onRun.push(draw);
    };
    win->onRun.push(draw);

    while (running){
        win->start();
        win->wait();
    };
}