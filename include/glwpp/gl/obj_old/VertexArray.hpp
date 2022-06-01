#pragma once

#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp {

class VertexArray : public Object {
public:
    VertexArray(wptr<Context> ctx, const SrcLoc loc = SrcLoc());
    
    bool isAttribEnabled(const Val<gl::UInt>& index, Ptr<bool>& dst,
                         const SrcLoc loc = SrcLoc()) const;
    bool getAttribSize(const Val<gl::UInt>& index, Ptr<gl::Int>& dst,
                       const SrcLoc loc = SrcLoc()) const;
    bool getAttribStride(const Val<gl::UInt>& index, Ptr<gl::Int>& dst,
                         const SrcLoc loc = SrcLoc()) const;
    bool getAttribType(const Val<gl::UInt>& index, Ptr<gl::DataType>& dst,
                       const SrcLoc loc = SrcLoc()) const;
    bool isAttribNormalized(const Val<gl::UInt>& index, Ptr<bool>& dst,
                            const SrcLoc loc = SrcLoc()) const;
    bool isAttribInteger(const Val<gl::UInt>& index, Ptr<bool>& dst,
                         const SrcLoc loc = SrcLoc()) const;
    bool isAttribLong(const Val<gl::UInt>& index, Ptr<bool>& dst,
                      const SrcLoc loc = SrcLoc()) const;
    bool getAttribDivisor(const Val<gl::UInt>& index, Ptr<gl::Int>& dst,
                          const SrcLoc loc = SrcLoc()) const;
    bool getAttribRelativeOffset(const Val<gl::UInt>& index, Ptr<gl::Int>& dst,
                                 const SrcLoc loc = SrcLoc()) const;
    bool getAttribBindingOffset(const Val<gl::UInt>& index, Ptr<gl::Int64>& dst,
                                const SrcLoc loc = SrcLoc()) const;
    
    bool enableAttrib(const Val<gl::UInt>& index, const SrcLoc loc = SrcLoc());
    bool disableAttrib(const Val<gl::UInt>& index, const SrcLoc loc = SrcLoc());
    bool setAttribBinding(const Val<gl::UInt>& index, const Val<gl::UInt>& binding,
                         const SrcLoc loc = SrcLoc());
    bool setAttribFormat(const Val<gl::UInt>& index, const Val<gl::Int>& size,
                         const Val<gl::DataType>& type, const Val<bool>& normalized,
                         const Val<gl::UInt>& relative_offset, const SrcLoc loc = SrcLoc());
    bool setBindingDivisor(const Val<gl::UInt>& binding, const Val<gl::UInt>& divisor,
                           const SrcLoc loc = SrcLoc());

    bool setElementBuffer(const Buffer& buffer, const SrcLoc loc = SrcLoc());
    bool setVertexBuffer(const Val<gl::UInt>& binding, const Buffer& buffer,
                         const Val<gl::IntPtr>& offset, const Val<gl::Sizei>& stride,
                         const SrcLoc loc = SrcLoc());

    bool draw(const Val<gl::DrawMode>& mode, const Val<size_t>& vertex_count,
              const Val<gl::DataType>& index_type, const Val<size_t>& instances, const SrcLoc loc = SrcLoc()) const;
};
    
} // namespace glwpp
