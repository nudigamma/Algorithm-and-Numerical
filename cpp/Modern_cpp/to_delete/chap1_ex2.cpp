/** examples 2,3,4 shows three cases when a litteral suffix is needed,
 *  the example for this case is when a templated type is used with a litteral,
 *  litteral suffix is needed 
 */
#include <iostream>
#include <complex>

using namespace std;

int main()
{
     complex<float> z1(1.5,2),z2;
     // z2 = z1 + 2.0; // invalid operands to binary expression ('complex<float>' and 'double')
                    //z2 = z1 + 2.0;
      z2 = z1 + 2.0f; // whenever templated types are used , the suffix is needed to specificy explictly the
                      /// literal type 
      
}   