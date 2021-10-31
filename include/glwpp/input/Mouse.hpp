#pragma once

#include <unordered_map>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/enums/MouseBtn.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/Event.hpp"

namespace glwpp::input {
    
class Mouse {
public:
    Mouse();
    virtual ~Mouse();

    void capture(Context &ctx, bool flag);

    void press(MouseBtn btn, KeyModeFlags modes);
    void release(MouseBtn btn, KeyModeFlags modes);
    void move(double x, double y);
    inline double getX(){return _x;};
    inline double getY(){return _y;};

    bool isDown(MouseBtn btn) const;

    Event<const Mouse&, const MouseBtn&, const KeyModeFlags&> onPress;
    Event<const Mouse&, const MouseBtn&, const KeyModeFlags&> onRelease;
    Event<const Mouse&, const double&, const double&> onMove;
    Event<const Mouse&> onEnter;
    Event<const Mouse&> onLeave;

private:
    double _x;
    double _y;
    std::unordered_map<MouseBtn, bool> _down;
};

}
