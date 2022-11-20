#pragma once

#include "Context.hpp"

namespace glwpp {

class Model {
public:
    Model(const std::shared_ptr<Context>& ctx, const std::string& model_path);
    ~Model();

    std::optional<std::string> getError();

};
    
} // namespace glwpp
