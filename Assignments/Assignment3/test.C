#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 8;
const int blockSize = 1024;
const float pi = M_PI;

int main(){
    // allocate arrays in main memory.
    float A[N] = {3.6, 2.9, 5.6, 4.8, 3.3, 5.9, 5, 4.3}; // real
    float B[N] = {2.6, 6.3, 4, 9.1, 0.4, 4.8, 2.6, 4.1}; // imaginary
    float C[N]; // real result
    float D[N]; // imaginary result


    // checking array init.
    printf("Initial Arrays:\n");
    for(int i = 0; i < 8; i++){
        printf("Array A[%d]: %f\n", i, A[i]);
        printf("Array B[%d]: %f\n", i, B[i]);
    }
    printf("\n\n\n");

    // compute the even FFT of A + Bi.
    for(int n = 0; n <= (N/2) - 1; n++){
        float cosTemp = cos((2 * pi * (2 * n)) / N);
        float sinTemp = -(sin((2 * pi * (2 * n)) / N)); 

        C[2 * n] = (A[2 * n] * cosTemp) + (-1 * (B[2 * n] * sinTemp)); // real
        D[2 * n] = (A[2 * n] * sinTemp) + (B[2 * n] * cosTemp); // imaginary
    }

    // compute the odd FFT of A + Bi.
    for(int n = 0; n <= (N/2) - 1; n++){
        float cosTemp = cos((2 * pi * (2 * n + 1)) / N);
        float sinTemp = -(sin((2 * pi * (2 * n + 1)) / N));

        C[2 * n + 1] = (A[2 * n + 1] * cosTemp) + (-1 * (B[2 * n + 1] * sinTemp)); // real
        D[2 * n + 1] = (A[2 * n + 1] * sinTemp) + (B[2 * n + 1] * cosTemp); // imaginary
    }

    // checking result array.
    printf("Result Arrays:\n");
    for(int i = 0; i < 8; i++){
        printf("Array C[%d]: %f\n", i, C[i]);
        printf("Array D[%d]: %f\n", i, D[i]);
    }
}