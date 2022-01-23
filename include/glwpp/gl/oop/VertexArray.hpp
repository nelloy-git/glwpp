#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

namespace glwpp {

class VertexArray : public ContextData {
public:
    static constexpr bool AUTOCLEAR = true;

    VertexArray(wptr<Context> ctx);
    VertexArray(const VertexArray&) = delete;
    VertexArray(const VertexArray&&);
    virtual ~VertexArray();
    
    std::shared_future<bool> getAttribParam_i64v(sptr<gl::UInt> index,
                                                 sptr<gl::VertexArrayAttribParam> param,
                                                 sptr<gl::Int64> dst);
    std::shared_future<bool> getAttribParam_iv(sptr<gl::UInt> index,
                                               sptr<gl::VertexArrayAttribParam> param,
                                               sptr<gl::Int> dst);

    std::shared_future<bool> enableAttrib(sptr<gl::UInt> index);
    std::shared_future<bool> disableAttrib(sptr<gl::UInt> index);
    std::shared_future<bool> setAttribBinding(sptr<gl::UInt> index, sptr<gl::UInt> binding_index);
    std::shared_future<bool> setAttribFormat(sptr<gl::UInt> index, sptr<gl::Int> size,
                                             sptr<gl::DataType> type, sptr<gl::Bool> normalized,
                                             sptr<gl::UInt> relative_offset);
    std::shared_future<bool> setBindingDivisor(sptr<gl::UInt> binding_index, sptr<gl::UInt> divisor);

    std::shared_future<bool> setElementBuffer(sptr<Buffer> buffer);
    std::shared_future<bool> setVertexBuffer(sptr<gl::UInt> binding_index, sptr<Buffer> buffer,
                                             sptr<gl::IntPtr> offset, sptr<gl::IntPtr> stride);
};
    
} // namespace glwpp::gl
