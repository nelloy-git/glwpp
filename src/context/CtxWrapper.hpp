#include "context/CtxExec.hpp"
#include "utils/WeakPtr.hpp" 

namespace glwpp {

template<typename T>
class CtxWrapper final {
public:
    template<bool IsCtx, typename ... Args>
    static Ref<CtxWrapper<T>> Make(Context& ctx, Args&&... args){
        constexpr auto func = [](Context& ctx, const Ref<CtxWrapper<T>>& wrapper, auto&&... args){
            wrapper->_init(ctx, args...);
        };

        Ptr<CtxWrapper<T>> p_wrapper(new CtxWrapper<T>(ctx));
        p_wrapper->_self = p_wrapper;
        Ref<CtxWrapper<T>> ref_wrapper(p_wrapper);

        p_wrapper->_exec.template call<IsCtx>(func, ref_wrapper, std::forward<Args>(args)...);
        return ref_wrapper;
    }
    virtual ~CtxWrapper(){};

    template<bool IsCtx, auto T::*M, typename... Args>
    auto member(Args&&... args){
        constexpr auto func = [](Context& ctx, const Ref<CtxWrapper<T>>& wrapper, auto&&... args){
            T* raw_ptr = wrapper->_ptr.get();
            (raw_ptr->*M)(std::forward<decltype(args)>(args)...);
        };
        return _exec.call<IsCtx>(func, _self.lock(), std::forward<Args>(args)...);
    }

    template<bool IsCtx, auto T::*M, typename... Args>
    auto memberCtx(Args&&... args){
        constexpr auto func = [](Context& ctx, const Ref<CtxWrapper<T>>& wrapper, auto&&... args){
            T* raw_ptr = wrapper->_ptr.get();
            (raw_ptr->*M)(ctx, std::forward<decltype(args)>(args)...);
        };
        return _exec.call<IsCtx>(func, _self.lock(), std::forward<Args>(args)...);
    }

protected:
    CtxWrapper(Context& ctx) :
        _exec(ctx),
        _ptr(nullptr){
    };

private:
    CtxExec _exec;
    WeakPtr<CtxWrapper<T>> _self;
    Ptr<T> _ptr;

    template<typename ... Args>
    void _init(Context& ctx, Args&&... args){
        _ptr.reset(new T(std::forward<Args>(args)...));
    }

};

} // namespace glwpp
