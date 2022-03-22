#pragma once

#include <string>

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp {

class Shader : public Object {
    friend class Program;
public:
    Shader(const std::weak_ptr<Context>& weak_ctx, const Val<gl::ShaderType>& type, const SrcLoc& loc = SrcLoc());

    bool getType(Ptr<gl::ShaderType> dst, const SrcLoc& loc = SrcLoc()) const;
    bool isCompiled(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getSourceLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc()) const;

    bool compile(const Val<std::string>& code, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp