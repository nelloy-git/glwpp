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

template <int I, class... Ts>
inline decltype(auto) getArg(Ts&&... ts) {
  return std::get<I>(std::forward_as_tuple(ts...));
}

template<class F, size_t ... Use, class ... ArgsW>
static decltype(auto) call(std::index_sequence<Use...>, F&& func, ArgsW&& ... args){
    return func(getArg<Use>(std::forward<ArgsW>(args)...)...);
};

}

template<class ... ArgsOut, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand_back(std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);
    static_assert(OutS >= InS);

    if constexpr (OutS == InS) return func;

    using Capture = std::make_index_sequence<InS>;
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

template<class ... ArgsOut, size_t ... Use, class R, class ... ArgsIn>
std::function<R(ArgsOut&&...)> func_expand(std::index_sequence<Use...> seq,
                                           std::function<R(ArgsIn...)> func){
    constexpr auto OutS = sizeof...(ArgsOut);
    constexpr auto InS = sizeof...(ArgsIn);
    
    if constexpr (OutS == InS) return func;

    return [seq, func](ArgsOut&& ... args) -> R {
        return detailed::call(seq, func, std::forward<ArgsOut>(args)...);
    };
}

namespace detailed {
template <class T, class Tuple>
struct Index;

template <class T, class... Types>
struct Index<T, std::tuple<T, Types...>> {
    static constexpr std::size_t value = 0;
};

template <class T, class U, class... Types>
struct Index<T, std::tuple<U, Types...>> {
    static constexpr std::size_t value = Index<T, std::tuple<Types...>>::value + 1;
};

template <class T1, class T2, size_t ... Seq>
constexpr bool is_same_tuples(std::index_sequence<Seq...>){
    return (std::is_same_v<std::tuple_element_t<Seq, T1>, std::tuple_element_t<Seq, T1>> && ...);
};
}

// Return value will be copied one extra time.
template<class ... ArgsOut, class R, class ... ArgsIn>
static std::function<R(ArgsOut...)> func_wrap(const std::function<R(ArgsIn...)> &callback){
    using TupleArgsOut = std::tuple<ArgsOut...>;
    using TupleArgsIn = std::tuple<ArgsIn...>;

    if constexpr (sizeof...(ArgsIn) == 0){
        if constexpr (sizeof...(ArgsOut) == 0){
            return callback;
        } else {
            return func_expand_front<ArgsOut...>(callback);
        }
    } else if constexpr (sizeof...(ArgsOut) == sizeof...(ArgsIn)) {
        using Seq = std::make_index_sequence<sizeof...(ArgsOut)>;
        if constexpr (detailed::is_same_tuples<TupleArgsOut, TupleArgsOut>(Seq{})){
            return callback;
        } else {
            []<bool F = false>(){static_assert(F, "Function can not be wrapped.");}();
        }
    } else {
        constexpr size_t start = detailed::Index<std::tuple_element_t<0, TupleArgsIn>, TupleArgsOut>::value;
        if constexpr (start == 0){
            return func_expand_back<ArgsOut...>(callback);
        } else if constexpr (start + sizeof...(ArgsIn) == sizeof...(ArgsOut)){
            return func_expand_front<ArgsOut...>(callback);
        }

        using Capture = detailed::make_index_range<start, start + sizeof...(ArgsIn)>;
        return func_expand<ArgsOut...>(Capture{}, callback);
    }
}


}