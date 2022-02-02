#pragma once

#include <atomic>
#include <memory>
#include <mutex>
#include <variant>

namespace glwpp {

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

template<class T>
using uptr = std::unique_ptr<T>;

template<class T, class ... Args>
inline sptr<T> make_sptr(Args&&... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

// Pointer
template<class T>
using Ptr = std::variant<T*, sptr<T>>;

template<class T>
static T* getPtrValue(const Ptr<T> &ptr){
    switch (ptr.index()){
        case 0: return std::get<T*>(ptr);
        case 1: return std::get<sptr<T>>(ptr).get();
        default: throw std::runtime_error("Is not Ptr.");
    }
}

// Value or pointer
template<class T>
using Vop = std::variant<T, T*, sptr<T>>;

template<class T>
static T& getVopRef(const Vop<T> &vop){
    switch (vop.index()){
        case 0: return std::get<T>(vop);
        case 1: return *std::get<T*>(vop);
        case 2: return *std::get<sptr<T>>(vop);
        default: throw std::runtime_error("Is not Vop.");
    }
}

template<class T>
static T getVopValue(const Vop<T> &vop){
    switch (vop.index()){
        case 0: return std::get<T>(vop);
        case 1: return *std::get<T*>(vop);
        case 2: return *std::get<sptr<T>>(vop);
        default: throw std::runtime_error("Is not Vop.");
    }
}

}