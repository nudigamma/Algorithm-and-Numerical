/** toy example that compute the exponential function using taylor series **/
#include <iostream>
#include <cmath>

using namespace std;

int main()

{   
    constexpr auto number = 2; // works only for 2 
    auto xn = 1.0, exp_x = 1.0; // avoid computing e^0 / 0 !
    unsigned long fac = 1;

    for (unsigned long i = 1 ; i <= 10 ; ++i)
    {
        xn= xn*number;
        fac*= i; // (1*2*3) = 3! and so on 
        exp_x+= xn/fac;

    }
    cout << "Exponential of " << number << "is" << exp_x <<endl;
    cout << "Exponential  of " << number << "is" << exp(number) << " as computed with cmath" <<endl;

}