#pragma once

#include <atomic>
#include "utils/Ptr.hpp"

namespace glwpp {

template<typename T>
class WeakPtr {
    using Counter = Ptr<T>::Counter;

public:
    WeakPtr();
    WeakPtr(const Ptr<T>& ptr);
    WeakPtr(Ptr<T>&& ptr);
    ~WeakPtr();

    Ptr<T> lock() const;
    Counter refCount() const;

private:
    std::atomic<T*>* _data_ptr;
    std::atomic<Counter>* _data_refs;
    std::atomic<Counter>* _counter_refs;
};


template<typename T>
WeakPtr<T>::WeakPtr(){
}


template<typename T>
WeakPtr<T>::WeakPtr(const Ptr<T>& ptr) :
    _data_ptr(ptr._data_ptr),
    _data_refs(ptr._data_refs),
    _counter_refs(ptr._counter_refs){
    _counter_refs->fetch_add(1);
}


template<typename T>
WeakPtr<T>::WeakPtr(Ptr<T>&& ptr) :
    _data_ptr(ptr._data_ptr),
    _data_refs(ptr._data_refs),
    _counter_refs(ptr._counter_refs){
    _counter_refs->fetch_add(1);
}


template<typename T>
WeakPtr<T>::~WeakPtr(){
    if (_counter_refs == nullptr){
        return;
    }

    auto c = _counter_refs->fetch_sub(1);
    if (c == 0){
        delete _data_refs;
        delete _counter_refs;
    }
}


template<typename T>
Ptr<T> WeakPtr<T>::lock() const {
    if (_data_refs->load() == 0){
        throw std::runtime_error("empty glwpp::WeakPtr can not be locked");
    }
    return Ptr<T>(_data_ptr, _data_refs, _counter_refs);
}


template<typename T>
WeakPtr<T>::Counter WeakPtr<T>::refCount() const {
    return _data_refs->load();
}

} // namespace glwpp