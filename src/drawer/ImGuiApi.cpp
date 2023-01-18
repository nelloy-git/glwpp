#include "drawer/ImGuiApi.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "utils/FuncWrapper.hpp"

using namespace glwpp;

thread_local ImGuiContext* MyImGuiTLS = nullptr;

ImGuiApi::ImGuiApi(Context& ctx) :
    CtxObj(ctx){
    call<TState::Unknown>(&_InitImguiBackendGL);
}

ImGuiApi::~ImGuiApi(){
    // call<TState::Unknown>(&_ShutdownImguiBackendGL);
}

void ImGuiApi::_NewFrame(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiApi::_Render(){
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool ImGuiApi::_Begin(const std::string& name, bool* p_open, int& flags){
    return ImGui::Begin(name.c_str(), p_open, flags);
}

void ImGuiApi::_End(){
    ImGui::End();
}

void ImGuiApi::_Text(const std::string& text){
    ImGui::Text(text.c_str());
}

void ImGuiApi::_InitImguiBackendGL(Context& ctx){
    if (_GetInstancesInContext() > 1){  
        return;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    if (!ImGui_ImplGlfw_InitForOpenGL(&ctx.getGlfw(), true)){
        throw std::runtime_error("ImGui_ImplGlfw_InitForOpenGL failed");
    }

    if (!ImGui_ImplOpenGL3_Init("#version 130")){
        throw std::runtime_error("ImGui_ImplOpenGL3_Init(\"#version 130\") failed");
    }

    ++_GetInstancesInContext();
    return;
}

void ImGuiApi::_ShutdownImguiBackendGL(){
    --_GetInstancesInContext();
    if (_GetInstancesInContext() != 0 || MyImGuiTLS == nullptr){
        return;
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    MyImGuiTLS = nullptr;
}

unsigned int& ImGuiApi::_GetInstancesInContext(){
    static thread_local unsigned int count = 0;
    return count;
}