#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>


__global__ void arr_mul(float* data, float value, size_t width) {
    size_t idx = (size_t)blockIdx.x * blockDim.x + threadIdx.x;

    if (idx < width) {
        data[idx] *= value; 
    }
}
int main() {
    size_t r = 128, c = 32;
    Tensor t = Tensor::randint(r, c, 1, 10);
    int thr_per_block = 256;
    int n_blocks = (thr_per_block + t.size()) / thr_per_block;
    int sure = n_blocks * thr_per_block;
    std::cout << t(3, 3) << std::endl;
    dim3 grid(n_blocks);
    dim3 block(thr_per_block);
    arr_mul<<<grid, block>>>(t.data(), 30, t.size());
    return 0;
}
