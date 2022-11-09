#pragma once

#include "glwpp/ctx/Context.hpp"
#include "glwpp/utils/Val.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp {

class ContextObject : public std::enable_shared_from_this<ContextObject> {

    template<typename C, typename R, typename ... Args>
    using Method = R(C::*)(Args...);

    template<typename C, typename R, typename ... Args>
    using ConstMethod = R(C::*)(Args...) const;

public:
    static sptr<ContextObject> make(const sptr<Context>& ctx);
    virtual ~ContextObject();

    const wptr<Context>& getContext() const;
    bool isContextThread() const;
    static void debug(const std::string& msg, const utils::SrcLoc& src_loc);

    bool executeInContext(auto&& func, auto&&... args) const {
        auto ctx = _wctx.lock();
        if (!ctx) return false;

        auto a = std::make_tuple(args...);
        ctx->onRun.push([=](){
            std::apply(func, a);
            // func(args...);
        });
        return true;
    }

    template<typename C, typename R, typename ... Args>
    bool executeMethodInContext(const Method<C, R, Args...>& method, auto&&... args){
        auto this_ptr = std::dynamic_pointer_cast<C>(shared_from_this());
        if (!this_ptr){
            return false;
        }
        return executeInContext(&ContextObject::_executeMethod<C, R, Args...>,
                                std::move(this_ptr), method, std::forward<decltype(args)>(args)...);
    }

    template<typename C, typename R, typename ... Args>
    bool executeMethodInContext(const ConstMethod<C, R, Args...>& method, auto&&... args) const {
        auto this_ptr = std::dynamic_pointer_cast<const C>(shared_from_this());
        if (!this_ptr){
            return false;
        }
        return executeInContext(&ContextObject::_executeConstMethod<const C, R, Args...>,
                                std::move(this_ptr), method, std::forward<decltype(args)>(args)...);
    }

    static std::atomic<std::function<void(const std::string&, const utils::SrcLoc&)>*> debug_function;

protected:
    ContextObject(const sptr<Context>& ctx);

private:
    std::thread::id _ctx_thread_id;
    const wptr<Context> _wctx;

    template<typename C, typename R, typename ... Args>
    static inline void _executeMethod(const sptr<C>& this_ptr, const Method<C, R, Args...>& method, Args&&... args){
        (this_ptr.get()->*method)(std::forward<Args>(args)...);
    }
    
    template<typename C, typename R, typename ... Args>
    static inline void _executeConstMethod(const sptr<C>& this_ptr, const ConstMethod<C, R, Args...>& method, Args&&... args){
        (this_ptr.get()->*method)(std::forward<Args>(args)...);
    }
};

}