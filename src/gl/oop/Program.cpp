#include "glwpp/gl/oop/Program.hpp"

#include "glwpp/gl/object/CtxProgram.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxProgram InitProgram(const SrcLoc& loc){
        return CtxProgram(loc);
    }
}

Program::Program(wptr<Context> ctx, const SrcLoc& loc) :
    Object(ctx, &InitProgram, Vop<SrcLoc>(loc)){
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

std::shared_future<bool> Program::getAttributeLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getAttributeLocation>(dst, name, loc);
}

std::shared_future<bool> Program::getUniformLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc) const {
    return _getFromMethod<CtxProgram, &CtxProgram::getUniformLocation>(dst, name, loc);
}

std::shared_future<bool> Program::attach(Shader& shader, const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::attach>(shader._getVop<CtxShader>(), loc);
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

std::shared_future<bool> Program::setUniform1F(const Vop<gl::Int> &unif_loc,
                                        const Vop<gl::Float>& val0,
                                        const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::setUniform1F>(unif_loc, val0, loc);
}

std::shared_future<bool> Program::setUniform2F(const Vop<gl::Int> &unif_loc,
                                        const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                        const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::setUniform2F>(unif_loc, val0, val1, loc);
}

std::shared_future<bool> Program::setUniform3F(const Vop<gl::Int> &unif_loc,
                                        const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                        const Vop<gl::Float>& val2,
                                        const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::setUniform3F>(unif_loc, val0, val1, val2, loc);
}

std::shared_future<bool> Program::setUniform4F(const Vop<gl::Int> &unif_loc,
                                        const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                        const Vop<gl::Float>& val2, const Vop<gl::Float>& val3,
                                        const SrcLoc& loc){
    return _callMethod<CtxProgram, &CtxProgram::setUniform4F>(unif_loc, val0, val1, val2, val3, loc);
}
