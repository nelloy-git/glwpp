#pragma once

#include <string>

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"
#include "glwpp/gl/obj/Object.hpp"

namespace glwpp::gl {

class Shader : public Object {
public:
    static sptr<Shader> make(const sptr<Context>& ctx, const Val<const GL::ShaderRefType>& type,
                             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
           
    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool getType(const Val<GL::ShaderRefType>& dst,
                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isCompiled(const Val<bool>& dst,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getSourceLength(const Val<gl::Int>& dst,
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getInfoLog(const Val<std::string>& dst,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool setSource(const Val<const std::string>& code,
                   const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool compile(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

protected:
    Shader(const sptr<Context>& wctx, const Val<const GL::ShaderRefType>& type,
           const Val<const utils::SrcLoc>& src_loc);

private:
    // Hide ContextObject::make
    using Object::make;

    static void _initer(const Val<UInt>& dst, const Val<const GL::ShaderRefType>& type,
                        const Val<const utils::SrcLoc>& src_loc);
    static void _deleter(const UInt& id);
};

} // namespace glwpp