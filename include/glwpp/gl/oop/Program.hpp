#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public Object {
public:
    Program(wptr<Context> ctx, const SrcLoc& loc = SrcLoc::current());

    std::shared_future<bool> isLinked(Ptr<bool> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> isValidated(Ptr<bool> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc::current()) const;

    std::shared_future<bool> getAttributeLocation(Ptr<gl::Int> dst, const Vop<std::string> name, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> getUniformLocation(Ptr<gl::Int> dst, const Vop<std::string> name, const SrcLoc& loc = SrcLoc::current()) const;

    std::shared_future<bool> attach(const Vop<Shader> shader, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> link(const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> validate(const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> use(const SrcLoc& loc = SrcLoc::current()) const;
};

} // namespace glwpp