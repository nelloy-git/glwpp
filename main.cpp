#include <vld.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <filesystem>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "glwpp/utils/File.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/ctx/FreeType/Font.hpp"

#include "glwpp/gl/oop/Buffer.hpp"
#include "glwpp/gl/oop/Program.hpp"
#include "glwpp/gl/oop/Shader.hpp"
#include "glwpp/gl/oop/Texture.hpp"
#include "glwpp/gl/oop/VertexArray.hpp"

#include "glwpp/model/Mesh.hpp"

#include "glad/gl.h"

std::string loadTextFile(const std::string& path){
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

void printTime(const std::chrono::microseconds& time){
    static int total_time = 0;
    static int counter = 0;

    total_time += time.count();
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
    auto compiled = glwpp::make_sptr<bool>(false);
    f_shader.isCompiled(compiled);
    win->onRun.push([compiled](){
        if (!*compiled){

        }
    });
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


    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile("D:\\projects\\Engine\\3rdparty\\glwpp\\3rdparty\\assimp\\test\\models\\STL\\Spider_binary.stl",
                                             aiProcess_CalcTangentSpace       |
                                             aiProcess_Triangulate            |
                                             aiProcess_JoinIdenticalVertices  |
                                             aiProcess_SortByPType);
    glwpp::Mesh mesh(win, glwpp::MeshInfo(glwpp::gl::DataType::Int_2_10_10_10,
                                          glwpp::gl::DataType::Float,
                                          glwpp::gl::DataType::Float,
                                          glwpp::gl::DataType::Float,
                                          glwpp::gl::DataType::Float,
                                          glwpp::gl::DataType::Float));
    mesh.loadAssimpMesh(*scene->mMeshes[0]);

    while (running){
        win->start();
        win->wait();
    };
}


