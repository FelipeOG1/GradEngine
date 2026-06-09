#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>
#include <vector>
#include <cstring>

inline int float_as_int(float f) {
    int i;
    std::memcpy(&i, &f, sizeof(float));
    return i;
}

class GpuBuffer {
private:
    size_t _n;
    float* _d_ptr;
public:
    GpuBuffer(size_t n) : _n(n) { hipMalloc(&_d_ptr, _n * sizeof(float)); }
    void upload(float* host_ptr, size_t size) { hipMemcpy(_d_ptr, host_ptr, size * sizeof(float), hipMemcpyHostToDevice); }
    void download(float* host_ptr, size_t size) { hipMemcpy(host_ptr, _d_ptr, size * sizeof(float), hipMemcpyDeviceToHost); }
    void fill(float value, size_t size) { hipMemsetD32(_d_ptr, float_as_int(value), size); }
    void zeros(size_t size) { hipMemsetD32(_d_ptr, 0, size); }
	float* data() const { return _d_ptr; }
	
    ~GpuBuffer() { hipFree(_d_ptr); }
    
};

