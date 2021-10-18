#pragma once

#include <memory>

namespace glwpp {

template<template<typename ...> class T, class ... Args>
decltype(auto) make_shared(Args&& ... args){
    using Tmp = std::remove_pointer_t<decltype(new T(args...))>;
    return std::make_shared<Tmp>(std::forward<Args>(args)...);
};

}