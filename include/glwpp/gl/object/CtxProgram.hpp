#pragma once

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/object/CtxShader.hpp"

namespace glwpp::gl {

class CtxProgram : public CtxObject {
public:
    CtxProgram(const SrcLoc& loc = SrcLoc::current());

    bool isLinked(const SrcLoc& loc = SrcLoc::current()) const;
    bool isValidated(const SrcLoc& loc = SrcLoc::current()) const;
    Int getAttachedShadersCount(const SrcLoc& loc = SrcLoc::current()) const;
    Int getActiveAttributesCount(const SrcLoc& loc = SrcLoc::current()) const;
    Int getActiveAttributeMaxNameLength(const SrcLoc& loc = SrcLoc::current()) const;
    Int getActiveUniformsCount(const SrcLoc& loc = SrcLoc::current()) const;
    Int getActiveUniformMaxNameLength(const SrcLoc& loc = SrcLoc::current()) const;
    std::string getInfoLog(const SrcLoc& loc = SrcLoc::current()) const;

    void attach(const CtxShader& shader, const SrcLoc& loc = SrcLoc::current());
    void link(const SrcLoc& loc = SrcLoc::current());
    void validate(const SrcLoc& loc = SrcLoc::current()) const;
    void use(const SrcLoc& loc = SrcLoc::current()) const;

    Int getAttributeLocation(const std::string &name, const SrcLoc& loc = SrcLoc::current()) const;
    Int getUniformLocation(const std::string &name, const SrcLoc& loc = SrcLoc::current()) const;

    void setUniform1F(const Int& unif_loc, const float& val0, const SrcLoc& loc = SrcLoc::current());
    void setUniform2F(const Int& unif_loc, const float& val0, const float& val1, const SrcLoc& loc = SrcLoc::current());
    void setUniform3F(const Int& unif_loc, const float& val0, const float& val1, const float& val2, const SrcLoc& loc = SrcLoc::current());
    void setUniform4F(const Int& unif_loc, const float& val0, const float& val1, const float& val2, const float& val3, const SrcLoc& loc = SrcLoc::current());
};

} // namespace glwpp::gl