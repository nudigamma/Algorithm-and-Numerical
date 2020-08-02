/** braces inialization show cases  c++ 11 and newer c++ in declaring and initialization of simple 
 * variables */
#include "braces_initialization.hpp"

using namespace std;

void braces_initialization()
{
  cout << "\nStart: Show case of braces initialization \n";
  cout << "Since c++11 it is perfered to initialize variables with \"{}\" or \"Non-Narrowing initialization\" "
       << " since it will allow for type  checking\n";
  cout << " \"constexpr\" type modifier  is used when we are able to compute or initialize the value on compile time\n";
  cout << "\t constexpr int A {3};\n";
  cout << "\t constexpr int B {4*3};\n";
  cout << "both the codes above compile, in the mutiplication case the compiler will do the computation\n";
  constexpr int A {3};
  constexpr int B {4*3};
  cout << "Note the braces enforce type checking for example \n";
  cout <<"\t constexpr int A{3.3};\n";
  //{constexpr int A{3.3};}
  cout << "the code above doesn't compile and the clang will say\n"
       << "braces_initialization.cpp:20:20: error: type 'double' cannot be narrowed to 'int' in initializer list"
       << " [-Wc++11-narrowing]\n" <<"however\n";
  cout <<"\t constexpr int A= 3;\n";
  cout << "the code above compiles but 3.3 will be clipped to 3\n";
  {constexpr int A= 3;}
  cout <<" \"auto\" is keyword that enables the compiler to determine the type it is the prefered way\n"
       <<" to declare type\n";
  cout <<"\t constexpr auto r1 {3.5}, r2 {7.3}, pi{3.14159};\n";
  cout <<"\t auto area1 = pi * r1 * r1;\n";
  cout <<"area1 is automatically determined as floatm it works for variables and literals\n";
  constexpr auto r1 {3.5}, r2 {7.3}, pi{3.14159}; // perfered way for initialization type checking
  auto area1 = pi * r1 * r1;
  cout << "\nEnd: Show case of braces initialization \n";

}