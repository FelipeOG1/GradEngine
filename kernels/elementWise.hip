#pragma once
#include "../ops/ops.h"


template<typename OpType>
__global__ compute_element_wise(float* A, float* B, float* C, int w_A, OpType op_type) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < w_A) {
        C[idx] = op(A[idx], B[idx]);
    }
}

void launch_element_wise(float* A, float* B, float* C, int w_A, OpCode opcode) {
    dim3 block(256);
    dim3 grid((w_A + block.x - 1) / block.x);
    switch(opcode) {
        case OpCode::SUM: compute_element_wise(A, B, C, w_A, SumOP{} )
        case OpCode::SUM: compute_element_wise(A, B, C, w_A, SubOP{} )
    }
        
    
    hipLaunchKernelGGL(, grid, block, 0, 0, A, B, C, h_A, w_A, w_b);

}
