#include "glwpp/utils/CmdLoop.hpp"

#include <iostream>

using namespace glwpp;

CmdLoop::CmdLoop(const std::function<void(CmdLoop&)> &init,
                 const std::function<void(CmdLoop&)> &final) :
    _alive(true),
    _thread(&CmdLoop::_loop, this, init, final){
}

CmdLoop::~CmdLoop(){
    _alive = false;
    _alive.notify_one();
    
    if (_thread.joinable()){
        _thread.join();
    }
}

WEvent<CmdLoop&> CmdLoop::onLoopStart(){
    return _onLoopStart;
}

WEvent<CmdLoop&> CmdLoop::onLoopRun(){
    return _onLoopRun;
}

WEvent<CmdLoop&> CmdLoop::onLoopEnd(){
    return _onLoopEnd;
}

WEvent<CmdLoop&> CmdLoop::onDestroy(){
    return _onDestroy;
}

void CmdLoop::_loop(std::function<void(CmdLoop&)> init,
                    std::function<void(CmdLoop&)> final){
    init(*this);

    while (_alive){
        // std::cout << _onLoopStart.size() << std::endl;
        _onLoopStart.emit(true, *this);
        _onLoopRun.emit(true, *this);
        _onLoopEnd.emit(true, *this);
    }

    _onDestroy.emit(true, *this);

    final(*this);
}