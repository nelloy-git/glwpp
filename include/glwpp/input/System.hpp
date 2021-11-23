#pragma once

#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp {
    class Context;
}

namespace glwpp::input {

class SystemCall {
public:
    SystemCall();
    virtual ~SystemCall();

    bool capture(std::weak_ptr<Context> wctx, bool flag);

    void close();

    WEvent<SystemCall&> onClose();

private:
    sptr<Watcher> _watcher;

    SEvent<SystemCall&> _onClose;
};

}