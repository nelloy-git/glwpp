#pragma once

#include <cstring>
#include <memory>
#include <type_traits>

namespace glwpp {

template<typename T>
using sptr = std::shared_ptr<T>;

template<typename T>
using wptr = std::weak_ptr<T>;

template<typename T, typename D = std::default_delete<T>>
using uptr = std::unique_ptr<T, D>;

template<typename T, typename ... Args>
inline sptr<T> make_sptr(Args&&... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename ... Args>
inline uptr<T> make_uptr(Args&&... args){
    return std::make_unique<T>(std::forward<Args>(args)...);
}

namespace utils {
    
namespace detail {

template<typename T>
static void tmp_deleter(T* ptr){
    delete[] ptr;
}

};

template<typename T>
static sptr<std::conditional_t<std::is_same_v<T, void>, void, T[]>> alloc_sptr_buffer(size_t size, const T* src = nullptr){
    using ST = std::conditional_t<std::is_same_v<T, void>, char, T>;

    sptr<ST[]> data(new ST[size], detail::tmp_deleter<ST>);

    if (src != nullptr){
        memcpy(data.get(), src, size);
    }

    if constexpr (std::is_same_v<T, void>){
        std::reinterpret_pointer_cast<void>(data);
    } else {
        return data;
    }
}

}

template <template<typename...> typename base, typename derived>
struct is_base_of_template_impl
{
    template<typename... Ts>
    static constexpr std::true_type  test(const base<Ts...> *);
    static constexpr std::false_type test(...);
    using type = decltype(test(std::declval<derived*>()));
};

template < template <typename...> typename base, typename derived>
using is_base_of_template = typename is_base_of_template_impl<base, derived>::type;

template<bool... b> constexpr bool var_and = (b && ...);
template<typename T, typename... Any> constexpr bool is_same_any = ((std::is_same_v<T, Any>) || ...);
template<typename T, typename... All> constexpr bool is_same_all = ((std::is_same_v<T, All>) && ...);

// concept
template<class T, class U>
concept Derived = std::is_base_of<U, T>::value;

} // namespace glwpp