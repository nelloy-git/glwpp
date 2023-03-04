#pragma once

#include <atomic>

namespace glwpp {

template<typename T>
class Ptr {
    template<typename V>
    friend class WeakPtr;

    using Counter = unsigned long int;
public:
    Ptr();
    Ptr(nullptr_t);
    Ptr(const T*& ptr);
    Ptr(T*&& ptr);
    Ptr(const Ptr<T>& other);
    Ptr(Ptr<T>&& other);
    ~Ptr();

    T* get() const;
    T* operator->() const;
    T& operator*() const;
    operator bool() const;
    operator T*() const;

    void reset(const T*& ptr);
    void reset(T*&& ptr);

private:
    std::atomic<T*>* _data_ptr;
    std::atomic<Counter>* _data_refs;
    std::atomic<Counter>* _counter_refs;

    Ptr(std::atomic<T*>* data_ptr, 
        std::atomic<Counter>* counter,
        std::atomic<Counter>* counter_refs);
};


template<typename T>
Ptr<T>::Ptr() :
    _data_ptr(new std::atomic<T*>(nullptr)),
    _data_refs(new std::atomic<Counter>(1)),
    _counter_refs(new std::atomic<Counter>(1)){
}


template<typename T>
Ptr<T>::Ptr(nullptr_t) :
    _data_ptr(new std::atomic<T*>(nullptr)),
    _data_refs(new std::atomic<Counter>(1)),
    _counter_refs(new std::atomic<Counter>(1)){
}


template<typename T>
Ptr<T>::Ptr(const T*& ptr) :
    _data_ptr(new std::atomic<T*>(ptr)),
    _data_refs(new std::atomic<Counter>(1)),
    _counter_refs(new std::atomic<Counter>(1)){
}


template<typename T>
Ptr<T>::Ptr(T*&& ptr) :
    _data_ptr(new std::atomic<T*>(std::move(ptr))),
    _data_refs(new std::atomic<Counter>(1)),
    _counter_refs(new std::atomic<Counter>(1)){
}


template<typename T>
Ptr<T>::Ptr(const Ptr<T>& other) :
    _data_ptr(other._data_ptr),
    _data_refs(other._data_refs),
    _counter_refs(other._counter_refs){
    _data_refs->fetch_add(1);
    _counter_refs->fetch_add(1);
}


template<typename T>
Ptr<T>::Ptr(Ptr<T>&& other) :
    _data_ptr(other._data_ptr),
    _data_refs(other._data_refs),
    _counter_refs(other._counter_refs){
    _data_refs->fetch_add(1);
    _counter_refs->fetch_add(1);
}


template<typename T>
Ptr<T>::Ptr(std::atomic<T*>* data_ptr, 
            std::atomic<Counter>* counter,
            std::atomic<Counter>* counter_refs) :
    _data_ptr(data_ptr),
    _data_refs(counter),
    _counter_refs(counter_refs){
    _data_refs->fetch_add(1);
    _counter_refs->fetch_add(1);
}


template<typename T>
Ptr<T>::~Ptr(){
    auto c = _data_refs->fetch_sub(1);
    if (c == 0){
        if (*_data_ptr != nullptr){
            if constexpr (std::is_array_v<T>){
                delete *_data_ptr;
            } else {
                delete[] *_data_ptr;
            }
        }
        delete _data_ptr;
    }

    c = _counter_refs->fetch_add(1);
    if (c == 0){
        delete _data_refs;
        delete _counter_refs;
    }
}


template<typename T>
T* Ptr<T>::get() const {
    return _data_ptr->load();
}


template<typename T>
T* Ptr<T>::operator->() const {
    return get();
}


template<typename T>
T& Ptr<T>::operator*() const {
    return *get();
}


template<typename T>
Ptr<T>::operator bool() const {
    return (*_data_ptr != nullptr);
}


template<typename T>
Ptr<T>::operator T*() const {
    return _data_ptr->load();
}


template<typename T>
void Ptr<T>::reset(const T*& ptr){
    *_data_ptr = ptr;
}


template<typename T>
void Ptr<T>::reset(T*&& ptr){
    *_data_ptr = std::move(ptr);
}

} // namespace glwpp