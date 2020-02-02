#include "VectorAdd.hpp"
#include <iostream>

int main()

{
    std::vector<double> h_v1(100,4);
    std::vector<double> h_v2(100,6);
    std::vector<double> h_v3(100);

    vecAdd(h_v1,h_v2,h_v3);

    for (const auto &x : h_v3)
        {
            std::cout<< x << std::endl;
        }
    return 0;
}