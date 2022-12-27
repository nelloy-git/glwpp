#include "Drawer.hpp"

using namespace glwpp;

Drawer::Drawer(Context& ctx, const SrcLoc& src_loc) :
    CallOptimizer(ctx),
    _program(ctx, src_loc){
}

Drawer::~Drawer(){
}

Drawer::CompileResult Drawer::_setShader(Context& ctx, GL::Program& program, const GLenum& type, const std::string& code, const SrcLoc& src_loc){
    GL::Shader shader(ctx, type, src_loc);
    shader.source<IsGlThread::True>(code, src_loc);
    shader.compile<IsGlThread::True>(src_loc);
    auto is_compiled = shader.isCompiled<IsGlThread::True>(src_loc)->value_or(false);
    if (!is_compiled){
        std::cout << "Here1" << std::endl;
        return {true, "Compile error:\n" + shader.getInfoLog<IsGlThread::True>(src_loc)->value_or("Unknown error")};
    }

    program.attach<IsGlThread::True>(shader, src_loc);
    program.link<IsGlThread::True>(src_loc);
    auto is_linked = program.isLinked<IsGlThread::True>(src_loc)->value_or(false);
    if (!is_linked){
        std::cout << "Here2" << std::endl;
        return {true, "Link error:\n" + program.getInfoLog<IsGlThread::True>(src_loc)->value_or("Unknown error")};
    }

    return {false, std::string{}};
}