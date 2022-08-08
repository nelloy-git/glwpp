#include "glwpp/ctx/ContextObject.hpp"

using namespace glwpp;
    
std::atomic<std::function<void(const std::string&, const utils::SrcLoc&)>*> ContextObject::debug_function = nullptr;

sptr<ContextObject> ContextObject::make(const sptr<Context>& ctx){
    return sptr<ContextObject>(new ContextObject(ctx));
};

ContextObject::ContextObject(const sptr<Context>& ctx) : 
    _ctx_thread_id(ctx->getThreadId()),
    _wctx(ctx){
}

ContextObject::~ContextObject(){
}

const wptr<Context>& ContextObject::getContext() const {
    return _wctx;
};

bool ContextObject::isContextThread() const {
    return _ctx_thread_id == std::this_thread::get_id();
}

void ContextObject::debug(const std::string& msg, const utils::SrcLoc& src_loc){
#ifdef GLWPP_DEBUG
    auto debug_func = debug_function.load();
    if (debug_func){
        (*debug_func)(msg, src_loc);
        return;
    }

    std::cout << "==========" << std::endl;
    std::cout << "Debug: " << msg.c_str() << std::endl << src_loc.to_string() << std::endl;
    std::cout << "==========" << std::endl;
#endif
};