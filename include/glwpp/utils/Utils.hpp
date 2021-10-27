#pragma once

#include <memory>

namespace glwpp {

template<template<typename ...> class T, class ... Args>
decltype(auto) make_shared(Args&& ... args){
    using Tmp = std::remove_pointer_t<decltype(new T(args...))>;
    return std::make_shared<Tmp>(std::forward<Args>(args)...);
};

template < template <typename...> class base,typename derived>
struct is_base_of_template_impl
{
    template<typename... Ts>
    static constexpr std::true_type  test(const base<Ts...> *);
    static constexpr std::false_type test(...);
    using type = decltype(test(std::declval<derived*>()));
};

template < template <typename...> class base, typename derived>
using is_base_of_template = typename is_base_of_template_impl<base,derived>::type;

template<bool... b> constexpr bool var_and = (b && ...);
template<class T, class... Any> constexpr bool is_same_any = (std::is_same_v<T, Any> || ...);
template<class T, class... All> constexpr bool is_same_all = (std::is_same_v<T, All> && ...);

}