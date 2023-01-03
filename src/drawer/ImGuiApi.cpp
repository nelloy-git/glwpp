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
    CallOptimizer(ctx),
    _imgui_context(ctx, nullptr),
    init_error(call<&_InitImguiBackendGL, IsGlThread::Unknown>(_imgui_context)){
}

ImGuiApi::~ImGuiApi(){
    callWithoutCtx<&_ShutdownImguiBackendGL, IsGlThread::Unknown>();
    // TODO
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

bool ImGuiApi::_Begin(const std::string& name, bool& p_open, int& flags){
    return ImGui::Begin(name.c_str(), &p_open, flags);
}

void ImGuiApi::_End(){
    ImGui::End();
}

void ImGuiApi::_Text(const std::string& text){
    ImGui::Text(text.c_str());
}

ImGuiApi::Error ImGuiApi::_InitImguiBackendGL(Context& ctx, ImGuiContext*& imgui_context){
    if (_GetInstancesInContext() > 1){
        imgui_context = ImGui::GetCurrentContext();
        return {false, std::string{}};
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    if (!ImGui_ImplGlfw_InitForOpenGL(ctx.getGlfw().get(), true)){
        return {true, "ImGui_ImplGlfw_InitForOpenGL failed"};
    }

    if (!ImGui_ImplOpenGL3_Init("#version 130")){
        return {true, "ImGui_ImplOpenGL3_Init(\"#version 130\") failed"};
    }

    ++_GetInstancesInContext();
    return {false, std::string{}};
}

void ImGuiApi::_ShutdownImguiBackendGL(){
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