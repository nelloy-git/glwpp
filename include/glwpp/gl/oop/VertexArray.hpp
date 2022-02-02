#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

namespace glwpp {

class VertexArray : public ContextData {
public:
    static constexpr bool DEBUG = true;

    VertexArray(wptr<Context> ctx);
    VertexArray(const VertexArray&) = delete;
    VertexArray(const VertexArray&&);
    virtual ~VertexArray();
    
    std::shared_future<bool> getAttribParam_i64v(Vop<const gl::UInt> index,
                                                 Vop<const gl::VertexArrayAttribParam> param,
                                                 Ptr<gl::Int64> dst);
    std::shared_future<bool> getAttribParam_iv(Vop<const gl::UInt> index,
                                               Vop<const gl::VertexArrayAttribParam> param,
                                               Ptr<gl::Int> dst);

    std::shared_future<bool> enableAttrib(Vop<const gl::UInt> index);
    std::shared_future<bool> disableAttrib(Vop<const gl::UInt> index);
    std::shared_future<bool> setAttribBinding(Vop<const gl::UInt> index, Vop<const gl::UInt> binding_index);
    std::shared_future<bool> setAttribFormat(Vop<const gl::UInt> index, Vop<const gl::Int> size,
                                             Vop<const gl::DataType> type, Vop<const gl::Bool> normalized,
                                             Vop<const gl::UInt> relative_offset);
    std::shared_future<bool> setBindingDivisor(Vop<const gl::UInt> binding_index, Vop<const gl::UInt> divisor);

    std::shared_future<bool> setElementBuffer(Ptr<const Buffer> buffer);
    std::shared_future<bool> setVertexBuffer(Vop<const gl::UInt> binding_index, Ptr<const Buffer> buffer,
                                             Vop<const gl::IntPtr> offset, Vop<const gl::IntPtr> stride);
};
    
} // namespace glwpp
