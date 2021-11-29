#pragma once

#include <thread>

#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp {

class CmdLoop final {
public:
    CmdLoop(std::function<void(CmdLoop&)> init = [](CmdLoop&){},
            std::function<void(CmdLoop&)> final = [](CmdLoop&){});
    ~CmdLoop();

    void start();
    void stop();
    bool isRunning();
    void waitRun();

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
    std::atomic<bool> _stopped;
    std::mutex _running;
    std::atomic<size_t> _runs;
    std::thread _thread;
    void _loop(std::function<void(CmdLoop&)> init,
               std::function<void(CmdLoop&)> final);
};

}