/** examples 2,3,4 shows three cases when a litteral suffix is needed,
 *  the example for this case is to solve ambiguity in function overload 
 *  litteral suffix is needed 
 */
#include <iostream>
#include <complex>

using namespace std;

void printNumber(float a)
{
     cout << "The float number is " << a << endl;
}


void printNumber(double a)
{
     cout << "The double number is " << a << endl;
}
int main()
{
     printNumber(0.0f); // prints the float overloads
     printNumber(0.0); // prints the double overloaded 
      
}   