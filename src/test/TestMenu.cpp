#include "test/TestMenu.hpp"

using namespace glwpp;
using namespace glwpp::test;

Menu::Menu(Context& ctx) :
    CtxObj(ctx),
    _imgui(ImGuiApi::Make(ctx)),
    _filebrowser(imgui::FileBrowser::Make(ctx, (imgui::FileBrowser::Flags)0)),
    _window_name("TestMenu"),
    _window_flags(0),
    _window_visible(true){
}

Menu::~Menu(){}

void Menu::_draw() const {
    _imgui->Begin<TState::True>(_window_name, _window_visible, _window_flags);

    _drawFileSelector();

    _imgui->End<TState::True>();
}

bool Menu::_isVisible() const {
    return _window_visible.value();
}

void Menu::_setVisible(bool flag){
    _window_visible = flag;
}

void Menu::_drawFileSelector() const {
    _imgui->Text<TState::True>("Path");
    _imgui->SameLine<TState::True>();

    auto pressed = _imgui->Button<TState::True>("...", 0, 0);
    if (pressed){
        _filebrowser->open<TState::True>();
    }

    auto selected = _filebrowser->hasSelected<TState::True>();
    if (selected && _filebrowser->isOpened<TState::True>()){
        auto path = _filebrowser->getSelected<TState::True>();
    }
    _filebrowser->draw<TState::True>();
}