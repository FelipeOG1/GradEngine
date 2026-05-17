
#include <hip/amd_detail/amd_hip_runtime.h>
#include <hip/hip_runtime.h>
#include "tensor.h"

template <typename T>
class GpuBuffer {
private:
    float* f_ptr = nullptr;
    size_t _size;

public:
    GpuBuffer(size_t n) : _size(n) {
        if (hipMalloc(&f_ptr, n * sizeof(T)) != hipSuccess) {  
            throw std::runtime_error("Failed to alocate memory on GPU");
            
        }
    }

    ~GpuBuffer() {
        if (f_ptr) {
            if (hipFree(f_ptr) != hipSuccess) {
                 throw std::runtime_error("Failed to free memory on GPU");
            }
        }
    }
};


