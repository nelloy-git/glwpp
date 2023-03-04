#include "context/CtxObj.hpp"
#include "imgui/ImGuiApi.hpp"
#include "imgui/FileBrowser.hpp"

namespace glwpp::test {

class Menu : public CtxObj<Menu> {
public:
    static Value<Menu> Make(Valuable<Context&> auto&& ctx){
        return Value<Menu>::Make(new Menu(GetValuable(ctx)));
    }
    virtual ~Menu();

    template<TState IsCtx>
    auto draw() const {return callMember<IsCtx, &Menu::_draw>();}
    
    template<TState IsCtx>
    auto isVisible() const {return callMember<IsCtx, &Menu::_isVisible>();}
    
    template<TState IsCtx>
    auto setVisible(Valuable<bool> auto&& flag){return callMember<IsCtx, &Menu::_setVisible>(flag);};

private:
    Value<ImGuiApi> _imgui;
    Value<imgui::FileBrowser> _filebrowser;
    std::string* _filebrowser_result;

    Value<std::string> _window_name;
    Value<int> _window_flags;
    Value<bool> _window_visible;

    Menu(Context& ctx);

    EXPORT void _draw() const;
    EXPORT bool _isVisible() const;
    EXPORT void _setVisible(bool flag);

    EXPORT void _drawFileSelector() const;

};
    
} // namespace glwpp