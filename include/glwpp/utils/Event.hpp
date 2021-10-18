#pragma once

#include <list>
#include <mutex>

#include "glwpp/utils/Functor.hpp"

namespace glwpp {

template<class ... Args>
class Event {
    using WeakList = std::list<std::weak_ptr<Functor<void, Args...>>>;

public:
    using Func = Functor<void, Args...>;

    void push_back(std::weak_ptr<Functor<void, Args...>> wptr){
        std::lock_guard<std::mutex> lg(_lock);
        _list.push_back(wptr);
    }

    void push_front(std::weak_ptr<Functor<void, Args...>> wptr){
        std::lock_guard<std::mutex> lg(_lock);
        _list.push_front(wptr);
    }

    void emit(Args&&... args){
        std::lock_guard<std::mutex> lg(_lock);
        for (auto wptr : _list){
            auto sptr = wptr.lock();
            if (wptr.expired()){
                continue;
            }
            
            (*sptr.get())(std::forward<Args>(args)...);
            _swap.push_back(wptr);
        }
        
        _list.clear();
        std::swap(_list, _swap);
    }

private:
    std::mutex _lock;
    WeakList _list;
    WeakList _swap;
};

}