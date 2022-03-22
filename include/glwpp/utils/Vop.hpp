#pragma once

#include <memory>
#include <variant>

#include "glwpp/gl/types.hpp"

namespace glwpp {

template<class T>
class Val {
    using Container = std::variant<T, T*, std::shared_ptr<T>>;

public:
    Val(const T& data){_data = std::make_shared<Container>(data);}
    explicit Val(const T* const data){_data = std::make_shared<Container>(data);}
    Val(const std::shared_ptr<T>& data){_data = std::make_shared<Container>(data);}
    virtual ~Val(){};

    // template<class T = T, class = std::enable_if_t<std::is_same_v<T, gl::UInt>>>
    // Val(const int& data){_data = std::make_shared<Container>(data);}


    T& getVal(){
        return _getVal(*_data);
    }
    
    const T& getVal() const {
        return _getVal(*_data);
    }

    T* getPtr(){
        return _getPtr(*_data);
    }

    const T* const getPtr() const {
        return _getPtr(*_data);
    }

private:
    std::shared_ptr<Container> _data;

    static inline auto& _getVal(auto& data){
        switch (data.index()){
            case 0: return std::get<0>(data);
            case 1: return *std::get<1>(data);
            case 2: return *std::get<2>(data);
            default: throw std::runtime_error("Val internal error");
        }
    }

    static inline auto* _getPtr(auto& data){
        switch (data.index()){
            case 0: return &std::get<0>(data);
            case 1: return std::get<1>(data);
            case 2: return std::get<2>(data).get();
            default: throw std::runtime_error("Val internal error");
        }
    }
};

template<class>
struct is_vop : std::false_type {};

template<class T>
struct is_vop<Val<T>> : std::true_type {
    using type = T;
};

// template<> Val<gl::IntPtr>::Val<gl::IntPtr>(const gl::IntPtr& data){}

// template<>
// class Val<gl::IntPtr> {

// };

} // namespace glwpp
