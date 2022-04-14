#include "glwpp/gl/obj/Program.hpp"

#include "glwpp/gl/ctx_only/CtxProgram.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxProgram InitProgram(const SrcLoc& loc){
        return CtxProgram(loc);
    }
}

Program::Program(const wptr<Context>& weak_ctx, const SrcLoc& loc) :
    Object(weak_ctx, &InitProgram, Val<SrcLoc>(loc)){
}

bool Program::isLinked(Ptr<bool> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::isLinked>(dst, loc);
}

bool Program::isValidated(Ptr<bool> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::isValidated>(dst, loc);
}

bool Program::getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getAttachedShadersCount>(dst, loc);
}

bool Program::getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getActiveAttributesCount>(dst, loc);
}

bool Program::getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getActiveAttributeMaxNameLength>(dst, loc);
}

bool Program::getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getActiveUniformsCount>(dst, loc);
}

bool Program::getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getActiveUniformMaxNameLength>(dst, loc);
}

bool Program::getInfoLog(Ptr<std::string> dst, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getInfoLog>(dst, loc);
}

bool Program::getAttributeLocation(Ptr<gl::Int> dst, const Val<std::string>& name, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getAttributeLocation>(dst, name, loc);
}

bool Program::getUniformLocation(Ptr<gl::Int> dst, const Val<std::string>& name, const SrcLoc& loc) const {
    return _executeGetter<CtxProgram, &CtxProgram::getUniformLocation>(dst, name, loc);
}

bool Program::attach(Shader& shader, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::attach>(shader._getVop<CtxShader>(), loc);
}

bool Program::link(const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::link>(loc);
}

bool Program::validate(const SrcLoc& loc) const {
    return _executeMethod<CtxProgram, &CtxProgram::validate>(loc);
}

bool Program::use(const SrcLoc& loc) const {
    return _executeMethod<CtxProgram, &CtxProgram::use>(loc);
}

bool Program::setUniform1F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniform1F>(unif_loc, data, count, loc);
}

bool Program::setUniform2F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniform2F>(unif_loc, data, count, loc);
}

bool Program::setUniform3F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniform3F>(unif_loc, data, count, loc);
}

bool Program::setUniform4F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniform4F>(unif_loc, data, count, loc);
}

bool Program::setUniformMat2x2F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat2x2F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat2x3F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat2x3F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat2x4F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat2x4F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat3x2F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat3x2F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat3x3F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat3x3F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat3x4F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat3x4F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat4x2F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat4x2F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat4x3F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat4x3F>(unif_loc, data, transpose, count, loc);
}

bool Program::setUniformMat4x4F(const Val<gl::Int>& unif_loc, const Ptr<Float>& data, const Val<bool>& transpose, 
                                const Val<Sizei>& count, const SrcLoc& loc){
    return _executeMethod<CtxProgram, &CtxProgram::setUniformMat4x4F>(unif_loc, data, transpose, count, loc);
}
