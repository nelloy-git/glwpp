#pragma once

#include "gl_object/Handler.hpp"

namespace glwpp::GL {

class Shader : public Handler<Shader> {
public:
    static Value<Shader> Make(Valuable<Context&> auto&& ctx,
                              Valuable<const GLenum&> auto&& type,
                              Valuable<const SrcLoc&> auto&& src_loc){
        return Value<Shader>::Make(new Shader(ctx, type, src_loc));
    }
    virtual ~Shader(){}

    template<TState IsCtx>
    auto source(Valuable<const std::string&> auto&& code,
                Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Shader::_source>(code, src_loc);
    }

    template<TState IsCtx>
    auto compile(Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Shader::_compile>(src_loc);
    }



    template<TState IsCtx>
    auto getParameteriv(Valuable<const GLenum&> auto&& pname,
                        Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Shader::_getParameteriv>(pname, src_loc);
    }
    
    template<TState IsCtx, typename T>
    auto getParameterivAs(Valuable<const GLenum&> auto&& pname,
                          Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Shader::_getParameterivAs<T>>(pname, src_loc);
    }

    template<TState IsCtx>
    auto getInfoLog(Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Shader::_getInfoLog>(src_loc);
    }

protected:
    Shader(Valuable<Context&> auto&& ctx,
           Valuable<const GLenum&> auto&& type,
           Valuable<const SrcLoc&> auto&& src_loc) : 
        Handler(ctx, _GetInit(GetValuable(type)), &_Free, src_loc){
    }

    EXPORT static std::function<GLuint(Context& ctx, const SrcLoc& src_loc)> _GetInit(const GLenum& type);
    EXPORT static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

    EXPORT void _source(Context& ctx, const std::string& code, const SrcLoc& src_loc); 
    EXPORT void _compile(Context& ctx, const SrcLoc& src_loc);

    EXPORT GLint _getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const;
    
    template<typename T>
    T _getParameterivAs(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
        return reinterpret_cast<T>(_getParameteriv(ctx, pname, src_loc));
    }
    std::string _getInfoLog(Context& ctx, const SrcLoc& src_loc) const;
};

} // namespace glwpp::GL