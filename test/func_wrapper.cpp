#include <functional>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>

#include "glwpp/utils/FuncWrapper.hpp"

struct A {
    void a(int &b){
        b++;
    }
};

int main(int argc, char **argv){
    int zero = 0;
    std::function f = [&](int a, int b) -> int {
        std::cout << zero + a << std::endl;
        return 13;
    };

    // std::function<void(A*, int&)> mf = std::mem_fn(&A::a);
    auto wb = glwpp::func_expand_back<int, int, double>(f);
    auto wf = glwpp::func_expand_front<double, int, int>(f);
    // std::function<int(int, int, double)> w1;
    // glwpp::expand(f);
    // glwpp::MoreArgsWrapper<int(int, int)> w(f);

    // std::cout << w(5, 5) << std::endl;

    return 0;
}