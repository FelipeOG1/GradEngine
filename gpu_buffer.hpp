#pragma once
#include <hip/hip_runtime.h>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <memory>

inline int float_as_int(float f) {
    int i;
    std::memcpy(&i, &f, sizeof(float));
    return i;
}

class GpuBuffer {
private:
    size_t _n;
    std::shared_ptr<float> _d_ptr;
public:
    GpuBuffer(size_t n) : _n(n) {
        float* ptr;
        hipMalloc(&ptr, _n * sizeof(float));
        _d_ptr = std::shared_ptr<float>(ptr, [](float* p){ hipFree(p); });
    }
    
    // Default copy constructor and assignment (shallow copy)
    GpuBuffer(const GpuBuffer&) = default;
    GpuBuffer& operator=(const GpuBuffer&) = default;
    
    // Move constructor
    GpuBuffer(GpuBuffer&& other) noexcept = default;
    
    // Move assignment
    GpuBuffer& operator=(GpuBuffer&& other) noexcept = default;
    
    void upload(float* host_ptr, size_t size) { hipMemcpy(_d_ptr.get(), host_ptr, size * sizeof(float), hipMemcpyHostToDevice); }
    void download(float* host_ptr, size_t size) { hipMemcpy(host_ptr, _d_ptr.get(), size * sizeof(float), hipMemcpyDeviceToHost); }
    void fill(float value, size_t size) { hipMemsetD32(_d_ptr.get(), float_as_int(value), size); }
    void zeros(size_t size) { hipMemset(_d_ptr.get(), 0, size * sizeof(float)); }
    float* data() const { return _d_ptr.get(); }
    
};

