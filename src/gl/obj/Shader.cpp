#include "glwpp/gl/obj/Shader.hpp"

#include "glwpp/gl/ctx_only/CtxShader.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxShader InitShader(const ShaderType& type, const SrcLoc& loc){
        return CtxShader(type, loc);
    }
}

Shader::Shader(const std::weak_ptr<Context>& weak_ctx, const Val<gl::ShaderType>& type, const SrcLoc& loc) :
    Object(weak_ctx, &InitShader, type, Val<SrcLoc>(loc)){
}

bool Shader::getType(Ptr<ShaderType> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxShader, &CtxShader::getType>(dst, loc);
}

bool Shader::isCompiled(Ptr<bool> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxShader, &CtxShader::isCompiled>(dst, loc);
}

bool Shader::getSourceLength(Ptr<Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxShader, &CtxShader::getSourceLength>(dst, loc);
}

bool Shader::getInfoLog(Ptr<std::string> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxShader, &CtxShader::getInfoLog>(dst, loc);
}

bool Shader::compile(const Val<std::string>& code, const SrcLoc& loc){
    return _executeMethod<CtxShader, &CtxShader::compile>(code, loc);
}