#pragma once

#include "glad/gl.h"

#include "gl_object/ObjectHandle.hpp"

namespace glwpp::GL {

class Buffer : public ObjectHandle {
public:
    EXPORT Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{}) :
        ObjectHandle(ctx, 0, &Buffer::_free, src_loc.add()){
        addCallGl<&GLapi::CreateBuffers>(1, data(), src_loc.add());
    }
    EXPORT virtual ~Buffer(){}



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setData(const ConstSizeiptr& size, const ConstData& data, const ConstEnum& usage, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::NamedBufferData, is_gl_thread>(id(), size, data, usage, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void clearData(const ConstEnum& internalformat, const ConstEnum& format, const ConstEnum& type, const ConstData& data, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::ClearNamedBufferData, is_gl_thread>(id(), internalformat, format, type, data, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setStorage(const ConstSizeiptr& size, const ConstData& data, const ConstBitfield& flags, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::NamedBufferStorage, is_gl_thread>(id(), size, data, flags, src_loc.add());
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setSubData(const ConstIntptr& offset, const ConstSizeiptr& size, const ConstData& data, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::NamedBufferSubData, is_gl_thread>(id(), offset, size, data, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void getSubData(const ConstIntptr& offset, const ConstSizeiptr& size, const Data& data, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::GetNamedBufferSubData, is_gl_thread>(id(), offset, size, data, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void copySubData(const Buffer& readBuffer, const ConstIntptr& readOffset, const ConstIntptr& writeOffset, const ConstSizeiptr& size, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::CopyNamedBufferSubData, is_gl_thread>(readBuffer.id(), id(), readOffset, writeOffset, size, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void clearSubData(const ConstEnum& internalformat, const ConstIntptr& offset, const ConstSizeiptr& size, const ConstEnum& format, const ConstEnum& type, const ConstData& data, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::ClearNamedBufferSubData, is_gl_thread>(id(), internalformat, offset, size, format, type, data, src_loc.add());
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void bindBase(const ConstEnum& target, const ConstUint& index, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::BindBuffer, is_gl_thread>(target, index, id(), src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void bindRange(const ConstEnum& target, const ConstUint& index, const ConstIntptr& offset, const ConstSizeiptr& size, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::BindBufferRange, is_gl_thread>(target, index, id(), offset, size, src_loc.add());
    }


    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void getPointerv(const ConstEnum& pname, const DataPtr& params, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::GetNamedBufferPointerv, is_gl_thread>(id(), pname, params, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT DataPtr map(const ConstEnum& access, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::MapNamedBuffer, is_gl_thread>(id(), access, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT DataPtr mapRange(const ConstIntptr& offset, const ConstSizeiptr& length, const ConstBitfield& access, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::MapNamedBufferRange, is_gl_thread>(id(), offset, length, access, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean unmap(const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::UnmapNamedBuffer, is_gl_thread>(id(), src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void flushRange(const ConstIntptr& offset, const ConstSizeiptr& length, const SrcLoc& src_loc = SrcLoc{}){
        return addCallGl<&GLapi::FlushMappedNamedBufferRange, is_gl_thread>(id(), offset, length, src_loc.add());
    }



    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getMapAccess(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_ACCESS);
        return _getParamiAs<Enum::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Bitfield getMapRangeAccess(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_ACCESS_FLAGS);
        return _getParamiAs<Bitfield::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isImmutableStorage(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_IMMUTABLE_STORAGE);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Boolean isMapped(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAPPED);
        return _getParamiAs<Boolean::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int getSize(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_SIZE);
        return _getParamiAs<Int::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Bitfield getStorageFlags(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_STORAGE_FLAGS);
        return _getParamiAs<Bitfield::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Enum getUsage(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_USAGE);
        return _getParamiAs<Enum::type, is_gl_thread>(pname, src_loc.add());
    }


    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getMapLength(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAP_LENGTH); 
        return _getParami64As<Int64::type, is_gl_thread>(pname, src_loc.add());
    }
    
    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Int64 getMapOffset(const SrcLoc& src_loc = SrcLoc{}){
        static const ConstEnum pname(GL_BUFFER_MAP_OFFSET);
        return _getParami64As<Int64::type, is_gl_thread>(pname, src_loc.add());
        
    }

private:
    static void _free(std::weak_ptr<Context> wctx, const GLuint* id_ptr, const SrcLoc& src_loc){
        static constexpr auto F = [](Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
            ctx.gl.DeleteBuffers(1, id_ptr, src_loc);
            delete id_ptr;
        };

        if (auto ctx = wctx.lock()){
            ctx->addCallGl<F>(id_ptr, src_loc);
        } else {
            delete id_ptr;
        }
    }

    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParamiAs(const ConstEnum& pname, const SrcLoc& src_loc){
        Int dst;
        addCallGl<&GLapi::GetNamedBufferParameteriv, is_gl_thread>(id(), pname, dst, src_loc);
        return dst.reinterpret<T>();
    }

    template<typename T, Context::IsGlThread is_gl_thread>
    inline T _getParami64As(const ConstEnum& pname, const SrcLoc& src_loc){
        Int64 dst;
        addCallGl<&GLapi::GetNamedBufferParameteri64v, is_gl_thread>(id(), pname, dst, src_loc);
        return dst.reinterpret<T>();
    }
    
};

} // namespace glwpp::GL