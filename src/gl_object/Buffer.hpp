#pragma once

#include "glad/gl.h"

#include "gl_object/Object.hpp"

namespace glwpp::GL {

namespace detail {

class BufferBase : public Object {
public:
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setData(const ConstSizeiptr& size, const ConstData& data, const ConstEnum& usage, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::NamedBufferData, is_gl_thread>(src_loc.add(), id(), size, data, usage);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void clearData(const ConstEnum& internalformat, const ConstEnum& format, const ConstEnum& type, const ConstData& data, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::ClearNamedBufferData, is_gl_thread>(src_loc.add(), id(), id(), internalformat, format, type, data);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setStorage(const ConstSizeiptr& size, const ConstData& data, const ConstBitfield& flags, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::NamedBufferStorage, is_gl_thread>(src_loc.add(), id(), size, data, flags);
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setSubData(const ConstIntptr& offset, const ConstSizeiptr& size, const ConstData& data, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::NamedBufferSubData, is_gl_thread>(src_loc.add(), id(), offset, size, data);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void getSubData(const ConstIntptr& offset, const ConstSizeiptr& size, const Data& data, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::GetNamedBufferSubData, is_gl_thread>(src_loc.add(), id(), offset, size, data);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void copySubDataFrom(const BufferBase& readBuffer, const ConstIntptr& readOffset, const ConstIntptr& writeOffset, const ConstSizeiptr& size, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::CopyNamedBufferSubData, is_gl_thread>(src_loc.add(), readBuffer.id(), id(), readOffset, writeOffset, size);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void clearSubData(const ConstEnum& internalformat, const ConstIntptr& offset, const ConstSizeiptr& size, const ConstEnum& format, const ConstEnum& type, const ConstData& data, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::ClearNamedBufferSubData, is_gl_thread>(src_loc.add(), id(), internalformat, offset, size, format, type, data);
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void bindBase(const ConstEnum& target, const ConstUint& index, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::BindBufferBase, is_gl_thread>(src_loc.add(), target, index, id());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void bindRange(const ConstEnum& target, const ConstUint& index, const ConstIntptr& offset, const ConstSizeiptr& size, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::BindBufferRange, is_gl_thread>(src_loc.add(), target, index, id(), offset, size);
    }


    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void getPointerv(const ConstEnum& pname, const DataPtr& params, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::GetNamedBufferPointerv, is_gl_thread>(src_loc.add(), id(), pname, params);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT DataPtr map(const ConstEnum& access, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::MapNamedBuffer, is_gl_thread>(src_loc.add(), id(), access);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT DataPtr mapRange(const ConstIntptr& offset, const ConstSizeiptr& length, const ConstBitfield& access, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::MapNamedBufferRange, is_gl_thread>(src_loc.add(), id(), offset, length, access);
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean unmap(const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::UnmapNamedBuffer, is_gl_thread>(src_loc.add(), id());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void flushRange(const ConstIntptr& offset, const ConstSizeiptr& length, const SrcLoc src_loc = SrcLoc{}){
        return _addCallGl<&GladGLContext::FlushMappedNamedBufferRange, is_gl_thread>(src_loc.add(), id(), offset, length);
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getMapAccess(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_ACCESS);
        return _getParamiAs<Enum::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Bitfield getMapRangeAccess(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_ACCESS_FLAGS);
        return _getParamiAs<Bitfield::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isImmutableStorage(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_IMMUTABLE_STORAGE);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isMapped(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAPPED);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getSize(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_SIZE);
        return _getParamiAs<Int::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Bitfield getStorageFlags(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_STORAGE_FLAGS);
        return _getParamiAs<Bitfield::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getUsage(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_USAGE);
        return _getParamiAs<Enum::type, is_gl_thread>(pname, src_loc.add());
    }


    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getMapLength(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAP_LENGTH); 
        return _getParami64As<Int64::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getMapOffset(const SrcLoc src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAP_OFFSET);
        return _getParami64As<Int64::type, is_gl_thread>(pname, src_loc.add());
        
    }


    
    EXPORT virtual ~BufferBase(){
        static const ConstSizei one(1);
        if (auto ctx = lockCtx()){
            _addCallGl<&GladGLContext::DeleteBuffers>(SrcLoc{}, one, id());
        }
    };

protected:
    EXPORT BufferBase(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc) :
        Object(ctx, ctx->addCallCustom(src_loc, [](Context& ctx){
            unsigned int dst;
            ctx.gl.CreateBuffers(1, &dst);
            return dst;
        })){
    }

private:
    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParamiAs(const ConstEnum& pname, const SrcLoc src_loc){
        Int dst;
        _addCallGl<&GladGLContext::GetNamedBufferParameteriv, is_gl_thread>(src_loc, id(), pname, dst);
        return dst.reinterpret<T>();
    }

    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParami64As(const ConstEnum& pname, const SrcLoc src_loc){
        Int64 dst;
        _adddCallGl<&GladGLContext::GetNamedBufferParameteri64v, is_gl_thread>(src_loc, id(), pname, dst);
        return dst.reinterpret<T>();
    }
    
};

} // namespace detail

class Buffer : public detail::BufferBase, public SharedObject<Buffer> {
public:
    EXPORT static std::shared_ptr<Buffer> New(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc = SrcLoc{}){
        return std::shared_ptr<Buffer>(new Buffer(ctx, src_loc.add()));
    }

protected:
    EXPORT Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc src_loc) : 
        BufferBase(ctx, src_loc){
    }
};

} // namespace glwpp::GL