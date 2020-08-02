/** example 5 shows the use of post increment and decrement 
 *  increment operators need a Lvalue to work 
 */
#include <iostream>
#include <complex>

using namespace std;

int main()
{
     int number_1 = 1;
     int number_2 = 2;

     cout << "Pre increment, evaluates in the same statement number_1 = number_1 + 1 " << ++number_1 <<endl; // 2 
     cout << "Post increment, evaluate in the same statement number_2 = number_2 " << number_2++ << endl ; // 2
     cout << "Post increment, evaluates the number_2 = number_2 + 1 " << number_2++ << endl; //3 

     cout << number_2 % 3 ;// 4
}