#pragma once

#include <memory>

#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl::v2 {

template<class T>
class Val {
public:
    template<typename T>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<T>, void>;

    template<typename T>
    static constexpr bool is_const = std::is_const_v<T>;

    template<typename V, typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    Val(const V& data){_data = make_sptr<T>(data);}

    
    Val(const sptr<T>& data) : _data(data){}
    template<typename T = T, typename = std::enable_if_t<(std::is_const_v<T>)>>
    Val(const sptr<std::remove_const_t<T>>& data) : _data(data){}


    template<typename U>
    Val(const Val<U>& other) : _data(other._data){}
    template<typename T = T, typename = std::enable_if_t<(!std::is_same_v<std::remove_const_t<T>, void> && std::is_const_v<T>)>>
    Val(const Val<std::remove_const_t<T>>& other) : _data(other._data){}


    template<typename U>
    Val(const Val<U>&& other) : _data(other._data){}
    template<typename T = T, typename = std::enable_if_t<(!std::is_same_v<std::remove_const_t<T>, void> && std::is_const_v<T>)>>
    Val(const Val<std::remove_const_t<T>>&& other) : _data(other._data){}


    virtual ~Val(){};
    

    template<typename V, typename U = T, std::enable_if_t<(!is_void<U> && !is_const<U>), bool> = true>
    operator V&() const {return *_data;}
    template<typename V, typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    operator const V&() const {return *_data;}
    operator T*() const {return _data.get();}

    template<typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    U* operator ->() const {return *_data;}

    // template<typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    // U& operator ->(){return *_data;}

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
