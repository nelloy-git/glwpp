#ifdef WIN32
#include <vld.h>
#endif

#include "Context.hpp"
#include "gl_object/Buffer.hpp"

int main(int argc, char **argv){
    glwpp::Context::Parameters ctx_params;
    ctx_params.width = 640;
    ctx_params.height = 480;
    ctx_params.fps = 60;
    ctx_params.title = "Noname";

    auto ctx = std::make_shared<glwpp::Context>(ctx_params);

    glwpp::GL::Buffer buffer(ctx);
    buffer.setData(4, glwpp::GL::Value<void>(4), ctx->gl().DYNAMIC_DRAW());
    buffer.map(ctx->gl().READ_WRITE());
    auto is_mapped = buffer.isMapped();
    
    ctx->getOnRunEvent().addActionQueued([ctx](glwpp::Context*, const glwpp::Context::ms& us){
        glwpp::GL::Buffer buffer(ctx);
        std::cout << "ID inner: " << *buffer.id() << std::endl;
        // std::cout << us.count() << std::endl;
        return true;
    });

    bool done = false;
    while(true){
        ctx->run().wait();
        if (!done){
            std::cout << "ID: " << *buffer.id() << std::endl;
            std::cout << (int)*is_mapped << std::endl;
            done = true;
        }

        // std::cout << *buffer.id() << std::endl;
    }
}