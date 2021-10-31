#include "glwpp/utils/CmdQueue.hpp"

#include <iostream>

#include "glwpp/utils/DoubleQueue.hpp"

using namespace glwpp;

CmdQueue::CmdQueue(std::optional<Cmd> initializer,
                   std::optional<Cmd> finalizer) :
    _alive(true),
    _executing(false),
    _thread(_threadFunction, this, initializer, finalizer){
}

CmdQueue::~CmdQueue(){
    _alive = false;
    _cv_start.notify_all();
    if (_thread.joinable()){
        _thread.join();
    }
}

bool CmdQueue::isExecuting(){
    return _executing;
}

bool CmdQueue::execute(){
    if (_executing){
        return false;
    }

    {
        std::lock_guard<std::mutex> ul(_lock_execution);
        _executing = true;
    }
    _cv_start.notify_all();
    return true;
}

void CmdQueue::wait(){
    if (!_executing) return;

    std::unique_lock<std::mutex> ul(_lock_execution);
    _cv_finish.wait(ul, [&](){return !_executing && _alive;});
}

bool CmdQueue::waitFor(const std::chrono::duration<double, std::nano> time){
    if (!_executing) return true;

    std::unique_lock<std::mutex> ul(_lock_execution);
    return _cv_finish.wait_for(ul, time, [&](){return !_executing && _alive;});
}

void CmdQueue::_threadFunction(std::optional<Cmd> initializer,
                               std::optional<Cmd> finalizer){
    if (initializer){
        initializer.value()();
    }

    while(_alive){
        _executeQueue();
    }
    
    if (finalizer){
        finalizer.value()();
    }
}

void CmdQueue::_executeQueue(){
    std::unique_lock<std::mutex> ul(_lock_execution);
    _cv_start.wait(ul, [&](){return _executing || !_alive;});
    _queue.swap();
    ul.unlock();

    auto cur = _queue.pop();
    while (cur){
        cur.value()();
        cur = _queue.pop();
    }

    _executing = false;
    _cv_finish.notify_all();
};