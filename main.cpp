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

#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/gl/obj/Program.hpp"
#include "glwpp/gl/obj/Shader.hpp"
#include "glwpp/gl/obj/Texture.hpp"
#include "glwpp/gl/obj/VertexArray.hpp"
#include "glwpp/gl/obj/Vector.hpp"

#include "glwpp/model/Mesh.hpp"

#include "glwpp/Drawer.hpp"

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
    v_shader.compile(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"));
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
    f_shader.compile(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"));
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

void enableCameraMovement(std::shared_ptr<glwpp::Context> win, glwpp::Drawer& drawer){
    win->onKey.push<[]{return true;}>([&drawer](const glwpp::Key& key){
        switch (key){
        case glwpp::Key::W: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{ 0.01, 0, 0}); break;
        case glwpp::Key::S: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{-0.01, 0, 0}); break;
        case glwpp::Key::A: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{0, 0, -0.01}); break;
        case glwpp::Key::D: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{0, 0,  0.01}); break;
        case glwpp::Key::LeftControl: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{0, -0.01, 0}); break;
        case glwpp::Key::Space: drawer.camera.setPosition(drawer.camera.getPosition() + glm::vec3{0, 0.01, 0}); break;
        
        default: break;
        }
    });
}

void draw(const glwpp::VertexArray& vao){
    glwpp::gl::UInt id;
    vao.getId(&id);

    glBindVertexArray(id);
    // glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
    glDrawElementsInstanced(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0, 1);

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

    glwpp::Drawer drawer(prog);
    drawer.bindUniform(glwpp::Drawer::Uniform::Camera, "Camera");
    enableCameraMovement(win, drawer);

    win->onRun.push<[]{return true;}>([](){
        glClear(GL_COLOR_BUFFER_BIT);
    });

    while (running){
        win->start();
        win->wait();
        drawer.updateCamera();
        // for (size_t i = 0; i < scene->mNumMeshes; ++i){
        //     win->onRun.push([&prog, &meshes, i](){
        //         glwpp::gl::Int loc;
        //         auto values = &meshes[i].getValueOffset(glwpp::MeshAttribute::Position);
        //         prog.getUniformLocation(&loc, "offset");
        //         // prog.setUniform3F(loc, reinterpret_cast<const glwpp::gl::Float*>(values), 1);

        //         prog.getUniformLocation(&loc, "mult");
        //         prog.setUniform1F(loc, &meshes[i].getValueMultiplicator(glwpp::MeshAttribute::Position));

        //         // std::cout << std::get<0>(*values) << ", " << std::get<1>(*values) << ", " << std::get<2>(*values) << std::endl;
        //         // std::cout << meshes[i].getValueMultiplicator(glwpp::MeshAttribute::Position) << std::endl;
        //     });
        //     meshes[i].getVAO()->draw(glwpp::gl::DrawMode::Triangles, 3 * scene->mMeshes[i]->mNumFaces, glwpp::gl::DataType::UByte, 1);
        // }
    };
}


