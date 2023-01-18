#pragma once

#include "gl_object/Shader.hpp"

namespace glwpp::GL {

class Program : public Handler<Program> {
public:
    static Value<Program> Make(Valuable<Context&> auto&& ctx,
                               Valuable<const SrcLoc&> auto&& src_loc){
        return Value<Program>::Make(new Program(ctx, src_loc));
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



    // template<TState IsCtx>
    // Int getAttribLocation(const ConstString& name){
    //     return _addCallCustom<IsCtx>([](Context& ctx, const ConstUint& id, const ConstString& name){
    //         return ctx.gl().GetAttribLocation(id, name->c_str());
    //     }, id(), name);
    // }
    
    // template<TState IsCtx>
    // void bindAttribLocation(const ConstUint& attr_index, const ConstString& name){
    //     return _addCallCustom<IsCtx>([](Context& ctx, const ConstUint& id, const ConstUint& attr_index, const ConstString& name){
    //         return ctx.gl().BindAttribLocation(id, attr_index, name->c_str());
    //     }, id(), attr_index, name);
    // }
    
    // template<TState IsCtx>
    // Int getUniformLocation(const ConstString& name){
    //     return _addCallCustom<IsCtx>([](Context& ctx, const ConstUint& id, const ConstString& name){
    //         return ctx.gl().GetUniformLocation(id, name->c_str());
    //     }, id(), name);
    // }
    
    // template<TState IsCtx>
    // Value<std::future<GLuint>> getUniformBlockIndex(Valuable<const std::string&> auto&& name,
    //                                                 Valuable<const SrcLoc&> auto&& src_loc){
    //     return call<[](Context& ctx, const GLuint& program, const std::string& name, const SrcLoc& src_loc){
    //         return ctx.gl().GetUniformBlockIndex(program, name.c_str(), src_loc);
    //     }, IsCtx>(id(), name, src_loc);
    // }
    
    // template<TState IsCtx>
    // auto setUniformBlockBinding(Valuable<const GLuint&> auto&& block_index,
    //                                                 Valuable<const GLuint&> auto&& block_binding,
    //                                                 Valuable<const SrcLoc&> auto&& src_loc){
    //     return callGLapi<&GLapi::UniformBlockBinding, IsCtx>(id(), block_index, block_binding, GetValuable(src_loc).add());
    // }




    // template<TState IsCtx>
    // Value<std::future<GLboolean>> isLinked(Valuable<const SrcLoc&> auto&& src_loc){
    //     return _getParamiAs<GLboolean, GLapi::GL_LINK_STATUS, IsCtx>(GetValuable(src_loc).add());
    // }

    // template<TState IsCtx>
    // Boolean isValidated(){
    //     static const ConstEnum pname(GLapi::GL_VALIDATE_STATUS);
    //     return _getParamiAs<Boolean::type, IsCtx>(pname);
    // }

    // template<TState IsCtx>
    // Value<std::future<GLint>> getAttachedShadersCount(Valuable<const SrcLoc&> auto&& src_loc){
    //     return _getParamiAs<GLint, GLapi::GL_ATTACHED_SHADERS, IsCtx>(GetValuable(src_loc).add());
    // }

    // template<TState IsCtx>
    // Int getActiveAttributesCount(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_ATTRIBUTES);
    //     return _getParamiAs<Int::type, IsCtx>(pname);
    // }

    // template<TState IsCtx>
    // Int getActiveAttributeMaxNameLength(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
    //     return _getParamiAs<Int::type, IsCtx>(pname);
    // }

    // template<TState IsCtx>
    // Int getActiveUniformsCount(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_UNIFORMS);
    //     return _getParamiAs<Int::type, IsCtx>(pname);
    // }

    // template<TState IsCtx>
    // Int getActiveUniformMaxNameLength(){
    //     static const ConstEnum pname(GLapi::GL_ACTIVE_UNIFORM_MAX_LENGTH);
    //     return _getParamiAs<Int::type, IsCtx>(pname);
    // }



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
    Program(Valuable<Context&> auto&& ctx,
            Valuable<const SrcLoc&> auto&& src_loc) : 
        Handler<Program>(ctx, &_Init, &_Free, src_loc){
    }

    EXPORT static GLuint _Init(Context& ctx, const SrcLoc& src_loc);
    EXPORT static void _Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc);

    EXPORT void _attach(Context& ctx, const Shader& shader, const SrcLoc& src_loc);
    EXPORT void _link(Context& ctx, const SrcLoc& src_loc);
    EXPORT void _validate(Context& ctx, const SrcLoc& src_loc) const;
    EXPORT void _use(Context& ctx, const SrcLoc& src_loc) const;

    EXPORT GLint _getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const;
    
    template<typename T>
    T _getParameterivAs(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
        return reinterpret_cast<T>(_getParameteriv(ctx, pname, src_loc));
    }
    std::string _getInfoLog(Context& ctx, const SrcLoc& src_loc) const;
};

} // namespace glwpp::GL