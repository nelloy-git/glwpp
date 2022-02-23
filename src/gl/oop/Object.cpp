#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/object/CtxObject.hpp"

using namespace glwpp;

void Object::getId(Ptr<gl::UInt> dst) const {
    _executeGetter<gl::CtxObject, &gl::CtxObject::getId>(dst);
}

wptr<Context> Object::getContext() const {
    return _ctx;
}