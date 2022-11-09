#ifdef WIN32
#include <vld.h>
#endif

// #include <node.h>

// #include <iostream>
// #include <memory>
// #include <chrono>
// #include <filesystem>

// #include "glm/gtx/string_cast.hpp"

// #include "glwpp/utils/File.hpp"

// #include "glwpp/ctx/Context.hpp"
// #include "glwpp/Drawer.hpp"
// #include "glwpp/Model.hpp"

// #include "glwpp/gl/obj/Array.hpp"

// #include "glad/gl.h"

// using namespace glwpp;
// using namespace glwpp::utils;

// void pushClear(std::shared_ptr<Context>& ctx){
//     ctx->onRun.push<[]{return true;}>([](){
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//     });
// }

// void pushKeyPrinter(std::shared_ptr<Context>& ctx, std::atomic<bool>& is_running){
//     ctx->onKey.push<[]{return true;}>([&is_running](const Key& key){
//         std::cout << "Key: " << char(key) << std::endl;
//         if (key == Key::Escape){
//             is_running = false;
//         }
//     });
// }

// static void pushTimePrinter(std::shared_ptr<Context>& ctx){
//     ctx->onRun.push<[]{return true;}>([](const std::chrono::microseconds& time){
//         static long long total_time = 0;
//         static int counter = 0;

//         total_time += time.count();
//         ++counter;

//         if (total_time > 1000000){
//             std::cout << "Time(us): " << (double)total_time / counter << std::endl;
//             total_time = 0;
//             counter = 0;
//         }
//     });
// }

// sptr<Context> initContext(std::atomic<bool>& is_running){
//     Context::Parameters ctx_params;
//     ctx_params.gl_major_ver = 4;
//     ctx_params.gl_minor_ver = 6;
//     ctx_params.width = 640;
//     ctx_params.height = 480;
//     ctx_params.fps = 60;
//     ctx_params.title = "Noname";

//     auto ctx = make_sptr<Context>(ctx_params);
//     pushClear(ctx);
//     pushKeyPrinter(ctx, is_running);
//     pushTimePrinter(ctx);
//     return ctx;
// }

// std::string loadTextFile(const std::string& path){
//     std::ifstream t(path);
//     std::stringstream buffer;
//     buffer << t.rdbuf();
//     return buffer.str();
// }

// sptr<Drawer> initDrawer(std::shared_ptr<Context> ctx){
//     auto v_shader = gl::Shader::make(ctx, gl::ShaderType::Vertex);
//     v_shader->setSource(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.vs"));
//     v_shader->compile();
//     ctx->onRun.push([v_shader](){
//         Val<bool> compiled(false);
//         v_shader->isCompiled(compiled);
//         if (!*compiled){
//             Val<std::string> log("");
//             v_shader->getInfoLog(log);
//             std::cout << "v_shader failed: " << log->c_str() << std::endl;
//         }
//     });
    
//     auto f_shader = gl::Shader::make(ctx, gl::ShaderType::Fragment);
//     f_shader->setSource(loadTextFile("D:\\projects\\Engine\\3rdparty\\glwpp\\shaders\\vertex_3d.fs"));
//     f_shader->compile();
//     ctx->onRun.push([f_shader](){
//         Val<bool> compiled(false);
//         f_shader->isCompiled(compiled);
//         if (!*compiled){
//             Val<std::string> log("");
//             f_shader->getInfoLog(log);
//             std::cout << "f_shader failed: " << log->c_str() << std::endl;
//         }
//     });

//     auto drawer = Drawer::make(ctx);
//     drawer->attach(*v_shader);
//     drawer->attach(*f_shader);
//     drawer->link();
//     ctx->onRun.push([drawer](){
//         Val<bool> linked(false);
//         drawer->isLinked(linked);
//         if (!*linked){
//             Val<std::string> log("");
//             drawer->getInfoLog(log);
//             std::cout << "drawer failed: " << log->c_str() << std::endl;
//         }
//     });
//     drawer->use();

//     Drawer::MeshAttributeBindings attr;
//     attr[model::MeshAttribute::Position] = "vPos";
//     drawer->bindMeshAttributes(attr);

