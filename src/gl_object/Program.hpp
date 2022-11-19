#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Shader.hpp"

namespace glwpp {

namespace GL {

class Program : public Object {
public:
    Program(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    Program(const Program&) = delete;
    Program(const Program&&) = delete;
    ~Program();

    void attach(const Shader& shader, const SrcLoc& src_loc = SrcLoc{});
    void link(const SrcLoc& src_loc = SrcLoc{});
    void validate(const SrcLoc& src_loc = SrcLoc{});
    void use(const SrcLoc& src_loc = SrcLoc{});

    Int getAttribLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    void bindAttribLocation(const Uint& attr_index, const String& name, const SrcLoc& src_loc = SrcLoc{});
    Int getUniformLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    Uint getUniformBlockIndex(const String& name, const SrcLoc& src_loc = SrcLoc{});

    Boolean isLinked(const SrcLoc& src_loc = SrcLoc{});
    Boolean isValidated(const SrcLoc& src_loc = SrcLoc{});
    Int getAttachedShadersCount(const SrcLoc& src_loc = SrcLoc{});
    Int getActiveAttributesCount(const SrcLoc& src_loc = SrcLoc{});
    Int getActiveAttributeMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    Int getActiveUniformsCount(const SrcLoc& src_loc = SrcLoc{});
    Int getActiveUniformMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

};

} // namespace GL

} // namespace glwpp