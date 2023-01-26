#pragma once

#include "gl_object/Shader.hpp"

namespace glwpp::GL {

class Program : public Handler<Program> {
public:
    template<TState IsCtx = TState::Unknown>
    static Value<Program> Make(Valuable<Context&> auto&& ctx,
                               Valuable<const SrcLoc&> auto&& src_loc){
        return Value<Program>::Make(new Program(GetValuable(ctx), GetValuable(src_loc), IsCtxFlag<IsCtx>{}));
    }
    virtual ~Program(){}

    template<TState IsCtx>
    auto attach(Valuable<const Shader&> auto&& shader,
                Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_attach>(shader, src_loc);
    }
    
    template<TState IsCtx>
    auto link(Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_link>(src_loc);
    }
    
    template<TState IsCtx>
    auto validate(Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_validate>(src_loc);
    }
    
    template<TState IsCtx>
    auto use(Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_use>(src_loc);
    }



    template<TState IsCtx>
    void setUniform1d(Valuable<const GLint&> auto&& location, Valuable<const GLdouble&> auto&& v0, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1d>(location, v0, src_loc);
    }

    template<TState IsCtx>
    void setUniform1dv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLdouble*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1dv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform2d(Valuable<const GLint&> auto&& location, Valuable<const GLdouble&> auto&& v0, Valuable<const GLdouble&> auto&& v1, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2d>(location, v0, v1, src_loc);
    }

    template<TState IsCtx>
    void setUniform2dv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLdouble*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2dv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform3d(Valuable<const GLint&> auto&& location, Valuable<const GLdouble&> auto&& v0, Valuable<const GLdouble&> auto&& v1, Valuable<const GLdouble&> auto&& v2, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3d>(location, v0, v1, v2, src_loc);
    }

    template<TState IsCtx>
    void setUniform3dv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLdouble*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3dv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform4d(Valuable<const GLint&> auto&& location, Valuable<const GLdouble&> auto&& v0, Valuable<const GLdouble&> auto&& v1, Valuable<const GLdouble&> auto&& v2, Valuable<const GLdouble&> auto&& v3, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4d>(location, v0, v1, v2, v3, src_loc);
    }

    template<TState IsCtx>
    void setUniform4dv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLdouble*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4dv>(location, count, arr, src_loc);
    }


    template<TState IsCtx>
    void setUniform1f(Valuable<const GLint&> auto&& location, const GLfloat& v0, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1f>(location, v0, src_loc);
    }

    template<TState IsCtx>
    void setUniform1fv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLfloat*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1fv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform2f(Valuable<const GLint&> auto&& location, const GLfloat& v0, const GLfloat& v1, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2f>(location, v0, v1, src_loc);
    }

    template<TState IsCtx>
    void setUniform2fv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLfloat*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2fv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform3f(Valuable<const GLint&> auto&& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3f>(location, v0, v1, v2, src_loc);
    }

    template<TState IsCtx>
    void setUniform3fv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLfloat*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3fv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform4f(Valuable<const GLint&> auto&& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4f>(location, v0, v1, v2, v3, src_loc);
    }

