#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/object/CtxObject.hpp"

using namespace glwpp;

std::shared_future<bool> Object::getId(Ptr<gl::UInt> dst) const {
    return _getFromMethod<gl::CtxObject, &gl::CtxObject::getId>(dst);
}

wptr<Context> Object::getContext() const {
    return _ctx;
}