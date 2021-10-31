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

    void capture(Context &ctx, bool flag);

    Event<const SystemCall&> onClose;
};

}