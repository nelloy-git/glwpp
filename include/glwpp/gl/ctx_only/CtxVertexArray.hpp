#pragma once

#include "glwpp/gl/ctx_only/CtxObject.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/ctx_only/CtxBuffer.hpp"

namespace glwpp::gl {

class CtxVertexArray : public CtxObject {
    static UInt _createGlVertexArray(const SrcLoc& loc);
    static void _deleteGlVertexArray(const UInt& id);

public:
    // Empty CtxVertexArray
    CtxVertexArray(const EmptyObj& flag) : CtxObject(flag){};
    // Refer same gl object
    CtxVertexArray(const CtxVertexArray& other) : CtxObject(other){};
    CtxVertexArray(const SrcLoc& loc = SrcLoc());
    
    Int getAttribParamI(const UInt& index, const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    Int64 getAttribParamI64(const UInt& index, const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    bool isAttribEnabled(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    Int getAttribSize(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    Int getAttribStride(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    DataType getAttribType(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    bool isAttribNormalized(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    bool isAttribInteger(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    bool isAttribLong(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    Int getAttribDivisor(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    Int getAttribRelativeOffset(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    Int64 getAttribBindingOffset(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    
    void enableAttrib(const UInt& index, const SrcLoc& loc = SrcLoc());
    void disableAttrib(const UInt& index, const SrcLoc& loc = SrcLoc());
    void setAttribBinding(const UInt& index, const UInt& binding, const SrcLoc& loc = SrcLoc());
    void setAttribFormat(const UInt& index, const Int& size, const DataType& type,
                         const bool& normalized, const UInt& relative_offset, const SrcLoc& loc = SrcLoc());
    void setBindingDivisor(const UInt& binding, const UInt& divisor, const SrcLoc& loc = SrcLoc());

    void setElementBuffer(const CtxBuffer& buffer, const SrcLoc& loc = SrcLoc());
    void setVertexBuffer(const gl::UInt& binding, const CtxBuffer& buffer,
                         const gl::IntPtr& offset, const Sizei& stride, const SrcLoc& loc = SrcLoc());

    void draw(const gl::DrawMode& mode, const size_t& vertex_count,
              const gl::DataType& index_type, const size_t& instances, const SrcLoc& loc = SrcLoc()) const;
};
    
} // namespace glwpp::gl
