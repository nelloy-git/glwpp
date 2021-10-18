#pragma once

#include <any>
#include <functional>
#include <optional>
#include <memory>
#include <source_location>
#include <type_traits>

namespace glwpp {

// namespace detailed {

//     template<class C, class R, class ...Args>
//     using ClassMethod = R (C::*)(Args...);

//     template<class C, class R, class ...Args>
//     using ClassMethodConst = R (C::*)(Args...) const;

// }

template<class R, class ...Args>
class Functor;

class FunctorBase {
public:
    virtual bool isValid() const = 0;
};

template<class R, class ... Args>
class Functor : public FunctorBase {
    using FunctorR = std::conditional_t<std::is_same_v<R, void>, void, std::optional<R>>;

public:

    Functor(std::function<R(Args...)> func,
            std::source_location loc = std::source_location::current()) :
        _func(func),
        _location(loc){
    };

    template<class C1, class C2>
    Functor(std::weak_ptr<C1> instance,
            R (C2::*method)(Args...),
            std::source_location loc = std::source_location::current()) :
        _func(_getWrapper(instance, method)),
        _location(loc){
    };

    template<class C1, class C2>
    Functor(std::weak_ptr<C1> instance,
            R (C2::*method)(Args...) const,
            std::source_location loc = std::source_location::current()) :
        _func(_getWrapper(instance, method)),
        _location(loc){
    };

    ~Functor(){
    };
    
    inline virtual FunctorR operator()(Args&&... args) const {
        return _func(std::forward<Args>(args)...);
    };

    inline const std::source_location &getLoc() const {
        return _location;
    };

    inline virtual bool isValid() const{
        return _isValid();
    }
    
protected:
    std::function<bool()> _isValid = [](){return true;};
    std::function<FunctorR(Args&&...)> _func;
    std::source_location _location;

    template<class C, class M>
    inline decltype(auto) _getWrapper(std::weak_ptr<C> watcher, M method){
        static_assert(std::is_invocable_v<M, C, Args...>);
        _isValid = [watcher](){return !watcher.expired();};

        return [watcher, method](Args&&... args) -> FunctorR {
            std::shared_ptr<C> shared = watcher.lock();
            if (watcher.expired()){
                if constexpr (std::is_same_v<R, void>) {
                    return;
                } else {
                    return std::nullopt;
                }
            }
            auto ptr = shared.get();
            return (ptr->*method)(std::forward<Args>(args)...);
        };
    }

    inline std::string _getLocStr(){
        return std::string(_location.file_name()) + ":" + std::to_string(_location.line());
    }
};


}