    template<TState IsCtx>
    void setUniform4fv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLfloat*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4fv>(location, count, arr, src_loc);
    }


    template<TState IsCtx>
    void setUniform1i(Valuable<const GLint&> auto&& location, const GLint& v0, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1i>(location, v0, src_loc);
    }

    template<TState IsCtx>
    void setUniform1iv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1iv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform2i(Valuable<const GLint&> auto&& location, const GLint& v0, const GLint& v1, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2i>(location, v0, v1, src_loc);
    }

    template<TState IsCtx>
    void setUniform2iv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2iv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform3i(Valuable<const GLint&> auto&& location, const GLint& v0, const GLint& v1, const GLint& v2, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3i>(location, v0, v1, v2, src_loc);
    }

    template<TState IsCtx>
    void setUniform3iv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3iv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform4i(Valuable<const GLint&> auto&& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4i>(location, v0, v1, v2, v3, src_loc);
    }

    template<TState IsCtx>
    void setUniform4iv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4iv>(location, count, arr, src_loc);
    }


    template<TState IsCtx>
    void setUniform1ui(Valuable<const GLint&> auto&& location, const GLuint& v0, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1ui>(location, v0, src_loc);
    }

    template<TState IsCtx>
    void setUniform1uiv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLuint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform1uiv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform2ui(Valuable<const GLint&> auto&& location, const GLuint& v0, const GLuint& v1, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2ui>(location, v0, v1, src_loc);
    }

    template<TState IsCtx>
    void setUniform2uiv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLuint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform2uiv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform3ui(Valuable<const GLint&> auto&& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3ui>(location, v0, v1, v2, src_loc);
    }

    template<TState IsCtx>
    void setUniform3uiv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLuint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform3uiv>(location, count, arr, src_loc);
    }

    template<TState IsCtx>
    void setUniform4ui(Valuable<const GLint&> auto&& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4ui>(location, v0, v1, v2, v3, src_loc);
    }

    template<TState IsCtx>
    void setUniform4uiv(Valuable<const GLint&> auto&& location, Valuable<const GLuint&> auto&& count, Valuable<const GLuint*> auto&& arr, Valuable<const SrcLoc&> auto&& src_loc){
        return callMember<IsCtx, &Program::_setUniform4uiv>(location, count, arr, src_loc);
    }



    template<TState IsCtx>
    auto getParameteriv(Valuable<const GLenum&> auto&& pname,
                        Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Program::_getParameteriv>(pname, src_loc);
    }
    
    template<TState IsCtx, typename T>
    auto getParameterivAs(Valuable<const GLenum&> auto&& pname,
                          Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Program::_getParameterivAs<T>>(pname, src_loc);
    }

    template<TState IsCtx>
    auto getInfoLog(Valuable<const SrcLoc&> auto&& src_loc) const {
        return callMember<IsCtx, &Program::_getInfoLog>(src_loc);
    }

protected:
    Program(Context& ctx, const SrcLoc& src_loc, const IsCtxTrue& IsCtx);
    Program(Context& ctx, const SrcLoc& src_loc, const IsCtxFalse& IsCtx);
    Program(Context& ctx, const SrcLoc& src_loc, const IsCtxUnknown& IsCtx);

    EXPORT static GLuint _Init(Context& ctx, const SrcLoc& src_loc);
    EXPORT static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

    EXPORT void _attach(Context& ctx, const Shader& shader, const SrcLoc& src_loc);
    EXPORT void _link(Context& ctx, const SrcLoc& src_loc);
    EXPORT void _validate(Context& ctx, const SrcLoc& src_loc) const;
    EXPORT void _use(Context& ctx, const SrcLoc& src_loc) const;

    EXPORT void _setUniform1d(Context& ctx, const GLint& location, const GLdouble& v0, const SrcLoc& src_loc);
    EXPORT void _setUniform1dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform2d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const SrcLoc& src_loc);
    EXPORT void _setUniform2dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform3d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const SrcLoc& src_loc);
    EXPORT void _setUniform3dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform4d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const GLdouble& v3, const SrcLoc& src_loc);
    EXPORT void _setUniform4dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc);

    EXPORT void _setUniform1f(Context& ctx, const GLint& location, const GLfloat& v0, const SrcLoc& src_loc);
    EXPORT void _setUniform1fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform2f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc);
    EXPORT void _setUniform2fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform3f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc);
    EXPORT void _setUniform3fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform4f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc);
    EXPORT void _setUniform4fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc);

    EXPORT void _setUniform1i(Context& ctx, const GLint& location, const GLint& v0, const SrcLoc& src_loc);
    EXPORT void _setUniform1iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform2i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc);
    EXPORT void _setUniform2iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform3i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc);
    EXPORT void _setUniform3iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform4i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc);
    EXPORT void _setUniform4iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc);

    EXPORT void _setUniform1ui(Context& ctx, const GLint& location, const GLuint& v0, const SrcLoc& src_loc);
    EXPORT void _setUniform1uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform2ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc);
    EXPORT void _setUniform2uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform3ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc);
    EXPORT void _setUniform3uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc);
    EXPORT void _setUniform4ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc);
    EXPORT void _setUniform4uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc);

    EXPORT GLint _getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const;

    template<typename T>
    T _getParameterivAs(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
        return reinterpret_cast<T>(_getParameteriv(ctx, pname, src_loc));
    }
    std::string _getInfoLog(Context& ctx, const SrcLoc& src_loc) const;
};

} // namespace glwpp::GL