#pragma once

#include <tuple>
#include <typeinfo>

#include "glwpp/ctx/ContextObject.hpp"
#include "glwpp/gl/types.hpp"

namespace glwpp::gl {

class Object : public ContextObject {
public:
    static sptr<Object> make(const sptr<Context>& ctx,
                             auto&& initer, auto&& deleter, auto&&... args){
        return sptr<Object>(new Object(ctx, initer, deleter, std::forward<decltype(args)>(args)...));
    }
    virtual ~Object();

    const Val<const UInt> id() const;
    static void debug(const utils::SrcLoc& src_loc);

protected:
    Val<UInt> _id;

    Object(const sptr<Context>& ctx,
           auto&& initer, auto&& deleter, auto&&... args) :
        ContextObject(ctx),
        _id(_make_id(ctx, deleter)){
        if (!isContextThread()){
            executeInContext(initer, _id, std::forward<decltype(args)>(args)...);
        } else {
            initer(_id, std::forward<decltype(args)>(args)...);
        }
    }

private:
    // Hide parent's make
    using ContextObject::make;

    sptr<UInt> _make_id(const sptr<Context>& ctx, auto&& deleter) const {
        return sptr<UInt>(new UInt(0), [wctx = wptr<Context>(ctx), deleter](UInt* id){
            auto ctx = wctx.lock();
            if (!ctx || *id == 0){
                delete id;
                return;
            }

            if (ctx->getThreadId() == std::this_thread::get_id()){
                deleter(*id);
            } else {
                ctx->onRun.push([=](){
                    deleter(*id);
                });
            }
            delete id;
            return;
        });
    };
};


} // namespace glwpp