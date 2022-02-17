#pragma once

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/object/CtxBuffer.hpp"

namespace glwpp::gl {

class CtxVertexArray : public CtxObject {
public:
    CtxVertexArray(const SrcLoc& loc = SrcLoc::current());
    
    bool isAttribEnabled(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    Int getAttribSize(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    Int getAttribStride(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    DataType getAttribType(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    bool isAttribNormalized(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    bool isAttribInteger(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    bool isAttribLong(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    Int getAttribDivisor(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    Int getAttribRelativeOffset(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    Int64 getAttribBindingOffset(const UInt& index, const SrcLoc& loc = SrcLoc::current()) const;
    
    void enableAttrib(const UInt& index, const SrcLoc& loc = SrcLoc::current());
    void disableAttrib(const UInt& index, const SrcLoc& loc = SrcLoc::current());
    void setAttribBinding(const UInt& index, const UInt& binding, const SrcLoc& loc = SrcLoc::current());
    void setAttribFormat(const UInt& index, const Int& size, const DataType& type,
                         const bool& normalized, const UInt& relative_offset, const SrcLoc& loc = SrcLoc::current());
    void setBindingDivisor(const UInt& binding, const UInt& divisor, const SrcLoc& loc = SrcLoc::current());

    void setElementBuffer(const CtxBuffer& buffer, const SrcLoc& loc = SrcLoc::current());
    void setVertexBuffer(const gl::UInt& binding, const CtxBuffer& buffer,
                         const gl::IntPtr& offset, const Sizei& stride, const SrcLoc& loc = SrcLoc::current());
};
    
} // namespace glwpp::gl
