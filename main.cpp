#ifdef WIN32
#include <vld.h>
#endif

#include <iostream>
#include <memory>
#include <chrono>
#include <filesystem>

#include "glwpp/utils/File.hpp"

#include "glwpp/ctx/Context.hpp"
#include "glwpp/Drawer.hpp"
#include "glwpp/Model.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::utils;

void pushClear(std::shared_ptr<Context>& ctx){
    ctx->onRun.push<[]{return true;}>([](){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    });
}

void pushKeyPrinter(std::shared_ptr<Context>& ctx, std::atomic<bool>& is_running){
    ctx->onKey.push<[]{return true;}>([&is_running](const Key& key){
        std::cout << "Key: " << char(key) << std::endl;
        if (key == Key::Escape){
            is_running = false;
        }
    });
}

static void pushTimePrinter(std::shared_ptr<Context>& ctx){
    ctx->onRun.push<[]{return true;}>([](const std::chrono::microseconds& time){
        static int total_time = 0;
        static int counter = 0;

        total_time += time.count();
        ++counter;

        if (total_time > 1000000){
            std::cout << "Time(us): " << (double)total_time / counter << std::endl;
            total_time = 0;
            counter = 0;
        }
    });
}

sptr<Context> initContext(std::atomic<bool>& is_running){
    Context::Parameters ctx_params;
    ctx_params.gl_major_ver = 4;
    ctx_params.gl_minor_ver = 6;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto ctx = make_sptr<Context>(ctx_params);
    pushClear(ctx);
    pushKeyPrinter(ctx, is_running);
    pushTimePrinter(ctx);
    return ctx;
}

