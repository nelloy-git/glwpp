#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public Object {
public:
    Program(wptr<Context> ctx, const SrcLoc& loc = SrcLoc());

    std::shared_future<bool> isLinked(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> isValidated(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc()) const;

    std::shared_future<bool> getAttributeLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> getUniformLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc = SrcLoc()) const;

    std::shared_future<bool> attach(Shader& shader, const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> link(const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> validate(const SrcLoc& loc = SrcLoc()) const;
    std::shared_future<bool> use(const SrcLoc& loc = SrcLoc()) const;

    std::shared_future<bool> setUniform1F(const Vop<gl::Int>& unif_loc,
                                          const Vop<gl::Float>& val0,
                                          const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> setUniform2F(const Vop<gl::Int>& unif_loc,
                                          const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                          const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> setUniform3F(const Vop<gl::Int>& unif_loc,
                                          const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                          const Vop<gl::Float>& val2,
                                          const SrcLoc& loc = SrcLoc());
    std::shared_future<bool> setUniform4F(const Vop<gl::Int>& unif_loc,
                                          const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                                          const Vop<gl::Float>& val2, const Vop<gl::Float>& val3,
                                          const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp