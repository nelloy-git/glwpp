#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

class VertexArray : public ObjectHandle {
public:
    VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{}) :
        ObjectHandle(ctx, 0, &VertexArray::_free, src_loc.add()){
        addCallGl<&GLapi::CreateVertexArrays>(1, data(), src_loc.add());
    }
    EXPORT virtual ~VertexArray(){}



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void enableAttrib(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::EnableVertexArrayAttrib>(id(), index, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void disableAttrib(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::DisableVertexArrayAttrib>(id(), index, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setAttribBinding(const ConstUint& index, const ConstUint& binding, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::VertexArrayAttribBinding>(id(), index, binding, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setAttribFormat(const ConstUint& index, const ConstInt& size, const ConstEnum& type, const ConstBoolean& normalized, const ConstUint& relative_offset, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::VertexArrayAttribFormat>(id(), index, size, type, normalized, relative_offset, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setBindingDivisor(const ConstUint& binding, const ConstUint& divisor, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::VertexArrayBindingDivisor>(id(), binding, divisor, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setElementBuffer(const Buffer& buffer, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::VertexArrayElementBuffer>(id(), buffer.id(), src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setVertexBuffer(const ConstUint& binding, const Buffer& buffer, const ConstIntptr& offset, const ConstSizei& stride, const SrcLoc src_loc = SrcLoc{}){
        return addCallGl<&GLapi::VertexArrayVertexBuffer>(id(), binding, buffer.id(), offset, stride, src_loc.add());
    }

    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribEnabled(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribSize(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_SIZE);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribStride(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getAttribType(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_TYPE);
        return _getAttribParamiAs<Enum::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribNormalized(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribInteger(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_INTEGER);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isAttribLong(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_LONG);
        return _getAttribParamiAs<Boolean::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getAttribDivisor(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
        return _getAttribParamiAs<Int::type, is_gl_thread>(index, pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getAttribBindingOffset(const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_ACTIVE_UNIFORMS);
        return _getAttribParami64As<Int64::type, is_gl_thread>(index, pname, src_loc.add());
    }

protected:
    static void _free(std::weak_ptr<Context> wctx, const GLuint* id_ptr, const SrcLoc& src_loc){
        if (auto ctx = wctx.lock()){
            ctx->addCallCustom([](Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
                ctx.gl.DeleteVertexArrays(1, id_ptr, src_loc);
                delete id_ptr;
            }, id_ptr, src_loc);
        } else {
            delete id_ptr;
        }
    }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getAttribParamiAs(const ConstUint& index, const ConstEnum& pname, const SrcLoc src_loc){
        Int dst;
        addCallGl<&GLapi::GetVertexArrayIndexediv, is_gl_thread>(id(), index, pname, dst, src_loc);
        return dst.reinterpret<T>();
    }
    
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getAttribParami64As(const ConstUint& index, const ConstEnum& pname, const SrcLoc src_loc){
        Int64 dst;
        addCallGl<&GLapi::GetVertexArrayIndexed64iv, is_gl_thread>(id(), index, pname, dst, src_loc);
        return dst.reinterpret<T>();
    }

};

} // namespace glwpp::GL