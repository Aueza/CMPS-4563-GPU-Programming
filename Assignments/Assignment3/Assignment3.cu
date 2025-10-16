//**************************************************************
// Assignment #3
// Name: Ethan Saenz and Isaiah Corrales 
// GPU Programming Date: (M/D/Y)
//**************************************************************
// This program 
//**************************************************************


//**************************************************************
// FOR ALL FUNCTIONS function Name::MethodName()
// Parameters: List them here and comment
// A discussion of what the method/function does and required
// parameters as well as return value.
//**************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 8192;
const int blockSize = 1024;
const int gridSize = 4;
const float pi = M_PI;

__global__
void FFT(float *Ad, float *Bd, float *Cd, float *Dd, int N, const float pi){
	// Getting global thread ID.
	int threadId = blockIdx.x * blockDim.x + threadIdx.x;

	// Each thread works with 2 indices.
	int index1 = threadId;
	int index2 = threadId + (N / 2);

	// Computing the FFT for the first index. (0 - 4095)
	float twiddleReal = cos((2 * pi * (threadId)) / N);
	float twiddleImag = -(sin((2 * pi * (threadId)) / N));
	Cd[index1] = (Ad[index1] * twiddleReal) + (-1 * (Bd[index1] * twiddleImag)); // real
    Dd[index1] = (Ad[index1] * twiddleImag) + (Bd[index1] * twiddleReal); // imaginary


    // Computing the FFT for the second index. (4096 - 8191)
    //twiddleReal = cos((2 * pi * (threadId)) / N);
    //twiddleImag = -(sin((2 * pi * (threadId)) / N));
    Cd[index2] = (Ad[index2] * twiddleReal) + (-1 * (Bd[index2] * twiddleImag)); // real
    Dd[index2] = (Ad[index2] * twiddleImag) + (Bd[index2] * twiddleReal); // imaginary
	
}

int main(){
	// Allocate arrays in main memory.
	float A[N] = {3.6, 2.9, 5.6, 4.8, 3.3, 5.9, 5, 4.3};
	float B[N] = {2.6, 6.3, 4, 9.1, 0.4, 4.8, 2.6, 4.1};
	float C[N], D[N];

	// Define pointers for global memory.
	float *Ad, *Bd, *Cd, *Dd;
	int size = N * sizeof(float);

	// Allocate array space in global memory.
	cudaMalloc((void**) &Ad, size);
	cudaMalloc((void**) &Bd, size);
	cudaMalloc((void**) &Cd, size);
	cudaMalloc((void**) &Dd, size);

	// Copy main memory arrays to global memory.
	cudaMemcpy(Ad, A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(Bd, B, size, cudaMemcpyHostToDevice);

	// Defining the computational grid.
	dim3 dimGrid(gridSize);
	dim3 dimBlock(blockSize);

	// Invoking the kernel with the defined computation grid.
	FFT<<<dimGrid, dimBlock>>>(Ad, Bd, Cd, Dd, N, pi);

	// Copying result arrays from global to main memory.
	cudaMemcpy(C, Cd, size, cudaMemcpyDeviceToHost);
	cudaMemcpy(D, Dd, size, cudaMemcpyDeviceToHost);

	// Printing the first seven results.
	printf("\n\nTOTAL PROCESSED SAMPLES: %d\n", N);
	printf("===============================================\n");
	for(int i = 0; i < 8; i++){
		printf("XR[%d]: %f 		XI[%d]: %f\n", i, C[i], i, D[i]);
		printf("===============================================\n");
	}


}