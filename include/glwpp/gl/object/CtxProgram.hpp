#pragma once

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/object/CtxShader.hpp"

namespace glwpp::gl {

class CtxProgram : public CtxObject {
public:
    // Dummy object. Can be used for preallocation.
    CtxProgram(const Dummy&);
    CtxProgram(const SrcLoc& loc = SrcLoc());

    Int getParamI(const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    bool isLinked(const SrcLoc& loc = SrcLoc()) const;
    bool isValidated(const SrcLoc& loc = SrcLoc()) const;
    Int getAttachedShadersCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveAttributesCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveAttributeMaxNameLength(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveUniformsCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveUniformMaxNameLength(const SrcLoc& loc = SrcLoc()) const;
    std::string getInfoLog(const SrcLoc& loc = SrcLoc()) const;

    void attach(const CtxShader& shader, const SrcLoc& loc = SrcLoc());
    void link(const SrcLoc& loc = SrcLoc());
    void validate(const SrcLoc& loc = SrcLoc()) const;
    void use(const SrcLoc& loc = SrcLoc()) const;

    Int getAttributeLocation(const std::string &name, const SrcLoc& loc = SrcLoc()) const;
    Int getUniformLocation(const std::string &name, const SrcLoc& loc = SrcLoc()) const;

    void setUniform1F(const Int& unif_loc, const Float& val0, const SrcLoc& loc = SrcLoc());
    void setUniform2F(const Int& unif_loc, const Float& val0, const Float& val1, const SrcLoc& loc = SrcLoc());
    void setUniform3F(const Int& unif_loc, const Float& val0, const Float& val1, const Float& val2, const SrcLoc& loc = SrcLoc());
    void setUniform4F(const Int& unif_loc, const Float& val0, const Float& val1, const Float& val2, const Float& val3, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp::gl