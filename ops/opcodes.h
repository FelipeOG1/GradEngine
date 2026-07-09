#pragma once
#include <hip/hip_runtime.h>

enum class OpCode { RELU, SUB, DIV, MUL, SUM };

struct SumOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a + b; } };

struct SubOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a - b; } };

struct MulOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a * b; } };

struct DivOp { __device__ __forceinline__ float operator()(float a, float b) const  { return a / b; } };

struct ReluOp { __device__ __forceinline__ float operator()(float a) const { return (a > 0) ? a : 0.0f; } };
