#include <iostream>
#include <hip/hip_runtime.h>
#include "../ops/ops.h"
#include "elementWise.h"

template<typename OpType>
__global__ void compute_element_wise(const float* A, const float* B, float* C, int w_A, OpType op) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < w_A) {
        C[idx] = op(A[idx], B[idx]);
    }
}

void launch_element_wise(const float* A, const float* B, float* C, int w_A, OpCode opcode) {
    dim3 block(256);
    dim3 grid((w_A + block.x - 1) / block.x);
    switch(opcode) {
        case OpCode::SUM:
            hipLaunchKernelGGL(compute_element_wise, grid, block, 0, 0, A, B, C, w_A, SumOp{}); break;
        case OpCode::SUB:
            hipLaunchKernelGGL(compute_element_wise, grid, block, 0, 0, A, B, C, w_A, SubOp{}); break;
    }
    
    hipError_t err = hipGetLastError();
    if (err != hipSuccess) {
        std::cerr << "HIP Error: " << hipGetErrorString(err) << std::endl;
    }
}




