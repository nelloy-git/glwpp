#pragma once

#include "gl_object/ObjectRef.hpp"

namespace glwpp::GL {

class Handler : public ObjectRef<GLuint> {
public:
    static constexpr GLuint INVALID_ID = 0;

    template<auto _Clean, int _Prio = Context::PRIORITY_MIN>
    static constexpr auto GetDeleter(){
        return [](std::weak_ptr<Context> wctx, GLuint* ptr, const SrcLoc& src_loc){
            if (auto ctx = wctx.lock()){
                ctx->event_on_run_gl.add(_Prio, [id = *ptr, src_loc](Context& ctx, const Context::ms&){
                    _Clean(ctx, id, src_loc);
                    return false;
                });
            }
            delete ptr;
        };
    };

    static auto GetDeleter(const std::function<void(Context&, const GLuint&, const SrcLoc&)>& clean){
        return [clean](std::weak_ptr<Context> wctx, GLuint* ptr, const SrcLoc& src_loc){
            if (auto ctx = wctx.lock()){
                ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT, [clean, id = *ptr, src_loc](Context& ctx, const Context::ms&){
                    clean(ctx, id, src_loc);
                    return false;
                });
            }
            delete ptr;
        };
    };

    Handler(Context& ctx, const std::function<void(Context&, const GLuint&, const SrcLoc&)> clean, const SrcLoc& src_loc) :
        ObjectRef(ctx, new GLuint(INVALID_ID), GetDeleter(clean), src_loc){
    }

    Handler(Context& ctx, const std::function<void(std::weak_ptr<Context> wctx, GLuint*, const SrcLoc&)> deleter, const SrcLoc& src_loc) :
        ObjectRef(ctx, new GLuint(INVALID_ID), deleter, src_loc){
    }

    inline Value<const GLuint> id() const {
        return data;
    }

protected:
    using ObjectRef<GLuint>::data;

};

} // namespace glwpp