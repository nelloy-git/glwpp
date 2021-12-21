#pragma once

#include <list>
#include <functional>
#include <mutex>

#include "glwpp/utils/Ptr.hpp"

namespace glwpp {

template <class ... Args>
class EventCallbackList {
public:
    using Callback = std::function<void(Args...)>;

    EventCallbackList(){
    };
    virtual ~EventCallbackList(){
    };

    EventCallbackList copy(bool reduce_counter = true){
        EventCallbackList copy;

        std::lock_guard lg(_lock);
        auto iter = _list.begin();
        while (iter != _list.end()){
            if (reduce_counter && iter->second > 0){
                --iter->second;
            }

            if (iter->first. iter->second == 0){
                iter = _list.erase(iter);
            } else {
                copy._list.push_back(iter);
            }
        }
        return copy;
    }

    int size() const {
        std::lock_guard lg(_lock);
        return _list.size();
    }

    std::pair<wptr<Callback>, int> get(int i) const {
        std::lock_guard lg(_lock);
        i = _get_i(i);
        return _list[i];
    }

    void insert(int i, wptr<Callback> callback, int emits = -1){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list.insert(_list.begin() + i, std::make_pair(callback, emits));
    }

    void remove(int i){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list.erase(_list.begin() + i);
    }

    void change(int i, int emits){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list[i].second = emits;
    }

    void clear(){
        _list.remove_if(_list.begin(), _list.end(), [](const std::pair<wptr<Callback>, int> v){
            return v.second == 0;
        });
    }

private:
    std::mutex _lock;
    std::list<std::pair<wptr<Callback>, int>> _list;

    inline int _get_i(int i){
        return i >= 0 ? std::min(i, _list.size() - 1)
                      : std::max(0, _list.size() + i);
    }
};

}