#pragma once

#include <atomic>
#include <memory>
#include <mutex>

namespace glwpp {

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

template<class T>
using uptr = std::unique_ptr<T>;

template<class T, class ... Args>
inline sptr<T> make_sptr(Args&&... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

}