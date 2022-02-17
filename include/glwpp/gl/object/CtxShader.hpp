#pragma once

#include <string>

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp::gl {

class CtxShader : public CtxObject {
public:
    CtxShader(const ShaderType& type, const SrcLoc& loc = SrcLoc::current());
    
    ShaderType getType(const SrcLoc& loc = SrcLoc::current()) const;
    bool isCompiled(const SrcLoc& loc = SrcLoc::current()) const;
    Int getSourceLength(const SrcLoc& loc = SrcLoc::current()) const;
    std::string getInfoLog(const SrcLoc& loc = SrcLoc::current()) const;

    void compile(const std::string& code, const SrcLoc& loc = SrcLoc::current());
};

} // namespace glwpp::gl