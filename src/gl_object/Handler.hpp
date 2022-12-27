#pragma once

#include "gl_object/ObjectRef.hpp"

namespace glwpp::GL {

class Handler : public ObjectRef<GLuint> {
public:
    template<auto D>
    static void DELETER(std::weak_ptr<Context> wctx, GLuint* id_ptr, const SrcLoc& src_loc){
        if (auto ctx = wctx.lock()){
            static constexpr auto F = [](Context& ctx, const GLuint* id_ptr, const SrcLoc& src_loc){
                D(ctx, id_ptr, src_loc);
                delete id_ptr;
            };
            ctx->on_run_gl.add([id_ptr, src_loc](Context& ctx, const Context::ms&){
                F(ctx, id_ptr, src_loc);
                return false;
            });
        } else {
            delete id_ptr;
        }
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