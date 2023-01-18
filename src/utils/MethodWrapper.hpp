#pragma once

#include <functional>
#include <memory>
#include <mutex>

namespace glwpp {

template<typename T, typename W>
class MethodWrapper {
public:
    MethodWrapper(auto&&... args) :
        _wrapped(std::forward<decltype(args)>(args)...){
    }


private:
    struct ptr {
        MethodWrapper* wrapper;
        
    }

    T _wrapped;

};

// namespace redi
// {
//   /** Generic implementation of the EXECUTE-AROUND POINTER pattern.
//    *
//    * See http://www.two-sdg.demon.co.uk/curbralan/papers/europlop/ExecutingAroundSequences.pdf
//    */
//   template<typename T>
//     class exec_around
//     {
//       template<typename> struct ptr;

//     public:
//       typedef std::function<void()> func_type;

//       template<typename... Args>
//         exec_around(func_type pre, func_type post, Args&&... args)
//         : pre(std::move(pre)), post(std::move(post)), t{std::forward<Args>(args)...}
//         { }

//       ptr<exec_around> operator->() { return ptr<exec_around>(this); }
//       ptr<const exec_around> operator->() const { return ptr<const exec_around>(this); }

//     private:
//       template<typename EA>
//         struct ptr
//         {
//           tidy_ptr<EA> ea;

//           explicit ptr(EA* ea) noexcept : ea(ea) { ea->pre(); }
//           ~ptr() { if (ea) ea->post(); }

//           ptr(const ptr&) = delete;
//           ptr& operator=(const ptr&) = delete;

//           ptr(ptr&&) = default;

//           auto operator->() const noexcept -> decltype(&ea->t)
//           { return &ea->t; }
//         };

//       func_type pre;
//       func_type post;
//       T t;
//     };

//   /// Create a wrapper for T that locks a mutex around each member function call.
//   template<typename T, typename... Args>
//     exec_around<T>
//     mutex_around(Args&&... args)
//     {
//       auto mx = std::make_shared<std::mutex>();
//       auto locker = [mx] { mx->lock(); };
//       auto unlocker = [mx] { mx->unlock(); };
//       return exec_around<T>( locker, unlocker, std::forward<Args>(args)... );
//     }

// }  // namespace redi

// #endif  // REDI_EXEC_AROUND_H

} // namespace glwpp
