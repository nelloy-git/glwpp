#pragma once

#include <list>
#include <functional>
#include <mutex>

#include "glwpp/utils/Ptr.hpp"

namespace glwpp {

template <class T>
class CounterList {
public:
    CounterList(){
    };
    CounterList(CounterList& other){
        std::lock_guard lg(_lock);
        
        for (auto iter = _list.begin(); iter != _list.end(); ++iter){
            if (iter->second > 0){
                --iter->second;
            } else {
                iter = _list.erase(iter);
            }
        }

        _list = other._list;
    }
    virtual ~CounterList(){
    };

    int size() const {
        std::lock_guard lg(_lock);
        return _list.size();
    }

    std::pair<T, int> get(int i) const {
        std::lock_guard lg(_lock);
        i = _get_i(i);
        return _list[i];
    }

    void insert(int i, const T& data, int counter = -1){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list.insert(_list.begin() + i, std::make_pair(data, counter));
    }

    void remove(int i){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list.erase(_list.begin() + i);
    }

    void change(int i, int counter){
        std::lock_guard lg(_lock);
        i = _get_i(i);
        _list[i].second = counter;
    }

    void reduceAll(){
        std::lock_guard lg(_lock);
        for (auto iter = _list.begin(); iter != _list.end(); ++iter){
            if (iter->second > 0){
                --iter->second;
            } else {
                iter = _list.erase(iter);
            }
        }
    }

    void clear(){
        std::lock_guard lg(_lock);
        _list.remove_if([](const std::pair<T, int> &pair){
            return pair.second == 0;
        });
    }

    template<class Cond>
    void clear(const Cond &remove_condition){
        std::lock_guard lg(_lock);
        _list.remove_if([&remove_condition](const std::pair<T, int> &pair){
            return pair.second == 0 || remove_condition(pair.first);
        });
    }

    // Is not threadsafe
    auto begin(){
        return _list.begin();
    }

    // Is not threadsafe
    auto end(){
        return _list.end();
    }

private:
    std::mutex _lock;
    std::list<std::pair<T, int>> _list;

    inline int _get_i(int i){
        return i >= 0 ? std::min(i, _list.size() - 1)
                      : std::max(0, _list.size() + i);
    }
};

}