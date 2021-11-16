#pragma once

#include "glwpp/ctx/ContextData.hpp"
#include "glwpp/ctx/data/Shader.hpp"
#include "glwpp/ctx/data/Program.hpp"

#include "glwpp/Model.hpp"

namespace glwpp {

template<class V>
class Renderer {

public:
    Renderer(std::weak_ptr<Context> wctx,
             std::weak_ptr<std::string> wcode_vshader,
             std::weak_ptr<std::string> wcode_fshader = std::weak_ptr<std::string>()){
        auto code_vshader = wcode_vshader.lock();
        auto code_fshader = wcode_fshader.lock();

        using s_string = std::shared_ptr<std::string>;
        _program.initFunc(wctx, std::function(_initialize), code_vshader, code_fshader);
    }

    bool use(){
        return _program.executeIgnoreResult(ctx::Program::use);
    }

    template<class I>
    bool draw(Model<V, I>& model, GLsizei count = 1){
        auto model_wctx = model._vert_arr.getContext();
        if (_wctx.owner_before(model_wctx) || model_wctx.owner_before(_wctx)) return false;

        // TODO check is program in use
        return model._vert_arr.executeIgnoreResult(ctx::VertexArray<V>::drawInstanced,
                                                   DrawModeGL::Triangles, count);
    }

protected:
    
private:
    std::weak_ptr<Context> _wctx;
    ctx::ContextData<ctx::Program> _program;

    static std::unique_ptr<ctx::Program> _initialize(std::shared_ptr<std::string> code_vshader,
                                              std::shared_ptr<std::string> code_fshader){
        auto prog = std::make_unique<ctx::Program>();

        if (code_vshader){
            auto vshader = _makeShader(ShaderTypeGL::Vertex, *code_vshader);
            prog->attach(*vshader);
            std::cout << "Renderer: VShader received" << std::endl;
        } else {
            return nullptr;
        }

        if (code_fshader){
            auto fshader = _makeShader(ShaderTypeGL::Fragment, *code_fshader);
            prog->attach(*fshader);
            std::cout << "Renderer: FShader received" << std::endl;
        }

        auto err = prog->link();
        std::cout << "Renderer: Linked" << std::endl;

        if (err){
            std::cout << "Renderer: linking error:" << std::endl;
            std::cout << err.value() << std::endl;
            return nullptr;
        }

        return prog;
    }

    static std::shared_ptr<ctx::Shader> _makeShader(ShaderTypeGL type, const std::string &code){
        auto sh = std::make_shared<ctx::Shader>(type);
        sh->setSource(code);
        auto err = sh->compile();

        if (err){
            std::cout << "Shader compilation error:" << std::endl;
            std::cout << err.value() << std::endl;
            return nullptr;
        }
        return sh;
    }

};

}