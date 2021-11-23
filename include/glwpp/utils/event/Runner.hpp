#pragma once

#include <functional>
#include <variant>

#include "glwpp/utils/Ptr.hpp"
#include "glwpp/utils/event/Watcher.hpp"
#include "glwpp/utils/FuncWrapper.hpp"

namespace glwpp {
template<class R, class ... Args>
class Runner;

template<class R, class ... Args>
class Runner<R(Args...)> final {
public:
    template<class F>
    Runner(const wptr<Watcher> &watcher, const F &cmd) :
        _watcher(watcher),
        _cmd(func_wrap<Args...>(std::function(cmd))){
        auto watch = _watcher.lock();
        if (watch) watch->lock_use();
    };

    ~Runner(){
        auto watch = _watcher.lock();
        if (watch) watch->unlock_use();
    }

    std::variant<R, std::exception_ptr> run(Args&&... args) const {
        auto watch = _watcher.lock();
        if (!watch) throw std::bad_weak_ptr();

        watch->lock_running();

        std::variant<R, std::exception_ptr> result;
        try {
            result = _cmd(std::forward<Args>(args)...);
            watch->unlock_running(true);
        } catch (...) {
            result = std::current_exception();
            watch->unlock_running(false);
        }
        return result;
    }

    wptr<Watcher> get_watcher() const {return _watcher;}

private:
    wptr<Watcher> _watcher;
    std::function<R(Args...)> _cmd;
};

}