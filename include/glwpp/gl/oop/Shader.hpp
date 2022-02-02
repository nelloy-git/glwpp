#pragma once

#include <string>

#include "glwpp/gl/oop/ContextData.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"

namespace glwpp {

class Shader : public ContextData {
    friend class Program;
public:
    static constexpr bool DEBUG = true;
    
    Shader(wptr<Context> ctx, Vop<const gl::ShaderType> type);
    Shader(const Shader&) = delete;
    Shader(const Shader&&);
    virtual ~Shader();
    
    std::shared_future<bool> getParam_iv(Vop<const gl::ShaderParamInt> param, Ptr<gl::Int> dst) const;
    std::shared_future<bool> getInfoLog(Ptr<std::string> dst) const;

    std::shared_future<bool> compile(Vop<const std::string> code);
};

} // namespace glwpp