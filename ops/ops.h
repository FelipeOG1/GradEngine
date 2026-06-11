#pragma once
#include "tensor.h"

enum class OpCode { SUM, SUB, DIV, MUL };

struct SumOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a + b; } };

struct SubOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a - b; } };

struct MulOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a * b; } };

struct DivOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a / b; } };


namespace ops {

    namespace elementWise {
        Tensor matsum(const Tensor& a, const Tensor& b);
        Tensor matsub(const Tensor& a, const Tensor& b);
        Tensor matmul(const Tensor& a, const Tensor& b);
        Tensor matdiv(const Tensor& a, const Tensor& b);


    }

    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b);
        

    }
}
