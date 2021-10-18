#include "glwpp/utils/CmdQueue.hpp"

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

void CmdQueue::push(const Cmd cmd){
    std::lock_guard<std::mutex> lg(_lock_queue);
    _queue.push(cmd);
};

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
    std::unique_lock<std::mutex> ul(_lock_execution);
    _cv_finish.wait(ul, [&](){return !_executing && _alive;});
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

void CmdQueue::_swapQueues(){
    std::lock_guard<std::mutex> lg(_lock_queue);
    std::swap(_queue, _active);
}

void CmdQueue::_executeQueue(){
    std::unique_lock<std::mutex> ul(_lock_execution);
    _cv_start.wait(ul, [&](){return _executing || !_alive;});

    _swapQueues();

    while (_active.size() > 0){
        auto &cmd = _active.front();
        cmd();
        _active.pop();
    }

    _executing = false;
    ul.unlock();
    _cv_finish.notify_all();
};