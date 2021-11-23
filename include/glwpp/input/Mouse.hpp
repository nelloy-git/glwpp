#pragma once

#include <unordered_map>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/enums/MouseBtn.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp::input {
    
class Mouse {
public:
    Mouse();
    virtual ~Mouse();

    bool capture(std::weak_ptr<Context> wctx, bool flag);

    void press(MouseBtn btn, KeyModeFlags modes);
    void release(MouseBtn btn, KeyModeFlags modes);
    void move(double x, double y);
    void enter();
    void leave();
    inline double get_x(){return _x;};
    inline double get_y(){return _y;};

    bool is_down(MouseBtn btn) const;

    WEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> onPress();
    WEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> onRelease();
    WEvent<const Mouse&, const double&, const double&> onMove();
    WEvent<const Mouse&> onEnter();
    WEvent<const Mouse&> onLeave();

private:
    sptr<Watcher> _watcher;
    SEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> _onPress;
    SEvent<const Mouse&, const MouseBtn&, const KeyModeFlags&> _onRelease;
    SEvent<const Mouse&, const double&, const double&> _onMove;
    SEvent<const Mouse&> _onEnter;
    SEvent<const Mouse&> _onLeave;

    double _x;
    double _y;
    std::unordered_map<MouseBtn, bool> _down;
};

}
