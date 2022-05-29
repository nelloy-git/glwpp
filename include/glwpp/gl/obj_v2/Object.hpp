#pragma once

#include <tuple>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/gl/obj_v2/Val.hpp"
#include "glwpp/gl/obj_v2/Ptr.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp::gl::v2 {

class Object {
public:
    Val<const UInt> id() const;
    virtual ~Object();
    
    template<typename F, typename ... Args>
    bool executeInContext(const Val<SrcLoc>& src_loc, F&& func, Args&&... args) const {
        auto ctx = _wctx.lock();
        if (!ctx) return false;

        if (ctx->getThreadId() == std::this_thread::get_id()){
            func(std::forward<Args>(args)...);
        } else {
            ctx->onRun.push([func, src_loc, ...args = std::forward<Args>(args)](){
                func(args...);
            });
        }
        return true;
    }

protected:
    template<typename ... Args>
    using Initer = void(*)(gl::UInt&, Args...);
    using Deleter = void(*)(const gl::UInt&);

    const wptr<Context> _wctx;
    sptr<UInt> _id;

    template<typename ... Args>
    Object(const wptr<Context>& wctx, const Val<SrcLoc>& src_loc,
           Initer<Args...> initer, Deleter deleter, Args&&... args) :
        _wctx(wctx){
        _id = _make_id(wctx, deleter);
        executeInContext(src_loc, &Object::_runIniterInContext<Args...>,
                         initer, Val(_id), std::forward<Args>(args)...);
    }

    Object(const Object&) = delete;
    Object(const Object&&) = delete;

private:
    template<typename ... Args>
    static void _runIniterInContext(Initer<Args...> initer, UInt& id, Args&&... args){
        initer(id, args...);
    }

    // template<typename ... Args>
    // bool _init(const Val<SrcLoc>& src_loc, Initer<Args...> initer, Args&&... args){
    //     if (*_id != 0){throw std::logic_error("glwpp::gl::Object have been initialized already");}
    //     return executeInContext(src_loc, &Object::_runIniterInContext<Args...>,
    //                             initer, Val(_id), std::forward<Args>(args)...);
    // }

    sptr<UInt> _make_id(const wptr<Context>& wctx, Deleter deleter) const;

};


} // namespace glwpp