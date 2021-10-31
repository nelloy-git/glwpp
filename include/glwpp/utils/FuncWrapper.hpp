#pragma once

#include <functional>
#include <utility>

namespace glwpp {

namespace detailed {

template<std::size_t N, std::size_t... Seq>
constexpr std::index_sequence<(N + Seq)...> add(std::index_sequence<Seq...>){
    return {};
}

template<std::size_t Min, std::size_t Max>
using make_index_range = decltype(add<Min>(std::make_index_sequence<Max-Min>()));

template <int I>
struct ignore {
    template <typename T>
    ignore(T&&){}
};

template <size_t N>
struct nth_arg {
    template <size_t ... Drop, class Arg, class... Rest>
    static decltype(auto) get(ignore<Drop>..., // ignore args 0...n-1
                              Arg&& arg,
                              Rest&& ...){      // also ignore the rest 
        return std::forward<Arg>(arg); // return nth arg
    }
};

template<class F, size_t ... Use, class ... ArgsW>
static decltype(auto) call(std::index_sequence<Use...>, F&& func, ArgsW&& ... args){
    return func(nth_arg<Use>::get(std::forward<ArgsW>(args)...)...);
};

}

template<class ... ArgsOut, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand_back(std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);
    static_assert(OutS >= InS);

    if constexpr (OutS == InS) return func;

    using Capture = detailed::make_index_range<0, InS>;
    return [func](ArgsOut&& ... args) -> R {
        return detailed::call(Capture{}, func, std::forward<ArgsOut>(args)...);
    };
}

template<class ... ArgsOut, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand_front(std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);
    static_assert(OutS >= InS);

    if constexpr (OutS == InS) return func;

    using Capture = detailed::make_index_range<OutS - InS, OutS>;
    return [func](ArgsOut&& ... args) -> R {
        return detailed::call(Capture{}, func, std::forward<ArgsOut>(args)...);
    };
}

template<class ... ArgsOut, size_t Start, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand(std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);
    static_assert(OutS >= (Start + InS));

    using Capture = detailed::make_index_range<Start, Start + InS>;
    return [func](ArgsOut&& ... args) -> R {
        return detailed::call(Capture{}, func, std::forward<ArgsOut>(args)...);
    };
}

template<class ... ArgsOut, size_t ... Use, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand(std::index_sequence<Use...>,
                                           std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);

    return [func](ArgsOut&& ... args) -> R {
        return detailed::call(std::index_sequence<Use...>{}, func, std::forward<ArgsOut>(args)...);
    };
}


}