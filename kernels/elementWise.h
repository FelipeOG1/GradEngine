#pragma once
#include "ops/ops.h"

template<typename OpType>
__global__ void compute_binary_op(const float* A, const float* B, float* C, int w_A, OpType op);

template<typename OpType>
__global__ void compute_unary_op(const float* A, float* C, int w_A, OpType op);

void launch_element_wise(const float* A, const float* B, float* C, int w_A, OpCode opcode);
void launch_element_wise(const float* A, float* C, int w_A, OpCode opcode);
