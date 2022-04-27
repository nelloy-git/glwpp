#pragma once

#include "glwpp/gl/ctx_only/CtxObject.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/ctx_only/CtxShader.hpp"

namespace glwpp::gl {

class CtxProgram : public CtxObject {
    static UInt _createGlProgram(const SrcLoc& loc);
    static void _deleteGlProgram(const UInt& id);
    
public:
    // Empty CtxProgram
    CtxProgram(const EmptyObj& flag) : CtxObject(flag){};
    // Refer same gl object
    CtxProgram(const CtxProgram& other) : CtxObject(other){};
    CtxProgram(const SrcLoc& loc = SrcLoc());

    Int getParamI(const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    bool isLinked(const SrcLoc& loc = SrcLoc()) const;
    bool isValidated(const SrcLoc& loc = SrcLoc()) const;
    Int getAttachedShadersCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveAttributesCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveAttributeMaxNameLength(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveUniformsCount(const SrcLoc& loc = SrcLoc()) const;
    Int getActiveUniformMaxNameLength(const SrcLoc& loc = SrcLoc()) const;
    std::string getInfoLog(const SrcLoc& loc = SrcLoc()) const;

    void attach(const CtxShader& shader, const SrcLoc& loc = SrcLoc());
    void link(const SrcLoc& loc = SrcLoc());
    void validate(const SrcLoc& loc = SrcLoc()) const;
    void use(const SrcLoc& loc = SrcLoc()) const;

    Int getAttributeLocation(const std::string &name, const SrcLoc& loc = SrcLoc()) const;
    Int getUniformLocation(const std::string &name, const SrcLoc& loc = SrcLoc()) const;
    UInt getUniformBlockLocation(const std::string &name, const SrcLoc& loc = SrcLoc()) const;

    void setUniform1F(const Int& unif_loc, const Float* data, const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniform2F(const Int& unif_loc, const Float* data, const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniform3F(const Int& unif_loc, const Float* data, const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniform4F(const Int& unif_loc, const Float* data, const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat2x2F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat2x3F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat2x4F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat3x2F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat3x3F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat3x4F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat4x2F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat4x3F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void setUniformMat4x4F(const Int& unif_loc, const Float* data, const bool& transpose = false, 
                           const Sizei& count = 1, const SrcLoc& loc = SrcLoc());
    void bindUniformBlock(const UInt& block_loc, const UInt& index);
};

} // namespace glwpp::gl