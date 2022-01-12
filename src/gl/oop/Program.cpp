#include "glwpp/gl/oop/Program.hpp"

#include <unordered_map>

using namespace glwpp;

namespace {
    static std::mutex id2prog_lock;
    static std::unordered_map<gl::UInt, Program*> id2prog;

    static gl::UInt CreateProgram(){
        return gl::CreateProgram();
    }
    static void DeleteProgram(gl::UInt *id){
        gl::DeleteProgram(*id);
        delete id;
    }
    static Program* GetActiveProgram(){
        static gl::Enum GL_CURRENT_PROGRAM = 0x8B8D;

        gl::Int prog_id;
        gl::GetIntegerv(GL_CURRENT_PROGRAM, &prog_id);

        std::lock_guard lg(id2prog_lock);
        auto iter = id2prog.find(prog_id);
        if (iter != id2prog.end()){
            return iter->second;
        }
        return nullptr;
    }
    static gl::Int GetParamInt(const sptr<gl::UInt> id, gl::ProgramParamInt param){
        gl::Int val;
        gl::GetProgramiv(*id, static_cast<gl::Enum>(param), &val);
        return val;
    }
    static void AttachShader(const sptr<gl::UInt> prog_id, const sptr<gl::UInt> shad_id){
        gl::AttachShader(*prog_id, *shad_id);
    }
    static bool Link(const sptr<gl::UInt> id){
        gl::LinkProgram(*id);
        return GetParamInt(id, gl::ProgramParamInt::LinkStatus);
    }
    static void Use(const sptr<gl::UInt> id){
        gl::UseProgram(*id);
    }
    static std::string GetInfoLog(const sptr<gl::UInt> id){
        gl::Int length = GetParamInt(id, gl::ProgramParamInt::InfoLogLength);

        std::string msg(length, '\0');
        gl::GetProgramInfoLog(*id, length, &length, msg.data());
        return msg;
    }
    static gl::Int GetAttribLoc(const sptr<gl::UInt> id, const std::string *name){
        return gl::GetAttribLocation(*id, name->c_str());
    }
}

Program::Program(wptr<Context> ctx) :
    ContextData(ctx, &CreateProgram, &DeleteProgram){
    std::lock_guard lg(id2prog_lock);
    id2prog[id()] = this;
}

Program::Program(const Program &&other) :
    ContextData(std::move(other)){
    std::lock_guard lg(id2prog_lock);
    id2prog[id()] = this;
}

Program::~Program(){
}

std::shared_future<Program*> Program::getActive(wptr<Context> ctx){
    return _execute(ctx, &GetActiveProgram);
}

std::shared_future<bool> Program::attach(const Shader &shader){
    return _execute(&AttachShader, idPtr(), shader.idPtr());
}

std::shared_future<bool> Program::link(){
    return _execute(&Link, idPtr());
}

std::shared_future<bool> Program::use() const {
    return _execute(&Use, idPtr());
}

std::shared_future<gl::Int> Program::getParamInt(gl::ProgramParamInt param) const {
    return _execute(&GetParamInt, idPtr(), param);
}

std::shared_future<std::string> Program::getInfoLog() const {
    return _execute(&GetInfoLog, idPtr());
}

std::shared_future<gl::Int> Program::getAttribLoc(const std::string *attrib) const {
    return _execute(&GetAttribLoc, idPtr(), attrib);
}