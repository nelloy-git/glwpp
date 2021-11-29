#include "glwpp/utils/CmdLoop.hpp"

#include <iostream>

using namespace glwpp;

CmdLoop::CmdLoop(std::function<void(CmdLoop&)> init,
                 std::function<void(CmdLoop&)> final) :
    _alive(true),
    _stopped(true),
    _runs(0),
    _thread(&CmdLoop::_loop, this, init, final){
}

CmdLoop::~CmdLoop(){
    _alive = false;
    _alive.notify_one();

    _stopped = false;
    _stopped.notify_one();
    
    if (_thread.joinable()){
        _thread.join();
    }
}

void CmdLoop::start(){
    _stopped = false;
    _stopped.notify_one();
}

void CmdLoop::stop(){
    _stopped = true;
    _stopped.notify_one();
}

bool CmdLoop::isRunning(){
    bool running = !_running.try_lock();
    if (!running) _running.unlock();
    return running;
}

void CmdLoop::waitRun(){
    std::lock_guard lock(_running);
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
        std::unique_lock lock(_running);
        if (_stopped){
            lock.unlock();
            _stopped.wait(true);
            lock.lock();
        }

        _onLoopStart.emit(true, *this);
        _onLoopRun.emit(true, *this);
        _onLoopEnd.emit(true, *this);
        _runs++;
        _runs.notify_all();
    }

    _onDestroy.emit(true, *this);

    final(*this);
}