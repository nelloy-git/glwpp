#pragma once

#include <GLapi/Glad.hpp>

#include "context/CtxObj.hpp"
#include "metric/Category.hpp"
#include "utils/Export.hpp"
#include "utils/SrcLoc.hpp"
#include "utils/TState.hpp"
#include "utils/Value.hpp"

namespace glwpp {

class GLapi : public CtxObj<GLapi> {
private:
    struct GLapiImpl;
    std::unique_ptr<GLapiImpl> _impl;
    std::shared_ptr<Metrics::Category> _metrics;
    std::unique_ptr<SrcLoc> _last_src_loc;

    template<auto M>
    auto _implCall(const SrcLoc& src_loc, const std::string_view& name, auto&&... args) const;

public:
    GLapi(Context& ctx);
    virtual ~GLapi();

    int VersionMajor() const {return _version_major;};
    int VersionMinor() const {return _version_minor;};

    template<TState IsCtx> inline auto loadGladGLContext(GLADloadfunc load){return callMember<IsCtx, &GLapi::_loadGladGLContext>(load);}

    EXPORT const SrcLoc& getLastSrcLoc() const;
    EXPORT void setMetricsCategory(const std::shared_ptr<Metrics::Category>& category);
    
    template<TState IsCtx> inline auto Accum(auto&&... args) const {return callMember<IsCtx, &GLapi::_Accum>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ActiveShaderProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_ActiveShaderProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ActiveTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_ActiveTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto AlphaFunc(auto&&... args) const {return callMember<IsCtx, &GLapi::_AlphaFunc>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto AreTexturesResident(auto&&... args) const {return callMember<IsCtx, &GLapi::_AreTexturesResident>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ArrayElement(auto&&... args) const {return callMember<IsCtx, &GLapi::_ArrayElement>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto AttachShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_AttachShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Begin(auto&&... args) const {return callMember<IsCtx, &GLapi::_Begin>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BeginConditionalRender(auto&&... args) const {return callMember<IsCtx, &GLapi::_BeginConditionalRender>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BeginQuery(auto&&... args) const {return callMember<IsCtx, &GLapi::_BeginQuery>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BeginQueryIndexed(auto&&... args) const {return callMember<IsCtx, &GLapi::_BeginQueryIndexed>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BeginTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_BeginTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindAttribLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindAttribLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindBufferBase(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindBufferBase>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindBuffersBase(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindBuffersBase>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindBuffersRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindBuffersRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindFragDataLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindFragDataLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindFragDataLocationIndexed(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindFragDataLocationIndexed>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindImageTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindImageTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindImageTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindImageTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindProgramPipeline(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindProgramPipeline>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindRenderbuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindRenderbuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindSampler(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindSampler>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindSamplers(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindSamplers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindTextureUnit(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindTextureUnit>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindVertexArray(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindVertexArray>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindVertexBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindVertexBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BindVertexBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_BindVertexBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Bitmap(auto&&... args) const {return callMember<IsCtx, &GLapi::_Bitmap>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendColor(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendColor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendEquation(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendEquation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendEquationSeparate(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendEquationSeparate>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendEquationSeparatei(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendEquationSeparatei>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendEquationi(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendEquationi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendFunc(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendFunc>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendFuncSeparate(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendFuncSeparate>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendFuncSeparatei(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendFuncSeparatei>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlendFunci(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlendFunci>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlitFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlitFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BlitNamedFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_BlitNamedFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_BufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BufferStorage(auto&&... args) const {return callMember<IsCtx, &GLapi::_BufferStorage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto BufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_BufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CallList(auto&&... args) const {return callMember<IsCtx, &GLapi::_CallList>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CallLists(auto&&... args) const {return callMember<IsCtx, &GLapi::_CallLists>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CheckFramebufferStatus(auto&&... args) const {return callMember<IsCtx, &GLapi::_CheckFramebufferStatus>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CheckNamedFramebufferStatus(auto&&... args) const {return callMember<IsCtx, &GLapi::_CheckNamedFramebufferStatus>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClampColor(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClampColor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Clear(auto&&... args) const {return callMember<IsCtx, &GLapi::_Clear>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearAccum(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearAccum>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferfi(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferfi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearBufferuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearBufferuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearColor(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearColor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearDepth(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearDepth>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearDepthf(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearDepthf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedBufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedBufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedFramebufferfi(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedFramebufferfi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedFramebufferfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedFramebufferfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedFramebufferiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedFramebufferiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearNamedFramebufferuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearNamedFramebufferuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearStencil(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearStencil>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClearTexSubImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClearTexSubImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClientActiveTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClientActiveTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClientWaitSync(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClientWaitSync>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClipControl(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClipControl>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ClipPlane(auto&&... args) const {return callMember<IsCtx, &GLapi::_ClipPlane>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3b(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3b>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3bv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3ub(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3ub>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3ubv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3ubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3uiv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3us(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3us>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color3usv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color3usv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4b(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4b>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4bv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4ub(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4ub>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4ubv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4ubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4uiv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4us(auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4us>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Color4usv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Color4usv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorMask(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorMask>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorMaski(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorMaski>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorMaterial(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorMaterial>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorP4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorP4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorP4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorP4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ColorPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_ColorPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompileShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompileShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTexSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTexSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTextureSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTextureSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTextureSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTextureSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CompressedTextureSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CompressedTextureSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyImageSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyImageSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyNamedBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyNamedBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyPixels(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyPixels>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTexImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTexImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTexImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTexImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTexSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTexSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTexSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTexSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTexSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTexSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTextureSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTextureSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTextureSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTextureSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CopyTextureSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_CopyTextureSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateFramebuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateFramebuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateProgramPipelines(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateProgramPipelines>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateQueries(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateQueries>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateRenderbuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateRenderbuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateSamplers(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateSamplers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateShaderProgramv(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateShaderProgramv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateTransformFeedbacks(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateTransformFeedbacks>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CreateVertexArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_CreateVertexArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto CullFace(auto&&... args) const {return callMember<IsCtx, &GLapi::_CullFace>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DebugMessageCallback(auto&&... args) const {return callMember<IsCtx, &GLapi::_DebugMessageCallback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DebugMessageControl(auto&&... args) const {return callMember<IsCtx, &GLapi::_DebugMessageControl>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DebugMessageInsert(auto&&... args) const {return callMember<IsCtx, &GLapi::_DebugMessageInsert>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteFramebuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteFramebuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteLists(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteLists>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteProgramPipelines(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteProgramPipelines>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteQueries(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteQueries>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteRenderbuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteRenderbuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteSamplers(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteSamplers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteSync(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteSync>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteTransformFeedbacks(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteTransformFeedbacks>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DeleteVertexArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_DeleteVertexArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthFunc(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthFunc>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthMask(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthMask>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthRangeArrayv(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthRangeArrayv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthRangeIndexed(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthRangeIndexed>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DepthRangef(auto&&... args) const {return callMember<IsCtx, &GLapi::_DepthRangef>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DetachShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_DetachShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Disable(auto&&... args) const {return callMember<IsCtx, &GLapi::_Disable>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DisableClientState(auto&&... args) const {return callMember<IsCtx, &GLapi::_DisableClientState>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DisableVertexArrayAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_DisableVertexArrayAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DisableVertexAttribArray(auto&&... args) const {return callMember<IsCtx, &GLapi::_DisableVertexAttribArray>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Disablei(auto&&... args) const {return callMember<IsCtx, &GLapi::_Disablei>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DispatchCompute(auto&&... args) const {return callMember<IsCtx, &GLapi::_DispatchCompute>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DispatchComputeIndirect(auto&&... args) const {return callMember<IsCtx, &GLapi::_DispatchComputeIndirect>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawArraysIndirect(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawArraysIndirect>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawArraysInstanced(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawArraysInstanced>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawArraysInstancedBaseInstance(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawArraysInstancedBaseInstance>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElements(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElements>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsBaseVertex(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsBaseVertex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsIndirect(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsIndirect>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsInstanced(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsInstanced>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsInstancedBaseInstance(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsInstancedBaseInstance>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsInstancedBaseVertex(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsInstancedBaseVertex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawElementsInstancedBaseVertexBaseInstance(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawElementsInstancedBaseVertexBaseInstance>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawPixels(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawPixels>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawRangeElements(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawRangeElements>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawRangeElementsBaseVertex(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawRangeElementsBaseVertex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawTransformFeedbackInstanced(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawTransformFeedbackInstanced>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawTransformFeedbackStream(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawTransformFeedbackStream>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto DrawTransformFeedbackStreamInstanced(auto&&... args) const {return callMember<IsCtx, &GLapi::_DrawTransformFeedbackStreamInstanced>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EdgeFlag(auto&&... args) const {return callMember<IsCtx, &GLapi::_EdgeFlag>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EdgeFlagPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_EdgeFlagPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EdgeFlagv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_EdgeFlagv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Enable(auto&&... args) const {return callMember<IsCtx, &GLapi::_Enable>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EnableClientState(auto&&... args) const {return callMember<IsCtx, &GLapi::_EnableClientState>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EnableVertexArrayAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_EnableVertexArrayAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EnableVertexAttribArray(auto&&... args) const {return callMember<IsCtx, &GLapi::_EnableVertexAttribArray>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Enablei(auto&&... args) const {return callMember<IsCtx, &GLapi::_Enablei>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto End(auto&&... args) const {return callMember<IsCtx, &GLapi::_End>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EndConditionalRender(auto&&... args) const {return callMember<IsCtx, &GLapi::_EndConditionalRender>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EndList(auto&&... args) const {return callMember<IsCtx, &GLapi::_EndList>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EndQuery(auto&&... args) const {return callMember<IsCtx, &GLapi::_EndQuery>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EndQueryIndexed(auto&&... args) const {return callMember<IsCtx, &GLapi::_EndQueryIndexed>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EndTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_EndTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord1dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord1fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord2dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalCoord2fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalCoord2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalMesh1(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalMesh1>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalMesh2(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalMesh2>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalPoint1(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalPoint1>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto EvalPoint2(auto&&... args) const {return callMember<IsCtx, &GLapi::_EvalPoint2>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FeedbackBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_FeedbackBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FenceSync(auto&&... args) const {return callMember<IsCtx, &GLapi::_FenceSync>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Finish(auto&&... args) const {return callMember<IsCtx, &GLapi::_Finish>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Flush(auto&&... args) const {return callMember<IsCtx, &GLapi::_Flush>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FlushMappedBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_FlushMappedBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FlushMappedNamedBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_FlushMappedNamedBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FogCoordPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_FogCoordPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FogCoordd(auto&&... args) const {return callMember<IsCtx, &GLapi::_FogCoordd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FogCoorddv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_FogCoorddv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FogCoordf(auto&&... args) const {return callMember<IsCtx, &GLapi::_FogCoordf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FogCoordfv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_FogCoordfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Fogf(auto&&... args) const {return callMember<IsCtx, &GLapi::_Fogf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Fogfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Fogfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Fogi(auto&&... args) const {return callMember<IsCtx, &GLapi::_Fogi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Fogiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Fogiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferRenderbuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferRenderbuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferTexture1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferTexture1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferTexture2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferTexture2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferTexture3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferTexture3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FramebufferTextureLayer(auto&&... args) const {return callMember<IsCtx, &GLapi::_FramebufferTextureLayer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto FrontFace(auto&&... args) const {return callMember<IsCtx, &GLapi::_FrontFace>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Frustum(auto&&... args) const {return callMember<IsCtx, &GLapi::_Frustum>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenFramebuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenFramebuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenLists(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenLists>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenProgramPipelines(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenProgramPipelines>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenQueries(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenQueries>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenRenderbuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenRenderbuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenSamplers(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenSamplers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenTransformFeedbacks(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenTransformFeedbacks>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenVertexArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenVertexArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenerateMipmap(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenerateMipmap>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GenerateTextureMipmap(auto&&... args) const {return callMember<IsCtx, &GLapi::_GenerateTextureMipmap>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveAtomicCounterBufferiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveAtomicCounterBufferiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveSubroutineName(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveSubroutineName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveSubroutineUniformName(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveSubroutineUniformName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveSubroutineUniformiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveSubroutineUniformiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveUniform(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveUniform>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveUniformBlockName(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveUniformBlockName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveUniformBlockiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveUniformBlockiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveUniformName(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveUniformName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetActiveUniformsiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetActiveUniformsiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetAttachedShaders(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetAttachedShaders>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetAttribLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetAttribLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBooleani_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBooleani_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBooleanv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBooleanv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBufferParameteri64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBufferParameteri64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBufferPointerv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBufferPointerv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetClipPlane(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetClipPlane>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetCompressedTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetCompressedTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetCompressedTextureImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetCompressedTextureImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetCompressedTextureSubImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetCompressedTextureSubImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetDebugMessageLog(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetDebugMessageLog>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetDoublei_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetDoublei_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetDoublev(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetDoublev>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetError(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetError>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFloati_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFloati_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFloatv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFloatv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFragDataIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFragDataIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFragDataLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFragDataLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFramebufferAttachmentParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFramebufferAttachmentParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetFramebufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetFramebufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetGraphicsResetStatus(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetGraphicsResetStatus>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetInteger64i_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetInteger64i_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetInteger64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetInteger64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetIntegeri_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetIntegeri_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetIntegerv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetIntegerv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetInternalformati64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetInternalformati64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetInternalformativ(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetInternalformativ>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetLightfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetLightfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetLightiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetLightiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMapdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMapdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMapfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMapfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMapiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMapiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMaterialfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMaterialfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMaterialiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMaterialiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetMultisamplefv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetMultisamplefv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedBufferParameteri64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedBufferParameteri64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedBufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedBufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedBufferPointerv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedBufferPointerv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedFramebufferAttachmentParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedFramebufferAttachmentParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedFramebufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedFramebufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetNamedRenderbufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetNamedRenderbufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetObjectLabel(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetObjectLabel>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetObjectPtrLabel(const auto&&... args) const {return callMember<IsCtx, &GLapi::_GetObjectPtrLabel>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetPixelMapfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetPixelMapfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetPixelMapuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetPixelMapuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetPixelMapusv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetPixelMapusv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetPointerv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetPointerv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetPolygonStipple(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetPolygonStipple>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramBinary(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramBinary>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramInfoLog(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramInfoLog>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramInterfaceiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramInterfaceiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramPipelineInfoLog(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramPipelineInfoLog>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramPipelineiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramPipelineiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramResourceIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramResourceIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramResourceLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramResourceLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramResourceLocationIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramResourceLocationIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramResourceName(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramResourceName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramResourceiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramResourceiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramStageiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramStageiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetProgramiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetProgramiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryBufferObjecti64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryBufferObjecti64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryBufferObjectiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryBufferObjectiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryBufferObjectui64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryBufferObjectui64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryBufferObjectuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryBufferObjectuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryIndexediv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryIndexediv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryObjecti64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryObjecti64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryObjectiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryObjectiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryObjectui64v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryObjectui64v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryObjectuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryObjectuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetQueryiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetQueryiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetRenderbufferParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetRenderbufferParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSamplerParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSamplerParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSamplerParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSamplerParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSamplerParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSamplerParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSamplerParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSamplerParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetShaderInfoLog(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetShaderInfoLog>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetShaderPrecisionFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetShaderPrecisionFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetShaderSource(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetShaderSource>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetShaderiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetShaderiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetString(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetString>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetStringi(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetStringi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSubroutineIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSubroutineIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSubroutineUniformLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSubroutineUniformLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetSynciv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetSynciv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexEnvfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexEnvfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexEnviv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexEnviv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexGendv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexGendv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexGenfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexGenfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexGeniv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexGeniv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexLevelParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexLevelParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexLevelParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexLevelParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTexParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTexParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureLevelParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureLevelParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureLevelParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureLevelParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTextureSubImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTextureSubImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTransformFeedbackVarying(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTransformFeedbackVarying>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTransformFeedbacki64_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTransformFeedbacki64_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTransformFeedbacki_v(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTransformFeedbacki_v>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetTransformFeedbackiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetTransformFeedbackiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformBlockIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformBlockIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformIndices(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformIndices>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformLocation(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformLocation>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformSubroutineuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformSubroutineuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetUniformuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetUniformuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexArrayIndexed64iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexArrayIndexed64iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexArrayIndexediv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexArrayIndexediv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexArrayiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexArrayiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribLdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribLdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribPointerv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribPointerv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetVertexAttribiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetVertexAttribiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnColorTable(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnColorTable>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnCompressedTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnCompressedTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnConvolutionFilter(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnConvolutionFilter>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnHistogram(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnHistogram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnMapdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnMapdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnMapfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnMapfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnMapiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnMapiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnMinmax(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnMinmax>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnPixelMapfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnPixelMapfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnPixelMapuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnPixelMapuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnPixelMapusv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnPixelMapusv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnPolygonStipple(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnPolygonStipple>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnSeparableFilter(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnSeparableFilter>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnUniformdv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnUniformdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnUniformfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnUniformfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnUniformiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnUniformiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto GetnUniformuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_GetnUniformuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Hint(auto&&... args) const {return callMember<IsCtx, &GLapi::_Hint>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IndexMask(auto&&... args) const {return callMember<IsCtx, &GLapi::_IndexMask>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IndexPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_IndexPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexd(auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexdv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexf(auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexfv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexi(auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexiv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexs(auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexs>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexsv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexsv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexub(auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexub>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Indexubv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Indexubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InitNames(auto&&... args) const {return callMember<IsCtx, &GLapi::_InitNames>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InterleavedArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_InterleavedArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateBufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateBufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateNamedFramebufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateNamedFramebufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateNamedFramebufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateNamedFramebufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateSubFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateSubFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateTexImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateTexImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto InvalidateTexSubImage(auto&&... args) const {return callMember<IsCtx, &GLapi::_InvalidateTexSubImage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsEnabled(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsEnabled>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsEnabledi(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsEnabledi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsFramebuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsFramebuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsList(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsList>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsProgramPipeline(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsProgramPipeline>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsQuery(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsQuery>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsRenderbuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsRenderbuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsSampler(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsSampler>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsSync(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsSync>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto IsVertexArray(auto&&... args) const {return callMember<IsCtx, &GLapi::_IsVertexArray>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LightModelf(auto&&... args) const {return callMember<IsCtx, &GLapi::_LightModelf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LightModelfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_LightModelfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LightModeli(auto&&... args) const {return callMember<IsCtx, &GLapi::_LightModeli>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LightModeliv(auto&&... args) const {return callMember<IsCtx, &GLapi::_LightModeliv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Lightf(auto&&... args) const {return callMember<IsCtx, &GLapi::_Lightf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Lightfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Lightfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Lighti(auto&&... args) const {return callMember<IsCtx, &GLapi::_Lighti>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Lightiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Lightiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LineStipple(auto&&... args) const {return callMember<IsCtx, &GLapi::_LineStipple>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LineWidth(auto&&... args) const {return callMember<IsCtx, &GLapi::_LineWidth>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LinkProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_LinkProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ListBase(auto&&... args) const {return callMember<IsCtx, &GLapi::_ListBase>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadIdentity(auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadIdentity>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadMatrixd(const auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadMatrixd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadMatrixf(const auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadMatrixf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadName(auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadTransposeMatrixd(const auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadTransposeMatrixd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LoadTransposeMatrixf(const auto&&... args) const {return callMember<IsCtx, &GLapi::_LoadTransposeMatrixf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto LogicOp(auto&&... args) const {return callMember<IsCtx, &GLapi::_LogicOp>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Map1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Map1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Map1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Map1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Map2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Map2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Map2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Map2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapBuffer (auto&&... args) const {return callMember<IsCtx, &GLapi::_MapBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapBufferRange (auto&&... args) const {return callMember<IsCtx, &GLapi::_MapBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapGrid1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MapGrid1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapGrid1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MapGrid1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapGrid2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MapGrid2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapGrid2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MapGrid2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapNamedBuffer (auto&&... args) const {return callMember<IsCtx, &GLapi::_MapNamedBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MapNamedBufferRange (auto&&... args) const {return callMember<IsCtx, &GLapi::_MapNamedBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Materialf(auto&&... args) const {return callMember<IsCtx, &GLapi::_Materialf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Materialfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Materialfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Materiali(auto&&... args) const {return callMember<IsCtx, &GLapi::_Materiali>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Materialiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Materialiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MatrixMode(auto&&... args) const {return callMember<IsCtx, &GLapi::_MatrixMode>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MemoryBarrier(auto&&... args) const {return callMember<IsCtx, &GLapi::_MemoryBarrier>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MemoryBarrierByRegion(auto&&... args) const {return callMember<IsCtx, &GLapi::_MemoryBarrierByRegion>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MinSampleShading(auto&&... args) const {return callMember<IsCtx, &GLapi::_MinSampleShading>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultMatrixd(const auto&&... args) const {return callMember<IsCtx, &GLapi::_MultMatrixd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultMatrixf(const auto&&... args) const {return callMember<IsCtx, &GLapi::_MultMatrixf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultTransposeMatrixd(const auto&&... args) const {return callMember<IsCtx, &GLapi::_MultTransposeMatrixd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultTransposeMatrixf(const auto&&... args) const {return callMember<IsCtx, &GLapi::_MultTransposeMatrixf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawArrays(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawArrays>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawArraysIndirect(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawArraysIndirect>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawArraysIndirectCount(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawArraysIndirectCount>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawElements(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawElements>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawElementsBaseVertex(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawElementsBaseVertex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawElementsIndirect(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawElementsIndirect>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiDrawElementsIndirectCount(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiDrawElementsIndirectCount>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1i(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1s(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord1sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord1sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord2sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord3sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoord4sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoord4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto MultiTexCoordP4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_MultiTexCoordP4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedBufferData(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedBufferData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedBufferStorage(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedBufferStorage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedBufferSubData(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedBufferSubData>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferDrawBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferDrawBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferDrawBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferDrawBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferReadBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferReadBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferRenderbuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferRenderbuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferTexture(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferTexture>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedFramebufferTextureLayer(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedFramebufferTextureLayer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedRenderbufferStorage(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedRenderbufferStorage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NamedRenderbufferStorageMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_NamedRenderbufferStorageMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NewList(auto&&... args) const {return callMember<IsCtx, &GLapi::_NewList>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3b(auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3b>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3bv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Normal3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Normal3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NormalP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_NormalP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NormalP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_NormalP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto NormalPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_NormalPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ObjectLabel(auto&&... args) const {return callMember<IsCtx, &GLapi::_ObjectLabel>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ObjectPtrLabel(const auto&&... args) const {return callMember<IsCtx, &GLapi::_ObjectPtrLabel>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Ortho(auto&&... args) const {return callMember<IsCtx, &GLapi::_Ortho>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PassThrough(auto&&... args) const {return callMember<IsCtx, &GLapi::_PassThrough>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PatchParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PatchParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PatchParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_PatchParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PauseTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_PauseTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelMapfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelMapfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelMapuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelMapuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelMapusv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelMapusv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelStoref(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelStoref>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelStorei(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelStorei>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelTransferf(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelTransferf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelTransferi(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelTransferi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PixelZoom(auto&&... args) const {return callMember<IsCtx, &GLapi::_PixelZoom>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PointParameterf(auto&&... args) const {return callMember<IsCtx, &GLapi::_PointParameterf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PointParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PointParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PointParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_PointParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PointParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_PointParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PointSize(auto&&... args) const {return callMember<IsCtx, &GLapi::_PointSize>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PolygonMode(auto&&... args) const {return callMember<IsCtx, &GLapi::_PolygonMode>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PolygonOffset(auto&&... args) const {return callMember<IsCtx, &GLapi::_PolygonOffset>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PolygonOffsetClamp(auto&&... args) const {return callMember<IsCtx, &GLapi::_PolygonOffsetClamp>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PolygonStipple(const auto&&... args) const {return callMember<IsCtx, &GLapi::_PolygonStipple>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PopAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_PopAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PopClientAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_PopClientAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PopDebugGroup(auto&&... args) const {return callMember<IsCtx, &GLapi::_PopDebugGroup>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PopMatrix(auto&&... args) const {return callMember<IsCtx, &GLapi::_PopMatrix>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PopName(auto&&... args) const {return callMember<IsCtx, &GLapi::_PopName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PrimitiveRestartIndex(auto&&... args) const {return callMember<IsCtx, &GLapi::_PrimitiveRestartIndex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PrioritizeTextures(auto&&... args) const {return callMember<IsCtx, &GLapi::_PrioritizeTextures>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramBinary(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramBinary>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1i(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniform4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniform4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2x3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2x3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2x3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2x3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2x4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2x4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix2x4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix2x4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3x2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3x2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3x2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3x2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3x4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3x4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix3x4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix3x4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4x2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4x2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4x2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4x2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4x3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4x3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProgramUniformMatrix4x3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProgramUniformMatrix4x3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ProvokingVertex(auto&&... args) const {return callMember<IsCtx, &GLapi::_ProvokingVertex>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PushAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_PushAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PushClientAttrib(auto&&... args) const {return callMember<IsCtx, &GLapi::_PushClientAttrib>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PushDebugGroup(auto&&... args) const {return callMember<IsCtx, &GLapi::_PushDebugGroup>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PushMatrix(auto&&... args) const {return callMember<IsCtx, &GLapi::_PushMatrix>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto PushName(auto&&... args) const {return callMember<IsCtx, &GLapi::_PushName>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto QueryCounter(auto&&... args) const {return callMember<IsCtx, &GLapi::_QueryCounter>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos2sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RasterPos4sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_RasterPos4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ReadBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_ReadBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ReadPixels(auto&&... args) const {return callMember<IsCtx, &GLapi::_ReadPixels>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ReadnPixels(auto&&... args) const {return callMember<IsCtx, &GLapi::_ReadnPixels>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectd(auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectd>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectdv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectdv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectf(auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectfv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Recti(auto&&... args) const {return callMember<IsCtx, &GLapi::_Recti>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectiv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rects(auto&&... args) const {return callMember<IsCtx, &GLapi::_Rects>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rectsv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Rectsv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ReleaseShaderCompiler(auto&&... args) const {return callMember<IsCtx, &GLapi::_ReleaseShaderCompiler>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RenderMode(auto&&... args) const {return callMember<IsCtx, &GLapi::_RenderMode>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RenderbufferStorage(auto&&... args) const {return callMember<IsCtx, &GLapi::_RenderbufferStorage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto RenderbufferStorageMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_RenderbufferStorageMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ResumeTransformFeedback(auto&&... args) const {return callMember<IsCtx, &GLapi::_ResumeTransformFeedback>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rotated(auto&&... args) const {return callMember<IsCtx, &GLapi::_Rotated>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Rotatef(auto&&... args) const {return callMember<IsCtx, &GLapi::_Rotatef>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SampleCoverage(auto&&... args) const {return callMember<IsCtx, &GLapi::_SampleCoverage>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SampleMaski(auto&&... args) const {return callMember<IsCtx, &GLapi::_SampleMaski>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameterf(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameterf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SamplerParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_SamplerParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Scaled(auto&&... args) const {return callMember<IsCtx, &GLapi::_Scaled>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Scalef(auto&&... args) const {return callMember<IsCtx, &GLapi::_Scalef>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Scissor(auto&&... args) const {return callMember<IsCtx, &GLapi::_Scissor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ScissorArrayv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ScissorArrayv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ScissorIndexed(auto&&... args) const {return callMember<IsCtx, &GLapi::_ScissorIndexed>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ScissorIndexedv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ScissorIndexedv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3b(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3b>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3bv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3ub(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3ub>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3ubv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3ubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3uiv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3us(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3us>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColor3usv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColor3usv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColorP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColorP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColorP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColorP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SecondaryColorPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_SecondaryColorPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SelectBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_SelectBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ShadeModel(auto&&... args) const {return callMember<IsCtx, &GLapi::_ShadeModel>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ShaderBinary(auto&&... args) const {return callMember<IsCtx, &GLapi::_ShaderBinary>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ShaderSource(auto&&... args) const {return callMember<IsCtx, &GLapi::_ShaderSource>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ShaderStorageBlockBinding(auto&&... args) const {return callMember<IsCtx, &GLapi::_ShaderStorageBlockBinding>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto SpecializeShader(auto&&... args) const {return callMember<IsCtx, &GLapi::_SpecializeShader>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilFunc(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilFunc>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilFuncSeparate(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilFuncSeparate>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilMask(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilMask>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilMaskSeparate(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilMaskSeparate>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilOp(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilOp>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto StencilOpSeparate(auto&&... args) const {return callMember<IsCtx, &GLapi::_StencilOpSeparate>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1i(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1s(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord1sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord1sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord2sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoord4sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoord4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordP4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordP4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexCoordPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexCoordPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexEnvf(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexEnvf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexEnvfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexEnvfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexEnvi(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexEnvi>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexEnviv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexEnviv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGend(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGend>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGendv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGendv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGenf(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGenf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGenfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGenfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGeni(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGeni>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexGeniv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexGeniv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexImage2DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexImage2DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexImage3DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexImage3DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameterf(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameterf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexStorage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexStorage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexStorage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexStorage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexStorage2DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexStorage2DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexStorage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexStorage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexStorage3DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexStorage3DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TexSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TexSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureBarrier(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureBarrier>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameterIiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameterIiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameterIuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameterIuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameterf(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameterf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameterfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameterfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameteri(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameteri>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureParameteriv(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureParameteriv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureStorage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureStorage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureStorage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureStorage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureStorage2DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureStorage2DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureStorage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureStorage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureStorage3DMultisample(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureStorage3DMultisample>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureSubImage1D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureSubImage1D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureSubImage2D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureSubImage2D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureSubImage3D(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureSubImage3D>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TextureView(auto&&... args) const {return callMember<IsCtx, &GLapi::_TextureView>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TransformFeedbackBufferBase(auto&&... args) const {return callMember<IsCtx, &GLapi::_TransformFeedbackBufferBase>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TransformFeedbackBufferRange(auto&&... args) const {return callMember<IsCtx, &GLapi::_TransformFeedbackBufferRange>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto TransformFeedbackVaryings(auto&&... args) const {return callMember<IsCtx, &GLapi::_TransformFeedbackVaryings>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Translated(auto&&... args) const {return callMember<IsCtx, &GLapi::_Translated>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Translatef(auto&&... args) const {return callMember<IsCtx, &GLapi::_Translatef>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Uniform4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_Uniform4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformBlockBinding(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformBlockBinding>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2x3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2x3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2x3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2x3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2x4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2x4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix2x4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix2x4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3x2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3x2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3x2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3x2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3x4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3x4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix3x4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix3x4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4x2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4x2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4x2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4x2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4x3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4x3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformMatrix4x3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformMatrix4x3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UniformSubroutinesuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_UniformSubroutinesuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UnmapBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_UnmapBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UnmapNamedBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_UnmapNamedBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UseProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_UseProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto UseProgramStages(auto&&... args) const {return callMember<IsCtx, &GLapi::_UseProgramStages>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ValidateProgram(auto&&... args) const {return callMember<IsCtx, &GLapi::_ValidateProgram>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ValidateProgramPipeline(auto&&... args) const {return callMember<IsCtx, &GLapi::_ValidateProgramPipeline>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex2sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Vertex4sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_Vertex4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayAttribBinding(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayAttribBinding>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayAttribFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayAttribFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayAttribIFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayAttribIFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayAttribLFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayAttribLFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayBindingDivisor(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayBindingDivisor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayElementBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayElementBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayVertexBuffer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayVertexBuffer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexArrayVertexBuffers(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexArrayVertexBuffers>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1f(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1s(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib1sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib1sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib2sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib3sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib3sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nbv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nbv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Niv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Niv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nsv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nsv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nub(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nub>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nubv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nuiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nuiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4Nusv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4Nusv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4bv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4f(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4fv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4s(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4ubv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4ubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttrib4usv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttrib4usv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribBinding(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribBinding>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribDivisor(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribDivisor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI1i(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI1i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI1iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI1iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI2iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI3iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4bv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4bv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4i(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4iv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4sv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4ubv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4ubv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribI4usv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribI4usv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribIFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribIFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribIPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribIPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL1d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL1d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL1dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL1dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL2dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL3dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL4d(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL4d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribL4dv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribL4dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribLFormat(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribLFormat>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribLPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribLPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP1ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP1ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP1uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP1uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribP4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribP4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexAttribPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexAttribPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexBindingDivisor(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexBindingDivisor>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP2ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP2ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP2uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP2uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP3ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP3ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP3uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP3uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP4ui(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP4ui>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexP4uiv(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexP4uiv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto VertexPointer(auto&&... args) const {return callMember<IsCtx, &GLapi::_VertexPointer>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto Viewport(auto&&... args) const {return callMember<IsCtx, &GLapi::_Viewport>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ViewportArrayv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ViewportArrayv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ViewportIndexedf(auto&&... args) const {return callMember<IsCtx, &GLapi::_ViewportIndexedf>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto ViewportIndexedfv(auto&&... args) const {return callMember<IsCtx, &GLapi::_ViewportIndexedfv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WaitSync(auto&&... args) const {return callMember<IsCtx, &GLapi::_WaitSync>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2d(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2f(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2i(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2s(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos2sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos2sv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3d(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3d>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3dv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3dv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3f(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3f>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3fv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3fv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3i(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3i>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3iv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3iv>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3s(auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3s>(std::forward<decltype(args)>(args)...);}
    template<TState IsCtx> inline auto WindowPos3sv(const auto&&... args) const {return callMember<IsCtx, &GLapi::_WindowPos3sv>(std::forward<decltype(args)>(args)...);}

private:
    int _version_major;
    int _version_minor;

    EXPORT int _loadGladGLContext(GLADloadfunc load);

    EXPORT void _Accum(GLenum op, GLfloat value, const SrcLoc& src_loc) const;
    EXPORT void _ActiveShaderProgram(GLuint pipeline, GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _ActiveTexture(GLenum texture, const SrcLoc& src_loc) const;
    EXPORT void _AlphaFunc(GLenum func, GLfloat ref, const SrcLoc& src_loc) const;
    EXPORT GLboolean _AreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences, const SrcLoc& src_loc) const;
    EXPORT void _ArrayElement(GLint i, const SrcLoc& src_loc) const;
    EXPORT void _AttachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const;
    EXPORT void _Begin(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _BeginConditionalRender(GLuint id, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _BeginQuery(GLenum target, GLuint id, const SrcLoc& src_loc) const;
    EXPORT void _BeginQueryIndexed(GLenum target, GLuint index, GLuint id, const SrcLoc& src_loc) const;
    EXPORT void _BeginTransformFeedback(GLenum primitiveMode, const SrcLoc& src_loc) const;
    EXPORT void _BindAttribLocation(GLuint program, GLuint index, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _BindBuffer(GLenum target, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _BindBufferBase(GLenum target, GLuint index, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _BindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const SrcLoc& src_loc) const;
    EXPORT void _BindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes, const SrcLoc& src_loc) const;
    EXPORT void _BindFragDataLocation(GLuint program, GLuint color, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _BindFramebuffer(GLenum target, GLuint framebuffer, const SrcLoc& src_loc) const;
    EXPORT void _BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format, const SrcLoc& src_loc) const;
    EXPORT void _BindImageTextures(GLuint first, GLsizei count, const GLuint * textures, const SrcLoc& src_loc) const;
    EXPORT void _BindProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const;
    EXPORT void _BindRenderbuffer(GLenum target, GLuint renderbuffer, const SrcLoc& src_loc) const;
    EXPORT void _BindSampler(GLuint unit, GLuint sampler, const SrcLoc& src_loc) const;
    EXPORT void _BindSamplers(GLuint first, GLsizei count, const GLuint * samplers, const SrcLoc& src_loc) const;
    EXPORT void _BindTexture(GLenum target, GLuint texture, const SrcLoc& src_loc) const;
    EXPORT void _BindTextureUnit(GLuint unit, GLuint texture, const SrcLoc& src_loc) const;
    EXPORT void _BindTextures(GLuint first, GLsizei count, const GLuint * textures, const SrcLoc& src_loc) const;
    EXPORT void _BindTransformFeedback(GLenum target, GLuint id, const SrcLoc& src_loc) const;
    EXPORT void _BindVertexArray(GLuint array, const SrcLoc& src_loc) const;
    EXPORT void _BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _BindVertexBuffers(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides, const SrcLoc& src_loc) const;
    EXPORT void _Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap, const SrcLoc& src_loc) const;
    EXPORT void _BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const;
    EXPORT void _BlendEquation(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const;
    EXPORT void _BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const;
    EXPORT void _BlendEquationi(GLuint buf, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _BlendFunc(GLenum sfactor, GLenum dfactor, const SrcLoc& src_loc) const;
    EXPORT void _BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, const SrcLoc& src_loc) const;
    EXPORT void _BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, const SrcLoc& src_loc) const;
    EXPORT void _BlendFunci(GLuint buf, GLenum src, GLenum dst, const SrcLoc& src_loc) const;
    EXPORT void _BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const;
    EXPORT void _BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const;
    EXPORT void _BufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage, const SrcLoc& src_loc) const;
    EXPORT void _BufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags, const SrcLoc& src_loc) const;
    EXPORT void _BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CallList(GLuint list, const SrcLoc& src_loc) const;
    EXPORT void _CallLists(GLsizei n, GLenum type, const void * lists, const SrcLoc& src_loc) const;
    EXPORT GLenum _CheckFramebufferStatus(GLenum target, const SrcLoc& src_loc) const;
    EXPORT GLenum _CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, const SrcLoc& src_loc) const;
    EXPORT void _ClampColor(GLenum target, GLenum clamp, const SrcLoc& src_loc) const;
    EXPORT void _Clear(GLbitfield mask, const SrcLoc& src_loc) const;
    EXPORT void _ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const;
    EXPORT void _ClearDepth(GLdouble depth, const SrcLoc& src_loc) const;
    EXPORT void _ClearDepthf(GLfloat d, const SrcLoc& src_loc) const;
    EXPORT void _ClearIndex(GLfloat c, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ClearStencil(GLint s, const SrcLoc& src_loc) const;
    EXPORT void _ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _ClientActiveTexture(GLenum texture, const SrcLoc& src_loc) const;
    EXPORT GLenum _ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const;
    EXPORT void _ClipControl(GLenum origin, GLenum depth, const SrcLoc& src_loc) const;
    EXPORT void _ClipPlane(GLenum plane, const GLdouble * equation, const SrcLoc& src_loc) const;
    EXPORT void _Color3b(GLbyte red, GLbyte green, GLbyte blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3bv(const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3d(GLdouble red, GLdouble green, GLdouble blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3f(GLfloat red, GLfloat green, GLfloat blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3i(GLint red, GLint green, GLint blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3s(GLshort red, GLshort green, GLshort blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3ub(GLubyte red, GLubyte green, GLubyte blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3ubv(const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3ui(GLuint red, GLuint green, GLuint blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3uiv(const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _Color3us(GLushort red, GLushort green, GLushort blue, const SrcLoc& src_loc) const;
    EXPORT void _Color3usv(const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4bv(const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4i(GLint red, GLint green, GLint blue, GLint alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4ubv(const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4uiv(const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha, const SrcLoc& src_loc) const;
    EXPORT void _Color4usv(const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, const SrcLoc& src_loc) const;
    EXPORT void _ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, const SrcLoc& src_loc) const;
    EXPORT void _ColorMaterial(GLenum face, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _ColorP3ui(GLenum type, GLuint color, const SrcLoc& src_loc) const;
    EXPORT void _ColorP3uiv(GLenum type, const GLuint * color, const SrcLoc& src_loc) const;
    EXPORT void _ColorP4ui(GLenum type, GLuint color, const SrcLoc& src_loc) const;
    EXPORT void _ColorP4uiv(GLenum type, const GLuint * color, const SrcLoc& src_loc) const;
    EXPORT void _ColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _CompileShader(GLuint shader, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, const SrcLoc& src_loc) const;
    EXPORT void _CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type, const SrcLoc& src_loc) const;
    EXPORT void _CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, const SrcLoc& src_loc) const;
    EXPORT void _CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, const SrcLoc& src_loc) const;
    EXPORT void _CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const;
    EXPORT void _CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const;
    EXPORT void _CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _CreateBuffers(GLsizei n, GLuint * buffers, const SrcLoc& src_loc) const;
    EXPORT void _CreateFramebuffers(GLsizei n, GLuint * framebuffers, const SrcLoc& src_loc) const;
    EXPORT GLuint _CreateProgram(const SrcLoc& src_loc) const;
    EXPORT void _CreateProgramPipelines(GLsizei n, GLuint * pipelines, const SrcLoc& src_loc) const;
    EXPORT void _CreateQueries(GLenum target, GLsizei n, GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _CreateRenderbuffers(GLsizei n, GLuint * renderbuffers, const SrcLoc& src_loc) const;
    EXPORT void _CreateSamplers(GLsizei n, GLuint * samplers, const SrcLoc& src_loc) const;
    EXPORT GLuint _CreateShader(GLenum type, const SrcLoc& src_loc) const;
    EXPORT GLuint _CreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings, const SrcLoc& src_loc) const;
    EXPORT void _CreateTextures(GLenum target, GLsizei n, GLuint * textures, const SrcLoc& src_loc) const;
    EXPORT void _CreateTransformFeedbacks(GLsizei n, GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _CreateVertexArrays(GLsizei n, GLuint * arrays, const SrcLoc& src_loc) const;
    EXPORT void _CullFace(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _DebugMessageCallback(GLDEBUGPROC callback, const void * userParam, const SrcLoc& src_loc) const;
    EXPORT void _DebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled, const SrcLoc& src_loc) const;
    EXPORT void _DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf, const SrcLoc& src_loc) const;
    EXPORT void _DeleteBuffers(GLsizei n, const GLuint * buffers, const SrcLoc& src_loc) const;
    EXPORT void _DeleteFramebuffers(GLsizei n, const GLuint * framebuffers, const SrcLoc& src_loc) const;
    EXPORT void _DeleteLists(GLuint list, GLsizei range, const SrcLoc& src_loc) const;
    EXPORT void _DeleteProgram(GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _DeleteProgramPipelines(GLsizei n, const GLuint * pipelines, const SrcLoc& src_loc) const;
    EXPORT void _DeleteQueries(GLsizei n, const GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _DeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers, const SrcLoc& src_loc) const;
    EXPORT void _DeleteSamplers(GLsizei count, const GLuint * samplers, const SrcLoc& src_loc) const;
    EXPORT void _DeleteShader(GLuint shader, const SrcLoc& src_loc) const;
    EXPORT void _DeleteSync(GLsync sync, const SrcLoc& src_loc) const;
    EXPORT void _DeleteTextures(GLsizei n, const GLuint * textures, const SrcLoc& src_loc) const;
    EXPORT void _DeleteTransformFeedbacks(GLsizei n, const GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _DeleteVertexArrays(GLsizei n, const GLuint * arrays, const SrcLoc& src_loc) const;
    EXPORT void _DepthFunc(GLenum func, const SrcLoc& src_loc) const;
    EXPORT void _DepthMask(GLboolean flag, const SrcLoc& src_loc) const;
    EXPORT void _DepthRange(GLdouble n, GLdouble f, const SrcLoc& src_loc) const;
    EXPORT void _DepthRangeArrayv(GLuint first, GLsizei count, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, const SrcLoc& src_loc) const;
    EXPORT void _DepthRangef(GLfloat n, GLfloat f, const SrcLoc& src_loc) const;
    EXPORT void _DetachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const;
    EXPORT void _Disable(GLenum cap, const SrcLoc& src_loc) const;
    EXPORT void _DisableClientState(GLenum array, const SrcLoc& src_loc) const;
    EXPORT void _DisableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _DisableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _Disablei(GLenum target, GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, const SrcLoc& src_loc) const;
    EXPORT void _DispatchComputeIndirect(GLintptr indirect, const SrcLoc& src_loc) const;
    EXPORT void _DrawArrays(GLenum mode, GLint first, GLsizei count, const SrcLoc& src_loc) const;
    EXPORT void _DrawArraysIndirect(GLenum mode, const void * indirect, const SrcLoc& src_loc) const;
    EXPORT void _DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, const SrcLoc& src_loc) const;
    EXPORT void _DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const;
    EXPORT void _DrawBuffer(GLenum buf, const SrcLoc& src_loc) const;
    EXPORT void _DrawBuffers(GLsizei n, const GLenum * bufs, const SrcLoc& src_loc) const;
    EXPORT void _DrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, const SrcLoc& src_loc) const;
    EXPORT void _DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, const SrcLoc& src_loc) const;
    EXPORT void _DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, const SrcLoc& src_loc) const;
    EXPORT void _DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex, const SrcLoc& src_loc) const;
    EXPORT void _DrawTransformFeedback(GLenum mode, GLuint id, const SrcLoc& src_loc) const;
    EXPORT void _DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, const SrcLoc& src_loc) const;
    EXPORT void _DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, const SrcLoc& src_loc) const;
    EXPORT void _DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, const SrcLoc& src_loc) const;
    EXPORT void _EdgeFlag(GLboolean flag, const SrcLoc& src_loc) const;
    EXPORT void _EdgeFlagPointer(GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _EdgeFlagv(const GLboolean * flag, const SrcLoc& src_loc) const;
    EXPORT void _Enable(GLenum cap, const SrcLoc& src_loc) const;
    EXPORT void _EnableClientState(GLenum array, const SrcLoc& src_loc) const;
    EXPORT void _EnableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _EnableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _Enablei(GLenum target, GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _End(const SrcLoc& src_loc) const;
    EXPORT void _EndConditionalRender(const SrcLoc& src_loc) const;
    EXPORT void _EndList(const SrcLoc& src_loc) const;
    EXPORT void _EndQuery(GLenum target, const SrcLoc& src_loc) const;
    EXPORT void _EndQueryIndexed(GLenum target, GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _EndTransformFeedback(const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord1d(GLdouble u, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord1dv(const GLdouble * u, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord1f(GLfloat u, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord1fv(const GLfloat * u, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord2d(GLdouble u, GLdouble v, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord2dv(const GLdouble * u, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord2f(GLfloat u, GLfloat v, const SrcLoc& src_loc) const;
    EXPORT void _EvalCoord2fv(const GLfloat * u, const SrcLoc& src_loc) const;
    EXPORT void _EvalMesh1(GLenum mode, GLint i1, GLint i2, const SrcLoc& src_loc) const;
    EXPORT void _EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2, const SrcLoc& src_loc) const;
    EXPORT void _EvalPoint1(GLint i, const SrcLoc& src_loc) const;
    EXPORT void _EvalPoint2(GLint i, GLint j, const SrcLoc& src_loc) const;
    EXPORT void _FeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer, const SrcLoc& src_loc) const;
    EXPORT GLsync _FenceSync(GLenum condition, GLbitfield flags, const SrcLoc& src_loc) const;
    EXPORT void _Finish(const SrcLoc& src_loc) const;
    EXPORT void _Flush(const SrcLoc& src_loc) const;
    EXPORT void _FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const;
    EXPORT void _FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const;
    EXPORT void _FogCoordPointer(GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _FogCoordd(GLdouble coord, const SrcLoc& src_loc) const;
    EXPORT void _FogCoorddv(const GLdouble * coord, const SrcLoc& src_loc) const;
    EXPORT void _FogCoordf(GLfloat coord, const SrcLoc& src_loc) const;
    EXPORT void _FogCoordfv(const GLfloat * coord, const SrcLoc& src_loc) const;
    EXPORT void _Fogf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _Fogfv(GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _Fogi(GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _Fogiv(GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, const SrcLoc& src_loc) const;
    EXPORT void _FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const;
    EXPORT void _FrontFace(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _Frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar, const SrcLoc& src_loc) const;
    EXPORT void _GenBuffers(GLsizei n, GLuint * buffers, const SrcLoc& src_loc) const;
    EXPORT void _GenFramebuffers(GLsizei n, GLuint * framebuffers, const SrcLoc& src_loc) const;
    EXPORT GLuint _GenLists(GLsizei range, const SrcLoc& src_loc) const;
    EXPORT void _GenProgramPipelines(GLsizei n, GLuint * pipelines, const SrcLoc& GetProgram) const;
    EXPORT void _GenQueries(GLsizei n, GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _GenRenderbuffers(GLsizei n, GLuint * renderbuffers, const SrcLoc& src_loc) const;
    EXPORT void _GenSamplers(GLsizei count, GLuint * samplers, const SrcLoc& src_loc) const;
    EXPORT void _GenTextures(GLsizei n, GLuint * textures, const SrcLoc& src_loc) const;
    EXPORT void _GenTransformFeedbacks(GLsizei n, GLuint * ids, const SrcLoc& src_loc) const;
    EXPORT void _GenVertexArrays(GLsizei n, GLuint * arrays, const SrcLoc& src_loc) const;
    EXPORT void _GenerateMipmap(GLenum target, const SrcLoc& src_loc) const;
    EXPORT void _GenerateTextureMipmap(GLuint texture, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName, const SrcLoc& src_loc) const;
    EXPORT void _GetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders, const SrcLoc& src_loc) const;
    EXPORT GLint _GetAttribLocation(GLuint program, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetBooleani_v(GLenum target, GLuint index, GLboolean * data, const SrcLoc& src_loc) const;
    EXPORT void _GetBooleanv(GLenum pname, GLboolean * data, const SrcLoc& src_loc) const;
    EXPORT void _GetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params, const SrcLoc& src_loc) const;
    EXPORT void _GetBufferParameteriv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetBufferPointerv(GLenum target, GLenum pname, void ** params, const SrcLoc& src_loc) const;
    EXPORT void _GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data, const SrcLoc& src_loc) const;
    EXPORT void _GetClipPlane(GLenum plane, GLdouble * equation, const SrcLoc& src_loc) const;
    EXPORT void _GetCompressedTexImage(GLenum target, GLint level, void * img, const SrcLoc& src_loc) const;
    EXPORT void _GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT GLuint _GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, const SrcLoc& src_loc) const;
    EXPORT void _GetDoublei_v(GLenum target, GLuint index, GLdouble * data, const SrcLoc& src_loc) const;
    EXPORT void _GetDoublev(GLenum pname, GLdouble * data, const SrcLoc& src_loc) const;
    EXPORT GLenum _GetError(const SrcLoc& src_loc) const;
    EXPORT void _GetFloati_v(GLenum target, GLuint index, GLfloat * data, const SrcLoc& src_loc) const;
    EXPORT void _GetFloatv(GLenum pname, GLfloat * data, const SrcLoc& src_loc) const;
    EXPORT GLint _GetFragDataIndex(GLuint program, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT GLint _GetFragDataLocation(GLuint program, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT GLenum _GetGraphicsResetStatus(const SrcLoc& src_loc) const;
    EXPORT void _GetInteger64i_v(GLenum target, GLuint index, GLint64 * data, const SrcLoc& src_loc) const;
    EXPORT void _GetInteger64v(GLenum pname, GLint64 * data, const SrcLoc& src_loc) const;
    EXPORT void _GetIntegeri_v(GLenum target, GLuint index, GLint * data, const SrcLoc& src_loc) const;
    EXPORT void _GetIntegerv(GLenum pname, GLint * data, const SrcLoc& src_loc) const;
    EXPORT void _GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params, const SrcLoc& src_loc) const;
    EXPORT void _GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetLightfv(GLenum light, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetLightiv(GLenum light, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetMapdv(GLenum target, GLenum query, GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _GetMapfv(GLenum target, GLenum query, GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _GetMapiv(GLenum target, GLenum query, GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _GetMaterialfv(GLenum face, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetMaterialiv(GLenum face, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetMultisamplefv(GLenum pname, GLuint index, GLfloat * val, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label, const SrcLoc& src_loc) const;
    EXPORT void _GetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label, const SrcLoc& src_loc) const;
    EXPORT void _GetPixelMapfv(GLenum map, GLfloat * values, const SrcLoc& src_loc) const;
    EXPORT void _GetPixelMapuiv(GLenum map, GLuint * values, const SrcLoc& src_loc) const;
    EXPORT void _GetPixelMapusv(GLenum map, GLushort * values, const SrcLoc& src_loc) const;
    EXPORT void _GetPointerv(GLenum pname, void ** params, const SrcLoc& src_loc) const;
    EXPORT void _GetPolygonStipple(GLubyte * mask, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT GLuint _GetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT GLint _GetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT GLint _GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values, const SrcLoc& src_loc) const;
    EXPORT void _GetProgramiv(GLuint program, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryObjectiv(GLuint id, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetQueryiv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog, const SrcLoc& src_loc) const;
    EXPORT void _GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision, const SrcLoc& src_loc) const;
    EXPORT void _GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source, const SrcLoc& src_loc) const;
    EXPORT void _GetShaderiv(GLuint shader, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT const GLubyte* _GetString(GLenum name, const SrcLoc& src_loc) const;
    EXPORT const GLubyte* _GetStringi(GLenum name, GLuint index, const SrcLoc& src_loc) const;
    EXPORT GLuint _GetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT GLint _GetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values, const SrcLoc& src_loc) const;
    EXPORT void _GetTexEnvfv(GLenum target, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexEnviv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexGendv(GLenum coord, GLenum pname, GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexGenfv(GLenum coord, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexGeniv(GLenum coord, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexParameterIiv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexParameterfv(GLenum target, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTexParameteriv(GLenum target, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureParameteriv(GLuint texture, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param, const SrcLoc& src_loc) const;
    EXPORT void _GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param, const SrcLoc& src_loc) const;
    EXPORT GLuint _GetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices, const SrcLoc& src_loc) const;
    EXPORT GLint _GetUniformLocation(GLuint program, const GLchar * name, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformdv(GLuint program, GLint location, GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformfv(GLuint program, GLint location, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformiv(GLuint program, GLint location, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetUniformuiv(GLuint program, GLint location, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribIiv(GLuint index, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetVertexAttribiv(GLuint index, GLenum pname, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table, const SrcLoc& src_loc) const;
    EXPORT void _GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image, const SrcLoc& src_loc) const;
    EXPORT void _GetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values, const SrcLoc& src_loc) const;
    EXPORT void _GetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _GetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _GetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _GetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values, const SrcLoc& src_loc) const;
    EXPORT void _GetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat * values, const SrcLoc& src_loc) const;
    EXPORT void _GetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint * values, const SrcLoc& src_loc) const;
    EXPORT void _GetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort * values, const SrcLoc& src_loc) const;
    EXPORT void _GetnPolygonStipple(GLsizei bufSize, GLubyte * pattern, const SrcLoc& src_loc) const;
    EXPORT void _GetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span, const SrcLoc& src_loc) const;
    EXPORT void _GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _Hint(GLenum target, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _IndexMask(GLuint mask, const SrcLoc& src_loc) const;
    EXPORT void _IndexPointer(GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _Indexd(GLdouble c, const SrcLoc& src_loc) const;
    EXPORT void _Indexdv(const GLdouble * c, const SrcLoc& src_loc) const;
    EXPORT void _Indexf(GLfloat c, const SrcLoc& src_loc) const;
    EXPORT void _Indexfv(const GLfloat * c, const SrcLoc& src_loc) const;
    EXPORT void _Indexi(GLint c, const SrcLoc& src_loc) const;
    EXPORT void _Indexiv(const GLint * c, const SrcLoc& src_loc) const;
    EXPORT void _Indexs(GLshort c, const SrcLoc& src_loc) const;
    EXPORT void _Indexsv(const GLshort * c, const SrcLoc& src_loc) const;
    EXPORT void _Indexub(GLubyte c, const SrcLoc& src_loc) const;
    EXPORT void _Indexubv(const GLubyte * c, const SrcLoc& src_loc) const;
    EXPORT void _InitNames(const SrcLoc& src_loc) const;
    EXPORT void _InterleavedArrays(GLenum format, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateBufferData(GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateTexImage(GLuint texture, GLint level, const SrcLoc& src_loc) const;
    EXPORT void _InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsBuffer(GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsEnabled(GLenum cap, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsEnabledi(GLenum target, GLuint index, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsFramebuffer(GLuint framebuffer, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsList(GLuint list, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsProgram(GLuint program, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsQuery(GLuint id, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsRenderbuffer(GLuint renderbuffer, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsSampler(GLuint sampler, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsShader(GLuint shader, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsSync(GLsync sync, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsTexture(GLuint texture, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsTransformFeedback(GLuint id, const SrcLoc& src_loc) const;
    EXPORT GLboolean _IsVertexArray(GLuint array, const SrcLoc& src_loc) const;
    EXPORT void _LightModelf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _LightModelfv(GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _LightModeli(GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _LightModeliv(GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _Lightf(GLenum light, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _Lightfv(GLenum light, GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _Lighti(GLenum light, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _Lightiv(GLenum light, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _LineStipple(GLint factor, GLushort pattern, const SrcLoc& src_loc) const;
    EXPORT void _LineWidth(GLfloat width, const SrcLoc& src_loc) const;
    EXPORT void _LinkProgram(GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _ListBase(GLuint base, const SrcLoc& src_loc) const;
    EXPORT void _LoadIdentity(const SrcLoc& src_loc) const;
    EXPORT void _LoadMatrixd(const GLdouble * m, const SrcLoc& src_loc) const;
    EXPORT void _LoadMatrixf(const GLfloat * m, const SrcLoc& src_loc) const;
    EXPORT void _LoadName(GLuint name, const SrcLoc& src_loc) const;
    EXPORT void _LoadTransposeMatrixd(const GLdouble * m, const SrcLoc& src_loc) const;
    EXPORT void _LoadTransposeMatrixf(const GLfloat * m, const SrcLoc& src_loc) const;
    EXPORT void _LogicOp(GLenum opcode, const SrcLoc& src_loc) const;
    EXPORT void _Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points, const SrcLoc& src_loc) const;
    EXPORT void _Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points, const SrcLoc& src_loc) const;
    EXPORT void _Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points, const SrcLoc& src_loc) const;
    EXPORT void _Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points, const SrcLoc& src_loc) const;
    EXPORT void* _MapBuffer (GLenum target, GLenum access, const SrcLoc& src_loc) const;
    EXPORT void* _MapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, const SrcLoc& src_loc) const;
    EXPORT void _MapGrid1d(GLint un, GLdouble u1, GLdouble u2, const SrcLoc& src_loc) const;
    EXPORT void _MapGrid1f(GLint un, GLfloat u1, GLfloat u2, const SrcLoc& src_loc) const;
    EXPORT void _MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2, const SrcLoc& src_loc) const;
    EXPORT void _MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const;
    EXPORT void* _MapNamedBuffer (GLuint buffer, GLenum access, const SrcLoc& src_loc) const;
    EXPORT void* _MapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, const SrcLoc& src_loc) const;
    EXPORT void _Materialf(GLenum face, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _Materialfv(GLenum face, GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _Materiali(GLenum face, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _Materialiv(GLenum face, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _MatrixMode(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _MemoryBarrier(GLbitfield barriers, const SrcLoc& src_loc) const;
    EXPORT void _MemoryBarrierByRegion(GLbitfield barriers, const SrcLoc& src_loc) const;
    EXPORT void _MinSampleShading(GLfloat value, const SrcLoc& src_loc) const;
    EXPORT void _MultMatrixd(const GLdouble * m, const SrcLoc& src_loc) const;
    EXPORT void _MultMatrixf(const GLfloat * m, const SrcLoc& src_loc) const;
    EXPORT void _MultTransposeMatrixd(const GLdouble * m, const SrcLoc& src_loc) const;
    EXPORT void _MultTransposeMatrixf(const GLfloat * m, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawArraysIndirectCount(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1d(GLenum target, GLdouble s, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1dv(GLenum target, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1f(GLenum target, GLfloat s, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1fv(GLenum target, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1i(GLenum target, GLint s, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1iv(GLenum target, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1s(GLenum target, GLshort s, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord1sv(GLenum target, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2dv(GLenum target, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2fv(GLenum target, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2i(GLenum target, GLint s, GLint t, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2iv(GLenum target, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2s(GLenum target, GLshort s, GLshort t, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord2sv(GLenum target, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3dv(GLenum target, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3fv(GLenum target, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3iv(GLenum target, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord3sv(GLenum target, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4dv(GLenum target, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4fv(GLenum target, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4iv(GLenum target, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoord4sv(GLenum target, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _MultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _NamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage, const SrcLoc& src_loc) const;
    EXPORT void _NamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags, const SrcLoc& src_loc) const;
    EXPORT void _NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum * bufs, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const;
    EXPORT void _NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const;
    EXPORT void _NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _NewList(GLuint list, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _Normal3b(GLbyte nx, GLbyte ny, GLbyte nz, const SrcLoc& src_loc) const;
    EXPORT void _Normal3bv(const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _Normal3d(GLdouble nx, GLdouble ny, GLdouble nz, const SrcLoc& src_loc) const;
    EXPORT void _Normal3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Normal3f(GLfloat nx, GLfloat ny, GLfloat nz, const SrcLoc& src_loc) const;
    EXPORT void _Normal3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Normal3i(GLint nx, GLint ny, GLint nz, const SrcLoc& src_loc) const;
    EXPORT void _Normal3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Normal3s(GLshort nx, GLshort ny, GLshort nz, const SrcLoc& src_loc) const;
    EXPORT void _Normal3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _NormalP3ui(GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _NormalP3uiv(GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _NormalPointer(GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _ObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label, const SrcLoc& src_loc) const;
    EXPORT void _ObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label, const SrcLoc& src_loc) const;
    EXPORT void _Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar, const SrcLoc& src_loc) const;
    EXPORT void _PassThrough(GLfloat token, const SrcLoc& src_loc) const;
    EXPORT void _PatchParameterfv(GLenum pname, const GLfloat * values, const SrcLoc& src_loc) const;
    EXPORT void _PatchParameteri(GLenum pname, GLint value, const SrcLoc& src_loc) const;
    EXPORT void _PauseTransformFeedback(const SrcLoc& src_loc) const;
    EXPORT void _PixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values, const SrcLoc& src_loc) const;
    EXPORT void _PixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values, const SrcLoc& src_loc) const;
    EXPORT void _PixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values, const SrcLoc& src_loc) const;
    EXPORT void _PixelStoref(GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _PixelStorei(GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _PixelTransferf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _PixelTransferi(GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _PixelZoom(GLfloat xfactor, GLfloat yfactor, const SrcLoc& src_loc) const;
    EXPORT void _PointParameterf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _PointParameterfv(GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _PointParameteri(GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _PointParameteriv(GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _PointSize(GLfloat size, const SrcLoc& src_loc) const;
    EXPORT void _PolygonMode(GLenum face, GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _PolygonOffset(GLfloat factor, GLfloat units, const SrcLoc& src_loc) const;
    EXPORT void _PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, const SrcLoc& src_loc) const;
    EXPORT void _PolygonStipple(const GLubyte * mask, const SrcLoc& src_loc) const;
    EXPORT void _PopAttrib(const SrcLoc& src_loc) const;
    EXPORT void _PopClientAttrib(const SrcLoc& src_loc) const;
    EXPORT void _PopDebugGroup(const SrcLoc& src_loc) const;
    EXPORT void _PopMatrix(const SrcLoc& src_loc) const;
    EXPORT void _PopName(const SrcLoc& src_loc) const;
    EXPORT void _PrimitiveRestartIndex(GLuint index, const SrcLoc& src_loc) const;
    EXPORT void _PrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities, const SrcLoc& src_loc) const;
    EXPORT void _ProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length, const SrcLoc& src_loc) const;
    EXPORT void _ProgramParameteri(GLuint program, GLenum pname, GLint value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1d(GLuint program, GLint location, GLdouble v0, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1f(GLuint program, GLint location, GLfloat v0, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1i(GLuint program, GLint location, GLint v0, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1ui(GLuint program, GLint location, GLuint v0, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _ProvokingVertex(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _PushAttrib(GLbitfield mask, const SrcLoc& src_loc) const;
    EXPORT void _PushClientAttrib(GLbitfield mask, const SrcLoc& src_loc) const;
    EXPORT void _PushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message, const SrcLoc& src_loc) const;
    EXPORT void _PushMatrix(const SrcLoc& src_loc) const;
    EXPORT void _PushName(GLuint name, const SrcLoc& src_loc) const;
    EXPORT void _QueryCounter(GLuint id, GLenum target, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2d(GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2f(GLfloat x, GLfloat y, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2i(GLint x, GLint y, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2s(GLshort x, GLshort y, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos2sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3d(GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3f(GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3i(GLint x, GLint y, GLint z, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3s(GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4i(GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc) const;
    EXPORT void _RasterPos4sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _ReadBuffer(GLenum src, const SrcLoc& src_loc) const;
    EXPORT void _ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data, const SrcLoc& src_loc) const;
    EXPORT void _Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, const SrcLoc& src_loc) const;
    EXPORT void _Rectdv(const GLdouble * v1, const GLdouble * v2, const SrcLoc& src_loc) const;
    EXPORT void _Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, const SrcLoc& src_loc) const;
    EXPORT void _Rectfv(const GLfloat * v1, const GLfloat * v2, const SrcLoc& src_loc) const;
    EXPORT void _Recti(GLint x1, GLint y1, GLint x2, GLint y2, const SrcLoc& src_loc) const;
    EXPORT void _Rectiv(const GLint * v1, const GLint * v2, const SrcLoc& src_loc) const;
    EXPORT void _Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2, const SrcLoc& src_loc) const;
    EXPORT void _Rectsv(const GLshort * v1, const GLshort * v2, const SrcLoc& src_loc) const;
    EXPORT void _ReleaseShaderCompiler(const SrcLoc& src_loc) const;
    EXPORT GLint _RenderMode(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _ResumeTransformFeedback(const SrcLoc& src_loc) const;
    EXPORT void _Rotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _SampleCoverage(GLfloat value, GLboolean invert, const SrcLoc& src_loc) const;
    EXPORT void _SampleMaski(GLuint maskNumber, GLbitfield mask, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameteri(GLuint sampler, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _SamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _Scaled(GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _Scalef(GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _Scissor(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _ScissorArrayv(GLuint first, GLsizei count, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _ScissorIndexedv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3bv(const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3i(GLint red, GLint green, GLint blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3s(GLshort red, GLshort green, GLshort blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3ubv(const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3ui(GLuint red, GLuint green, GLuint blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3uiv(const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3us(GLushort red, GLushort green, GLushort blue, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColor3usv(const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColorP3ui(GLenum type, GLuint color, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColorP3uiv(GLenum type, const GLuint * color, const SrcLoc& src_loc) const;
    EXPORT void _SecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _SelectBuffer(GLsizei size, GLuint * buffer, const SrcLoc& src_loc) const;
    EXPORT void _ShadeModel(GLenum mode, const SrcLoc& src_loc) const;
    EXPORT void _ShaderBinary(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length, const SrcLoc& src_loc) const;
    EXPORT void _ShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length, const SrcLoc& src_loc) const;
    EXPORT void _ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, const SrcLoc& src_loc) const;
    EXPORT void _SpecializeShader(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue, const SrcLoc& src_loc) const;
    EXPORT void _StencilFunc(GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const;
    EXPORT void _StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const;
    EXPORT void _StencilMask(GLuint mask, const SrcLoc& src_loc) const;
    EXPORT void _StencilMaskSeparate(GLenum face, GLuint mask, const SrcLoc& src_loc) const;
    EXPORT void _StencilOp(GLenum fail, GLenum zfail, GLenum zpass, const SrcLoc& src_loc) const;
    EXPORT void _StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, const SrcLoc& src_loc) const;
    EXPORT void _TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1d(GLdouble s, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1f(GLfloat s, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1i(GLint s, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1s(GLshort s, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord1sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2d(GLdouble s, GLdouble t, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2f(GLfloat s, GLfloat t, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2i(GLint s, GLint t, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2s(GLshort s, GLshort t, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord2sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3d(GLdouble s, GLdouble t, GLdouble r, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3f(GLfloat s, GLfloat t, GLfloat r, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3i(GLint s, GLint t, GLint r, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3s(GLshort s, GLshort t, GLshort r, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4i(GLint s, GLint t, GLint r, GLint q, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q, const SrcLoc& src_loc) const;
    EXPORT void _TexCoord4sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP1ui(GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP1uiv(GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP2ui(GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP2uiv(GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP3ui(GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP3uiv(GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP4ui(GLenum type, GLuint coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordP4uiv(GLenum type, const GLuint * coords, const SrcLoc& src_loc) const;
    EXPORT void _TexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _TexEnvf(GLenum target, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _TexEnvfv(GLenum target, GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _TexEnvi(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _TexEnviv(GLenum target, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _TexGend(GLenum coord, GLenum pname, GLdouble param, const SrcLoc& src_loc) const;
    EXPORT void _TexGendv(GLenum coord, GLenum pname, const GLdouble * params, const SrcLoc& src_loc) const;
    EXPORT void _TexGenf(GLenum coord, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _TexGenfv(GLenum coord, GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _TexGeni(GLenum coord, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _TexGeniv(GLenum coord, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TexParameterIiv(GLenum target, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _TexParameterIuiv(GLenum target, GLenum pname, const GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _TexParameterf(GLenum target, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _TexParameterfv(GLenum target, GLenum pname, const GLfloat * params, const SrcLoc& src_loc) const;
    EXPORT void _TexParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _TexParameteriv(GLenum target, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const;
    EXPORT void _TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const;
    EXPORT void _TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TextureBarrier(const SrcLoc& src_loc) const;
    EXPORT void _TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameterIiv(GLuint texture, GLenum pname, const GLint * params, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameterIuiv(GLuint texture, GLenum pname, const GLuint * params, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameterf(GLuint texture, GLenum pname, GLfloat param, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameterfv(GLuint texture, GLenum pname, const GLfloat * param, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameteri(GLuint texture, GLenum pname, GLint param, const SrcLoc& src_loc) const;
    EXPORT void _TextureParameteriv(GLuint texture, GLenum pname, const GLint * param, const SrcLoc& src_loc) const;
    EXPORT void _TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const;
    EXPORT void _TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const;
    EXPORT void _TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const;
    EXPORT void _TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels, const SrcLoc& src_loc) const;
    EXPORT void _TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, const SrcLoc& src_loc) const;
    EXPORT void _TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const;
    EXPORT void _TransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode, const SrcLoc& src_loc) const;
    EXPORT void _Translated(GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _Translatef(GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1d(GLint location, GLdouble x, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1dv(GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1f(GLint location, GLfloat v0, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1fv(GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1i(GLint location, GLint v0, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1iv(GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1ui(GLint location, GLuint v0, const SrcLoc& src_loc) const;
    EXPORT void _Uniform1uiv(GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2d(GLint location, GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2dv(GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2f(GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2fv(GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2i(GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2iv(GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2ui(GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const;
    EXPORT void _Uniform2uiv(GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3dv(GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3fv(GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3iv(GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const;
    EXPORT void _Uniform3uiv(GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4dv(GLint location, GLsizei count, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4fv(GLint location, GLsizei count, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4iv(GLint location, GLsizei count, const GLint * value, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const;
    EXPORT void _Uniform4uiv(GLint location, GLsizei count, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value, const SrcLoc& src_loc) const;
    EXPORT void _UniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint * indices, const SrcLoc& src_loc) const;
    EXPORT GLboolean _UnmapBuffer(GLenum target, const SrcLoc& src_loc) const;
    EXPORT GLboolean _UnmapNamedBuffer(GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _UseProgram(GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _ValidateProgram(GLuint program, const SrcLoc& src_loc) const;
    EXPORT void _ValidateProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2d(GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2f(GLfloat x, GLfloat y, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2i(GLint x, GLint y, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2s(GLshort x, GLshort y, const SrcLoc& src_loc) const;
    EXPORT void _Vertex2sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3d(GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3f(GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3i(GLint x, GLint y, GLint z, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3s(GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const;
    EXPORT void _Vertex3sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4i(GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc) const;
    EXPORT void _Vertex4sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const;
    EXPORT void _VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1f(GLuint index, GLfloat x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1fv(GLuint index, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1s(GLuint index, GLshort x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib1sv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2fv(GLuint index, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2s(GLuint index, GLshort x, GLshort y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib2sv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3fv(GLuint index, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib3sv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nbv(GLuint index, const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Niv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nsv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nubv(GLuint index, const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nuiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4Nusv(GLuint index, const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4bv(GLuint index, const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4fv(GLuint index, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4iv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4sv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4ubv(GLuint index, const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4uiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttrib4usv(GLuint index, const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribBinding(GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribDivisor(GLuint index, GLuint divisor, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI1i(GLuint index, GLint x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI1iv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI1ui(GLuint index, GLuint x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI1uiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI2i(GLuint index, GLint x, GLint y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI2iv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI2ui(GLuint index, GLuint x, GLuint y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI2uiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI3iv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI3uiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4bv(GLuint index, const GLbyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4iv(GLuint index, const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4sv(GLuint index, const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4ubv(GLuint index, const GLubyte * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4uiv(GLuint index, const GLuint * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribI4usv(GLuint index, const GLushort * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL1dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL2dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL3dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribL4dv(GLuint index, const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _VertexBindingDivisor(GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const;
    EXPORT void _VertexP2ui(GLenum type, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexP2uiv(GLenum type, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexP3ui(GLenum type, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexP3uiv(GLenum type, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexP4ui(GLenum type, GLuint value, const SrcLoc& src_loc) const;
    EXPORT void _VertexP4uiv(GLenum type, const GLuint * value, const SrcLoc& src_loc) const;
    EXPORT void _VertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer, const SrcLoc& src_loc) const;
    EXPORT void _Viewport(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const;
    EXPORT void _ViewportArrayv(GLuint first, GLsizei count, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, const SrcLoc& src_loc) const;
    EXPORT void _ViewportIndexedfv(GLuint index, const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2d(GLdouble x, GLdouble y, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2f(GLfloat x, GLfloat y, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2i(GLint x, GLint y, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2s(GLshort x, GLshort y, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos2sv(const GLshort * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3d(GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3dv(const GLdouble * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3f(GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3fv(const GLfloat * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3i(GLint x, GLint y, GLint z, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3iv(const GLint * v, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3s(GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const;
    EXPORT void _WindowPos3sv(const GLshort * v, const SrcLoc& src_loc) const;


};

} // namespace glwpp