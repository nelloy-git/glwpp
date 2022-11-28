#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Shader.hpp"

namespace glwpp {

namespace GL {

class ProgramBase : public Object {
public:
    EXPORT ~ProgramBase();

    EXPORT void attach(const ShaderBase& shader, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void link(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void validate(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void use(const SrcLoc& src_loc = SrcLoc{});

    EXPORT Int getAttribLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void bindAttribLocation(const Uint& attr_index, const String& name, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getUniformLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Uint getUniformBlockIndex(const String& name, const SrcLoc& src_loc = SrcLoc{});

    EXPORT Boolean isLinked(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isValidated(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getAttachedShadersCount(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getActiveAttributesCount(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getActiveAttributeMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getActiveUniformsCount(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getActiveUniformMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    EXPORT String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

protected:
    ProgramBase(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc);

};

class Program : public ProgramBase, public SharedObject<Program> {
public:
    EXPORT static std::shared_ptr<Program> New(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{}){
        return std::shared_ptr<Program>(new Program(ctx, src_loc));
    }

protected:
    Program(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) : 
        ProgramBase(ctx, src_loc){
    }
};

} // namespace GL

} // namespace glwpp