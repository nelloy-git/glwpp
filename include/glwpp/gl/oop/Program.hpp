#pragma once

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/oop/Shader.hpp"

namespace glwpp {

class Program : public ContextData {
public:
    Program(wptr<Context> ctx);
    Program(const Program&) = delete;
    Program(const Program&&);
    virtual ~Program(); 

    static std::shared_future<Program*> getActive(wptr<Context> ctx);

    std::shared_future<bool> attach(const Shader &shader);
    std::shared_future<bool> link();
    std::shared_future<bool> use() const;

    std::shared_future<gl::Int> getParamInt(gl::ProgramParamInt param) const;
    std::shared_future<std::string> getInfoLog() const;
    std::shared_future<gl::Int> getAttribLoc(const std::string *attrib) const;
};

}