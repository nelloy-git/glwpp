#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public ContextData {
public:
    static constexpr bool DEBUG = true;
    
    Program(wptr<Context> ctx);
    Program(const Program&) = delete;
    Program(const Program&&);
    virtual ~Program(); 

    static std::shared_future<bool> getActive(wptr<Context> ctx, Ptr<Program*> dst);

    std::shared_future<bool> getParam_iv(Vop<const gl::ProgramParam> param, Ptr<gl::Int> dst) const;
    std::shared_future<bool> getInfoLog(Ptr<std::string> dst) const;

    std::shared_future<bool> attach(Ptr<const Shader> shader);
    std::shared_future<bool> link();
    std::shared_future<bool> setActive() const;
    
    std::shared_future<bool> getAttribLoc(Vop<const std::string> attrib, Ptr<gl::Int> dst) const;
    
};

} // namespace glwpp