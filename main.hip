#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>

__global__ void matsum(float* data, size_t size, int value) {
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if (idx < (int)size) {
		data[idx] += value;
	}
}


void cpu_mat_sum(std::vector<float> &tmp, float value) {
    for (auto &v : tmp) { 
        v += value; 
    }
}


int main () {
    
    return 0;
}
