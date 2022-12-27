#ifdef WIN32
// #include <vld.h>
#endif

// #include "glad/gl.h"
#include <string>
#include <fstream>
#include <streambuf>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Context.hpp"
#include "model/Model.hpp"
#include "Drawer.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"
#include "gl_object/Shader.hpp"
// #include "gl_object/BufferVector.hpp"

void add_imgui(const std::shared_ptr<glwpp::Context>& ctx){
    auto gl_metrics = std::make_shared<glwpp::Metrics::Category>();
    ctx->gl.setMetricsCategory(gl_metrics);

    ctx->on_run_gl.add([](glwpp::Context& ctx, const glwpp::Context::ms&){
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        if (!ImGui_ImplGlfw_InitForOpenGL(ctx.getGlfw().get(), true) || !ImGui_ImplOpenGL3_Init("#version 130")){
            std::cout << "ImGui error" << std::endl;
        }
        return false;
    });

    // glwpp::Metrics::inst()["ImGui::Render"].value_period() = std::chrono::seconds(1);
    // glwpp::Metrics::inst()["ImGui::Render"].max_values() = 10;

    auto show_demo_window = new bool(true);
    ctx->on_run_gl.add([show_demo_window, gl_metrics](glwpp::Context& ctx, const glwpp::Context::ms&){
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        ImGui::ShowDemoWindow(show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            ImGui::Begin("Metrics");                          // Create a window called "Hello, world!" and append into it.

            auto all_names = gl_metrics->getAllNames();
            std::sort(all_names.begin(), all_names.end());
            for (auto& name : all_names){
                ImGui::Text("%s: %d", name.c_str(), (*gl_metrics)[name].getTotal().first);
            }
            // ImGui::Text("FPS: %0.1f (%.1fms)", 1000 / glwpp::Metrics::inst()["ImGui::Render"].getAvg(), glwpp::Metrics::inst()["ImGui::Render"].getAvg());
            // for (auto& pair : glwpp::Metrics::inst().getLast()){
            //     ImGui::Text("%s: %.1f (%zu)", pair.first.c_str(), pair.second.value, pair.second.count);
            // }
            ImGui::End();
        }

        // 3. Show another simple window.
        // if (show_another_window)
        // {
            // ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        //     ImGui::Text("Hello from another window!");
        //     if (ImGui::Button("Close Me"))
        //         show_another_window = false;
        //     ImGui::End();
        // }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(ctx.getGlfw().get(), &display_w, &display_h);
        ctx.gl.Viewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // glwpp::Metrics::inst()["ImGui::Render"] += static_cast<double>(dt.count());

        return true;
    });
}

std::string read_file(const std::string& path){
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

auto init_drawer(glwpp::Context& ctx, const glwpp::SrcLoc& src_loc = glwpp::SrcLoc{}){
    glwpp::Drawer drawer(ctx, src_loc);
    auto vert_err = drawer.setVertexShader(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc);
    auto frag_err = drawer.setFragmentShader(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc);

    ctx.after_run_any.add([vert_err, frag_err](glwpp::Context& ctx, const glwpp::Context::ms&){
        if (vert_err->value().first or frag_err->value().first){
            std::cout << vert_err->value().second.c_str() << std::endl;
            std::cout << frag_err->value().second.c_str() << std::endl;
        }
        return false;
    });

    // glwpp::GL::Shader vert(ctx, GL_VERTEX_SHADER, src_loc);
    // vert.source(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"), src_loc);
    // vert.compile(src_loc);
    // auto vert_info = vert.getInfoLog(src_loc);
    
    // glwpp::GL::Shader frag(ctx, GL_FRAGMENT_SHADER, src_loc);
    // frag.source(read_file("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"), src_loc);
    // frag.compile(src_loc);
    // auto frag_info = frag.getInfoLog(src_loc);

    // glwpp::GL::Program prog(ctx, src_loc);
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
    add_imgui(ctx);

    init_drawer(*ctx);

    // glwpp

#ifdef WIN32
    glwpp::Model book_model(*ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\test\\models\\book\\scene.gltf");
#else
    glwpp::Model book_model(*ctx, "/home/sbugrov/glwpp/test/models/book/scene.gltf");
#endif

    if (book_model.loading_error.has_value()){
        std::cout << book_model.loading_error.value().c_str() << std::endl;
    }

    bool done = false;
    while(true){
        ctx->run().wait();
        if (!done){
            done = true;

            // std::cout << "VertInfo:\n" << std::get<0>(info).value().value_or("").c_str() << std::endl;
            // std::cout << "FragInfo:\n" << std::get<1>(info).value().value_or("").c_str() << std::endl;
            // std::cout << "ProgInfo:\n" << std::get<2>(info).value().value_or("").c_str() << std::endl;
            // std::cout << std::get<2>(info).value().c_str() << std::endl;
            // std::cout << *buf.id() << std::endl;
            // std::cout << *buf.id() << std::endl;
        }

        // std::cout << glwpp::Metrics::inst()["ImGui::Render"].getLast().value << std::endl;
    }
}