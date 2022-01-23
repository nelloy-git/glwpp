#include "glwpp/gl/oop/Program.hpp"

#include "glad/gl.h"

#include <unordered_map>

using namespace glwpp;

namespace {
    static std::mutex id2prog_lock;
    static std::unordered_map<Context*, std::unordered_map<gl::UInt, Program*>> id2prog;

    static void setMapProg (wptr<Context> ctx, gl::UInt id, Program *prog){
        Context* raw_ctx = ctx.lock().get();

        std::lock_guard lg(id2prog_lock);
        auto map_iter = id2prog.find(raw_ctx);
        if (map_iter == id2prog.end()){
            auto [tmp_iter, success] = id2prog.insert({raw_ctx, {}});
            map_iter = tmp_iter;
        }
        map_iter->second[id] = prog;
    }

    static void delMapProg(wptr<Context> ctx, gl::UInt id, Program* prog){
        Context* raw_ctx = ctx.lock().get();

        std::lock_guard lg(id2prog_lock);
        auto map_iter = id2prog.find(raw_ctx);
        if (map_iter == id2prog.end()){
            auto [tmp_iter, success] = id2prog.insert({raw_ctx, {}});
            map_iter = tmp_iter;
        }
        auto id_iter = map_iter->second.find(id);
        if (id_iter == map_iter->second.end()){
            return;
        }
        if (id_iter->second != prog){
            return;
        }
        map_iter->second.erase(id_iter);
    }

    static Program* getMapProg(wptr<Context> ctx, gl::UInt id){
        Context* raw_ctx = ctx.lock().get();
        auto map_iter = id2prog.find(raw_ctx);
        if (map_iter == id2prog.end()){
            return nullptr;
        }
        auto id_iter = map_iter->second.find(id);
        if (id_iter == map_iter->second.end()){
            return nullptr;
        }
        return id_iter->second;
    }
    
    static void GetActiveProgram(wptr<Context> ctx, sptr<Program*> dst){
        gl::Int prog_id;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prog_id);
        *dst = getMapProg(ctx, prog_id);
    }

    static gl::UInt CreateProgram(wptr<Context> ctx, Program* prog){
        gl::UInt id = glCreateProgram();
        setMapProg(ctx, id, prog);
        return id;
    }
    static void DeleteProgram(gl::UInt *id, wptr<Context> ctx, Program* prog){
        glDeleteProgram(*id);
        delMapProg(ctx, *id, prog);
        delete id;
    }
    static auto getDeteler(wptr<Context> ctx, Program* prog){
        return [ctx, prog](gl::UInt *id){
            DeleteProgram(id, ctx, prog);
        };
    }
}

Program::Program(wptr<Context> ctx) :
    ContextData(ctx, &CreateProgram, getDeteler(ctx, this), ctx, this){
}

Program::Program(const Program &&other) :
    ContextData(std::move(other)){
    setMapProg(ctx(), id(), this);
}

Program::~Program(){
}

std::shared_future<bool> Program::getActive(wptr<Context> ctx, sptr<Program*> dst){
    if constexpr (AUTOCLEAR) _clear(ctx, dst);
    return _lockCtx(ctx)->onRun.push([ctx, dst](){
        GetActiveProgram(ctx, dst);
    });
}

std::shared_future<bool> Program::getParam_iv(sptr<gl::ProgramParam> param, sptr<gl::Int> dst) const {
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetProgramiv(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Program::getInfoLog(sptr<std::string> dst) const {
    if constexpr (AUTOCLEAR) _clear(dst);
    return _lockCtx()->onRun.push([id = idPtr(), dst](){
        gl::Int length;
        glGetProgramiv(*id, GL_LINK_STATUS, &length);
        dst->resize(length);
        glGetProgramInfoLog(*id, length, &length, dst->data());
    });
}

std::shared_future<bool> Program::attach(sptr<const Shader> shader){
    if constexpr (AUTOCLEAR) _clear(shader);
    return _lockCtx()->onRun.push([id = idPtr(), shader_id = shader->idPtr()](){
        glAttachShader(*id, *shader_id);
    });
}

std::shared_future<bool> Program::link(){
    return _lockCtx()->onRun.push([id = idPtr()](){
        glLinkProgram(*id);
    });
}

std::shared_future<bool> Program::setActive() const {
    return _lockCtx()->onRun.push([id = idPtr()](){
        glUseProgram(*id);
    });
}

std::shared_future<bool> Program::getAttribLoc(sptr<const std::string> attrib, sptr<gl::Int> dst) const {
    if constexpr (AUTOCLEAR) _clear(attrib, dst);
    return _lockCtx()->onRun.push([id = idPtr(), attrib, dst](){
        *dst = glGetAttribLocation(*id, attrib->c_str());
    });
}