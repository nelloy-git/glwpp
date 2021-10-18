#pragma once

#include <unordered_map>

#include "glwpp/enums/Key.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/Event.hpp"

namespace glwpp {

class Keyboard {
public:
    Keyboard();
    virtual ~Keyboard();

    void press(Key key, KeyModeFlags mods);
    void release(Key key, KeyModeFlags mods);

    bool isDown(Key key) const;

    Event<const Keyboard&, const Key&, const KeyModeFlags&> onPress;
    using onPressCB = decltype(onPress)::Func;
    
    Event<const Keyboard&, const Key&, const KeyModeFlags&> onRelease;
    using onReleaseCB = decltype(onRelease)::Func;

private:
    std::unordered_map<Key, bool> _down;
};

}