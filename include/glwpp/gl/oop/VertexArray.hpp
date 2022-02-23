#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

namespace glwpp {

class VertexArray : public Object {
public:
    VertexArray(wptr<Context> ctx, const SrcLoc& loc = SrcLoc());
    
    bool isAttribEnabled(const Vop<gl::UInt>& index, Ptr<bool>& dst,
                         const SrcLoc& loc = SrcLoc()) const;
    bool getAttribSize(const Vop<gl::UInt>& index, Ptr<gl::Int>& dst,
                       const SrcLoc& loc = SrcLoc()) const;
    bool getAttribStride(const Vop<gl::UInt>& index, Ptr<gl::Int>& dst,
                         const SrcLoc& loc = SrcLoc()) const;
    bool getAttribType(const Vop<gl::UInt>& index, Ptr<gl::DataType>& dst,
                       const SrcLoc& loc = SrcLoc()) const;
    bool isAttribNormalized(const Vop<gl::UInt>& index, Ptr<bool>& dst,
                            const SrcLoc& loc = SrcLoc()) const;
    bool isAttribInteger(const Vop<gl::UInt>& index, Ptr<bool>& dst,
                         const SrcLoc& loc = SrcLoc()) const;
    bool isAttribLong(const Vop<gl::UInt>& index, Ptr<bool>& dst,
                      const SrcLoc& loc = SrcLoc()) const;
    bool getAttribDivisor(const Vop<gl::UInt>& index, Ptr<gl::Int>& dst,
                          const SrcLoc& loc = SrcLoc()) const;
    bool getAttribRelativeOffset(const Vop<gl::UInt>& index, Ptr<gl::Int>& dst,
                                 const SrcLoc& loc = SrcLoc()) const;
    bool getAttribBindingOffset(const Vop<gl::UInt>& index, Ptr<gl::Int64>& dst,
                                const SrcLoc& loc = SrcLoc()) const;
    
    bool enableAttrib(const Vop<gl::UInt>& index, const SrcLoc& loc = SrcLoc());
    bool disableAttrib(const Vop<gl::UInt>& index, const SrcLoc& loc = SrcLoc());
    bool setAttribBinding(const Vop<gl::UInt>& index, const Vop<gl::UInt>& binding,
                         const SrcLoc& loc = SrcLoc());
    bool setAttribFormat(const Vop<gl::UInt>& index, const Vop<gl::Int>& size,
                         const Vop<gl::DataType>& type, const Vop<bool>& normalized,
                         const Vop<gl::UInt>& relative_offset, const SrcLoc& loc = SrcLoc());
    bool setBindingDivisor(const Vop<gl::UInt>& binding, const Vop<gl::UInt>& divisor,
                           const SrcLoc& loc = SrcLoc());

    bool setElementBuffer(const Buffer& buffer, const SrcLoc& loc = SrcLoc());
    bool setVertexBuffer(const Vop<gl::UInt>& binding, const Buffer& buffer,
                         const Vop<gl::IntPtr>& offset, const Vop<gl::Sizei>& stride,
                         const SrcLoc& loc = SrcLoc());
};
    
} // namespace glwpp
