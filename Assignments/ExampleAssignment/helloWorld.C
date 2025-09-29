#include <stdio.h>
#include <cuda.h>

const int N = 7;
const int blockSize = 7;

// __global__ implies that this function is a kernel function
__global__ 
void hello(char *a, int *b){
    a[threadIdx.x] += b[threadIdx.x];
}

int main(){
    char a[N] = "Hello ";
    int b[N] = {15, 10, 6, 0, -11, 1, 0};

    char *ad; int *bd;
    const int cSize = N * sizeof(char);
    const int iSize = N * sizeof(int);

    printf("%s", a);

    // allocating memory on the GPU.
    // address of ptr to be allocated, size of allocated obj.
    cudaMalloc((void**) &ad, cSize);
    cudaMalloc((void**) &bd, iSize);

    // destination, source, size, direction.
    cudaMemcpy(ad, a, cSize, cudaMemcpyHostToDevice);
    cudaMemcpy(bd, b, iSize, cudaMemcpyHostToDevice);

    // defining the computational grid:
    // computational grid --> building.
    // blocks --> classrooms.
    // threads --> students.
    dim3 dim3Grid(1, 1);
    dim3 dim3Block(blockSize, 1);

    hello<<<dim3Grid, dim3Block>>>(ad, bd);

    cudaMemcpy(a, ad, cSize, cudaMemcpyDeviceToHost);
    cudaFree(ad);
    cudaFree(bd);

    printf("%s\n", a);
}