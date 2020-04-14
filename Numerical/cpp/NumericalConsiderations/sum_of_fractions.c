#include <stdio.h>
#include <math.h>
int main()
{
    float numerator = 1.0;
    float denominator = 11.0;
    float fraction = numerator/denominator;
    
    float sum = 0.0;
    for (int i = 0; i < (int) denominator ; i++ )
    {
        sum += fraction;
    }

    float difference = abs(sum-numerator); 

    if( difference == 0)
        printf("Equal to zero. \n");
    else
    {
        printf("Difference is not Equal to zero .\n");
    }
    
} // end of main 