#ifdef WIN32
#include <vld.h>
#endif

#include <string>
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

std::string read_file(const std::string& path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

auto init_drawer(glwpp::Context& ctx, const glwpp::SrcLoc& src_loc = glwpp::SrcLoc{}){
    auto f = __func__;

    glwpp::Drawer drawer(ctx, src_loc);
    auto vert_err = drawer.setVertexShader(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc);
    auto frag_err = drawer.setFragmentShader(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc);

    drawer.setShaderTest(std::string(""), src_loc);

    ctx.event_after_run_nongl.add(glwpp::Context::PRIORITY_DEFAULT, [vert_err, frag_err](glwpp::Context& ctx, const glwpp::Context::ms&){
        std::cout << "Drawer debug" << std::endl;
        auto& v_err = vert_err.value();
        if (v_err.first){
            std::cout << "Msg: " << v_err.second.c_str() << std::endl;
        }

        auto& f_err = frag_err.value();
        if (f_err.first){
            std::cout << "Msg: " << f_err.second.c_str() << std::endl;
        }
        return false;
    });

    // glwpp::GL::ShaderRef vert(ctx, GL_VERTEX_SHADER, src_loc);
    // vert.source(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc);
    // vert.compile(src_loc);
    // auto vert_info = vert.getInfoLog(src_loc);
    
    // glwpp::GL::ShaderRef frag(ctx, GL_FRAGMENT_SHADER, src_loc);
    // frag.source(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc);
    // frag.compile(src_loc);
    // auto frag_info = frag.getInfoLog(src_loc);

    // glwpp::GL::ProgramRef prog(ctx, src_loc);
    // prog.attach(vert, src_loc);
    // prog.attach(frag, src_loc);
    // prog.link(src_loc);
    // auto prog_info = prog.getInfoLog(src_loc);

    // return std::make_tuple(vert_info, frag_info, prog_info);
}

int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.width = 1280;
    ctx_params.height = 1024;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto ctx = std::make_shared<glwpp::Context>(ctx_params);
    glwpp::ImGuiApi imgui(*ctx);
    glwpp::Value<std::string> name("Metrics");
    glwpp::Value<bool> opened(true);
    glwpp::Value<int> flags(0);
    
    auto gl_metrics = std::make_shared<glwpp::Metrics::Category>();
    ctx->gl.setMetricsCategory(gl_metrics);

    // init_drawer(*ctx);

    // glwpp

    // glwpp::GL::Buffer buffer(*ctx, glwpp::SrcLoc{});

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
    while(i < 5000){
        ++i;
        auto run_future = ctx->run();

        if (*opened){
            imgui.NewFrame();
            imgui.Begin(name, opened, flags);
            auto all_names = gl_metrics->getAllNames();
            std::sort(all_names.begin(), all_names.end());
            for (auto& name : all_names){
                imgui.Text(name + std::string(": ") + std::to_string((*gl_metrics)[name].getTotal().first));
            }
            imgui.End();
            imgui.Render();
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