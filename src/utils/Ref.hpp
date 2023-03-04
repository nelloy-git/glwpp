#pragma once

#include "utils/Ptr.hpp"

namespace glwpp {

template<typename T>
class Ref {
    template<typename U>
    friend class Ref;

public:
    using type = T;

    static Ref<T> Make(auto&&... args);


    Ref(const T& value);
    Ref(T&& value);
    Ref(const Ptr<T>& ptr);
    Ref(Ptr<T>&& ptr);
    Ref(const Ref<T>& other);
    Ref(Ref<T>&& other);


    T& value() const;
    T& operator*() const;
    Ptr<T> get() const;
    Ptr<T> operator->() const;

    operator T() const;

protected:
    Ptr<T> _ptr;
};

// =============================================


template<typename T>
Ref<T> Ref<T>::Make(auto&&... args){
    return Ref<T>(Ptr<T>(new T(std::forward<decltype(args)>(args)...)));
}


template<typename T>
Ref<T>::Ref(const T& value) :
    _ptr(new T(value)){
}


template<typename T>
Ref<T>::Ref(T&& value) :
    _ptr(new T(std::move(value))){
}


template<typename T>
Ref<T>::Ref(const Ptr<T>& ptr) :
    _ptr(ptr){
    if (!_ptr){
        throw std::logic_error("glwpp::Ref can not be empty.");
    }
}


template<typename T>
Ref<T>::Ref(Ptr<T>&& ptr) :
    _ptr(std::move(ptr)){
    if (!_ptr){
        throw std::logic_error("glwpp::Ref can not be empty.");
    }
}


template<typename T>
Ref<T>::Ref(const Ref<T>& other) :
    _ptr(other._ptr){
}


template<typename T>
Ref<T>::Ref(Ref<T>&& other) :
    _ptr(std::move(other._ptr)){
}


template<typename T>
inline T& Ref<T>::value() const {
    return *_ptr;
}


template<typename T>
inline T& Ref<T>::operator*() const {
    return value();
}


template<typename T>
Ptr<T> Ref<T>::get() const {
    return _ptr.get();
}


template<typename T>
Ptr<T> Ref<T>::operator->() const {
    return get();
}


template<typename T>
Ref<T>::operator T() const {
    return value();
}


} // namespace glwpp