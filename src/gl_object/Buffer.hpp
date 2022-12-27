#pragma once

#include "gl_object/Handler.hpp"

namespace glwpp::GL {

class Buffer : public Handler {
public:
    Buffer(Valuable<Context&> auto&& ctx,
           Valuable<const SrcLoc&> auto&& src_loc) :
        Handler(GetValuable(ctx), new GLuint(0), &Handler::DELETER<_free>, GetValuable(src_loc).add()){
        call<[](Context& ctx, GLuint& dst, const SrcLoc& src_loc){
            ctx.gl.CreateBuffers(1, &dst, src_loc);
        }, IsGlThread::Unknown>(data, GetValuable(src_loc).add());
    }
    virtual ~Buffer(){}

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setData(Valuable<const GLsizeiptr&> auto&& size,
                 Valuable<const void*> auto&& data,
                 Valuable<const GLenum&> auto&& usage,
                 Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::NamedBufferData, is_gl_thread>(id(), size, data, usage, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void clearData(Valuable<const GLenum&> auto&& internalformat,
                   Valuable<const GLenum&> auto&& format,
                   Valuable<const GLenum&> auto&& type,
                   Valuable<const void*> auto&& data,
                   Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::ClearNamedBufferData, is_gl_thread>(id(), internalformat, format, type, data, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setStorage(Valuable<const GLsizeiptr&> auto&& size,
                    Valuable<const void*> auto&& data,
                    Valuable<const GLbitfield&> auto&& flags,
                    Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::NamedBufferStorage, is_gl_thread>(id(), size, data, flags, GetValuable(src_loc).add());
    }



    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setSubData(Valuable<const GLintptr&> auto&& offset,
                    Valuable<const GLsizeiptr&> auto&& size,
                    Valuable<const void*> auto&& data,
                    Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::NamedBufferSubData, is_gl_thread>(id(), offset, size, data, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void getSubData(Valuable<const GLintptr&> auto&& offset,
                    Valuable<const GLsizeiptr&> auto&& size,
                    Valuable<void*> auto&& data,
                    Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::GetNamedBufferSubData, is_gl_thread>(id(), offset, size, data, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void copySubData(Valuable<const Buffer&> auto&& readBuffer,
                     Valuable<const GLintptr&> auto&& readOffset,
                     Valuable<const GLintptr&> auto&& writeOffset,
                     Valuable<const GLsizeiptr&> auto&& size,
                     Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::CopyNamedBufferSubData, is_gl_thread>(readBuffer.id(), id(), readOffset, writeOffset, size, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void clearSubData(Valuable<const GLenum&> auto&& internalformat,
                      Valuable<const GLintptr&> auto&& offset,
                      Valuable<const GLsizeiptr&> auto&& size,
                      Valuable<const GLenum&> auto&& format,
                      Valuable<const GLenum&> auto&& type,
                      Valuable<const void*> auto&& data,
                      Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::ClearNamedBufferSubData, is_gl_thread>(id(), internalformat, offset, size, format, type, data, GetValuable(src_loc).add());
    }



    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void bindBase(Valuable<const GLenum&> auto&& target,
                  Valuable<const GLuint&> auto&& index,
                  Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::BindBuffer, is_gl_thread>(target, index, id(), GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void bindRange(Valuable<const GLenum&> auto&& target,
                   Valuable<const GLuint&> auto&& index,
                   Valuable<const GLintptr&> auto&& offset,
                   Valuable<const GLsizeiptr&> auto&& size,
                   Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::BindBufferRange, is_gl_thread>(target, index, id(), offset, size, GetValuable(src_loc).add());
    }


    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void getPointerv(Valuable<const GLenum&> auto&& pname,
                     Valuable<void*> auto&& params,
                     Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::GetNamedBufferPointerv, is_gl_thread>(id(), pname, params, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<void*> map(Valuable<const GLenum&> auto&& access,
                     Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::MapNamedBuffer, is_gl_thread>(id(), access, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<void*> mapRange(Valuable<const GLintptr&> auto&& offset,
                          Valuable<const GLsizeiptr&> auto&& length,
                          Valuable<const GLbitfield&> auto&& access,
                          Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::MapNamedBufferRange, is_gl_thread>(id(), offset, length, access, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLboolean> unmap(Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::UnmapNamedBuffer, is_gl_thread>(id(), GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void flushRange(Valuable<const GLintptr&> auto&& offset,
                    Valuable<const GLsizeiptr&> auto&& length,
                    Valuable<const SrcLoc&> auto&& src_loc){
        return addCallGl<&GLapi::FlushMappedNamedBufferRange, is_gl_thread>(id(), offset, length, GetValuable(src_loc).add());
    }



    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLenum> getMapAccess(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_ACCESS);
        return _getParamiAs<GLenum, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLbitfield> getMapRangeAccess(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_ACCESS_FLAGS);
        return _getParamiAs<GLbitfield, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLboolean> isImmutableStorage(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_IMMUTABLE_STORAGE);
        return _getParamiAs<GLboolean, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLboolean> isMapped(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_MAPPED);
        return _getParamiAs<GLboolean, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLint> getSize(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_SIZE);
        return _getParamiAs<GLint, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLbitfield> getStorageFlags(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_STORAGE_FLAGS);
        return _getParamiAs<GLbitfield, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLenum> getUsage(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_USAGE);
        return _getParamiAs<GLenum, is_gl_thread>(pname, GetValuable(src_loc).add());
    }


    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLint64> getMapLength(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_MAP_LENGTH); 
        return _getParami64As<GLint64, is_gl_thread>(pname, GetValuable(src_loc).add());
    }
    
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<GLint64> getMapOffset(Valuable<const SrcLoc&> auto&& src_loc){
        static const Value<const GLenum> pname(GL_BUFFER_MAP_OFFSET);
        return _getParami64As<GLint64, is_gl_thread>(pname, GetValuable(src_loc).add());
    }

private:
    static void _free(Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
        ctx.gl.DeleteBuffers(1, id_ptr, src_loc);
    }

    template<typename T, IsGlThread is_gl_thread>
    inline T _getParamiAs(Valuable<const GLenum&> auto&& pname,
                          Valuable<const GLenum&> auto&& src_loc){
        Value<GLint> dst(*this->lockCtx(), 0);
        addCallGl<&GLapi::GetNamedBufferParameteriv, is_gl_thread>(id(), pname, dst, src_loc);
        return dst.reinterpret<T>();
    }

    template<typename T, IsGlThread is_gl_thread>
    inline T _getParami64As(Valuable<const GLenum&> auto&& pname,
                            Valuable<const GLenum&> auto&& src_loc){
        Value<GLint64> dst(*this->lockCtx(), 0);
        addCallGl<&GLapi::GetNamedBufferParameteri64v, is_gl_thread>(id(), pname, dst, src_loc);
        return dst.reinterpret<T>();
    }
    
};

} // namespace glwpp::GL