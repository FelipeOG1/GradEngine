#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>

__global__ void first_kernel(float *m, size_t size , float value) {
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	
	if (idx < (int)size) {
		m[idx] += value;
	}
}


int main() {
    Tensor a = Tensor::rand(2, 2);
	dim3 grid(1, 1);
	dim3 block(a.size());
	int value = 5;
	first_kernel<<<grid, block>>>(a.data(), a.size(), value);
	hipDeviceSynchronize();
    return 0;
}

