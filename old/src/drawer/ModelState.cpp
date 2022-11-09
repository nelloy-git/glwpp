#include "glwpp/drawer/ModelState.hpp"

using namespace glwpp;
using namespace glwpp::utils;

ModelState::ModelState(const sptr<Context>& ctx,
                       const Val<const SrcLoc>& src_loc) :
    node_transforms(wctx, 4, gl::BufferUsage::DynamicDraw, std::nullopt, src_loc) {
}

ModelState::~ModelState(){
}

void ModelState::apply(){
    
}