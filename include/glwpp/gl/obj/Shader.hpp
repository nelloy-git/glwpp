#pragma once

#include <string>

#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/enums/ShaderType.hpp"
#include "glwpp/gl/enums/ShaderParam.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp::gl {

class Shader : public Object {
public:
    Shader(const wptr<Context>& wctx, const Val<const gl::ShaderType>& type,
           const Val<const SrcLoc>& src_loc = SrcLoc{});
           
    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const;

    bool getType(const Val<gl::ShaderType> dst,
                 const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool isCompiled(const Val<bool> dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getSourceLength(const Val<gl::Int> dst,
                         const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getInfoLog(const Val<std::string> dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const;

    bool setSource(const Val<const std::string>& code,
                   const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true);
    bool compile(const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true);

private:
    static void _initer(UInt& dst, const gl::ShaderType& type);
    static void _deleter(const UInt& id);
};

} // namespace glwpp