#pragma once

#include <algorithm>
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
    CounterList(const CounterList& other){
        _list = other._list;
    }
    virtual ~CounterList(){
    };

    int size() const {
        return _list.size();
    }

    std::pair<T, int> get(int i) const {
        i = _get_i(i);
        return _list[i];
    }

    void insert(int i, const T& data, int counter = -1){
        i = _get_i(i);
        auto iter = _list.begin();
        std::advance(iter, i);
        _list.insert(iter, std::make_pair(data, counter));
    }

    void remove(int i){
        i = _get_i(i);
        auto iter = _list.begin();
        std::advance(iter, i);
        _list.erase(iter);
    }

    void changeCounter(int i, int counter){
        i = _get_i(i);
        _list[i].second = counter;
    }

    void reduceAll(){
        for (auto iter = _list.begin(); iter != _list.end(); ++iter){
            if (iter->second > 0){
                --iter->second;
            }
        }
    }

    template<class Cond>
    void reduceAll(const Cond &remove_condition){
        auto iter = _list.begin();
        while (iter != _list.end()){ 
            if (iter->second > 0){
                --iter->second;
            }

            if (remove_condition(*iter)){
                iter = _list.erase(iter);
            } else {
                ++iter;
            }
        }
    }

    void clear(){
        _list.clear();
    }

    template<class Cond>
    void clear(const Cond &remove_condition){
        _list.remove_if([&remove_condition](const std::pair<T, int> &pair){
            return remove_condition(pair);
        });
    }

    auto begin(){
        return _list.begin();
    }

    auto end(){
        return _list.end();
    }

private:
    std::list<std::pair<T, int>> _list;

    inline int _get_i(int i){
        return i >= 0 ? std::min(i, std::max(0, int(_list.size() - 1)))
                      : std::max(0, int(_list.size() + i));
    }
};

}