#pragma once

#include "gl_object/Object.hpp"

namespace glwpp {

namespace GL {

class Shader : public Object {
public:
    Shader(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc = SrcLoc{});
    Shader(const Shader&) = delete;
    Shader(const Shader&&) = delete;
    ~Shader();

    void source(const String& code, const SrcLoc& src_loc = SrcLoc{});
    void compile(const SrcLoc& src_loc = SrcLoc{});

    Enum getType(const SrcLoc& src_loc = SrcLoc{});
    Boolean isCompiled(const SrcLoc& src_loc = SrcLoc{});
    Int getSourceLength(const SrcLoc& src_loc = SrcLoc{});
    String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

};

} // namespace GL

} // namespace glwpp