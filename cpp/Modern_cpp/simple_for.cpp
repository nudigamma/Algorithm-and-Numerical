/** this program show cases the implementation of 2 version of for loops using 
 *  vec addtion program */
#include "simple_for.hpp"
using namespace std;

void  add_vec(const vector<double> & in1, const vector<double>& in2, vector<double> & out)
{
    // vector add is only defined to equally sized vectors 

    for ( int i = 0 ; i < in1.size(); i++)
    // non range for loop
        {
            out[i] = in1[i] + in2[i];
        }


}

void print_vec(const vector<double> & sum_vec)
{   
   for (auto i : sum_vec)
   {
       cout << i << "\n"; 
   }

}

void execute()
{
    vector<double> in1 {1.0,3.0,5.0};
    vector<double> in2 {2.0,4.0,6.0};
    vector<double> out(3);
    add_vec(in1,in2,out);
    cout << "\nStart: Showcasing the use of two simple loops \n\n";
    print_vec(out);
    cout << "\nEnd: Showcasing the use of two simple loops \n\n";
}

void simple_for()
{   
    
    execute();
    
}