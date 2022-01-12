#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/oop/Buffer.hpp"
// #include "glwpp/gl/oop/VertexFormat.hpp"

namespace glwpp {

class VertexArray : public ContextData {
public:
    VertexArray(wptr<Context> ctx);
    VertexArray(const VertexArray&) = delete;
    VertexArray(const VertexArray&&);
    virtual ~VertexArray();
    
    std::shared_future<gl::Int64> getAttribParamInt64(gl::UInt index, gl::VertexArrayAttribParamInt param);
    std::shared_future<gl::Int> getAttribParamInt(gl::UInt index, gl::VertexArrayAttribParamInt param);

    std::shared_future<bool> enableAttrib(gl::UInt index);
    std::shared_future<bool> disableAttrib(gl::UInt index);
    std::shared_future<bool> setAttribBinding(gl::UInt index, gl::UInt binding_index);
    std::shared_future<bool> setAttribFormat(gl::UInt index, gl::Int size, gl::DataType type, bool normalized, gl::UInt relative_offset);
    std::shared_future<bool> setBindingDivisor(gl::UInt binding_index, gl::UInt divisor);

    std::shared_future<bool> setElementBuffer(const Buffer &buffer);
    std::shared_future<bool> setVertexBuffer(gl::UInt binding_index, const Buffer &buffer, gl::IntPtr offset, gl::IntPtr stride);
};
    
} // namespace glwpp::gl
