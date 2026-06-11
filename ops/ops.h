#pragma once
#include "tensor.h"

enum class OpCode { SUM, SUB, DIV, MUL };

struct SumOp { __device__ float operator()(float a, float b) const  { return a + b; } };

struct SubOp { __device__ float operator()(float a, float b) const  { return a - b; } };



namespace ops {

    namespace elementWise {


    }

    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b);
        

    }
}
