#include "drawer/ImGuiApi.hpp"

namespace glwpp {

class ImGuiMainTest : public CtxObj<ImGuiMainTest> {
public:
    ImGuiMainTest();
    ~ImGuiMainTest();

    template<TState IsCtx>
    auto isVisible() const {return callMember<IsCtx, &ImGuiMainTest::_isVisible>();}
    auto setVisible(Valuable<bool> auto&& flag){return callMember<IsCtx, &ImGuiMainTest::_setVisible>(flag);};

private:
    bool _visible = true;

    EXPORT bool _isVisible() const;
    EXPORT void _setVisible(bool flag);

};
    
} // namespace glwpp