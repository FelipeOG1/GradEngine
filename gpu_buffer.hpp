#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>
#include <vector>
class GpuBuffer {
private:
    size_t _n;
    float* _d_ptr;
public:
    std::vector<float> shape;
    GpuBuffer(size_t n) : _n(n), shape(2)  { hipMalloc(&_d_ptr, _n * sizeof(float)); }
    void upload(float* host_ptr, size_t size) { hipMemcpy(_d_ptr, host_ptr, size * sizeof(float), hipMemcpyHostToDevice); }
    void download(float* host_ptr, size_t size) { hipMemcpy(host_ptr, _d_ptr, size * sizeof(float), hipMemcpyDeviceToHost); }

	float* data() const { return _d_ptr; }
	
    ~GpuBuffer() { hipFree(_d_ptr); }
    
};

