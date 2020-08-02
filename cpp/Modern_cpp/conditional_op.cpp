/** conditional_op.cpp show cases how to use the conidtional op in c++ */

#include "conditional_op.hpp"

using namespace std;
void conditional_op()
{
    bool flag= true;
    string statement= "";
    
    cout << "\nStart: Show casing the use of conditional op\n\n";
    statement= flag ?  "true" :  "false";
    cout << "flag is set to true \n " << "\tstatement = flag ?  \"true\" :  \"false\"; " << statement << endl;

    flag= false;

    statement = flag ?  "true" :  "false";
    cout << "flag is set to false \n " << "\tstatement = flag ?  \"true\" :  \"false\"; " << statement << endl;
    cout << "\nEnd: Show casing the use of conditional op\n\n";
}