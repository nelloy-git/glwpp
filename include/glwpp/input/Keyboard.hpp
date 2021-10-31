#pragma once

#include <unordered_map>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/enums/Key.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/Event.hpp"

namespace glwpp::input {

class Keyboard {
public:
    Keyboard();
    virtual ~Keyboard();

    void capture(Context &ctx, bool flag);

    void press(Key key, KeyModeFlags mods);
    void release(Key key, KeyModeFlags mods);

    bool isDown(Key key) const;

    Event<const Keyboard&, const Key&, const KeyModeFlags&> onPress;
    
    Event<const Keyboard&, const Key&, const KeyModeFlags&> onRelease;

private:
    std::unordered_map<Key, bool> _down;
};

}