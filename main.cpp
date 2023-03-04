#ifdef WIN32
#include <vld.h>
#endif

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <streambuf>

#include <filesystem>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Context.hpp"
#include "model/Model.hpp"
// #include "Drawer.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"
#include "gl_object/Shader.hpp"
// #include "gl_object/BufferVector.hpp"

#include "imgui/ImGuiApi.hpp"
#include "imgui/FileBrowser.hpp"

#include "test/TestMenu.hpp"

#include "GLapi.hpp"

#include "context/CtxWrapper.hpp"
#include "imgui.h"
#include "imfilebrowser.h"

std::string read_file(const std::string& path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

// auto init_drawer(glwpp::Context& ctx,
//                  const std::string& vert_path,
//                  const std::string& frag_path,
//                  const glwpp::SrcLoc& src_loc = glwpp::SrcLoc{}){
//     auto drawer = glwpp::Drawer::Make(ctx, src_loc);
//     drawer->on_shader_error.add<[](auto& drawer, const auto& err){
//         std::cout << "Msg: " << err.second.c_str() << std::endl;
//         return true;
//     }>(ctx.PRIORITY_DEFAULT, src_loc);
    
//     std::cout << "vert: " << vert_path.c_str() << std::endl;
//     drawer->setShader(glwpp::GL_VERTEX_SHADER, read_file(vert_path), src_loc.add());

//     std::cout << "frag: " << frag_path.c_str() << std::endl;
//     drawer->setShader(glwpp::GL_FRAGMENT_SHADER, read_file(frag_path), src_loc.add());
    // drawer->setShader(glwpp::GL_VERTEX_SHADER, read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc.add());
    // drawer->setShader(glwpp::GL_FRAGMENT_SHADER, read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc.add());

//     return drawer;
// }

int main(int argc, char **argv){
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i){
        std::cout << argv[i] << "...";
        args.push_back(argv[i]);
    }
    std::cout << std::endl;

    std::string vert_path;
    for (int i = 0; i < argc; ++i){
        if (args[i] == "-vert"){
            vert_path = args[i+1];
            break;
        }
    }

    std::string frag_path;
    for (int i = 0; i < argc; ++i){
        if (args[i] == "-frag"){
            frag_path = args[i+1];
            break;
        }
    }

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

    // auto drawer = init_drawer(*ctx, vert_path, frag_path);

    auto test_menu = glwpp::test::Menu::Make(*ctx);


    const glwpp::Ref<unsigned int> fb_flags(0);
    auto file_browser = glwpp::CtxWrapper<ImGui::FileBrowser>::Make<false>(*ctx, fb_flags);
    auto file_browser2 = file_browser;
    // wrapped->init<false>(fb_flags);
    file_browser2->member<false, &ImGui::FileBrowser::Open>();
    // file_browser->callWrapped<glwpp::TState::False, &ImGui::FileBrowser::Open>();

    using t = glwpp::GetValuableT<decltype(fb_flags)>::type;

    bool done = false;
    while(opened.value()){
        auto run_future = ctx->run();

        if (opened.value()){
            imgui->NewFrame<glwpp::TState::False>();
            imgui->Begin<glwpp::TState::False>(name, opened, flags);
            auto all_names = gl_metrics->getAllNames();
            std::sort(all_names.begin(), all_names.end());
            for (auto& name : all_names){
                imgui->Text<glwpp::TState::False>(name + std::string(": ") + std::to_string((*gl_metrics)[name].getTotal().first));
            }
            imgui->End<glwpp::TState::False>();

            file_browser->member<false, &ImGui::FileBrowser::Display>();

            imgui->ShowDemo<glwpp::TState::False>(opened);
            test_menu->draw<glwpp::TState::False>();

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

// MESA_GL_VERSION_OVERRIDE=4.6 ./glwpp_test -vert ../shaders/vertex_3d.vs -frag ../shaders/vertex_3d.fs