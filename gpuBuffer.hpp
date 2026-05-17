#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>

class GpuBuffer {

private:
    float* _f_ptr;
    size_t _n;

public:
    GpuBuffer(size_t n) : _n(n) {
        if(hipMalloc(&_f_ptr, n * sizeof(float)) != hipSuccess) {
            throw std::runtime_error("Probel alocating memory on gpu");
        }
    }
    ~GpuBuffer() { if (_f_ptr)  hipFree(_f_ptr); }
};


 



