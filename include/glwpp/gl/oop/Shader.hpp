#pragma once

#include <string>

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp {

class Shader : public Object {
    friend class Program;
public:
    Shader(wptr<Context> ctx, const Vop<gl::ShaderType>& type, const SrcLoc& loc = SrcLoc::current());

    std::shared_future<bool> getType(Ptr<gl::ShaderType> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> isCompiled(Ptr<bool> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getSourceLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc::current()) const;

    std::shared_future<bool> compile(const Vop<std::string>& code, const SrcLoc& loc = SrcLoc::current());
};

} // namespace glwpp