#pragma once

#include <tuple>
#include <typeinfo>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/utils/Val.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp::gl {

class Object {
public:
    template<typename T>
    using Val = utils::Val<T>;
    using SrcLoc = utils::SrcLoc;

    Val<const UInt> id() const;
    wptr<Context> ctx() const;
    virtual ~Object() = 0;
    
    bool executeInContext(bool check_ctx, const Val<const SrcLoc>& src_loc, auto&& func, auto&&... args) const {
        if (!check_ctx){
            func(args...);
            _printDebug(src_loc);
            return true;
        }

        auto ctx = _wctx.lock();
        if (!ctx) return false;

        if (ctx->getThreadId() == std::this_thread::get_id()){
            func(args...);
            _printDebug(src_loc);
        } else {
            ctx->onRun.push([func, src_loc, args...](){
                func(args...);
                _printDebug(src_loc);
            });
        }
        return true;
    }

protected:
    const wptr<Context> _wctx;
    sptr<UInt> _id;

    Object(const wptr<Context>& wctx, const Val<const SrcLoc>& src_loc,
           auto&& initer, auto&& deleter, auto&&... args) :
        _wctx(wctx){
        _id = _make_id(wctx, deleter);
        executeInContext(true, src_loc, std::forward<decltype(initer)>(initer),
                         Val<UInt>(_id), std::forward<decltype(args)>(args)...);
    }

private:
    sptr<UInt> _make_id(const wptr<Context>& wctx, auto&& deleter) const {
        return sptr<UInt>(new UInt(0), [wctx, deleter](UInt* id){
            auto ctx = wctx.lock();
            if (!ctx || *id == 0){
                delete id;
                return;
            }

            if (ctx->getThreadId() == std::this_thread::get_id()){
                deleter(*id);
            } else {
                ctx->onRun.push([deleter, id = *id](){
                    deleter(id);
                });
            }
            delete id;
            return;
        });
    }

    // TODO custom error handler
    static void _printDebug(const SrcLoc& loc);

};

inline Object::~Object(){
}


} // namespace glwpp