#include "imgui/FileBrowser.hpp"

#include "imgui.h"
#include "imfilebrowser.h"

using namespace glwpp;
using namespace glwpp::imgui;

FileBrowser::FileBrowser(Context& ctx) :
    CtxObj(ctx){
}

FileBrowser::~FileBrowser(){
}

void FileBrowser::_init(const Flags& flags){
    _imgui_fb = std::make_unique<ImGui::FileBrowser>(flags);
}

void FileBrowser::_setWindowPos(const int& x, const int& y) {
    _imgui_fb->SetWindowPos(x, y);
}

void FileBrowser::_setWindowSize(const int& w, const int& h) {
    _imgui_fb->SetWindowSize(w, h);
}

void FileBrowser::_setTitle(const std::string& title) {
    _imgui_fb->SetTitle(title);
}

void FileBrowser::_open() {
    _imgui_fb->Open();
}

void FileBrowser::_close() {
    _imgui_fb->Close();
}

bool FileBrowser::_isOpened() const {
    return _imgui_fb->IsOpened();
}

void FileBrowser::_draw() {
    _imgui_fb->Display();
}

bool FileBrowser::_hasSelected() const {
    return _imgui_fb->HasSelected();
}

bool FileBrowser::_setPwd(const std::filesystem::path& pwd) {
    return _imgui_fb->SetPwd(pwd);
}

const std::filesystem::path& FileBrowser::_getPwd() const {
    return _imgui_fb->GetPwd();
}

std::filesystem::path FileBrowser::_getSelected() const {
    return _imgui_fb->GetSelected();
}

std::vector<std::filesystem::path> FileBrowser::_getMultiSelected() const {
    return _imgui_fb->GetMultiSelected();
}

void FileBrowser::_setTypeFilters(const std::vector<std::string>& typeFilters) {
    _imgui_fb->SetTypeFilters(typeFilters);
}

void FileBrowser::_setCurrentTypeFilterIndex(const int& index) {
    _imgui_fb->SetCurrentTypeFilterIndex(index);
}

void FileBrowser::_setInputName(const std::string_view& input) {
    _imgui_fb->SetInputName(input);
}
