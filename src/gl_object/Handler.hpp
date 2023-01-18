#pragma once

#include "GLapi.hpp"

namespace glwpp::GL {

template<typename T>
class Handler : public CtxObj<T> {
public:
    static constexpr GLuint INVALID_ID = 0;

    using Init = std::function<GLuint(Context&, const SrcLoc&)>;
    using Free = std::function<void(Context&, const GLuint&, const SrcLoc&)>;

    Handler(Context& ctx, const Init& init, const Free& free, const SrcLoc& src_loc) :
        CtxObj<T>(ctx),
        _id(Value<GLuint>::Make(new GLuint(INVALID_ID), _GetDeleter(ctx, free, src_loc))){
        _init(init, src_loc);
    }

    inline Value<const GLuint> id() const {
        return _id;
    }

private:
    Value<GLuint> _id;

    void _init(const Init& init, const SrcLoc& src_loc){
        static constexpr auto F = [](Context& ctx, GLuint& id, const Init& init, const SrcLoc& src_loc){
            id = init(ctx, src_loc);
        };
        this->call<TState::Unknown>(F, _id, init, src_loc);
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

} // namespace glwpp