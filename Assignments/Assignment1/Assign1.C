// Ethan Saenz
// CMPS 4563 - GPU Programming
// Assignment 1 - CUDA Programming
// This program computes the product of two arrays using CUDA.

const int N = 4096; // Size of the arrays.

#include <stdio.h>
#include <cuda.h>

// Compute array product: C = A * B
// Occurs in device (GPU) global memory (kernel).
__global__
void arrProductKernel(const int *A_d, const int *B_d, int *C_d, int N){
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i < N){
        C_d[i] = A_d[i] * B_d[i];
    }
}

int main(){
    // allocating host (CPU) arrays.
    int A[N], B[N] C[N * 2];

    // initializing host arrays.
    for(int i = 0; i < N; i++){
        A[i] = i;
        B[i] = i + 4096;
    }

    // allocating device (GPU) arrays.
    int *A_d, *B_d, *C_d;
    const int size = N * sizeof(int);

    // allocating memory (global) on the device (GPU).
    // (address of ptr to be allocated, size of allocated object).
    cudaMalloc((void**) &A_d, size);
    cudaMalloc((void**) &B_d, size);
    cudaMalloc((void**) &C_d, size);

    // copying host (CPU) arrays to device (GPU) arrays.
    // (destination, source, size, direction).
    cudaMemcpy(A_d, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(B_d, B, size, cudaMemcpyHostToDevice);

    // defining the computation grid.
    dim3 dimGrid(32, 1); // 32 blocks.
    dim3 dimBlock(256, 1); // 256 threads per block.

    // launching the kernel with the grid.
    arrProductKernel<<<dimGrid, dimBlock>>>(A_d, B_d, C_d, N);

    

}
