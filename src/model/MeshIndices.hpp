#pragma once

#include "gl_object/Buffer.hpp"

struct aiFace;

namespace glwpp {

class MeshIndices : public CtxObj<MeshIndices> {
public:
    enum class Type {
        UInt
    };
    
    static Value<MeshIndices> Make(Valuable<Context&> auto&& ctx,
                                   Valuable<const unsigned int&> auto&& mNumFaces,
                                   Valuable<const aiFace*> auto&& ai_faces,
                                   Valuable<const SrcLoc&> auto&& src_loc){
        return Value<MeshIndices>::Make(new MeshIndices(GetValuable(ctx), GetValuable(mNumFaces), GetValuable(ai_faces), GetValuable(src_loc)));
    }
    virtual ~MeshIndices();
    
    const Type type;
    const Value<GL::Buffer> buffer;

private:
    EXPORT MeshIndices(Context& ctx, const unsigned int& mNumFaces, const aiFace* ai_faces, const SrcLoc& src_loc);

};

} // namespace glwpp