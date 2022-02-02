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
    
    static void GetActiveProgram(wptr<Context> ctx, Program** dst){
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

std::shared_future<bool> Program::getActive(wptr<Context> ctx, Ptr<Program*> dst){
    return _lockCtx(ctx)->onRun.push([ctx, dst](){
        auto p_dst = getPtrValue(dst);
        GetActiveProgram(ctx, p_dst);
    });
}

std::shared_future<bool> Program::getParam_iv(Vop<const gl::ProgramParam> param, Ptr<gl::Int> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetProgramiv(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Program::getInfoLog(Ptr<std::string> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), dst](){
        auto p_dst = getPtrValue(dst);

        gl::Int success;
        glGetProgramiv(*id, GL_LINK_STATUS, &success);
        if (success == GL_FALSE){
            gl::Int length;
            glGetProgramiv(*id, GL_INFO_LOG_LENGTH, &length);
            p_dst->resize(length);
            glGetProgramInfoLog(*id, length, &length, p_dst->data());
        }

        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Program::attach(Ptr<const Shader> shader){
    return _lockCtx()->onRun.push([id = _idPtr(), shader](){
        auto p_shader = getPtrValue(shader);
        glAttachShader(*id, p_shader->id());
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Program::link(){
    return _lockCtx()->onRun.push([id = _idPtr()](){
        glLinkProgram(*id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Program::setActive() const {
    return _lockCtx()->onRun.push([id = _idPtr()](){
        std::cout << "Prog " << *id << std::endl;
        glUseProgram(*id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Program::getAttribLoc(Vop<const std::string> attrib, Ptr<gl::Int> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), attrib, dst](){
        auto &v_attrib = getVopRef(attrib);
        auto p_dst = getPtrValue(dst);

        *p_dst = glGetAttribLocation(*id, v_attrib.c_str());
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}