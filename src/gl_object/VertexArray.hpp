#pragma once

#include "gl_object/Handler.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

namespace detail {

class VertexArrayImpl : public Handler<VertexArrayImpl> {
public:
    VertexArrayImpl(Context& ctx,
                Valuable<const SrcLoc&> auto&& src_loc) :
        Handler(ctx, &_Init, &_Free, src_loc){
    }
    virtual ~VertexArrayImpl(){}



    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> enableAttrib(Valuable<const GLuint&> auto&& index,
                                          Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::EnableVertexArrayAttrib, is_gl>(id(), index, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> disableAttrib(Valuable<const GLuint&> auto&& index,
                                           Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::DisableVertexArrayAttrib, is_gl>(id(), index, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setAttribBinding(Valuable<const GLuint&> auto&& index,
                                              Valuable<const GLuint&> auto&& binding,
                                              Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayAttribBinding, is_gl>(id(), index, binding, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setAttribFormat(Valuable<const GLuint&> auto&& index,
                                             Valuable<const GLint&> auto&& size,
                                             Valuable<const GLenum&> auto&& type,
                                             Valuable<const GLboolean&> auto&& normalized,
                                             Valuable<const GLuint&> auto&& relative_offset,
                                             Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayAttribFormat, is_gl>(id(), index, size, type, normalized, relative_offset, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setBindingDivisor(Valuable<const GLuint&> auto&& binding,
                                               Valuable<const GLuint&> auto&& divisor,
                                               Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::VertexArrayBindingDivisor>(id(), binding, divisor, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setElementBuffer(Valuable<const BufferRef&> auto&& buffer,
                                              Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayElementBuffer, is_gl>(id(), buffer->id(), GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setVertexBuffer(Valuable<const GLuint&> auto&& binding,
                                             Valuable<const BufferRef&> auto&& buffer,
                                             Valuable<const GLintptr&> auto&& offset,
                                             Valuable<const GLsizei&> auto&& stride,
                                             Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::VertexArrayVertexBuffer, is_gl>(id(), binding, buffer->id(), offset, stride, GetValuable(src_loc).add());
    }


    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLboolean>> isAttribEnabled(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_ENABLED);
    //     return _getAttribParamiAs<GLboolean, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLint>> getAttribSize(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_SIZE);
    //     return _getAttribParamiAs<GLint, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLint>> getAttribStride(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_STRIDE);
    //     return _getAttribParamiAs<GLint, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLenum>> getAttribType(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_TYPE);
    //     return _getAttribParamiAs<GLenum, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLboolean>> isAttribNormalized(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
    //     return _getAttribParamiAs<GLboolean, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLboolean>> isAttribInteger(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_INTEGER);
    //     return _getAttribParamiAs<GLboolean, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLboolean>> isAttribLong(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_LONG);
    //     return _getAttribParamiAs<GLboolean, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLint>> getAttribDivisor(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
    //     return _getAttribParamiAs<GLint, is_gl>(index, pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<std::future<GLint64>> getAttribBindingOffset(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_ACTIVE_UNIFORMS);
    //     return _getAttribParami64As<GLint64, is_gl>(index, pname, GetValuable(src_loc).add());
    // }

protected:
    static GLuint _Init(Context& ctx, const SrcLoc& src_loc){
        GLuint id;
        ctx.gl.CreateVertexArrays(1, &id, src_loc);
        return id;
    }

    static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
        ctx.gl.DeleteVertexArrays(1, &id, src_loc);
    }
    
    // template<typename T, IsGlThread is_gl>
    // inline T _getAttribParamiAs(Valuable<const GLuint&> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
    //     Value<GLint> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetVertexArrayIndexediv, is_gl>(id(), index, pname, dst, src_loc);
    //     return dst.reinterpret<T>();
    // }
    
    // template<typename T, IsGlThread is_gl>
    // inline T _getAttribParami64As(Valuable<const GLuint&> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
    //     Value<GLint64> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetVertexArrayIndexed64iv, is_gl>(id(), index, pname, dst, src_loc);
    //     return dst.reinterpret<T>();
    // }

};

} // namespace detail

class VertexArrayRef : public CtxObjRef<detail::VertexArrayImpl> {
public:
    VertexArrayRef(Valuable<Context&> auto&& ctx,
                   Valuable<const SrcLoc&> auto&& src_loc) :
        CtxObjRef(ctx, src_loc){
    }
};

} // namespace glwpp::GL