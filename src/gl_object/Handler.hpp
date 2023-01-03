#pragma once

#include "gl_object/ObjectRef.hpp"

namespace glwpp::GL {

class Handler : public ObjectRef<GLuint> {
public:
    template<auto D>
    static void DELETER(std::weak_ptr<Context> wctx, GLuint* id_ptr, const SrcLoc& src_loc){
        if (auto ctx = wctx.lock()){
            ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT, [id = *id_ptr, src_loc](Context& ctx, const Context::ms&){
                D(ctx, id, src_loc);
                return false;
            });
        }
        delete id_ptr;
    };

    Handler(Context& ctx, GLuint* init_gl_data, const DelFunc& deleter, const SrcLoc& src_loc = SrcLoc{}) :
        ObjectRef(ctx, init_gl_data, deleter, src_loc){
    };

    inline Value<const GLuint> id() const {
        return data;
    }

protected:
    using ObjectRef<GLuint>::data;

};

} // namespace glwpp