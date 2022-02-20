#include <vld.h>

#include <iostream>

#include "glwpp/utils/Vop.hpp"

int main(int argc, char **argv){
    int value = 11;
    auto v = glwpp::Vop(value);

    auto v2 = v.getPtr();

}


