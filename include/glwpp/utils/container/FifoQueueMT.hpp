#pragma once

#include <iostream>


#include <memory>
#include <optional>
#include <queue>

namespace glwpp {

template<class T>
class FifoQueueMT {
public:
    FifoQueueMT(){
        _for_pop = std::make_unique<std::queue<T>>();
        _for_push = std::make_unique<std::queue<T>>();
    }

    inline void push(T data){
        std::lock_guard lg(_lock_push);
        _for_push->push(data);
    }

    inline std::optional<T> pop(){
        std::lock_guard lg(_lock_pop);

        auto res = _popUnsafe();
        if (res) return res;
        
        {
            std::lock_guard lg_push(_lock_push);
            _for_push.swap(_for_pop);
        }

        return _popUnsafe();
    }

    inline size_t size(){
        std::lock_guard lg1(_lock_pop);
        std::lock_guard lg2(_lock_push);
        return _for_push->size() + _for_pop->size();
    }

private:
    std::mutex _lock_pop;
    std::unique_ptr<std::queue<T>> _for_pop;

    std::mutex _lock_push;
    std::unique_ptr<std::queue<T>> _for_push;

    inline std::optional<T> _popUnsafe(){
        if (_for_pop->size() == 0) return std::nullopt;
        
        auto res = _for_pop->front();
        _for_pop->pop();
        return res;
    }
};
    
}
