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
    static void DEFAULT_DELETER(std::weak_ptr<Context> wctx, T* data, const SrcLoc& src_loc){
        static constexpr auto F = [](Context& ctx, T* data, const SrcLoc& src_loc){
            delete data;
        };

        if (auto ctx = wctx.lock()){
            ctx->addCallGl<F>(data, src_loc);
        } else {
            delete data;
        }
    };

    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;
    virtual ~Object() = 0;

    inline Value<T>& data(){
        return _gl_data;
    }

    inline const Value<T>& data() const {
        return _gl_data;
    }

    std::shared_ptr<Context> lockCtx(){
        return _wctx.lock();
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    inline auto addCallCustom(auto&& func, auto&&... args) const {
        if constexpr (is_gl_thread == Context::IsGlThread::True){
            return _addCallCustomFromGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
        } else if constexpr (is_gl_thread == Context::IsGlThread::False){
            return _addCallCustomFromNonGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
        } else {
            if (std::this_thread::get_id() == _ctx_thread_id){
                return _addCallCustomFromGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
            } else {
                return _addCallCustomFromNonGlThread(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
            }
        }
    }

    template<auto F, Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    inline auto addCallGl(auto&&... args) const {
        if constexpr (is_gl_thread == Context::IsGlThread::True){
            return _addCallGlFromGlThread<F>(std::forward<decltype(args)>(args)...);
        } else if constexpr (is_gl_thread == Context::IsGlThread::False){
            return _addCallGlFromNonGlThread<F>(std::forward<decltype(args)>(args)...);
        } else {
            if (std::this_thread::get_id() == _ctx_thread_id){
                return _addCallGlFromGlThread<F>(std::forward<decltype(args)>(args)...);
            } else {
                return _addCallGlFromNonGlThread<F>(std::forward<decltype(args)>(args)...);
            }
        }
    }

protected:
    using Deleter = std::function<void(std::weak_ptr<Context>, T*, const SrcLoc&)>;
    struct DeleterObj {
        DeleterObj(const std::shared_ptr<Context>& ctx, const Deleter& deleter, const SrcLoc& src_loc) :
            _wctx(ctx),
            _deleter(deleter),
            _src_loc(SrcLoc(src_loc, src_loc.file_name(), src_loc.line(), (std::string(src_loc.function_name()) + "::~GL").c_str())){
        }

        void operator()(T* gl_data){
            _deleter(_wctx, gl_data, _src_loc);
        }

    private:
        const Deleter _deleter;
        std::weak_ptr<Context> _wctx;
        SrcLoc _src_loc;
    };

    Object(const std::shared_ptr<Context>& ctx, const T& init_gl_data, const Deleter& deleter, const SrcLoc& src_loc = SrcLoc{}) :
        _wctx(ctx),
        _p_ctx(ctx.get()),
        _ctx_thread_id(ctx->getGlThreadId()),
        _gl_data(init_gl_data, DeleterObj(ctx, deleter, src_loc)){
    };

private:
    std::weak_ptr<Context> _wctx;
    Context* _p_ctx;
    std::thread::id _ctx_thread_id;
    Value<T> _gl_data;

    inline auto _addCallCustomFromGlThread(auto&& func, auto&&... args) const {
        return _p_ctx->addCallCustom<Context::IsGlThread::True>(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
    }

    inline auto _addCallCustomFromNonGlThread(auto&& func, auto&&... args) const {
        if (auto ctx = _wctx.lock()){
            return ctx->addCallCustom<Context::IsGlThread::False>(std::forward<decltype(func)>(func), std::forward<decltype(args)>(args)...);
        }
        throw std::runtime_error("Object's context is destroyed.");
    }

    template<auto F>
    inline auto _addCallGlFromGlThread(auto&&... args) const {
        return _p_ctx->addCallGl<F, Context::IsGlThread::True>(std::forward<decltype(args)>(args)...);
    }

    template<auto F>
    inline auto _addCallGlFromNonGlThread(auto&&... args) const {
        if (auto ctx = _wctx.lock()){
            return ctx->addCallGl<F, Context::IsGlThread::False>(std::forward<decltype(args)>(args)...);
        }
        throw std::runtime_error("Object's context is destroyed.");
    }

};

template<typename T>
inline Object<T>::~Object(){
}

} // namespace GL

} // namespace glwpp