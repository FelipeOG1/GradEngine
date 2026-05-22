#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>
#include <tensor.h>
class GTensor {

private:
    float* _f_ptr;
    size_t _n;
    void _upload(const float* host_ptr, size_t bytes) {
        hipMemcpy(_f_ptr, host_ptr, bytes * sizeof(float), hipMemcpyHostToDevice);
    }
    
    void _download(float* host_ptr, size_t bytes) {
        hipMemcpy(host_ptr, _f_ptr, bytes * sizeof(float), hipMemcpyDeviceToHost);
    }
    
    void _download(float* host_ptr, size_t bytes, size_t offset) {
        hipMemcpy(host_ptr, _f_ptr, (bytes * sizeof(float)) + offset, hipMemcpyDeviceToHost);
    }



public:
    GTensor(Tensor t) : _n(t.size())  {
        if(hipMalloc(&_f_ptr, t.size()) != hipSuccess) {
            throw std::runtime_error("Proble alocating bytes in gpu");
        }
        
    }

   
    size_t () const { return _n; }
    float* data() const { return _f_ptr; }
    
   ~GpuBuffer() { if (_f_ptr)  hipFree(_f_ptr); }
};


 



