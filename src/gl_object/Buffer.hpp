#pragma once

#include "Context.hpp"
#include "gl/InterfaceGl.hpp"

namespace glwpp {

class Buffer {
public:
    Buffer(Context& ctx);
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    ~Buffer();

private:
    std::shared_ptr<Interface::GLuint> _id;

};

} // namespace glwpp