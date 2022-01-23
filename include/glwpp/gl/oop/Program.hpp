#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public ContextData {
public:
    static constexpr bool AUTOCLEAR = true;

    Program(wptr<Context> ctx);
    Program(const Program&) = delete;
    Program(const Program&&);
    virtual ~Program(); 

    static std::shared_future<bool> getActive(wptr<Context> ctx, sptr<Program*> dst);

    std::shared_future<bool> getParam_iv(sptr<gl::ProgramParam> param, sptr<gl::Int> dst) const;
    std::shared_future<bool> getInfoLog(sptr<std::string> dst) const;

    std::shared_future<bool> attach(sptr<const Shader> shader);
    std::shared_future<bool> link();
    std::shared_future<bool> setActive() const;
    
    std::shared_future<bool> getAttribLoc(sptr<const std::string> attrib, sptr<gl::Int> dst) const;
    
};

}