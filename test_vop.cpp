#include <vld.h>

#include <iostream>

#include "glwpp/utils/Val.hpp"

int main(int argc, char **argv){
    int value = 11;
    auto v = glwpp::Val(value);

    auto v2 = v.getPtr();

}


