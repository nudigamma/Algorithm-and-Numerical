#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main()
{
    double number = 2;

    const int ITERATIONS = 100;

    for (int iteration = 0 ; iteration < ITERATIONS ; ++iteration)
    {
        number = sqrt(number);
    }

    for (int iteration = 0 ; iteration < ITERATIONS; ++iteration)
    {
        number = number * number;
    }

    printf("%12g\n",number);


}// end of main