//     Drawer::UniformBlockBindings unif;
//     unif[DrawerUniformBlock::Camera] = "Camera";
//     unif[DrawerUniformBlock::MeshTransform] = "MeshTransform";
//     drawer->bindUniformBlocks(unif);

//     return drawer;
// }

// sptr<Model> initModel(std::shared_ptr<Context> ctx, const std::string& path){
//     model::MeshVertexConfig vert_config;
//     vert_config.enable(model::MeshAttribute::Position, true);
//     vert_config.setCompression(model::MeshAttribute::Position, 0);
//     vert_config.setSize(model::MeshAttribute::Position, model::MeshAttributeSize::Vec3);

//     auto model =  make_sptr<Model>(ctx, path, vert_config);
//     if (model->getError()){
//         std::cout << "model failed: " << model->getError().value().c_str() << std::endl;
//     }

//     return model;
// }

// void enableCameraMovement(std::shared_ptr<Context> ctx, sptr<Drawer> drawer){
//     static const float vel = float(0.1);
//     ctx->onKey.push<[]{return true;}>([drawer](const Key& key){
//         switch (key){
//         case Key::W: drawer->getCamera().pos += glm::vec3{vel, 0, 0}; break;
//         case Key::S: drawer->getCamera().pos += glm::vec3{-vel, 0, 0}; break;
//         case Key::A: drawer->getCamera().pos += glm::vec3{0, 0, -vel}; break;
//         case Key::D: drawer->getCamera().pos += glm::vec3{0, 0,  vel}; break;
//         case Key::LeftControl: drawer->getCamera().pos += glm::vec3{0, -vel, 0}; break;
//         case Key::Space: drawer->getCamera().pos += glm::vec3{0, vel, 0}; break;
        
//         default: break;
//         }

//         drawer->getCamera().apply();
//         std::cout << "Camera {" << drawer->getCamera().pos.x << ", "
//                                 << drawer->getCamera().pos.y << ", "
//                                 << drawer->getCamera().pos.z << "}" << std::endl;
//     });
// }

// void draw(const VertexArray& vao){
//     gl::UInt id;
//     vao.getId(&id);

//     glBindVertexArray(id);
//     // glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
//     glDrawElementsInstanced(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0, 1);

//     gl::Enum err = glGetError();
//     while (err != GL_NO_ERROR){
//         std::string err_name;
//         switch (err){
//             case GL_INVALID_ENUM: err_name = "GL_INVALID_ENUM";
//             case GL_INVALID_VALUE: err_name = "GL_INVALID_VALUE";
//             case GL_INVALID_OPERATION: err_name = "GL_INVALID_OPERATION";
//             case GL_STACK_OVERFLOW: err_name = "GL_STACK_OVERFLOW";
//             case GL_STACK_UNDERFLOW: err_name = "GL_STACK_UNDERFLOW";
//             case GL_OUT_OF_MEMORY: err_name = "GL_OUT_OF_MEMORY";
//             case GL_INVALID_FRAMEBUFFER_OPERATION: err_name = "GL_INVALID_FRAMEBUFFER_OPERATION";
//             case GL_CONTEXT_LOST: err_name = "GL_CONTEXT_LOST";
//             default: err_name = "UNKNOWN";
//         }

//         std::cout << " Err: " << err_name << "(" << err << ")" << std::endl;
//         err = glGetError();
//     }
// }

// #include "glwpp/gl/Name.hpp"

