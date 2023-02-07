#pragma once

#include "GLapi.hpp"

namespace glwpp::GL {

template<typename T>
class Handler : public CtxObj<T> {
public:
    static constexpr GLuint INVALID_ID = 0;

    using IsCtxTrue = CtxObj<T>::IsCtxTrue;
    using IsCtxFalse = CtxObj<T>::IsCtxFalse;
    using IsCtxUnknown = CtxObj<T>::IsCtxUnknown;
    template<TState IsCtx>
    using IsCtxFlag = typename CtxObj<T>::IsCtxFlag<IsCtx>;

    using Init = std::function<GLuint(Context&, const SrcLoc&)>;
    using Free = std::function<void(Context&, const GLuint&, const SrcLoc&)>;

    virtual ~Handler() = 0;

    inline Value<const GLuint> id() const {
        return _id;
    }

protected:
    Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxTrue&);
    Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxFalse&);
    Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxUnknown& = IsCtxUnknown{});

private:
    Value<GLuint> _id;

    template<TState IsCtx>
    void _init(const Init& init, const SrcLoc& src_loc){
        static constexpr auto F = [](Context& ctx, GLuint& id, const Init& init, const SrcLoc& src_loc){
            id = init(ctx, src_loc);
        };
        this->template call<IsCtx>(F, _id, init, src_loc);
    }

    static constexpr auto _GetDeleter(Context& ctx, const Free& free, const SrcLoc& src_loc){
        return [wctx = ctx.weak_from_this(), free, src_loc](GLuint* ptr){
            if (auto ctx = wctx.lock()){
                ctx->event_on_run_gl.add(Context::PRIORITY_MIN, [free, id = *ptr, src_loc](Context& ctx, const Context::time&){
                    free(ctx, id, src_loc);
                    return false;
                });
            }
            delete ptr;
        };
    };
};

template<typename T>
inline Handler<T>::Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxTrue&) :
    CtxObj<T>(ctx),
    _id(Value<GLuint>::Make(new GLuint(INVALID_ID), _GetDeleter(ctx, free, src_loc))){
    _init<TState::True>(init, src_loc);
}

template<typename T>
inline Handler<T>::Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxFalse&) :
    CtxObj<T>(ctx),
    _id(Value<GLuint>::Make(new GLuint(INVALID_ID), _GetDeleter(ctx, free, src_loc))){
    _init<TState::False>(init, src_loc);
}

template<typename T>
inline Handler<T>::Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc, const IsCtxUnknown&) :
    CtxObj<T>(ctx),
    _id(Value<GLuint>::Make(new GLuint(INVALID_ID), _GetDeleter(ctx, free, src_loc))){
    _init<TState::Unknown>(init, src_loc);
}

template<typename T>
inline Handler<T>::~Handler(){
}

} // namespace glwpp