#pragma once

#include "gl_object/Object.hpp"

namespace glwpp {

namespace GL {

class ShaderBase : public Object {
public:
    EXPORT ~ShaderBase();

    EXPORT void source(const String& code, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void compile(const SrcLoc& src_loc = SrcLoc{});

    EXPORT Enum getType(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Boolean isCompiled(const SrcLoc& src_loc = SrcLoc{});
    EXPORT Int getSourceLength(const SrcLoc& src_loc = SrcLoc{});
    EXPORT String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

protected:
    ShaderBase(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc);

};

class Shader : public ShaderBase, public SharedObject<Shader> {
public:
    EXPORT static std::shared_ptr<Shader> New(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc = SrcLoc{}){
        return std::shared_ptr<Shader>(new Shader(ctx, type, src_loc));
    }

protected:
    Shader(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc) : 
        ShaderBase(ctx, type, src_loc){
    }
};

} // namespace GL

} // namespace glwpp