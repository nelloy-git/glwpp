#pragma once

#include <atomic>
#include <memory>
#include <mutex>
#include <source_location>
#include <variant>

namespace glwpp {
    
using SrcLoc = std::source_location;

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

template<class T, class D = std::default_delete<T>>
using uptr = std::unique_ptr<T, D>;

template<class T, class ... Args>
inline sptr<T> make_sptr(Args&&... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

// Pointer
template<class T>
using Ptr = std::variant<T*, sptr<T>>;

template<typename>
struct is_ptr : std::false_type {};

template<typename T>
struct is_ptr<Ptr<T>> : std::true_type {
    using type = T;
};

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

template<typename>
struct is_vop : std::false_type {};

template<typename T>
struct is_vop<Vop<T>> : std::true_type {
    using type = T;
};

template<class T>
static T& getVopRef(Vop<T> &vop){
    switch (vop.index()){
        case 0: return std::get<T>(vop);
        case 1: return *std::get<T*>(vop);
        case 2: return *std::get<sptr<T>>(vop);
        default: throw std::runtime_error("Is not Vop.");
    }
}

template<class T>
static const T& getVopRef(const Vop<T> &vop){
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

using VoidData = sptr<void>;

static sptr<void*> createTmpData(const void* src, size_t size){
    void* data = malloc(size);
    memcpy(data, src, size);

    static auto deleter = [](void** ptr){
        delete *ptr;
        delete ptr;
    };
    return sptr<void*>(new void*(data), deleter);
}

}