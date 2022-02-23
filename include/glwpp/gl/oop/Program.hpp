#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public Object {
public:
    Program(const wptr<Context>& weak_ctx, const SrcLoc& loc = SrcLoc());

    bool isLinked(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    bool isValidated(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc()) const;

    bool getAttributeLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc = SrcLoc()) const;
    bool getUniformLocation(Ptr<gl::Int> dst, const Vop<std::string>& name, const SrcLoc& loc = SrcLoc()) const;

    bool attach(Shader& shader, const SrcLoc& loc = SrcLoc());
    bool link(const SrcLoc& loc = SrcLoc());
    bool validate(const SrcLoc& loc = SrcLoc()) const;
    bool use(const SrcLoc& loc = SrcLoc()) const;

    bool setUniform1F(const Vop<gl::Int>& unif_loc,
                      const Vop<gl::Float>& val0,
                      const SrcLoc& loc = SrcLoc());
    bool setUniform2F(const Vop<gl::Int>& unif_loc,
                      const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                      const SrcLoc& loc = SrcLoc());
    bool setUniform3F(const Vop<gl::Int>& unif_loc,
                      const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                      const Vop<gl::Float>& val2,
                      const SrcLoc& loc = SrcLoc());
    bool setUniform4F(const Vop<gl::Int>& unif_loc,
                      const Vop<gl::Float>& val0, const Vop<gl::Float>& val1,
                      const Vop<gl::Float>& val2, const Vop<gl::Float>& val3,
                      const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp