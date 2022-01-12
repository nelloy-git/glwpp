#pragma once

#include <string>

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/api/gl_46.hpp"
#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp {

class Shader : public ContextData {
public:
    Shader(wptr<Context> ctx, gl::ShaderType type);
    Shader(const Shader&) = delete;
    Shader(const Shader&&);
    virtual ~Shader();

    std::shared_future<bool> compile(const std::string *code);
    
    std::shared_future<gl::Int> getParamInt(gl::ShaderParamInt param) const;
    std::shared_future<std::string> getLogInfo() const;
};

}