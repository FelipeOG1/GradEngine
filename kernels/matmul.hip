#include <hip/hip_runtime.h>

__global__ void matmul(const float* A, const float* B, float* C, int h_A, int w_A, int w_B) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < h_A && col < w_B) {
        
        float sum = 0.0f;
        for (int i=0; i < w_A; ++i) {
            sum += A[row * w_A + i] * B[i * w_B + col];
            
        }
        C[row * w_B + col] = sum;
    }

}

void launch_matmul(const float* A, const float* B, float* C, int h_A, int w_A, int w_b) {
    dim3 block(16, 16);
    dim3 grid((w_b + block.x - 1) / block.x,
              (h_A + block.y - 1) / block.y);
    
    hipLaunchKernelGGL(matmul, grid, block, 0, 0, A, B, C, h_A, w_A, w_b);
}

