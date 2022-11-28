#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp {

namespace GL {

class VertexArrayBase : public Object {
public:
    EXPORT ~VertexArrayBase();

    EXPORT void enableAttrib(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void disableAttrib(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setAttribBinding(const Uint& index, const Uint& binding, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setAttribFormat(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relative_offset, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setBindingDivisor(const Uint& binding, const Uint& divisor, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setElementBuffer(const BufferBase& buffer, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setVertexBuffer(const Uint& binding, const BufferBase& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc = SrcLoc{});

    EXPORT Boolean isAttribEnabled(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getAttribSize(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getAttribStride(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Enum getAttribType(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isAttribNormalized(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isAttribInteger(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isAttribLong(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getAttribDivisor(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int64 getAttribBindingOffset(const Uint& index, const SrcLoc& src_loc = SrcLoc{});

protected:
    VertexArrayBase(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc);

};

class VertexArray : public VertexArrayBase, public SharedObject<VertexArray> {
public:
    EXPORT static std::shared_ptr<VertexArray> New(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{}){
        return std::shared_ptr<VertexArray>(new VertexArray(ctx, src_loc));
    }

protected:
    VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) : 
        VertexArrayBase(ctx, src_loc){
    }
};

} // namespace GL

} // namespace glwpp