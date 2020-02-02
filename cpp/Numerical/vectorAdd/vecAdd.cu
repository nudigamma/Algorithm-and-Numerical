#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <iostream>
#include <vecAdd.cuh>
#include <cstdlib>
#include <cstdio>

/** OBJECTIVES : To run a vector Addition on the gpu .
Two input vectors are given as input and they are added in element wise fation
and they resultant per element addition is writen out on a third vector

Procedure:
Define the number of elements for the vector addition
Allocate memory for three vectors 2 in vector and one 1 out vector on CPU

Initialize the two in vectors to number and the out vectors to zero
Allocate memory for the three vectors on CPU 

Move the memory from CPU to GPU 
call the kernel and do the operation on GPU
copy back the memory from CPU to GPU 

deallocate cpu and gpu memory

**/
int main(void)
{   
    // Define default value of error 
    cudaError_t err = cudaSuccess;
    // Number of elements in the array
    int numElements = 50000;
    // assign the size of dynamically allocated memory
    size_t size = sizeof(float)*numElements;
    // Infor user of the vector addition operation
    std::cout << "Vector Addition of " << numElements << std::endl;

    // Allocate memory

    float * h_A = (float *) malloc(size);
    float * h_B = (float *) malloc(size);
    float * h_C = (float *) malloc(size);
    // check if pointers are pointing to memory location 
    if(h_A == NULL || h_B == NULL || h_C == NULL)
    {
        fprintf(stderr,"Failed to allocate host vectors !\n");
        exit(EXIT_FAILURE);
    }    
    // Initialize the host vectors

    for (int i = 0; i < numElements; i++)
    {
       h_A[i] = rand()/(float) RAND_MAX;
       h_B[i] = rand()/(float) RAND_MAX;
       // most probably assigned to 
       h_C[i] = 0;       
    }

    float * d_A = NULL;
    err = cudaMalloc((void **)&d_A, size);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Could not allocate device vector A (error code %s)",cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    float *d_B = NULL;
    err = cudaMalloc((void **)&d_B, size);

    if (err != cudaSuccess)
    {
        fprintf(stderr,"Could not allocate device vector B (error code %s)",cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    float *d_C = NULL;
    err = cudaMalloc((void **)&d_C, size);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Couldnt not allocate devices vector C( error code %s)",cudaGetErrorString (err));
        exit(EXIT_FAILURE);
    }

    printf("Copying data to device \n");
    err = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Couldn't move memory from host vector A  to device vector A %s",cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    err = cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    if(err != cudaSuccess )
    {
        fprintf(stderr,"Could'nt move memory from host B  to device B %s",cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    //
    int number_of_threads = 256;

    int number_of_blocks = (int) ceil(((float)numElements)/number_of_threads);


    vectorAdd<<<number_of_blocks, number_of_threads>>> (d_A, d_B, d_C, numElements);

    err = cudaGetLastError();

    if (err != cudaSuccess)
    {
        fprintf(stderr,"Failure in kernel launch %s", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    if ( err != cudaSuccess)
    {
        fprintf(stderr,"Failed to copy memory from device to host %s",cudaGetErrorString(err));

    }

    if(checksOut_vecAdd(h_A, h_B, h_C, numElements))
      {
          printf("vecadd on gpu validated!\n");
      }
    else 
       printf("Error exceeded tolerance!\n");

    free(h_A);
    free(h_B);
    free(h_C);

    err = cudaFree(d_A);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Failed to free A device memory %s",cudaGetErrorString(err));
    }

    err = cudaFree(d_B);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Failed to free B device memory %s",cudaGetErrorString(err));
    }

    err = cudaFree(d_C);
    if (err != cudaSuccess)
    {
        fprintf(stderr,"Failed to free A device memory %s",cudaGetErrorString(err));
    }

    printf("Program Terminated \n");
    return 0;
}