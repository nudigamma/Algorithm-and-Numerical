/** examples 2,3,4 shows three cases when a litteral suffix is needed,
 *  This example avoid clipping  
 */
#include <iostream>
#include <complex>

using namespace std;

int main()
{
     long double third1= 0.3333333333333333333; // may lose digits
     long double third2= 0.3333333333333333333l; // accurate 

     cout << third1 << endl;

     cout << third2 << endl;
}   