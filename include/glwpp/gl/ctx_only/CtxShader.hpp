#pragma once

#include <string>

#include "glwpp/gl/ctx_only/CtxObject.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp::gl {

class CtxShader : public CtxObject {
    static UInt _createGlShader(const ShaderType& type, const SrcLoc loc);
    static void _deleteGlShader(const UInt& id);

public:
    // Empty CtxShader
    CtxShader(const EmptyObj& flag) : CtxObject(flag){};
    // Refer same gl object
    CtxShader(const CtxShader& other) : CtxObject(other){};
    CtxShader(const ShaderType& type, const SrcLoc loc = SrcLoc());
    
    Int getParamI(const Enum& param, const SrcLoc loc = SrcLoc()) const;
    ShaderType getType(const SrcLoc loc = SrcLoc()) const;
    bool isCompiled(const SrcLoc loc = SrcLoc()) const;

    Int getSourceLength(const SrcLoc loc = SrcLoc()) const;
    std::string getInfoLog(const SrcLoc loc = SrcLoc()) const;

    void compile(const std::string& code, const SrcLoc loc = SrcLoc());
};

} // namespace glwpp::gl