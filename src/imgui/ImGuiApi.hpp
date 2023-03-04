#pragma once

#include "Context.hpp"
#include "context/CtxObj.hpp"

struct ImGuiContext;
struct ImGuiIO;

namespace glwpp {

class ImGuiApi : public CtxObj<ImGuiApi> {
public:
    static Value<ImGuiApi> Make(Valuable<Context&> auto&& ctx){
        return Value<ImGuiApi>::Make(new ImGuiApi(GetValuable(ctx)));
    }
    EXPORT virtual ~ImGuiApi();

    template<TState IsCtx = TState::Unknown>
    auto ShowDemo(Valuable<bool> auto&& p_open){
        return callMember<IsCtx, &ImGuiApi::_ShowDemo>(p_open);
    }

    template<TState IsCtx = TState::Unknown>
    auto NewFrame(){
        return callMember<IsCtx, &ImGuiApi::_NewFrame>();
    }

    template<TState IsCtx = TState::Unknown>
    auto Render(){
        return callMember<IsCtx, &ImGuiApi::_Render>();
    }

    template<TState IsCtx = TState::Unknown>
    auto Begin(Valuable<const std::string&> auto&& name,
               Valuable<bool> auto&& p_open,
               Valuable<int> auto&& flags){
        return callMember<IsCtx, &ImGuiApi::_Begin>(name, p_open, flags);
    }

    template<TState IsCtx = TState::Unknown>
    auto End(){
        return callMember<IsCtx, &ImGuiApi::_End>();
    }

    template<TState IsCtx = TState::Unknown>
    auto Text(Valuable<const std::string&> auto&& text){
        return callMember<IsCtx, &ImGuiApi::_Text>(text);
    }

    template<TState IsCtx = TState::Unknown>
    auto Button(Valuable<const std::string&> auto&& label,
                Valuable<const float&> auto&& w,
                Valuable<const float&> auto&& h){
        return callMember<IsCtx, &ImGuiApi::_Button>(label, w, h);
    }

    template<TState IsCtx = TState::Unknown>
    auto SameLine(){
        return callMember<IsCtx, &ImGuiApi::_SameLine>();
    }

    template<TState IsCtx = TState::Unknown>
    auto PushID(Valuable<const int&> auto&& id){
        return callMember<IsCtx, &ImGuiApi::_PushID>();
    }

    template<TState IsCtx = TState::Unknown>
    auto PopID(){
        return callMember<IsCtx, &ImGuiApi::_PopID>();
    }

private:
    EXPORT ImGuiApi(Context& ctx);

    EXPORT void _ShowDemo(bool& p_open);

    EXPORT void _NewFrame();
    EXPORT void _Render();
    EXPORT bool _Begin(const std::string& name, bool& p_open, int& flags);
    EXPORT void _End();
    EXPORT void _Text(const std::string& text);
    EXPORT bool _Button(const std::string& label, const float& w, const float& h);
    EXPORT void _SameLine();
    EXPORT void _PushID(const int& id);
    EXPORT void _PopID();

    EXPORT static void _InitImguiBackendGL(Context& ctx);
    EXPORT static void _ShutdownImguiBackendGL();

    EXPORT static unsigned int& _GetInstancesInContext();

};



} // namespace glwpp