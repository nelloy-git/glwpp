#pragma once

#include <deque>
#include <functional>
#include <memory>
#include <mutex>

#include "glwpp/utils/FuncWrapper.hpp"

namespace glwpp {

template<class ... Args>
class Event {
    template <class T, class Tuple>
    struct Index;

    template <class T, class... Types>
    struct Index<T, std::tuple<T, Types...>> {
        static constexpr std::size_t value = 0;
    };

    template <class T, class U, class... Types>
    struct Index<T, std::tuple<U, Types...>> {
        static constexpr std::size_t value = 1 + Index<T, std::tuple<Types...>>::value;
    };

public:
    using CB = std::function<void(Args...)>;
    using Watcher = std::shared_ptr<CB>;

    template<class ... ArgsF>
    static CB expand(std::function<void(ArgsF...)> callback){
        using EventArgs = std::tuple<Args...>;
        using FuncArgs = std::tuple<ArgsF...>;

        if constexpr (sizeof...(ArgsF) == 0){
            return func_expand_front<Args...>(callback);
        } else {
            constexpr size_t start = Index<std::tuple_element_t<0, FuncArgs>, EventArgs>::value;
            if constexpr (start == 0){
                return func_expand_front<Args...>(callback);
            } else if constexpr (start + sizeof...(ArgsF) == sizeof...(Args)){
                return func_expand_back<Args...>(callback);
            }

            return func_expand<Args..., start>(callback);
        }
    }

    template<class F>
    static std::shared_ptr<CB> prepare(F&& callback){
        return std::make_shared<CB>(expand(std::function(callback)));
    }   

    Event(){
        _callbacks = std::make_unique<std::deque<std::weak_ptr<CB>>>();
    }

    void push_back(std::weak_ptr<CB> callback){
        std::lock_guard<std::mutex> lg(_lock_changes);
        _front_changes.push_back(callback);
    }

    void push_front(std::weak_ptr<CB> callback){
        std::lock_guard<std::mutex> lg(_lock_changes);
        _back_changes.push_back(callback);
    }

    void emit(Args&&... args){
        auto swap = std::make_unique<std::deque<std::weak_ptr<CB>>>();

        _applyChanges();

        for (auto callback : *_callbacks){
            auto p_func = callback.lock();
            if (callback.expired()){
                continue;
            }
            
            (*p_func.get())(std::forward<Args>(args)...);
            swap->push_back(callback);
        }
        
        _callbacks.swap(swap);
    }

private:
    std::unique_ptr<std::deque<std::weak_ptr<CB>>> _callbacks;

    std::mutex _lock_changes;
    std::deque<std::weak_ptr<CB>> _front_changes;
    std::deque<std::weak_ptr<CB>> _back_changes;

    void _applyChanges(){
        std::lock_guard<std::mutex> lg(_lock_changes);

        for (auto it = _front_changes.begin(); it != _front_changes.end(); ++it){
            _callbacks->push_front(*it);
        }

        for (auto it = _back_changes.begin(); it != _back_changes.end(); ++it){
            _callbacks->push_back(*it);
        }

        _front_changes.clear();
        _back_changes.clear();
    }
};

}