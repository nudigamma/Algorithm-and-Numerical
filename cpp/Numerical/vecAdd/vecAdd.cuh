#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <math.h>

__global__ void 
vectorAdd( const float *A, const float *B, float *C, int numElements)
{

    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < numElements)
    {
        C[i] = A[i] + B[i];
    }


}

__host__ void 
vectorAddHost( const float *A, const float *B, float * C, int numElements)
{
    for (int element = 0; element < numElements; element++)
        C[element] = A[element] + B[element];

}


__host__ bool
checksOut_vecAdd(const float * A, const float *B, float * C , int numElements)
{
    bool error = true;
    for (int element = 0 ; element < numElements; element++)
    {
           if(abs(A[element]+ B[element] - C[element]) >= 1e-6)
            return false;
    }
    return error;
}