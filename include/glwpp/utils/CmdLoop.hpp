#pragma once

#include "glwpp/utils/event/SEvent.hpp"

namespace glwpp {

class CmdLoop final {
public:
    CmdLoop(Cmd<void, CmdLoop&> &init,
            Cmd<void, CmdLoop&> &final);
    ~CmdLoop();

    // std::weak_ptr<Event<CmdLoop&>> onLoopStart();
    // std::weak_ptr<Event<CmdLoop&>> onLoopRun();
    // std::weak_ptr<Event<CmdLoop&>> onLoopEnd();
    // std::weak_ptr<Event<CmdLoop&>> onDestroy();

private:
    SEvent<CmdLoop&> _onLoopStart;
    SEvent<CmdLoop&> _onLoopRun;
    SEvent<CmdLoop&> _onLoopEnd;
    SEvent<CmdLoop&> _onDestroy;
};

}