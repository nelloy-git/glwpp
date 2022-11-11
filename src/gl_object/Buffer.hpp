#pragma once

#include "Context.hpp"
#include "gl/Interface.hpp"
#include "gl/Value.hpp"

namespace glwpp {

namespace GL {

class Buffer {
public:
    Buffer(Context& ctx);
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    ~Buffer();

private:
    GLuintRes _id;

};

} // namespace GL

} // namespace glwpp