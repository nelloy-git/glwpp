#pragma once

#include "glwpp/utils/Event.hpp"

namespace glwpp {
    class Context;
}

namespace glwpp::input {

class SystemCall {
public:
    SystemCall();
    virtual ~SystemCall();

    bool capture(std::weak_ptr<Context> wctx, bool flag);

    Event<SystemCall&> onClose;

private:
    std::shared_ptr<CmdWatcher> _captures;

};

}