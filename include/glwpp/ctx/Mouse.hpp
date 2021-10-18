#pragma once

#include <unordered_map>

#include "glwpp/enums/MouseBtn.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/Event.hpp"

namespace glwpp {
    
class Mouse {
public:
    Mouse();
    virtual ~Mouse();

    void press(MouseBtn btn, KeyModeFlags modes);
    void release(MouseBtn btn, KeyModeFlags modes);
    void move(double x, double y);
    inline double getX(){return _x;};
    inline double getY(){return _y;};

    bool isDown(MouseBtn key) const;

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
