#pragma once

#include "Context.hpp"
#include "context/CallOptimizer.hpp"

struct ImGuiContext;
struct ImGuiIO;

namespace glwpp {

class ImGuiApi : protected CallOptimizer {
    Value<ImGuiContext*> _imgui_context;
public:
    using Error = std::pair<bool, std::string>;

    EXPORT ImGuiApi(Context& ctx);
    EXPORT virtual ~ImGuiApi();

    Value<std::future<Error>> init_error;

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> NewFrame() const {
        return callWithoutCtx<&_NewFrame, is_gl>();
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> Render() const {
        return callWithoutCtx<&_Render, is_gl>();
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<bool>> Begin(const Value<std::string>& name, const Value<bool>& p_open, const Value<int> flags) const {
        return callWithoutCtx<&_Begin, is_gl>(name, p_open, flags);
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> End() const {
        return callWithoutCtx<&_End, is_gl>();
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> Text(Valuable<const std::string&> auto&& text) const {
        return callWithoutCtx<&_Text, is_gl>(std::forward<decltype(text)>(text));
    }

private:

    EXPORT static void _NewFrame();
    EXPORT static void _Render();
    EXPORT static bool _Begin(const std::string& name, bool& p_open, int& flags);
    EXPORT static void _End();
    EXPORT static void _Text(const std::string& text);

    EXPORT static Error _InitImguiBackendGL(Context& ctx, ImGuiContext*& imgui_context);
    EXPORT static void _ShutdownImguiBackendGL();

    EXPORT static unsigned int& _GetInstancesInContext();

};



} // namespace glwpp