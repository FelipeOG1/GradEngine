#pragma once

struct SumOp { __device__ operator()(float a, float b) const  { return a + b } }

struct SubOp { __device__ operator()(float a, float b) const  { return a - b } }

