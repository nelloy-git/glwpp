#pragma once

#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

namespace glwpp {

std::unique_ptr<std::string> readTextFile(const std::string &path){
    auto code = std::make_unique<std::string>();
    std::ifstream file;

    // ensure ifstream objects can throw exceptions:
    // file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
        file.open(path);
        std::stringstream str_stream;

        std::string line;
        while(std::getline(file, line)){
	        // Saves the line in STRING.
	        *code += line + "\n";
        }
        file.close();
    } catch(std::ifstream::failure e){
        std::cout << e.what() << std::endl;
        return nullptr;
    }

    return code;
};

}