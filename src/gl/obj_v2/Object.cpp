#include "glwpp/gl/obj_v2/Object.hpp"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::gl::v2;

Object::~Object(){
}

Val<const UInt> Object::id() const {
    return Val<const UInt>(_id);
}

sptr<UInt> Object::_make_id(const wptr<Context>& wctx, Deleter deleter) const {
    return sptr<UInt>(new UInt(0), [wctx, deleter](UInt* id){
        auto ctx = wctx.lock();
        if (!ctx || *id == 0){
            delete id;
            return;
        }

        if (ctx->getThreadId() == std::this_thread::get_id()){
            deleter(*id);
            delete id;
        } else {
            ctx->onRun.push([deleter, id](){
                deleter(*id);
                delete id;
            });
        }
        return;
    });
}