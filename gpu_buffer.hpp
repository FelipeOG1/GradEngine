#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>
#include <tensor.h>

class GpuBuffer {
private:
    size_t _n;
    float* _d_ptr;
public:
    GpuBuffer(size_t n) : _n(n) {hipMalloc(&_d_ptr, _n); }




};

