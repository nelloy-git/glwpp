#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/object/CtxObject.hpp"

using namespace glwpp;

wptr<Context> Object::getCtx() const {
    return _ctx;
}


sptr<Context> Object::_lockCtx(const wptr<Context>& ctx){
    auto locked_ctx = ctx.lock();
    if (!locked_ctx){
        throw std::runtime_error("Context do not exist");
    }
    return locked_ctx;
}

std::shared_future<bool> Object::getId(Ptr<gl::UInt> dst) const {
    return _getFromMethod<gl::CtxObject, &gl::CtxObject::getId>(dst);
}

sptr<Context> Object::_lockCtx() const {
    return _lockCtx(_ctx);
}