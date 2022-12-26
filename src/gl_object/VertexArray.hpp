#pragma once

#include "gl_object/Handler.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

class VertexArray : public Handler {
public:
    VertexArray(Context& ctx,
                Valuable<const SrcLoc> auto&& src_loc) :
        Handler(ctx, new GLuint(0), &Handler::DELETER<_free>, GetValuable(src_loc).add()){
        call<[](Context& ctx, GLuint& dst, const SrcLoc& src_loc){
            ctx.gl.CreateVertexArrays(1, &dst, src_loc);
        }, IsGlThread::Unknown>(data, GetValuable(src_loc).add());
    }
    EXPORT virtual ~VertexArray(){}



    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void enableAttrib(Valuable<const GLuint> auto&& index,
                             Valuable<const SrcLoc> auto&& src_loc){
        return callGLapi<&GLapi::EnableVertexArrayAttrib, is_gl_thread>(id(), index, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void disableAttrib(Valuable<const GLuint> auto&& index,
                              Valuable<const SrcLoc> auto&& src_loc){
        return callGLapi<&GLapi::DisableVertexArrayAttrib, is_gl_thread>(id(), index, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void setAttribBinding(Valuable<const GLuint> auto&& index,
                                 Valuable<const GLuint> auto&& binding,
                                 Valuable<const SrcLoc> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayAttribBinding, is_gl_thread>(id(), index, binding, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void setAttribFormat(Valuable<const GLuint> auto&& index,
                                Valuable<const GLint> auto&& size,
                                Valuable<const GLenum> auto&& type,
                                Valuable<const GLboolean> auto&& normalized,
                                Valuable<const GLuint> auto&& relative_offset,
                                Valuable<const SrcLoc> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayAttribFormat, is_gl_thread>(id(), index, size, type, normalized, relative_offset, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void setBindingDivisor(Valuable<const GLuint> auto&& binding,
                                  Valuable<const GLuint> auto&& divisor,
                                  Valuable<const SrcLoc> auto&& src_loc){
        return addCallGl<&GLapi::VertexArrayBindingDivisor>(id(), binding, divisor, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void setElementBuffer(Valuable<const Buffer> auto&& buffer,
                                 Valuable<const SrcLoc> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const Buffer& buffer, const SrcLoc& src_loc){
            ctx.gl.VertexArrayElementBuffer(id, buffer.id().value(), src_loc);
        }, is_gl_thread>(id(), buffer, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT void setVertexBuffer(Valuable<const GLuint> auto&& binding,
                                Valuable<const Buffer> auto&& buffer,
                                Valuable<const GLintptr> auto&& offset,
                                Valuable<const GLsizei> auto&& stride,
                                Valuable<const SrcLoc> auto&& src_loc){
        return call<[](Context& ctx, const GLuint& id, const GLuint& binding, const Buffer& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
            ctx.gl.VertexArrayVertexBuffer(id, binding, buffer.id().value(), offset, stride, src_loc);
        }, is_gl_thread>(id(), binding, buffer, offset, stride, GetValuable(src_loc).add());
    }

    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLboolean> isAttribEnabled(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
        return _getAttribParamiAs<GLboolean, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLint> getAttribSize(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_SIZE);
        return _getAttribParamiAs<GLint, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLint> getAttribStride(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
        return _getAttribParamiAs<GLint, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLenum> getAttribType(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_TYPE);
        return _getAttribParamiAs<GLenum, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLboolean> isAttribNormalized(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
        return _getAttribParamiAs<GLboolean, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLboolean> isAttribInteger(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_INTEGER);
        return _getAttribParamiAs<GLboolean, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLboolean> isAttribLong(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_LONG);
        return _getAttribParamiAs<GLboolean, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLint> getAttribDivisor(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
        return _getAttribParamiAs<GLint, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    EXPORT Value<GLint64> getAttribBindingOffset(Valuable<const GLuint> auto&& index, Valuable<const SrcLoc> auto&& src_loc){
        static const Value<const GLenum> pname(GL_ACTIVE_UNIFORMS);
        return _getAttribParami64As<GLint64, is_gl_thread>(index, pname, GetValuable(src_loc).add());
    }

protected:
    static void _free(Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
        ctx.gl.DeleteVertexArrays(1, id_ptr, src_loc);
    }
    
    template<typename T, IsGlThread is_gl_thread>
    inline T _getAttribParamiAs(Valuable<const GLuint> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
        Value<GLint> dst(*this->lockCtx(), 0);
        addCallGl<&GLapi::GetVertexArrayIndexediv, is_gl_thread>(id(), index, pname, dst, src_loc);
        return dst.reinterpret<T>();
    }
    
    template<typename T, IsGlThread is_gl_thread>
    inline T _getAttribParami64As(Valuable<const GLuint> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
        Value<GLint64> dst(*this->lockCtx(), 0);
        addCallGl<&GLapi::GetVertexArrayIndexed64iv, is_gl_thread>(id(), index, pname, dst, src_loc);
        return dst.reinterpret<T>();
    }

};

} // namespace glwpp::GL