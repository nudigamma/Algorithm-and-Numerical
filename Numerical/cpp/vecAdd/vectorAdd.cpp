#include "VectorAdd.hpp"


void vecAdd(const std::vector<double>  a, const std::vector<double>  b, std::vector<double> & c)
{
    for (int i = 0; i != a.size(); i++)
        c[i] = a[i] + b[i];
    return;
}

