// #pragma once

// #include "context/CtxObj.hpp"
// #include "gl_object/Handler.hpp"

// namespace glwpp::ST {

// class BufferRef {
// public:
//     BufferRef();
//     ~BufferRef();

//     template<TState IsCtx>
//     auto setData(Valuable<const GLsizeiptr&> auto&& size,
//                  Valuable<const void*> auto&& data,
//                  Valuable<const GLenum&> auto&& usage,
//                  Valuable<const SrcLoc&> auto&& src_loc){
//         return callMember<IsCtx, &Buffer::_setData>(size, data, usage, GetValuable(src_loc).add());
//     }

//     template<TState IsCtx>
//     auto clearData(Valuable<const GLenum&> auto&& internalformat,
//                    Valuable<const GLenum&> auto&& format,
//                    Valuable<const GLenum&> auto&& type,
//                    Valuable<const void*> auto&& data,
//                    Valuable<const SrcLoc&> auto&& src_loc){
//         return callMember<IsCtx, &Buffer::_clearData>(internalformat, format, type, data, GetValuable(src_loc).add());
//     }

//     template<TState IsCtx>
//     auto setStorage(Valuable<const GLsizeiptr&> auto&& size,
//                     Valuable<const void*> auto&& data,
//                     Valuable<const GLbitfield&> auto&& flags,
//                     Valuable<const SrcLoc&> auto&& src_loc){
//         return callMember<IsCtx, &Buffer::_setStorage>(size, data, flags, GetValuable(src_loc).add());
//     }



//     // template<TState IsCtx>
//     // void setSubData(Valuable<const GLintptr&> auto&& offset,
//     //                 Valuable<const GLsizeiptr&> auto&& size,
//     //                 Valuable<const void*> auto&& data,
//     //                 Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::NamedBufferSubData>(id(), offset, size, data, GetValuable(src_loc).add());
//     // }

//     // template<TState IsCtx>
//     // void getSubData(Valuable<const GLintptr&> auto&& offset,
//     //                 Valuable<const GLsizeiptr&> auto&& size,
//     //                 Valuable<void*> auto&& data,
//     //                 Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::GetNamedBufferSubData>(id(), offset, size, data, GetValuable(src_loc).add());
//     // }

//     // template<TState IsCtx>
//     // void copySubData(Valuable<const Buffer&> auto&& readBuffer,
//     //                  Valuable<const GLintptr&> auto&& readOffset,
//     //                  Valuable<const GLintptr&> auto&& writeOffset,
//     //                  Valuable<const GLsizeiptr&> auto&& size,
//     //                  Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::CopyNamedBufferSubData>(readBuffer.id(), id(), readOffset, writeOffset, size, GetValuable(src_loc).add());
//     // }

//     // template<TState IsCtx>
//     // void clearSubData(Valuable<const GLenum&> auto&& internalformat,
//     //                   Valuable<const GLintptr&> auto&& offset,
//     //                   Valuable<const GLsizeiptr&> auto&& size,
//     //                   Valuable<const GLenum&> auto&& format,
//     //                   Valuable<const GLenum&> auto&& type,
//     //                   Valuable<const void*> auto&& data,
//     //                   Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::ClearNamedBufferSubData>(id(), internalformat, offset, size, format, type, data, GetValuable(src_loc).add());
//     // }



//     template<TState IsCtx>
//     auto bindBase(Valuable<const GLenum&> auto&& target,
//                   Valuable<const GLuint&> auto&& index,
//                   Valuable<const SrcLoc&> auto&& src_loc){
//         return callMember<IsCtx, &Buffer::_bindBase>(target, index, GetValuable(src_loc).add());
//     }

//     // template<TState IsCtx>
//     // void bindRange(Valuable<const GLenum&> auto&& target,
//     //                Valuable<const GLuint&> auto&& index,
//     //                Valuable<const GLintptr&> auto&& offset,
//     //                Valuable<const GLsizeiptr&> auto&& size,
//     //                Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::BindBufferRange>(target, index, id(), offset, size, GetValuable(src_loc).add());
//     // }


    
//     // template<TState IsCtx>
//     // void getPointerv(Valuable<const GLenum&> auto&& pname,
//     //                  Valuable<void*> auto&& params,
//     //                  Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::GetNamedBufferPointerv>(id(), pname, params, GetValuable(src_loc).add());
//     // }

