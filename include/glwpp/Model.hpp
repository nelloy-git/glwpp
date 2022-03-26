#pragma once

#include <string>
#include <vector>

namespace glwpp {
    
class Model {
public:
    Model();
    virtual ~Model();

    bool readFile(const std::string& path);

private:
    
};

} // namespace glwpp
