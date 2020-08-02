/** this program show cases a simple for loop */
#include <iostream>
#include "simple_for.hpp"
using namespace std;

void add_vec(const vector<double> &A, const vector<double> &B,  vector<double>  &C)
{   
    cout << "add_vec function demonstrates a simple for loop with index \n";
    cout << "\t for (int i = 0 ; i < C.size(); ++i)";
    cout << "\t\t{\n"
         << "\t\tC[i] = A[i] + B[i];"
         << "\t\t}\n";
    cout << "reminder that for loop supports comma seperated multiple initialization, multiple incrementation"
         << " and logic operation in the condition for example :\n "
         << "\t for (int i = 0, int j = 0 ; i < C.size() && j > 1000; ++i, j *=4)";
    
    for (int i = 0 ; i < C.size()  ; ++i)
    {
        C[i] = A[i] + B[i];

    }
}
void print_vec( const vector<double>  &C)
{
    for (auto & i : C)
    {
        cout << i <<"\n";

    }
}
void execute()
{
    vector<double> A{1.0,2.0,3.0}; 
    vector<double> B{1.0,2.0,3.0};
    vector<double> C{0,0,0};

    add_vec(A,B,C);
    print_vec(C);    
}
void simple_for()
{
    execute();
}