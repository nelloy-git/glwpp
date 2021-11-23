#pragma once

#include <thread>

#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp {

class CmdLoop final {
public:
    CmdLoop(const std::function<void(CmdLoop&)> &init,
            const std::function<void(CmdLoop&)> &final);
    ~CmdLoop();

    // TODO priority map
    WEvent<CmdLoop&> onLoopStart();
    WEvent<CmdLoop&> onLoopRun();
    WEvent<CmdLoop&> onLoopEnd();
    WEvent<CmdLoop&> onDestroy();

private:
    SEvent<CmdLoop&> _onLoopStart;
    SEvent<CmdLoop&> _onLoopRun;
    SEvent<CmdLoop&> _onLoopEnd;
    SEvent<CmdLoop&> _onDestroy;

    std::atomic<bool> _alive;
    std::thread _thread;
    void _loop(std::function<void(CmdLoop&)> init,
               std::function<void(CmdLoop&)> final);
};

}