#include "utils/CmdQueue.hpp"

using namespace glwpp;

CmdQueue::CmdQueue(const std::shared_ptr<BS::thread_pool>& pool) :
    _lock(new std::mutex),
    _is_executing(new std::atomic<bool>(false)),
    _queue(new std::deque<std::function<void()>>),
    _pool(pool){
}

CmdQueue::~CmdQueue(){
    _is_executing->wait(true);
}

void CmdQueue::lock(){
    _lock->lock();
}

void CmdQueue::unlock(){
    _lock->unlock();
}

size_t CmdQueue::size() const {
    std::lock_guard lg(*_lock);
    return _queue->size();
}

void CmdQueue::_push_back_with_lock(const std::function<void()>& cmd){
    std::lock_guard lg(*_lock);
    _queue->push_back(cmd);
    _update();
}

void CmdQueue::_push_back_no_lock(const std::function<void()>& cmd){
    _queue->push_back(cmd);
    _update();
}

void CmdQueue::_push_front_with_lock(const std::function<void()>& cmd){
    std::lock_guard lg(*_lock);
    _queue->push_front(cmd);
    _update();
}

void CmdQueue::_push_front_no_lock(const std::function<void()>& cmd){
    _queue->push_front(cmd);
    _update();
}

// Should be called when mutex is locked
void CmdQueue::_update(){
    bool executing = false;
    while(!_is_executing->compare_exchange_weak(executing, true) && !executing);

    if (!executing && _queue->size() > 0){
        static_cast<void>(_pool->submit([lock = _lock, is_executing = _is_executing, queue = _queue](){
            std::function<void()> cmd;
            while(true){
                {
                    std::lock_guard lg(*lock);
                    if (queue->size() <= 0){
                        *is_executing = false;
                        is_executing->notify_one();
                        break;
                    }
                    cmd = queue->front();
                    queue->pop_front();
                }
                cmd();
            }
        }));
    }
}

