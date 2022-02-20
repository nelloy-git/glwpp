#include "glwpp/gl/oop/Shader.hpp"

#include "glwpp/gl/object/CtxShader.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxShader InitShader(const ShaderType& type, const SrcLoc& loc){
        return CtxShader(type, loc);
    }
}

Shader::Shader(wptr<Context> ctx, const Vop<gl::ShaderType>& type, const SrcLoc& loc) :
    Object(ctx, &InitShader, type, Vop<SrcLoc>(loc)){
}

std::shared_future<bool> Shader::getType(Ptr<ShaderType> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxShader, &CtxShader::getType>(dst, loc);
}

std::shared_future<bool> Shader::isCompiled(Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxShader, &CtxShader::isCompiled>(dst, loc);
}

std::shared_future<bool> Shader::getSourceLength(Ptr<Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxShader, &CtxShader::getSourceLength>(dst, loc);
}

std::shared_future<bool> Shader::getInfoLog(Ptr<std::string> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxShader, &CtxShader::getInfoLog>(dst, loc);
}


std::shared_future<bool> Shader::compile(const Vop<std::string>& code, const SrcLoc& loc){
    return _callMethod<CtxShader, &CtxShader::compile>(code, loc);
}