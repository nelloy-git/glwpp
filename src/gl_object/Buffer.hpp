#pragma once

#include "context/CtxObj.hpp"
#include "gl_object/Handler.hpp"

namespace glwpp::GL {

namespace detail {

class BufferImpl : public Handler<BufferImpl> {
public:
    BufferImpl(Valuable<Context&> auto&& ctx,
               Valuable<const SrcLoc&> auto&& src_loc) :
        Handler(ctx, &_Init, &_Free, src_loc){
    }
    virtual ~BufferImpl(){}

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setData(Valuable<const GLsizeiptr&> auto&& size,
                                     Valuable<const void*> auto&& data,
                                     Valuable<const GLenum&> auto&& usage,
                                     Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<&BufferImpl::_setData, is_gl>(size, data, usage, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> clearData(Valuable<const GLenum&> auto&& internalformat,
                                       Valuable<const GLenum&> auto&& format,
                                       Valuable<const GLenum&> auto&& type,
                                       Valuable<const void*> auto&& data,
                                       Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<&BufferImpl::_clearData, is_gl>(internalformat, format, type, data, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setStorage(Valuable<const GLsizeiptr&> auto&& size,
                                        Valuable<const void*> auto&& data,
                                        Valuable<const GLbitfield&> auto&& flags,
                                        Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<&BufferImpl::_setStorage, is_gl>(size, data, flags, GetValuable(src_loc).add());
    }



    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void setSubData(Valuable<const GLintptr&> auto&& offset,
    //                 Valuable<const GLsizeiptr&> auto&& size,
    //                 Valuable<const void*> auto&& data,
    //                 Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::NamedBufferSubData, is_gl>(id(), offset, size, data, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void getSubData(Valuable<const GLintptr&> auto&& offset,
    //                 Valuable<const GLsizeiptr&> auto&& size,
    //                 Valuable<void*> auto&& data,
    //                 Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::GetNamedBufferSubData, is_gl>(id(), offset, size, data, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void copySubData(Valuable<const Buffer&> auto&& readBuffer,
    //                  Valuable<const GLintptr&> auto&& readOffset,
    //                  Valuable<const GLintptr&> auto&& writeOffset,
    //                  Valuable<const GLsizeiptr&> auto&& size,
    //                  Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::CopyNamedBufferSubData, is_gl>(readBuffer.id(), id(), readOffset, writeOffset, size, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void clearSubData(Valuable<const GLenum&> auto&& internalformat,
    //                   Valuable<const GLintptr&> auto&& offset,
    //                   Valuable<const GLsizeiptr&> auto&& size,
    //                   Valuable<const GLenum&> auto&& format,
    //                   Valuable<const GLenum&> auto&& type,
    //                   Valuable<const void*> auto&& data,
    //                   Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::ClearNamedBufferSubData, is_gl>(id(), internalformat, offset, size, format, type, data, GetValuable(src_loc).add());
    // }



    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> bindBase(Valuable<const GLenum&> auto&& target,
                                      Valuable<const GLuint&> auto&& index,
                                      Valuable<const SrcLoc&> auto&& src_loc){
        return callGLapi<&GLapi::BindBufferBase, is_gl>(target, index, id(), GetValuable(src_loc).add());
    }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void bindRange(Valuable<const GLenum&> auto&& target,
    //                Valuable<const GLuint&> auto&& index,
    //                Valuable<const GLintptr&> auto&& offset,
    //                Valuable<const GLsizeiptr&> auto&& size,
    //                Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::BindBufferRange, is_gl>(target, index, id(), offset, size, GetValuable(src_loc).add());
    // }


    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void getPointerv(Valuable<const GLenum&> auto&& pname,
    //                  Valuable<void*> auto&& params,
    //                  Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::GetNamedBufferPointerv, is_gl>(id(), pname, params, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<void*> map(Valuable<const GLenum&> auto&& access,
    //                  Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::MapNamedBuffer, is_gl>(id(), access, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<void*> mapRange(Valuable<const GLintptr&> auto&& offset,
    //                       Valuable<const GLsizeiptr&> auto&& length,
    //                       Valuable<const GLbitfield&> auto&& access,
    //                       Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::MapNamedBufferRange, is_gl>(id(), offset, length, access, GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLboolean> unmap(Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::UnmapNamedBuffer, is_gl>(id(), GetValuable(src_loc).add());
    // }

    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // void flushRange(Valuable<const GLintptr&> auto&& offset,
    //                 Valuable<const GLsizeiptr&> auto&& length,
    //                 Valuable<const SrcLoc&> auto&& src_loc){
    //     return addCallGl<&GLapi::FlushMappedNamedBufferRange, is_gl>(id(), offset, length, GetValuable(src_loc).add());
    // }



    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLenum> getMapAccess(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_ACCESS);
    //     return _getParamiAs<GLenum, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLbitfield> getMapRangeAccess(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_ACCESS_FLAGS);
    //     return _getParamiAs<GLbitfield, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLboolean> isImmutableStorage(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_IMMUTABLE_STORAGE);
    //     return _getParamiAs<GLboolean, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLboolean> isMapped(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_MAPPED);
    //     return _getParamiAs<GLboolean, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLint> getSize(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_SIZE);
    //     return _getParamiAs<GLint, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLbitfield> getStorageFlags(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_STORAGE_FLAGS);
    //     return _getParamiAs<GLbitfield, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLenum> getUsage(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_USAGE);
    //     return _getParamiAs<GLenum, is_gl>(pname, GetValuable(src_loc).add());
    // }


    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLint64> getMapLength(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_MAP_LENGTH); 
    //     return _getParami64As<GLint64, is_gl>(pname, GetValuable(src_loc).add());
    // }
    
    // template<IsGlThread is_gl = IsGlThread::Unknown>
    // Value<GLint64> getMapOffset(Valuable<const SrcLoc&> auto&& src_loc){
    //     static const Value<const GLenum> pname(GLapi::GL_BUFFER_MAP_OFFSET);
    //     return _getParami64As<GLint64, is_gl>(pname, GetValuable(src_loc).add());
    // }

private:
    static GLuint _Init(Context& ctx, const SrcLoc& src_loc);
    static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

    void _setData(Context& ctx, const GLsizeiptr& size, const void* data, const GLenum& usage, const SrcLoc& src_loc);
    void _clearData(Context& ctx, const GLenum& internalformat, const GLenum& format, const GLenum& type, const void* data, const SrcLoc& src_loc);
    void _setStorage(Context& ctx, const GLsizeiptr& size, const void* data, const GLbitfield& flags, const SrcLoc& src_loc);
    void _bindBase(Context& ctx, const GLenum target, const GLuint index, const SrcLoc src_loc);


    // template<typename T, IsGlThread is_gl>
    // inline T _getParamiAs(Valuable<const GLenum&> auto&& pname,
    //                       Valuable<const GLenum&> auto&& src_loc){
    //     Value<GLint> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetNamedBufferParameteriv, is_gl>(id(), pname, dst, src_loc);
    //     return dst.reinterpret<T>();
    // }

    // template<typename T, IsGlThread is_gl>
    // inline T _getParami64As(Valuable<const GLenum&> auto&& pname,
    //                         Valuable<const GLenum&> auto&& src_loc){
    //     Value<GLint64> dst(*this->lockCtx(), 0);
    //     addCallGl<&GLapi::GetNamedBufferParameteri64v, is_gl>(id(), pname, dst, src_loc);
    //     return dst.reinterpret<T>();
    // }
    
};

} // namespace detail

class BufferRef : public CtxObjRef<detail::BufferImpl> {
public:
    BufferRef(Valuable<Context&> auto&& ctx,
              Valuable<const SrcLoc&> auto&& src_loc) :
        CtxObjRef(ctx, src_loc){
    }
};

} // namespace glwpp::GL