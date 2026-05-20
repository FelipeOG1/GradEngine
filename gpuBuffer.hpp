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
            throw std::runtime_error("Proble alocating memory on gpu");
        }
    }

    void upload(const float* host_ptr, size_t bytes) {
        
        hipMemcpy(_f_ptr, host_ptr, bytes * sizeof(float), hipMemcpyHostToDevice);
    }
    
    void download(float* host_ptr, size_t bytes) {
        hipMemcpy(host_ptr, _f_ptr, bytes * sizeof(float), hipMemcpyDeviceToHost);
    }
    
    void download(float* host_ptr, size_t bytes, size_t offset) {
        hipMemcpy(host_ptr, _f_ptr, (bytes * sizeof(float)) + offset, hipMemcpyDeviceToHost);
    }
    
    size_t alocated_bytes() const { return _n; }

    
   ~GpuBuffer() { if (_f_ptr)  hipFree(_f_ptr); }
};


 



