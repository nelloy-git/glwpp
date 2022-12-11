#pragma once

#include "glad/gl.h"

#include "utils/SharedObject.hpp"
#include "Context.hpp"

namespace glwpp {

namespace GL {

using Boolean = Value<GLboolean>;
using ConstBoolean = Value<const GLboolean>;
using BooleanArr = Value<GLboolean[]>;

using Enum = Value<GLenum>;
using ConstEnum = Value<const GLenum>;
using EnumArr = Value<GLenum[]>;

using Bitfield = Value<GLbitfield>;
using ConstBitfield = Value<const GLbitfield>;
using BitfieldArr = Value<GLbitfield[]>;

using Byte = Value<GLbyte>;
using ByteArr = Value<GLbyte[]>;

using Ubyte = Value<GLubyte>;
using UbyteArr = Value<GLubyte[]>;

using Short = Value<GLshort>;
using ShortArr = Value<GLshort[]>;

using Ushort = Value<GLushort>;
using UshortArr = Value<GLushort[]>;

using Int = Value<GLint>;
using ConstInt = Value<const GLint>;
using IntArr = Value<GLint[]>;

using Uint = Value<GLuint>;
using ConstUint = Value<const GLuint>;
using UintArr = Value<GLuint[]>;

using Int64 = Value<GLint64>;
using Int64Arr = Value<GLint64[]>;

using Uint64 = Value<GLuint64>;
using Uint64Arr = Value<GLuint64[]>;

using Float = Value<GLfloat>;
using FloatArr = Value<GLfloat[]>;

using Double = Value<GLdouble>;
using DoubleArr = Value<GLdouble[]>;

using Sizei = Value<GLsizei>;
using ConstSizei = Value<const GLsizei>;
using SizeiArr = Value<GLsizei[]>;

using Sizeiptr = Value<GLsizeiptr>;
using ConstSizeiptr = Value<const GLsizeiptr>;
using SizeiptrArr = Value<GLsizeiptr[]>;

using Intptr = Value<GLintptr>;
using ConstIntptr = Value<const GLintptr>;
using IntptrArr = Value<GLintptr[]>;

using String = Value<std::string>;
using ConstString = Value<const std::string>;
using StringArr = Value<std::string[]>;

using Data = Value<void>;
using ConstData = Value<const void>;
using DataPtr = Value<void*>;

using Sync = Value<__GLsync*>;

template<typename T>
class Object {
public:
    virtual ~Object() = 0;

    inline auto& getData() const {
        return _gl_data;
    }

    std::shared_ptr<Context> lockCtx(){
        return _wctx.lock();
    }

protected:
    using Deleter = std::function<void(std::weak_ptr<Context>, T*, const SrcLoc&)>;
    struct DeleterObj {
        DeleterObj(const std::shared_ptr<Context>& ctx, const Deleter& deleter, const SrcLoc& src_loc) :
            _wctx(ctx),
            _deleter(deleter){
            _src_loc = src_loc;
        }

        void operator()(T* gl_data){
            _deleter(_wctx, gl_data, _src_loc);
        }

    private:
        const Deleter _deleter;
        std::weak_ptr<Context> _wctx;
        SrcLoc _src_loc;
    };

    Object(const std::shared_ptr<Context>& ctx, T& init_gl_data, const Deleter& deleter, const SrcLoc& src_loc = SrcLoc{}) :
        _wctx(ctx),
        _p_ctx(ctx.get()),
        _ctx_thread_id(ctx->getGlThreadId()),
        _gl_data(std::shared_ptr<T>(new T(init_gl_data), 
                 DeleterObj(ctx, deleter, SrcLoc(src_loc, src_loc.file_name(), src_loc.line(), (std::string(src_loc.function_name()) + "::~GL").c_str())))){
    };
    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    auto _addCallCustom(const SrcLoc& src_loc, const auto& func, const auto&... args){
        if constexpr (is_gl_thread == Context::IsGlThread::True){
            return _addCallCustomFromGlThread(src_loc, func, args...);
        } else if constexpr (is_gl_thread == Context::IsGlThread::False){
            return _addCallCustomFromNonGlThread(src_loc, func, args...);
        } else {
            if (std::this_thread::get_id() == _ctx_thread_id){
                return _addCallCustomFromGlThread(src_loc, func, args...);
            } else {
                return _addCallCustomFromNonGlThread(src_loc, func, args...);
            }
        }
    }

    template<auto F, Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    auto _addCallGl(const SrcLoc& src_loc, const auto&... args){
        if constexpr (is_gl_thread == Context::IsGlThread::True){
            return _addCallGlFromGlThread<F>(src_loc, args...);
        } else if constexpr (is_gl_thread == Context::IsGlThread::False){
            return _addCallGlFromNonGlThread<F>(src_loc, args...);
        } else {
            if (std::this_thread::get_id() == _ctx_thread_id){
                return _addCallGlFromGlThread<F>(src_loc, args...);
            } else {
                return _addCallGlFromNonGlThread<F>(src_loc, args...);
            }
        }
    }

private:
    std::weak_ptr<Context> _wctx;
    Context* _p_ctx;
    std::thread::id _ctx_thread_id;
    const glwpp::Value<T> _gl_data;

    auto _addCallCustomFromGlThread(const SrcLoc& src_loc, const auto& func, const auto&... args){
        return _p_ctx->addCallCustom<Context::IsGlThread::True>(src_loc, func, args...);
    }

    auto _addCallCustomFromNonGlThread(const SrcLoc& src_loc, const auto& func, const auto&... args){
        if (auto ctx = _wctx.lock()){
            return ctx->addCallCustom<Context::IsGlThread::False>(src_loc, func, args...);
        }
        throw std::runtime_error("Object's context is destroyed.");
    }

    template<auto F>
    auto _addCallGlFromGlThread(const SrcLoc& src_loc, const auto&... args){
        return _p_ctx->addCallGl<F, Context::IsGlThread::True>(src_loc, args...);
    }

    template<auto F>
    auto _addCallGlFromNonGlThread(const SrcLoc& src_loc, const auto&... args){
        if (auto ctx = _wctx.lock()){
            return ctx->addCallGl<F, Context::IsGlThread::False>(src_loc, args...);
        }
        throw std::runtime_error("Object's context is destroyed.");
    }

};

template<typename T>
inline Object<T>::~Object(){
}

class ObjectHandle : public Object<GLuint> {
public:
    ObjectHandle(const std::shared_ptr<Context>& ctx, GLuint init_gl_data, const Deleter& deleter, const SrcLoc& src_loc = SrcLoc{}) :
        Object<GLuint>(ctx, init_gl_data, deleter, src_loc){
    };

    inline ConstUint id(){
        return getData();
    }

protected:
    using Object<GLuint>::getData;

};

} // namespace GL

} // namespace glwpp