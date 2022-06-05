#pragma once

#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/obj/Shader.hpp"

namespace glwpp::gl {

class Program : public Object {
public:
    Program(const wptr<Context>& wctx,
            const Val<const SrcLoc> src_loc = SrcLoc{});
            
    bool getParamInt(
        const Val<Int>& dst, const Val<const Enum>& param,
        const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true
    ) const;

    bool isLinked(
        const Val<bool> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool isValidated(
        const Val<bool> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getAttachedShadersCount(
        const Val<Int> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getActiveAttributesCount(
        const Val<Int> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getActiveAttributeMaxNameLength(
        const Val<Int> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getActiveUniformsCount(
        const Val<Int> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getActiveUniformMaxNameLength(
        const Val<Int> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getInfoLog(
        const Val<std::string> dst,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;


    bool getAttributeLocation(
        const Val<Int> dst, const Val<const std::string>& name,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getUniformLocation(
        const Val<Int> dst, const Val<const std::string>& name,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool getUniformBlockIndex(
        const Val<UInt>& dst, const Val<const std::string>& name,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;


    bool attach(
        const Shader& shader,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool link(
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool validate(
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool use(
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    ) const;

    bool setUniform1F(
        const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );
    bool setUniform2F(
        const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );
    bool setUniform3F(
        const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );
    bool setUniform4F(
        const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat2x2F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat2x3F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat2x4F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat3x2F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat3x3F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat3x4F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat4x2F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat4x3F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

    bool setUniformMat4x4F(
        const Val<const Int>& unif_loc, const Val<const Float>& data,
        const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
        const Val<const SrcLoc> src_loc = SrcLoc{}, const bool check_ctx = true
    );

private:
    static void _initer(UInt& dst);
    static void _deleter(const UInt& id);
};

} // namespace glwpp