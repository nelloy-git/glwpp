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

    template<TState IsCtx>
    auto NewFrame(){
        return callMember<IsCtx, &ImGuiApi::_NewFrame>();
    }

    template<TState IsCtx>
    auto Render(){
        return callMember<IsCtx, &ImGuiApi::_Render>();
    }

    template<TState IsCtx>
    auto Begin(Valuable<const std::string&> auto&& name,
               Valuable<bool*> auto&& p_open,
               Valuable<int> auto&& flags){
        return callMember<IsCtx, &ImGuiApi::_Begin>(name, p_open, flags);
    }

    template<TState IsCtx>
    auto End(){
        return callMember<IsCtx, &ImGuiApi::_End>();
    }

    template<TState IsCtx>
    auto Text(Valuable<const std::string&> auto&& text){
        return callMember<IsCtx, &ImGuiApi::_Text>(text);
    }

private:
    EXPORT ImGuiApi(Context& ctx);

    EXPORT void _NewFrame();
    EXPORT void _Render();
    EXPORT bool _Begin(const std::string& name, bool* p_open, int& flags);
    EXPORT void _End();
    EXPORT void _Text(const std::string& text);

    EXPORT static void _InitImguiBackendGL(Context& ctx);
    EXPORT static void _ShutdownImguiBackendGL();

    EXPORT static unsigned int& _GetInstancesInContext();

};



} // namespace glwpp