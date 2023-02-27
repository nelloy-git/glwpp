#ifdef WIN32
#include <vld.h>
#endif

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <streambuf>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Context.hpp"
#include "model/Model.hpp"
#include "Drawer.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"
#include "gl_object/Shader.hpp"
// #include "gl_object/BufferVector.hpp"

#include "drawer/ImGuiApi.hpp"

#include "GLapi.hpp"

std::string read_file(const std::string& path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

auto init_drawer(glwpp::Context& ctx, const glwpp::SrcLoc& src_loc = glwpp::SrcLoc{}){
    auto drawer = glwpp::Drawer::Make(ctx, src_loc);
    drawer->on_shader_error.add<[](auto& drawer, const auto& err){
        std::cout << "Msg: " << err.second.c_str() << std::endl;
        return true;
    }>(ctx.PRIORITY_DEFAULT, src_loc);
    drawer->setShader(glwpp::GL_VERTEX_SHADER, read_file("/home/nelloy/glwpp/shaders/vertex_3d.vs"), src_loc.add());
    drawer->setShader(glwpp::GL_FRAGMENT_SHADER, read_file("/home/nelloy/glwpp/shaders/vertex_3d.fs"), src_loc.add());
    // drawer->setShader(glwpp::GL_VERTEX_SHADER, read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc.add());
    // drawer->setShader(glwpp::GL_FRAGMENT_SHADER, read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc.add());

    return drawer;
}

int main(int argc, char **argv){
    glwpp::Context::Config ctx_params;
    ctx_params.width = 1280;
    ctx_params.height = 1024;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto ctx = glwpp::Context::Make(ctx_params);
    auto imgui = glwpp::ImGuiApi::Make(*ctx);
    glwpp::Value<std::string> name("Metrics");
    glwpp::Value<bool> opened(true);
    glwpp::Value<int> flags(0);
    
    auto gl_metrics = std::make_shared<glwpp::Metrics::Category>();
    ctx->gl().setMetricsCategory(gl_metrics);

    auto drawer = init_drawer(*ctx);

#ifdef WIN32
    glwpp::Model book_model(*ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\test\\models\\book\\scene.gltf");
#else
    glwpp::Model book_model(*ctx, "/home/sbugrov/glwpp/test/models/book/scene.gltf");
#endif

    if (book_model.loading_error.has_value()){
        std::cout << book_model.loading_error.value().c_str() << std::endl;
    }

    bool done = false;
    size_t i = 0;
    while(i < 3000){
        ++i;
        auto run_future = ctx->run();

        if (*opened){
            imgui->NewFrame<glwpp::TState::False>();
            imgui->Begin<glwpp::TState::False>(name, opened.get(), flags);
            auto all_names = gl_metrics->getAllNames();
            std::sort(all_names.begin(), all_names.end());
            for (auto& name : all_names){
                imgui->Text<glwpp::TState::False>(name + std::string(": ") + std::to_string((*gl_metrics)[name].getTotal().first));
            }
            imgui->End<glwpp::TState::False>();
            imgui->Render<glwpp::TState::False>();
        }
    

        run_future.wait();


        if (!done){
            done = true;

            // std::cout << "VertInfo:\n" << std::get<0>(info).value().value_or("").c_str() << std::endl;
            // std::cout << "FragInfo:\n" << std::get<1>(info).value().value_or("").c_str() << std::endl;
            // std::cout << "ProgInfo:\n" << std::get<2>(info).value().value_or("").c_str() << std::endl;
            // std::cout << std::get<2>(info).value().c_str() << std::endl;
            // std::cout << *buf.id() << std::endl;
            // std::cout << "Loop" << std::endl;
        }

        // std::cout << glwpp::Metrics::inst()["ImGui::Render"].getLast().value << std::endl;
    }
}