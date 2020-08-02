#include <iostream>
/** this example introduces 
    I/O are not part of the language and they need be included 
    I/O has a stream model
    int main () is necessary for any c++ program
    << can be used to pass objects in this example from to the cout 
*/
int main()
{
    std::cout << "The answer to the Ultimate Question of Life,\n"
              << "The Universe, and Everything is:"
              << std::endl << 6*7 << std::endl;
    return 0;

}