int main(int argc, char **argv){
    // std::atomic<bool> is_running = true;
    // auto ctx = initContext(is_running);
    // auto drawer = initDrawer(ctx);

    // auto model = initModel(ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\3rdparty\\assimp\\test\\models\\BLEND\\HUMAN.blend");
    // auto model = initModel(ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\3rdparty\\assimp\\test\\models\\OBJ\\spider.obj");
    // auto model = initModel(ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\3rdparty\\assimp\\test\\models\\glTF2\\textureTransform\\TextureTransformTest.gltf");
    // auto model = initModel(ctx, "D:\\projects\\Engine\\3rdparty\\glwpp\\test\\models\\book\\scene.gltf");


    // auto name = gl::Object::make(ctx, [](Val<gl::UInt>){}, [](gl::UInt){});
    

    // enableCameraMovement(ctx, drawer);
    // drawer->getCamera().pos = {-1, -1, 0};
    // drawer->getCamera().far_z = 10000;
    // drawer->getCamera().apply();

    // ctx->onRun.push<[]{return true;}>([=](){
    //     drawer->getMeshTransform().transforms.clear();
    //     drawer->getMeshTransform().transforms.reserve(model->getNodes().size());

    //     std::cout << "Nodes: " << model->getNodes().size() << std::endl;
    //     for (unsigned int i = 0; i < 2; ++i){//model->getNodes().size(); ++i){
    //         auto& node = model->getNodes()[i];

    //         glm::mat4 t = node->mat;
    //         if (!node->parent.expired()){
    //             t = node->parent.lock()->mat * t;
    //         }

    //         // std::cout << glm::to_string(t) << std::endl;
    //         drawer->getMeshTransform().transforms.push_back(t);
    //         drawer->getMeshTransform().transforms.push_back(t);
    //     }
    //     drawer->getMeshTransform().apply();


    //     const Val<gl::Int> loc(-1);
    //     drawer->getUniformLocation(loc, "node_n");
    //     std::cout << "node_n location: " << *loc << std::endl;
    //     // std::cout << glm::to_string(drawer->getMeshTransform().transforms[0]) << std::endl;

    //     for (unsigned int i = 0; i < 2; ++i){//model->getMeshes().size(); ++i){
    //         drawer->setUniform_1I(loc, i);
    //         model->getMeshes()[i]->getVertexArray()->draw(gl::DrawMode::Triangles,
    //                                                     model->getMeshes()[i]->getIndexData().getIndexCount(),
    //                                                     getMeshIndexTypeGlType(model->getMeshes()[i]->getIndexData().getType()),
    //                                                     1);
    //     }

    //     static bool shown = false;
    //     if (!shown){
    //         std::cout << "Meshes: " << model->getMeshes().size() << std::endl;

    //         for (int i = 0; i < model->getMeshes().size(); ++i){
    //             auto& mesh = model->getMeshes()[i];

    //             // std::cout << "Mesh " << i << std::endl;
    //             // std::cout << "\tMult: " << mesh->getVertexData().getValueMultiplier(model::MeshAttribute::Position) << std::endl;
    //             // std::cout << "\tIndices: " << mesh->getIndexData().getIndexCount() << std::endl;
    //             // std::cout << "\tIndex type: " << getMeshIndexTypeString(mesh->getIndexData().getType()).data() << std::endl;
    //         }

    //         shown = true;
    //     }



    //     // gl::UInt id;
    //     // vao.getId(&id);

    //     // glBindVertexArray(id);
    //     // // glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
    //     // glDrawElementsInstanced(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0, 1);

    //     gl::Enum err = glGetError();
    //     while (err != GL_NO_ERROR){
    //         std::string err_name;
    //         switch (err){
    //             case GL_INVALID_ENUM: err_name = "GL_INVALID_ENUM";
    //             case GL_INVALID_VALUE: err_name = "GL_INVALID_VALUE";
    //             case GL_INVALID_OPERATION: err_name = "GL_INVALID_OPERATION";
    //             case GL_STACK_OVERFLOW: err_name = "GL_STACK_OVERFLOW";
    //             case GL_STACK_UNDERFLOW: err_name = "GL_STACK_UNDERFLOW";
    //             case GL_OUT_OF_MEMORY: err_name = "GL_OUT_OF_MEMORY";
    //             case GL_INVALID_FRAMEBUFFER_OPERATION: err_name = "GL_INVALID_FRAMEBUFFER_OPERATION";
    //             case GL_CONTEXT_LOST: err_name = "GL_CONTEXT_LOST";
    //             default: err_name = "UNKNOWN";
    //         }

    //         std::cout << " Err: " << err_name << "(" << err << ")" << std::endl;
    //         err = glGetError();
    //     }
    // });

    // while (is_running){
    //     ctx->start();
    //     ctx->wait();
    // };
}


