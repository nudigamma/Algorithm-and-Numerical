#include <iostream>
#include <memory>

using namespace std;
int main()

{
    unique_ptr<double> dptr {new double};

    *dptr = 8;

    cout << *dptr << endl;

    double * rawdptr = dptr.get();

    cout << *rawdptr << endl;    
}