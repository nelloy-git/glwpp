#ifdef WIN32
#include <vld.h>
#endif

#include "Context.hpp"
#include "gl/InterfaceGl.hpp"

int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto ctx = std::make_shared<glwpp::Context>(ctx_params);

    

    auto id = std::make_shared<unsigned int[]>(1);
    // ctx->GL().CreateBuffers(std::make_shared<int>(1), id);
    
    ctx->getOnStartEvent().addActionQueued([](glwpp::Context* ctx, const glwpp::Context::ms& us){
        std::cout << us.count() << std::endl;
        return true;
    });

    while(true){
        ctx->run().wait();
    }
}