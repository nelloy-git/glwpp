#pragma once

#include <memory>

#include "glwpp/utils/Utils.hpp"

namespace glwpp::utils {

template<class T>
class Val {
public:
    template<typename U>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<U>, void>;

    template<typename U>
    static constexpr bool is_const = std::is_const_v<U>;

    template<typename U>
    using non_const = std::remove_const_t<U>;


    template<typename V, typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    Val(const V& data){_data = make_sptr<T>(data);}
    

    template<typename V>
    Val(const sptr<V>& data) : _data(data){
        if constexpr (!is_void<T>){
            if (data.get() == nullptr){
                throw std::logic_error("non-void glwpp::util::Val can not be nullptr");
            }
        }
    }


    template<typename U>
    Val(const Val<U>& other) : _data(other._data){}
    template<typename U = T, std::enable_if_t<(!is_void<U> && is_const<U>), bool> = true>
    Val(const Val<non_const<U>>& other) : _data(other._data){}


    template<typename U>
    Val(const Val<U>&& other) : _data(other._data){}
    template<typename U = T, std::enable_if_t<(!is_void<U> && is_const<U>), bool> = true>
    Val(const Val<non_const<U>>&& other) : _data(other._data){}


    virtual ~Val(){};
    

    template<typename V, typename U = T, std::enable_if_t<(!is_void<U> && (std::is_const_v<V> == std::is_const_v<U>)), bool> = true>
    operator V&() const {return *_data;}
    template<typename V, typename U = T, std::enable_if_t<(!is_void<U> && std::is_const_v<V> && !std::is_const_v<U>), bool> = true>
    operator V&() const {return const_cast<V&>(*_data);}
    template<typename V, typename U = T, std::enable_if_t<(!is_void<U> && !std::is_const_v<V> && std::is_const_v<U>), bool> = true>
    operator V() const {return *_data;}
    template<typename V>
    operator V*() const {return _data.get();}


    T* operator->() const {return _data.get();}
    template<typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    U& operator*() const {return *_data;}


    template<typename D>
    Val<D> cast_static() const {return Val<D>(std::static_pointer_cast<D>(_data));}

    template<typename D>
    Val<D> cast_dynamic() const {return Val<D>(std::dynamic_pointer_cast<D>(_data));}

    template<typename D>
    Val<D> cast_reinterpret() const {return Val<D>(std::reinterpret_pointer_cast<D>(_data));}

private:
    sptr<T> _data;
    
    template<typename>
    friend class Val;
};

template<class>
struct isVal : std::false_type {};

template<class T>
struct isVal<Val<T>> : std::true_type {
    using type = T;
};

} // namespace glwpp
