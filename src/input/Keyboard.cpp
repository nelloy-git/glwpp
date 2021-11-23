#include "glwpp/input/Keyboard.hpp"

#include "glwpp/utils/LinkMap.hpp"

using namespace glwpp::input;

namespace {
    glwpp::LinkMap<GLFWwindow, Keyboard> _links;

    void _gltfKeyCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mode){
        auto links = _links.get(glfw_win);
        if (!links) return;

        for (auto kb : *links){
            if (action == GLFW_PRESS){
                kb->press(static_cast<Key>(key), mode);
            } else if (action == GLFW_RELEASE){
                kb->release(static_cast<Key>(key), mode);
            }
        }
    }
}

Keyboard::Keyboard() {
    _watcher = make_sptr<Watcher>();
}

Keyboard::~Keyboard(){
    _links.remove(this);
}

bool Keyboard::capture(std::weak_ptr<Context> wctx, bool flag){
    auto ctx = wctx.lock();
    if (!ctx) return false;

    ctx->onLoopStart().push_back(_watcher, [this, wctx, flag](){
        auto ctx = wctx.lock();
        if (!ctx) return EventAction::Stop;

        if (flag){
            auto keyboards = _links.get(ctx->getGlfwWindow());
            _links.add(ctx->getGlfwWindow(), this);

            if (!keyboards){
                glfwSetKeyCallback(ctx->getGlfwWindow(), _gltfKeyCallback);
            }
        } else {
            _links.remove(ctx->getGlfwWindow(), this);
        }

        return EventAction::Stop;
    });

    ctx->onDestroy().push_back(_watcher, [](Context& ctx){
        _links.remove(ctx.getGlfwWindow());
        return EventAction::Stop;
    });

    return true;
}

void Keyboard::press(Key key, KeyModeFlags mods){
    _down[key] = true;
    _onPress.emit(true, *this, key, mods);
}

void Keyboard::release(Key key, KeyModeFlags mods){
    _down.erase(key);
    _onRelease.emit(true, *this, key, mods);
}

bool Keyboard::is_down(Key key) const {
    return _down.find(key) != _down.end();
}

glwpp::WEvent<const Keyboard&, const Key&, const KeyModeFlags&> Keyboard::onPress(){
    return _onPress;
}

glwpp::WEvent<const Keyboard&, const Key&, const KeyModeFlags&> Keyboard::onRelease(){
    return _onRelease;
}
