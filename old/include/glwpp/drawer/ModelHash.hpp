#include <string>
#include <unordered_map>

#include "glwpp/Model.hpp"
#include "glwpp/model/MeshVertexConfig.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class ModelHash {
public:
    sptr<Model> loadModel(const std::string& path, const MeshVertexConfig& default_config);

private:
    std::unordered_map<std::string, wptr<Model>> _map;

};

}