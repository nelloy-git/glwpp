#pragma once

#include <iostream>


#include <memory>
#include <optional>
#include <queue>

namespace glwpp {

template<class T>
class DoubleQueue {
public:
    DoubleQueue(){
        _for_pop = std::make_unique<std::queue<T>>();
        _for_push = std::make_unique<std::queue<T>>();
    }

    inline void push(T data){
        std::lock_guard lg(_lock);
        _for_push->push(data);
    }

    inline std::optional<T> pop(){
        std::lock_guard lg(_lock);
        if (_for_pop->size() > 0){
            auto res = _for_pop->front();
            _for_pop->pop();
            return res;
        } else
            return std::nullopt;
    }

    inline void swap(){
        std::lock_guard lg(_lock);
        _for_push.swap(_for_pop);
    }

private:
    std::mutex _lock;
    std::unique_ptr<std::queue<T>> _for_pop;
    std::unique_ptr<std::queue<T>> _for_push;
};
    
}