//     template<TState IsCtx>
//     auto map(Valuable<const GLenum&> auto&& access,
//              Valuable<const SrcLoc&> auto&& src_loc){
//         return callMember<IsCtx, &Buffer::_map>(access, src_loc);
//     }

//     // template<TState IsCtx>
//     // Value<void*> mapRange(Valuable<const GLintptr&> auto&& offset,
//     //                       Valuable<const GLsizeiptr&> auto&& length,
//     //                       Valuable<const GLbitfield&> auto&& access,
//     //                       Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::MapNamedBufferRange>(id(), offset, length, access, GetValuable(src_loc).add());
//     // }

//     // template<TState IsCtx>
//     // Value<GLboolean> unmap(Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::UnmapNamedBuffer>(id(), GetValuable(src_loc).add());
//     // }

//     // template<TState IsCtx>
//     // void flushRange(Valuable<const GLintptr&> auto&& offset,
//     //                 Valuable<const GLsizeiptr&> auto&& length,
//     //                 Valuable<const SrcLoc&> auto&& src_loc){
//     //     return addCallGl<&GLapi::FlushMappedNamedBufferRange>(id(), offset, length, GetValuable(src_loc).add());
//     // }


    
//     template<TState IsCtx>
//     auto getParameteriv(Valuable<const GLenum&> auto&& pname,
//                         Valuable<const SrcLoc&> auto&& src_loc) const {
//         return callMember<IsCtx, &Buffer::_getParameteriv>(pname, src_loc);
//     }
    
//     template<TState IsCtx>
//     auto getParameteri64v(Valuable<const GLenum&> auto&& pname,
//                           Valuable<const SrcLoc&> auto&& src_loc) const {
//         return callMember<IsCtx, &Buffer::_getParameteri64v>(pname, src_loc);
//     }
    
//     template<TState IsCtx, typename T>
//     auto getParameterivAs(Valuable<const GLenum&> auto&& pname,
//                           Valuable<const SrcLoc&> auto&& src_loc) const {
//         return callMember<IsCtx, &Buffer::_getParameterivAs<T>>(pname, src_loc);
//     }

// private:
//     Buffer(Context& ctx, const SrcLoc& src_loc, const IsCtxTrue& IsCtx);
//     Buffer(Context& ctx, const SrcLoc& src_loc, const IsCtxFalse& IsCtx);
//     Buffer(Context& ctx, const SrcLoc& src_loc, const IsCtxUnknown& IsCtx);

//     EXPORT static GLuint _Init(Context& ctx, const SrcLoc& src_loc);
//     EXPORT static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

//     EXPORT void _setData(Context& ctx, const GLsizeiptr& size, const void* data, const GLenum& usage, const SrcLoc& src_loc);
//     EXPORT void _clearData(Context& ctx, const GLenum& internalformat, const GLenum& format, const GLenum& type, const void* data, const SrcLoc& src_loc);
//     EXPORT void _setStorage(Context& ctx, const GLsizeiptr& size, const void* data, const GLbitfield& flags, const SrcLoc& src_loc);
//     EXPORT void* _map(Context& ctx, const GLenum& access, const SrcLoc& src_loc);
//     EXPORT void _bindBase(Context& ctx, const GLenum target, const GLuint index, const SrcLoc src_loc);

//     EXPORT GLint _getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const;
//     EXPORT GLint64 _getParameteri64v(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const;
    
//     template<typename T>
//     T _getParameterivAs(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
//         return reinterpret_cast<T>(_getParameteriv(ctx, pname, src_loc));
//     }

//     // template<typename T, TState IsCtx>
//     // inline T _getParamiAs(Valuable<const GLenum&> auto&& pname,
//     //                       Valuable<const GLenum&> auto&& src_loc){
//     //     Value<GLint> dst(*this->lockCtx(), 0);
//     //     addCallGl<&GLapi::GetNamedBufferParameteriv>(id(), pname, dst, src_loc);
//     //     return dst.reinterpret<T>();
//     // }

//     // template<typename T, TState IsCtx>
//     // inline T _getParami64As(Valuable<const GLenum&> auto&& pname,
//     //                         Valuable<const GLenum&> auto&& src_loc){
//     //     Value<GLint64> dst(*this->lockCtx(), 0);
//     //     addCallGl<&GLapi::GetNamedBufferParameteri64v>(id(), pname, dst, src_loc);
//     //     return dst.reinterpret<T>();
//     // }
    
// };

// } // namespace glwpp::GL