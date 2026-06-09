#include <hip/hip_runtime.h>

__global__ matmul(float* A, float* B, float* C, int h_A, int w_A, int w_B) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < h_A && col < w_B) {
        
        float sum = 0.0f;
        for (int i=0; i < w_A; ++i) {
            sum += A[row * w_A + i] * B[i * w_B + col];
            
        }
        C[row * b_w + col] = sum;
    }

}
