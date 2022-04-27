#pragma once

#include <memory>

namespace glwpp {

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

template<class T, class ... Args>
inline uptr<T> make_uptr(Args&&... args){
    return std::make_unique<T>(std::forward<Args>(args)...);
}

struct EmptyObj {};

static sptr<void> createTmpData(const void* src, size_t size){
    void* data;

    if (src != nullptr){
        data = malloc(size);
        memcpy(data, src, size);
    } else {
        data = calloc(size, sizeof(char));
    }

    static auto deleter = [](void* ptr){
        delete ptr;
    };
    return sptr<void>(data, deleter);
}

template<template<typename ...> class T, class ... OutArgs>
inline decltype(auto) make_shared(OutArgs&& ... args){
    using Tmp = std::remove_pointer_t<decltype(new T(args...))>;
    return std::make_shared<Tmp>(std::forward<OutArgs>(args)...);
};

template <template<typename...> class base, class derived>
struct is_base_of_template_impl
{
    template<typename... Ts>
    static constexpr std::true_type  test(const base<Ts...> *);
    static constexpr std::false_type test(...);
    using type = decltype(test(std::declval<derived*>()));
};

template < template <typename...> class base, typename derived>
using is_base_of_template = typename is_base_of_template_impl<base, derived>::type;

template<bool... b> constexpr bool var_and = (b && ...);
template<class T, class... Any> constexpr bool is_same_any = (std::is_same_v<T, Any> || ...);
template<class T, class... All> constexpr bool is_same_all = (std::is_same_v<T, All> && ...);

} // namespace glwpp