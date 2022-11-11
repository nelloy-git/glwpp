#pragma once

#include "Context.hpp"
#include "gl/Interface.hpp"
#include "gl/Value.hpp"

namespace glwpp {

namespace GL {

class Object {
public:
    Object(Context& ctx, const Value<>& id);
    Object(const Object&) = delete;
    Object(const Object&&) = delete;
    ~Object();

private:
    GLuintRes _id;

};

} // namespace GL

} // namespace glwpp