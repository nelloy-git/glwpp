#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

namespace glwpp {

class VertexArray : public Object {
public:
    VertexArray(wptr<Context> ctx, const SrcLoc& loc = SrcLoc::current());
    
    std::shared_future<bool> isAttribEnabled(const Vop<gl::UInt> index, Ptr<bool> dst,
                                             const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribSize(const Vop<gl::UInt> index, Ptr<gl::Int> dst,
                                           const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribStride(const Vop<gl::UInt> index, Ptr<gl::Int> dst,
                                             const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribType(const Vop<gl::UInt> index, Ptr<gl::DataType> dst,
                                           const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> isAttribNormalized(const Vop<gl::UInt> index, Ptr<bool> dst,
                                                const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> isAttribInteger(const Vop<gl::UInt> index, Ptr<bool> dst,
                                             const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> isAttribLong(const Vop<gl::UInt> index, Ptr<bool> dst,
                                          const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribDivisor(const Vop<gl::UInt> index, Ptr<gl::Int> dst,
                                              const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribRelativeOffset(const Vop<gl::UInt> index, Ptr<gl::Int> dst,
                                                     const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttribBindingOffset(const Vop<gl::UInt> index, Ptr<gl::Int64> dst,
                                                    const SrcLoc& loc = SrcLoc::current()) const;
    
    std::shared_future<bool> enableAttrib(const Vop<gl::UInt> index, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> disableAttrib(const Vop<gl::UInt> index, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setAttribBinding(const Vop<gl::UInt> index, const Vop<gl::UInt> binding,
                                              const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setAttribFormat(const Vop<gl::UInt> index, const Vop<gl::Int> size,
                                             const Vop<gl::DataType> type, const Vop<bool> normalized,
                                             const Vop<gl::UInt> relative_offset, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setBindingDivisor(const Vop<gl::UInt> binding, const Vop<gl::UInt> divisor,
                                               const SrcLoc& loc = SrcLoc::current());

    std::shared_future<bool> setElementBuffer(const Vop<Buffer> buffer, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setVertexBuffer(const Vop<gl::UInt> binding, const Vop<Buffer> buffer,
                                             const Vop<gl::IntPtr> offset, const Vop<gl::Sizei> stride,
                                             const SrcLoc& loc = SrcLoc::current());
};
    
} // namespace glwpp
