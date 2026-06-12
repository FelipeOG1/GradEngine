#pragma once
#include "tensor.h"

enum class OpCode { SUM, SUB, DIV, MUL, RELU };

struct SumOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a + b; } };

struct SubOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a - b; } };

struct MulOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a * b; } };

struct DivOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a / b; } };

struct ReluOp { __device__ __forceinline__ float operator()(float a) const { return (a > 0) ? a : 0.0f; } };

namespace ops {

    namespace elementWise {
        Tensor matsum(const Tensor& a, const Tensor& b);
        Tensor matsub(const Tensor& a, const Tensor& b);
        Tensor matmul(const Tensor& a, const Tensor& b);
        Tensor matdiv(const Tensor& a, const Tensor& b);
        Tensor relu(const Tensor& t);

    }

    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b);
        

    }
}
