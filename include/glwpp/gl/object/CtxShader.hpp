#pragma once

#include <string>

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp::gl {

class CtxShader : public CtxObject {
public:
    CtxShader(const ShaderType& type, const SrcLoc& loc = SrcLoc());
    
    Int getParamI(const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    ShaderType getType(const SrcLoc& loc = SrcLoc()) const;
    bool isCompiled(const SrcLoc& loc = SrcLoc()) const;

    Int getSourceLength(const SrcLoc& loc = SrcLoc()) const;
    std::string getInfoLog(const SrcLoc& loc = SrcLoc()) const;

    void compile(const std::string& code, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp::gl