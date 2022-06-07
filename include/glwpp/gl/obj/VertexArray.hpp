#pragma once

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

class VertexArray : public Object {
public:
    VertexArray(const wptr<Context>& wctx,
                const Val<const SrcLoc> src_loc = SrcLoc{});

    bool getParamInt(const Val<Int> dst, const Val<const UInt>& index, const Val<const Enum> param,
                     const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getParamInt64(const Val<Int64> dst, const Val<const UInt>& index, const Val<const Enum> param,
                       const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    
    bool isAttribEnabled(const Val<bool>& dst, const Val<const UInt>& index, 
                         const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribSize(const Val<Int>& dst, const Val<const UInt>& index, 
                       const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribStride(const Val<Int>& dst, const Val<const UInt>& index, 
                         const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribType(const Val<DataType>& dst, const Val<const UInt>& index, 
                       const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool isAttribNormalized(const Val<bool>& dst, const Val<const UInt>& index, 
                            const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool isAttribInteger(const Val<bool>& dst, const Val<const UInt>& index, 
                         const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool isAttribLong(const Val<bool>& dst, const Val<const UInt>& index, 
                      const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribDivisor(const Val<Int>& dst, const Val<const UInt>& index, 
                          const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribRelativeOffset(const Val<Int>& dst, const Val<const UInt>& index, 
                                 const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    bool getAttribBindingOffset(const Val<Int64>& dst, const Val<const UInt>& index, 
                                const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;
    
    bool enableAttrib(const Val<const UInt>& index, 
                      const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);
    bool disableAttrib(const Val<const UInt>& index, 
                       const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);
    bool setAttribBinding(const Val<const UInt>& index, const Val<const UInt>& binding, 
                          const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);
    bool setAttribFormat(const Val<const UInt>& index, const Val<const Int>& size,
                         const Val<const DataType>& type, const Val<const bool>& normalized,
                         const Val<const UInt>& relative_offset, 
                         const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);
    bool setBindingDivisor(const Val<const UInt>& binding, const Val<const UInt>& divisor, 
                           const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);

    bool setElementBuffer(const Buffer& buffer, 
                          const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);
    bool setVertexBuffer(const Val<const UInt>& binding, const Buffer& buffer,
                         const Val<const IntPtr>& offset, const Val<const Sizei>& stride, 
                         const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true);

    bool draw(const Val<const DrawMode>& mode, const Val<const Sizei>& vertex_count,
              const Val<const DataType>& index_type, const Val<const Sizei>& instances, 
              const Val<const SrcLoc> src_loc = SrcLoc{}, bool check_ctx = true) const;

private:
    static void _initer(UInt& dst);
    static void _deleter(const UInt& id);
};
    
} // namespace glwpp::gl
