#pragma once

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/enums/VertexArrayAttribParam.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

class VertexArray : public Object {
public:
    static sptr<VertexArray> make(const sptr<Context>& ctx,
                                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool getParamInt(const Val<Int>& dst, const Val<const UInt>& index, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getParamInt64(const Val<Int64>& dst, const Val<const UInt>& index, const Val<const Enum>& param,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    
    bool isAttribEnabled(const Val<bool>& dst, const Val<const UInt>& index, 
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribSize(const Val<Int>& dst, const Val<const UInt>& index, 
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribStride(const Val<Int>& dst, const Val<const UInt>& index, 
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribType(const Val<DataType>& dst, const Val<const UInt>& index, 
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isAttribNormalized(const Val<bool>& dst, const Val<const UInt>& index, 
                            const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isAttribInteger(const Val<bool>& dst, const Val<const UInt>& index, 
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool isAttribLong(const Val<bool>& dst, const Val<const UInt>& index, 
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribDivisor(const Val<Int>& dst, const Val<const UInt>& index, 
                          const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribRelativeOffset(const Val<Int>& dst, const Val<const UInt>& index, 
                                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getAttribBindingOffset(const Val<Int64>& dst, const Val<const UInt>& index, 
                                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    
    bool enableAttrib(const Val<const UInt>& index, 
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool disableAttrib(const Val<const UInt>& index, 
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool setAttribBinding(const Val<const UInt>& index, const Val<const UInt>& binding, 
                          const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool setAttribFormat(const Val<const UInt>& index, const Val<const Int>& size,
                         const Val<const DataType>& type, const Val<const bool>& normalized,
                         const Val<const UInt>& relative_offset, 
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool setBindingDivisor(const Val<const UInt>& binding, const Val<const UInt>& divisor, 
                           const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool setElementBuffer(const Val<const Buffer>& buffer, 
                          const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool setVertexBuffer(const Val<const UInt>& binding, const Val<const Buffer>& buffer,
                         const Val<const IntPtr>& offset, const Val<const Sizei>& stride, 
                         const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool draw(const Val<const DrawMode>& mode, const Val<const Sizei>& vertex_count,
              const Val<const DataType>& index_type, const Val<const Sizei>& instances, 
              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
protected:
    VertexArray(const sptr<Context>& ctx,
                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

private:
    // Hide parent's make
    using Object::make;

    static void _initer(const Val<UInt>& dst, const Val<const utils::SrcLoc>& src_loc);
    static void _deleter(const UInt& id);
};
    
} // namespace glwpp::gl
