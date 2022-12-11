#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

namespace detail {

class VertexArrayBase : public ObjectHandle {
public:
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void enableAttrib(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::EnableVertexArrayAttrib>(src_loc, id(), index);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void disableAttrib(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::DisableVertexArrayAttrib>(src_loc, id(), index);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setAttribBinding(const ConstUint& index, const ConstUint& binding, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::VertexArrayAttribBinding>(src_loc, id(), index, binding);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setAttribFormat(const ConstUint& index, const ConstInt& size, const ConstEnum& type, const ConstBoolean& normalized, const ConstUint& relative_offset, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::VertexArrayAttribFormat>(src_loc, id(), index, size, type, normalized, relative_offset);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setBindingDivisor(const ConstUint& binding, const ConstUint& divisor, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::VertexArrayBindingDivisor>(src_loc, id(), binding, divisor);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setElementBuffer(const Buffer& buffer, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::VertexArrayElementBuffer>(src_loc, id(), buffer.id());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setVertexBuffer(const ConstUint& binding, const Buffer& buffer, const ConstIntptr& offset, const ConstSizei& stride, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::VertexArrayVertexBuffer>(src_loc, id(), binding, buffer.id(), offset, stride);
    }

    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribEnabled(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribSize(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_SIZE);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribStride(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getAttribType(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_TYPE);
        return _getAttribParamiAs<Enum::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribNormalized(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribInteger(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_INTEGER);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribLong(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_LONG);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribDivisor(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc);
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getAttribBindingOffset(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_ACTIVE_UNIFORMS);
        return _getAttribParami64As<Int64::type, is_gl_thread>(index, pname, src_loc);
    }



    EXPORT virtual ~VertexArrayBase(){
        static const ConstSizei one(1);
        if (auto ctx = lockCtx()){
            _addCallGl<&GladGLContext::DeleteVertexArrays>(SrcLoc{}, one, id());
        }
    }

protected:
    // EXPORT VertexArrayBase(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc) :
    //     ObjectHandle(ctx, ctx->addCallCustom(src_loc, [](Context& ctx){
    //         unsigned int dst;
    //         ctx.gl.CreateVertexArrays(1, &dst);
    //         return dst;
    //     })){
    // }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getAttribParamiAs(const ConstUint& index, const ConstEnum& pname, const SrcLoc src_loc){
        Int dst;
        _addCallGl<&GladGLContext::GetVertexArrayIndexediv, is_gl_thread>(src_loc, id(), index, pname, dst);
        return dst.reinterpret<T>();
    }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getAttribParami64As(const ConstUint& index, const ConstEnum& pname, const SrcLoc src_loc){
        Int64 dst;
        _addCallGl<&GladGLContext::GetVertexArrayIndexed64iv, is_gl_thread>(src_loc, id(), index, pname, dst);
        return dst.reinterpret<T>();
    }

};

} // namespace detail

// class VertexArray : public detail::VertexArrayBase, public SharedObject<VertexArray> {
// public:
//     EXPORT static std::shared_ptr<VertexArray> New(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc = SrcLoc{}){
//         return std::shared_ptr<VertexArray>(new VertexArray(ctx, src_loc));
//     }

// protected:
//     EXPORT VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc) : 
//         VertexArrayBase(ctx, src_loc){
//     }
// };

} // namespace glwpp::GL