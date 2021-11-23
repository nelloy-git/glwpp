#pragma once

#include <unordered_map>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/enums/Key.hpp"
#include "glwpp/enums/KeyMod.hpp"
#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp::input {

class Keyboard {
public:
    Keyboard();
    virtual ~Keyboard();

    bool capture(std::weak_ptr<Context> wctx, bool flag);

    void press(Key key, KeyModeFlags mods);
    void release(Key key, KeyModeFlags mods);

    bool is_down(Key key) const;

    WEvent<const Keyboard&, const Key&, const KeyModeFlags&> onPress();
    WEvent<const Keyboard&, const Key&, const KeyModeFlags&> onRelease();

private:
    sptr<Watcher> _watcher;
    SEvent<const Keyboard&, const Key&, const KeyModeFlags&> _onPress;
    SEvent<const Keyboard&, const Key&, const KeyModeFlags&> _onRelease;
    
    std::unordered_map<Key, bool> _down;
};

}