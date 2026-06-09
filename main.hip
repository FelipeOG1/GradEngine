#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>


//blockIdx
//blockDim
//threadIdx

__global__ void k(float* data, size_t size) {
    int idx = blockIdx * blockDim + threadIdx;
    if (idx < size) {
        data
        
    }
    
}

int main () {
    
    return 0;
}
