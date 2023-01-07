#pragma once


namespace glwpp {

template <class, template <class, class...> class>
struct is_instance : public std::false_type {};

template <class...Ts, template <class, class...> class U>
struct is_instance<U<Ts...>, U> : public std::true_type {};

template<typename T>
constexpr bool is_value = is_instance<std::remove_const_t<std::remove_reference_t<T>>, Value>::value;
    
template<typename T, typename Req>
constexpr bool IsValuable(){
    if constexpr (std::is_convertible_v<T, Req>){
        return true;
    } else {
        if constexpr (is_value<T){
            using R = decltype(std::declval<T>().value());
            if constexpr (is_instance<std::remove_const_t<std::remove_reference_t<R>>, std::future>::value){
                return std::is_convertible_v<R::value_type, Req>;
            }
            return std::is_convertible_v<R, Req>;
        } else {
            return false;
        }
    }
}

template<typename T, typename Req>
concept Valuable = IsValuable<T, Req>();

static inline decltype(auto) GetValuable(auto&& val){
    using T = std::remove_const_t<std::remove_reference_t<decltype(val)>>;

    if constexpr (is_instance<T, Value>::value){
        using R = std::remove_const_t<std::remove_reference_t<decltype(std::declval<T>().value())>>;
        if constexpr (is_instance<R, std::future>::value){
            if (!val.value().wait_for(std::chrono::seconds(0))){
                throw std::runtime_error("empty optional");
            }
            return val.value().get();
        } else {
            return val.value();
        }
    } else {
        return std::forward<decltype(val)>(val);
    }
}

} // namespace glwpp