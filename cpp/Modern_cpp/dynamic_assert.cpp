#include "dynamic_assert.hpp"

using namespace std;

void test_assert(int number)
{
    assert(number >= 0);
    cout << "The number is " << number <<endl;
}


void dynamic_assert()
{
    constexpr int test_positive = 1;
    test_assert(test_positive);

    constexpr int test_negative = -1;
    test_assert(test_negative);
}