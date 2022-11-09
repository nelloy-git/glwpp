#include "utils/GlobalThreadPool.hpp"

using namespace glwpp;

GlobalThreadPool::GlobalThreadPool(){
}

GlobalThreadPool::~GlobalThreadPool(){
}

std::shared_ptr<BS::thread_pool> GlobalThreadPool::get(){
    static std::mutex lock;
    static std::weak_ptr<BS::thread_pool> wptr;

    std::lock_guard lg(lock);

    auto sptr = wptr.lock();
    if (sptr){return sptr;}

    sptr = std::make_shared<BS::thread_pool>();
    wptr = sptr;
    return sptr;
}