std::string loadTextFile(const std::string& path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

sptr<Drawer> initDrawer(std::shared_ptr<Context> ctx){
    auto v_shader = make_sptr<gl::Shader>(ctx, gl::ShaderType::Vertex);
    v_shader->setSource(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"));
    v_shader->compile();
    ctx->onRun.push([v_shader](){
        Val<bool> compiled(false);
        v_shader->isCompiled(compiled);
        if (!*compiled){
            Val<std::string> log("");
            v_shader->getInfoLog(log);
            std::cout << "v_shader failed: " << log->c_str() << std::endl;
        }
    });
    
    auto f_shader = make_sptr<gl::Shader>(ctx, gl::ShaderType::Fragment);
    f_shader->setSource(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"));
    f_shader->compile();
    ctx->onRun.push([f_shader](){
        Val<bool> compiled(false);
        f_shader->isCompiled(compiled);
        if (!*compiled){
            Val<std::string> log("");
            f_shader->getInfoLog(log);
            std::cout << "f_shader failed: " << log->c_str() << std::endl;
        }
    });

    auto drawer = make_sptr<Drawer>(ctx);
    drawer->attach(*v_shader);
    drawer->attach(*f_shader);
    drawer->link();
    ctx->onRun.push([drawer](){
        Val<bool> linked(false);
        drawer->isLinked(linked);
        if (!*linked){
            Val<std::string> log("");
            drawer->getInfoLog(log);
            std::cout << "drawer failed: " << log->c_str() << std::endl;
        }
    });
    drawer->use();

    Drawer::MeshAttributeBindings attr;
    attr[model::MeshAttribute::Position] = "vPos";
    drawer->bindMeshAttributes(attr);

    Drawer::UniformBlockBindings unif;    unif[DrawerUniformBlock::Camera] = "Camera";
    drawer->bindUniformBlocks(unif);

    return drawer;
}

sptr<Model> initModel(std::shared_ptr<Context> ctx, const std::string& path){
    model::MeshVertexConfig vert_config;
    vert_config.enable(model::MeshAttribute::Position, true);
    vert_config.setCompression(model::MeshAttribute::Position, 0);
    vert_config.setSize(model::MeshAttribute::Position, model::MeshAttributeSize::Vec3);

    auto model =  make_sptr<Model>(ctx, path, vert_config);
    if (model->getError()){
        std::cout << "model failed: " << model->getError().value().c_str() << std::endl;
    }

    return model;
}

void enableCameraMovement(std::shared_ptr<Context> ctx, Drawer& drawer){
    static const float vel = 0.1;
    ctx->onKey.push<[]{return true;}>([&drawer](const Key& key){
        switch (key){
        case Key::W: drawer.camera().pos += glm::vec3{vel, 0, 0}; break;
        case Key::S: drawer.camera().pos += glm::vec3{-vel, 0, 0}; break;
        case Key::A: drawer.camera().pos += glm::vec3{0, 0, -vel}; break;
        case Key::D: drawer.camera().pos += glm::vec3{0, 0,  vel}; break;
        case Key::LeftControl: drawer.camera().pos += glm::vec3{0, -vel, 0}; break;
        case Key::Space: drawer.camera().pos += glm::vec3{0, vel, 0}; break;
        
        default: break;
        }

        drawer.camera().apply();
        std::cout << "Camera {" << drawer.camera().pos.x << ", "
                                << drawer.camera().pos.y << ", "
                                << drawer.camera().pos.z << "}" << std::endl;
    });
}

// void draw(const VertexArray& vao){
//     gl::UInt id;
//     vao.getId(&id);

//     glBindVertexArray(id);
//     // glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
//     glDrawElementsInstanced(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0, 1);

//     gl::Enum err = glGetError();
//     while (err != GL_NO_ERROR){
//         std::string err_name;
//         switch (err){
//             case GL_INVALID_ENUM: err_name = "GL_INVALID_ENUM";
//             case GL_INVALID_VALUE: err_name = "GL_INVALID_VALUE";
//             case GL_INVALID_OPERATION: err_name = "GL_INVALID_OPERATION";
//             case GL_STACK_OVERFLOW: err_name = "GL_STACK_OVERFLOW";
//             case GL_STACK_UNDERFLOW: err_name = "GL_STACK_UNDERFLOW";
//             case GL_OUT_OF_MEMORY: err_name = "GL_OUT_OF_MEMORY";
//             case GL_INVALID_FRAMEBUFFER_OPERATION: err_name = "GL_INVALID_FRAMEBUFFER_OPERATION";
//             case GL_CONTEXT_LOST: err_name = "GL_CONTEXT_LOST";
//             default: err_name = "UNKNOWN";
//         }

//         std::cout << " Err: " << err_name << "(" << err << ")" << std::endl;
//         err = glGetError();
//     }
// }

int main(int argc, char **argv){
    std::atomic<bool> is_running = true;
    auto ctx = initContext(is_running);
    auto drawer = initDrawer(ctx);
    auto model = initModel(ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\3rdparty\\assimp\\test\\models\\OBJ\\spider.obj");

    enableCameraMovement(ctx, *drawer);
    drawer->camera().pos = {-1, -1, 0};
    drawer->camera().far_z = 10000;
    drawer->camera().apply();

    ctx->onRun.push<[]{return true;}>([=](){
        for (auto& mesh : model->getMeshes()){
            mesh.getVertexArray().draw(gl::DrawMode::Triangles, mesh.getIndexData().getIndexCount(), getMeshIndexTypeGlType(mesh.getIndexData().getType()), 1, utils::SrcLoc{}, false);
        }

        static bool shown = false;
        if (!shown){
            std::cout << "Meshes: " << model->getMeshes().size() << std::endl;

            for (int i = 0; i < model->getMeshes().size(); ++i){
                auto& mesh = model->getMeshes()[i];

                std::cout << "Mesh " << i << std::endl;
                std::cout << "\tMult: " << mesh.getVertexData().getValueMultiplier(model::MeshAttribute::Position) << std::endl;
                std::cout << "\tIndices: " << mesh.getIndexData().getIndexCount() << std::endl;
                std::cout << "\tIndex type: " << getMeshIndexTypeString(mesh.getIndexData().getType()).data() << std::endl;

                auto vert_0 = make_sptr<int>(0);
                mesh.getVertexData().getVertices().getSubData(vert_0, 0, sizeof(int));
                std::cout << "\t(int)Vertex[0]: " << *vert_0 << std::endl;
            }

            shown = true;
        }



        // gl::UInt id;
        // vao.getId(&id);

        // glBindVertexArray(id);
        // // glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
        // glDrawElementsInstanced(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0, 1);

        gl::Enum err = glGetError();
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
    });

    while (is_running){
        ctx->start();
        ctx->wait();
    };
}


