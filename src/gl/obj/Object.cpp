#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/ctx_only/CtxObject.hpp"

using namespace glwpp;

void Object::getId(Ptr<gl::UInt> dst) const {
    _executeGetter<gl::CtxObject, &gl::CtxObject::getId>(dst);
}

wptr<Context> Object::getContext() const {
    return _ctx;
}