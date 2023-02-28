#pragma once

#include "gl_object/Handler.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

class VertexArray : public Handler<VertexArray> {
public:
    static Value<VertexArray> Make(Valuable<Context&> auto&& ctx,
                                   Valuable<const SrcLoc&> auto&& src_loc){
        return Value<VertexArray>::Make(new VertexArray(ctx, src_loc.add()));
    }
    virtual ~VertexArray(){}



    template<TState IsCtx>
    auto enableAttrib(Valuable<const GLuint&> auto&& index,
                      Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_enableAttrib>(index, src_loc.add());
    }
    
    template<TState IsCtx>
    auto disableAttrib(Valuable<const GLuint&> auto&& index,
                       Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_disableAttrib>(index, src_loc.add());
    }

    template<TState IsCtx>
    auto setVertexAttribPointer(){
        return callMember<IsCtx, &VertexArray::_setVertexAttribPointer>();
    }
    
    template<TState IsCtx>
    auto setAttribBinding(Valuable<const GLuint&> auto&& index,
                          Valuable<const GLuint&> auto&& binding,
                          Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_setAttribBinding>(index, binding, src_loc.add());
    }
    
    template<TState IsCtx>
    auto setAttribFormat(Valuable<const GLuint&> auto&& index,
                         Valuable<const GLint&> auto&& size,
                         Valuable<const GLenum&> auto&& type,
                         Valuable<const GLboolean&> auto&& normalized,
                         Valuable<const GLuint&> auto&& relative_offset,
                         Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_setAttribFormat>(index, size, type, normalized, relative_offset, src_loc.add());
    }
    
    template<TState IsCtx>
    auto setBindingDivisor(Valuable<const GLuint&> auto&& binding,
                           Valuable<const GLuint&> auto&& divisor,
                           Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_setBindingDivisor>(binding, divisor, src_loc.add());
    }
    
    template<TState IsCtx>
    auto setElementBuffer(Valuable<const Buffer&> auto&& buffer,
                          Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_setElementBuffer>(buffer, src_loc.add());
    }
    
    template<TState IsCtx>
    auto setVertexBuffer(Valuable<const GLuint&> auto&& binding,
                         Valuable<const Buffer&> auto&& buffer,
                         Valuable<const GLintptr&> auto&& offset,
                         Valuable<const GLsizei&> auto&& stride,
                         Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &VertexArray::_setVertexBuffer>(binding, buffer, offset, stride, src_loc.add());
    }


    
    // template<TState IsCtx>
    // Value<std::future<GLboolean>> isAttribEnabled(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_ENABLED);
    //     return _getAttribParamiAs<GLboolean, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLint>> getAttribSize(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_SIZE);
    //     return _getAttribParamiAs<GLint, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLint>> getAttribStride(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_STRIDE);
    //     return _getAttribParamiAs<GLint, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLenum>> getAttribType(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_TYPE);
    //     return _getAttribParamiAs<GLenum, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLboolean>> isAttribNormalized(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
    //     return _getAttribParamiAs<GLboolean, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLboolean>> isAttribInteger(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_INTEGER);
    //     return _getAttribParamiAs<GLboolean, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLboolean>> isAttribLong(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_LONG);
    //     return _getAttribParamiAs<GLboolean, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLint>> getAttribDivisor(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
    //     return _getAttribParamiAs<GLint, IsCtx>(index, pname, src_loc.add());
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLint64>> getAttribBindingOffset(Valuable<const GLuint&> auto&& index, Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_ACTIVE_UNIFORMS);
    //     return _getAttribParami64As<GLint64, IsCtx>(index, pname, src_loc.add());
    // }

protected:
    VertexArray(Valuable<Context&> auto&& ctx,
                Valuable<const SrcLoc&> auto&& src_loc) :
        Handler(ctx, &_Init, &_Free, src_loc.add()){
    }

    EXPORT static GLuint _Init(Context& ctx, const SrcLoc& src_loc);
    EXPORT static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

    EXPORT void _enableAttrib(Context& ctx, const GLuint& index, const SrcLoc& src_loc);
    EXPORT void _disableAttrib(Context& ctx, const GLuint& index, const SrcLoc& src_loc);
    EXPORT void _setVertexAttribPointer(Context& ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, const SrcLoc& src_loc);
    EXPORT void _setAttribBinding(Context& ctx, const GLuint& index, const GLuint& binding, const SrcLoc& src_loc);
    EXPORT void _setAttribFormat(Context& ctx, const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relative_offset, const SrcLoc& src_loc);
    EXPORT void _setBindingDivisor(Context& ctx, const GLuint& binding, const GLuint& divisor, const SrcLoc& src_loc);    
    EXPORT void _setElementBuffer(Context& ctx, const Buffer& buffer, const SrcLoc& src_loc);
    EXPORT void _setVertexBuffer(Context& ctx, const GLuint& binding, const Buffer& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc);
    
    // template<typename T, TState IsCtx>
    // inline T _getAttribParamiAs(Valuable<const GLuint&> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
    //     Value<GLint> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetVertexArrayIndexediv, IsCtx>(id(), index, pname, dst, src_loc.add());
    //     return dst.reinterpret<T>();
    // }
    
    // template<typename T, TState IsCtx>
    // inline T _getAttribParami64As(Valuable<const GLuint&> auto&& index, const Value<const GLenum>& pname, const SrcLoc src_loc){
    //     Value<GLint64> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetVertexArrayIndexed64iv, IsCtx>(id(), index, pname, dst, src_loc.add());
    //     return dst.reinterpret<T>();
    // }

};

} // namespace glwpp::GL