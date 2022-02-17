#include "glwpp/gl/oop/Program.hpp"

#include "glwpp/gl/object/CtxProgram.hpp"

using namespace glwpp;
using namespace glwpp::gl;

Program::Program(wptr<Context> ctx, const SrcLoc& loc) :
    Object(ctx, &make_sptr<gl::CtxProgram, const SrcLoc&>, Vop<SrcLoc>(loc)){
}

std::shared_future<bool> Program::isLinked(Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::isLinked>(dst, loc);
}

std::shared_future<bool> Program::isValidated(Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::isValidated>(dst, loc);
}

std::shared_future<bool> Program::getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getAttachedShadersCount>(dst, loc);
}

std::shared_future<bool> Program::getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getActiveAttributesCount>(dst, loc);
}

std::shared_future<bool> Program::getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getActiveAttributeMaxNameLength>(dst, loc);
}

std::shared_future<bool> Program::getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getActiveUniformsCount>(dst, loc);
}

std::shared_future<bool> Program::getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getActiveUniformMaxNameLength>(dst, loc);
}

std::shared_future<bool> Program::getInfoLog(Ptr<std::string> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getInfoLog>(dst, loc);
}

std::shared_future<bool> Program::getAttributeLocation(Ptr<gl::Int> dst, const Vop<std::string> name, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getAttributeLocation>(dst, name, loc);
}

std::shared_future<bool> Program::getUniformLocation(Ptr<gl::Int> dst, const Vop<std::string> name, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getUniformLocation>(dst, name, loc);
}

std::shared_future<bool> Program::attach(const Vop<Shader> shader, const SrcLoc& loc){
    static auto func = [](sptr<CtxProgram>* gl, const sptr<const CtxShader>* shader, const SrcLoc& loc){
        auto raw_prog = gl->get();
        auto raw_shader = shader->get();
        raw_prog->attach(*raw_shader, loc);
    };
    return _execute(func, _getPtr<CtxProgram>(), getVopRef(shader)._getPtr<CtxShader>(), loc);
}

std::shared_future<bool> Program::link(const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::link>(loc);
}

std::shared_future<bool> Program::validate(const SrcLoc& loc) const {
    return _callMethod<CtxProgram, &CtxProgram::validate>(loc);
}

std::shared_future<bool> Program::use(const SrcLoc& loc) const {
    return _callMethod<CtxProgram, &CtxProgram::use>(loc);
}

