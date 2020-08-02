/** this program uses a cosine to try gnu plot **/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const double PI_2 = 2*2*acos(0.0);
constexpr auto NUMBER_OF_POINTS = 300;
const auto RESOLUTION = PI_2/(NUMBER_OF_POINTS); 

int main()
{
    double * x_axis = new double[NUMBER_OF_POINTS];// a vector is better
    double * y_axis = new double[NUMBER_OF_POINTS];
    auto eps = 0.01;
    auto accum = 0.0;
    auto index = 0;

    ofstream ofs("sin.dat");
    
    while (abs(PI_2 - accum) >= eps)
    {   
        x_axis[index] = accum;
       
        y_axis[index] =sin(accum);
        
        ofs << x_axis[index] << " " << y_axis[index] << "\n";
        ++index;
        accum = accum + RESOLUTION;
    }

    delete [] x_axis;
    delete [] y_axis;

}
