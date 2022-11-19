#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp {

namespace GL {

class VertexArray : public Object {
public:
    VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    VertexArray(const VertexArray&) = delete;
    VertexArray(const VertexArray&&) = delete;
    ~VertexArray();

    void enableAttrib(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    void disableAttrib(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    void setAttribBinding(const Uint& index, const Uint& binding, const SrcLoc& src_loc = SrcLoc{});
    void setAttribFormat(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relative_offset, const SrcLoc& src_loc = SrcLoc{});
    void setBindingDivisor(const Uint& binding, const Uint& divisor, const SrcLoc& src_loc = SrcLoc{});
    void setElementBuffer(const Buffer& buffer, const SrcLoc& src_loc = SrcLoc{});
    void setVertexBuffer(const Uint& binding, const Buffer& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc = SrcLoc{});

    Boolean isAttribEnabled(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Int getAttribSize(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Int getAttribStride(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Enum getAttribType(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Boolean isAttribNormalized(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Boolean isAttribInteger(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Boolean isAttribLong(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Int getAttribDivisor(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    Int64 getAttribBindingOffset(const Uint& index, const SrcLoc& src_loc = SrcLoc{});

};

} // namespace GL

} // namespace glwpp