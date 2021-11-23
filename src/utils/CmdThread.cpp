#include "glwpp/utils/CmdThread.hpp"

using namespace glwpp;

CmdThread::CmdThread(Cmd<void, CmdThread&> &init,
                     Cmd<void, CmdThread&> &final) :
    _alive(true),
    _empty(true),
    _thread(&CmdThread::_threadFunction, this, init, final){
}

CmdThread::~CmdThread(){
    _alive = false;
    _alive.notify_one();
    
    _empty = true;
    _empty.notify_one();
    
    if (_thread.joinable()){
        _thread.join();
    }
}

void CmdThread::_threadFunction(Cmd<void, CmdThread&> init,
                                Cmd<void, CmdThread&> final){
    init(*this);

    while(_alive){
        _empty.wait(true);

        auto opt_runner = _queue.pop();
        while (opt_runner && _alive){
            auto runner = opt_runner.value();
            auto res = (runner->run(*this)).value_or(CmdAct::Stop);

            switch (res){
            case CmdAct::Repeat:
                _queue.push(runner);
                break;
            case CmdAct::Stop:            
            default:
                break;
            }
            
            opt_runner = _queue.pop();
        };

        _empty = _queue.size() == 0;
    }
    
    final(*this);
}