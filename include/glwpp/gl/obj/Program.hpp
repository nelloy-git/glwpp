#pragma once

#include "glwpp/gl/enums/ProgramParam.hpp"
#include "glwpp/gl/obj/Object.hpp"
#include "glwpp/gl/obj/Shader.hpp"

namespace glwpp::gl {

class Program : public Object {
public:
    static sptr<Program> make(const sptr<Context>& ctx,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
            
    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool isLinked(const Val<bool>& dst,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool isValidated(const Val<bool>& dst,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getAttachedShadersCount(const Val<Int>& dst,
                                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getActiveAttributesCount(const Val<Int>& dst,
                                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getActiveAttributeMaxNameLength(const Val<Int>& dst,
                                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getActiveUniformsCount(const Val<Int>& dst,
                                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getActiveUniformMaxNameLength(const Val<Int>& dst,
                                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getInfoLog(const Val<std::string>& dst,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;


    bool getAttributeLocation(const Val<Int>& dst, const Val<const std::string>& name,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
                              
    bool bindAttributeLocation(const Val<const UInt>& attr_index, const Val<const std::string>& name,
                               const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getUniformLocation(const Val<Int>& dst, const Val<const std::string>& name,
                            const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getUniformBlockIndex(const Val<UInt>& dst, const Val<const std::string>& name,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
                              
    bool bindUniformBlockIndex(const Val<const UInt>& block_index, const Val<const std::string>& name,
                               const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;


    bool attach(const Val<const Shader>& shader,
                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool link(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool validate(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool use(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    // bool setUniform1F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );
    // bool setUniform2F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );
    // bool setUniform3F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );
    // bool setUniform4F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat2x2F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat2x3F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat2x4F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat3x2F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat3x3F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat3x4F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat4x2F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat4x3F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

    // bool setUniformMat4x4F(
    //     const Val<const Int>& unif_loc, const Val<const Float>& data,
    //     const Val<const bool>& transpose = false, const Val<const Sizei>& count = 1,
    //     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}
    // );

protected:
    Program(const sptr<Context>& ctx,
            const Val<const utils::SrcLoc>& src_loc);

private:
    // Hide parent's make
    using Object::make;

    static void _initer(const Val<UInt>& dst,
                        const Val<const utils::SrcLoc>& src_loc);
    static void _deleter(const UInt& id);
};

} // namespace glwpp