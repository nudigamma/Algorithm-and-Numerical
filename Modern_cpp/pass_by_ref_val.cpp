/** program to demonstrate pass by ref and pass by val */


#include "pass_by_ref_val.hpp"

using namespace std; 

void increment_by_val (int i)
{
    ++i;
}
void increment_by_ref (int& i)
{
    ++i;
}

void execute(int value)
{
    auto i = value;
    cout << " The orginal value of the integer i==  " << i << endl;
    cout << " passing i by value to the function increment by val\n";
    cout << " the function will make an internal copy of i and therefore will\n"
         << " only increment the copy and not the original i";

    increment_by_val(i);

    cout << "The value of i remains unchanged once the functional exits i== " << i << endl;
    cout << "Now we pass by reference instead\n";

    increment_by_ref(i);
    cout <<"We can see that that the value of i is incremented i== " << i <<endl;
} // end of funnction execute

void pass_by_ref_val()
{
    execute(1);
}