#pragma once

#include <filesystem>

#include "Context.hpp"
#include "context/CtxObj.hpp"


struct ImGuiContext;
struct ImGuiIO;

namespace ImGui {
    class FileBrowser;
}

namespace glwpp::imgui {

class FileBrowser : public CtxObj<FileBrowser> {
public:
    enum Flags {
        SelectDirectory   = 1 << 0, // select directory instead of regular file
        EnterNewFilename  = 1 << 1, // allow user to enter new filename when selecting regular file
        NoModal           = 1 << 2, // file browsing window is modal by default. specify this to use a popup window
        NoTitleBar        = 1 << 3, // hide window title bar
        NoStatusBar       = 1 << 4, // hide status bar at the bottom of browsing window
        CloseOnEsc        = 1 << 5, // close file browser when pressing 'ESC'
        CreateNewDir      = 1 << 6, // allow user to create new directory
        MultipleSelection = 1 << 7, // allow user to select multiple files. this will hide ImGuiFileBrowserFlags_EnterNewFilename
    };

    template<TState IsCtx = TState::Unknown>
    static Value<FileBrowser> Make(Valuable<Context&> auto&& ctx,
                                   Valuable<const Flags&> auto&& flags){
        auto browser = Value<FileBrowser>::Make(new FileBrowser(GetValuable(ctx)));
        browser->callMember<IsCtx, &FileBrowser::_init>(flags);
        return browser;
    }
    EXPORT virtual ~FileBrowser();

    template<TState IsCtx = TState::Unknown>
    auto setWindowPos(Valuable<const int&> auto&& x,
                      Valuable<const int&> auto&& y){
        return callMember<IsCtx, &FileBrowser::_setWindowPos>(x, y);
    }

    template<TState IsCtx = TState::Unknown>
    auto setWindowSize(Valuable<const int&> auto&& w,
                       Valuable<const int&> auto&& h){
        return callMember<IsCtx, &FileBrowser::_setWindowSize>(w, h);
    }

    template<TState IsCtx = TState::Unknown>
    auto setTitle(Valuable<const std::string&> auto&& title){
        return callMember<IsCtx, &FileBrowser::_setTitle>(title);
    }

    template<TState IsCtx = TState::Unknown>
    auto open(){
        return callMember<IsCtx, &FileBrowser::_open>();
    }

    template<TState IsCtx = TState::Unknown>
    auto close(){
        return callMember<IsCtx, &FileBrowser::_close>();
    }

    template<TState IsCtx = TState::Unknown>
    auto isOpened(){
        return callMember<IsCtx, &FileBrowser::_isOpened>();
    }

    template<TState IsCtx = TState::Unknown>
    auto draw(){
        return callMember<IsCtx, &FileBrowser::_draw>();
    }

    template<TState IsCtx = TState::Unknown>
    auto hasSelected(){
        return callMember<IsCtx, &FileBrowser::_hasSelected>();
    }

    template<TState IsCtx = TState::Unknown>
    auto setPwd(Valuable<const std::filesystem::path&> auto&& pwd){
        return callMember<IsCtx, &FileBrowser::_setPwd>();
    }

    template<TState IsCtx = TState::Unknown>
    auto getPwd(){
        return callMember<IsCtx, &FileBrowser::_getPwd>();
    }

    template<TState IsCtx = TState::Unknown>
    auto getSelected(){
        return callMember<IsCtx, &FileBrowser::_getSelected>();
    }

    template<TState IsCtx = TState::Unknown>
    auto getMultiSelected(){
        return callMember<IsCtx, &FileBrowser::_getMultiSelected>();
    }

    template<TState IsCtx = TState::Unknown>
    auto setTypeFilters(Valuable<const std::vector<std::string>&> auto&& typeFilters){
        return callMember<IsCtx, &FileBrowser::_setTypeFilters>();
    }

    template<TState IsCtx = TState::Unknown>
    auto setCurrentTypeFilterIndex(Valuable<const int&> auto&& index){
        return callMember<IsCtx, &FileBrowser::_setCurrentTypeFilterIndex>();
    }

    template<TState IsCtx = TState::Unknown>
    auto setInputName(Valuable<const std::string_view&> auto&& input){
        return callMember<IsCtx, &FileBrowser::_setInputName>();
    }

private:
    std::unique_ptr<ImGui::FileBrowser> _imgui_fb;

    EXPORT FileBrowser(Context& ctx);
    EXPORT void _init(const Flags& flags);

    void _setWindowPos(const int& x, const int& y);
    void _setWindowSize(const int& w, const int& h);
    void _setTitle(const std::string& title);
    void _open();
    void _close();
    bool _isOpened() const;
    void _draw();
    bool _hasSelected() const;
    bool _setPwd(const std::filesystem::path& pwd);
    const std::filesystem::path& _getPwd() const;
    std::filesystem::path _getSelected() const;
    std::vector<std::filesystem::path> _getMultiSelected() const;
    void _setTypeFilters(const std::vector<std::string>& typeFilters);
    void _setCurrentTypeFilterIndex(const int& index);
    void _setInputName(const std::string_view& input);
};



} // namespace glwpp::imgui