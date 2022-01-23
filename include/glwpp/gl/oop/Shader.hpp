#pragma once

#include <string>

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp {

class Shader : public ContextData {
public:
    static constexpr bool AUTOCLEAR = true;

    Shader(wptr<Context> ctx, gl::ShaderType type);
    Shader(const Shader&) = delete;
    Shader(const Shader&&);
    virtual ~Shader();
    
    std::shared_future<bool> getParam_iv(sptr<gl::ShaderParamInt> param, sptr<gl::Int> dst) const;
    std::shared_future<bool> getLogInfo(sptr<std::string> dst) const;

    std::shared_future<bool> compile(sptr<const std::string> code);
};

}