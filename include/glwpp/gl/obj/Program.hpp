#pragma once

#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/obj/Shader.hpp"

namespace glwpp {

class Program : public Object {
public:
    Program(const wptr<Context>& weak_ctx, const SrcLoc& loc = SrcLoc());

    bool isLinked(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    bool isValidated(Ptr<bool> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getAttachedShadersCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveAttributesCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveAttributeMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveUniformsCount(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getActiveUniformMaxNameLength(Ptr<gl::Int> dst, const SrcLoc& loc = SrcLoc()) const;
    bool getInfoLog(Ptr<std::string> dst, const SrcLoc& loc = SrcLoc()) const;

    bool getAttributeLocation(Ptr<gl::Int> dst, const Val<std::string>& name, const SrcLoc& loc = SrcLoc()) const;
    bool getUniformLocation(Ptr<gl::Int> dst, const Val<std::string>& name, const SrcLoc& loc = SrcLoc()) const;

    bool attach(Shader& shader, const SrcLoc& loc = SrcLoc());
    bool link(const SrcLoc& loc = SrcLoc());
    bool validate(const SrcLoc& loc = SrcLoc()) const;
    bool use(const SrcLoc& loc = SrcLoc()) const;                      

    bool setUniform1F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<gl::Sizei>& count = 1, const SrcLoc& loc = SrcLoc());
    bool setUniform2F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<gl::Sizei>& count = 2, const SrcLoc& loc = SrcLoc());
    bool setUniform3F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<gl::Sizei>& count = 3, const SrcLoc& loc = SrcLoc());
    bool setUniform4F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<gl::Sizei>& count = 4, const SrcLoc& loc = SrcLoc());
    bool setUniformMat2x2F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 4, const SrcLoc& loc = SrcLoc());
    bool setUniformMat2x3F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 6, const SrcLoc& loc = SrcLoc());
    bool setUniformMat2x4F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 8, const SrcLoc& loc = SrcLoc());
    bool setUniformMat3x2F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 6, const SrcLoc& loc = SrcLoc());
    bool setUniformMat3x3F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 9, const SrcLoc& loc = SrcLoc());
    bool setUniformMat3x4F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 12, const SrcLoc& loc = SrcLoc());
    bool setUniformMat4x2F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 8, const SrcLoc& loc = SrcLoc());
    bool setUniformMat4x3F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 12, const SrcLoc& loc = SrcLoc());
    bool setUniformMat4x4F(const Val<gl::Int>& unif_loc, const Ptr<gl::Float>& data, const Val<bool>& transpose = false, 
                           const Val<gl::Sizei>& count = 16, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp