#include <iostream>
#include "tensor.h"
#include "gpuBuffer.hpp"
#include <vector>



__global__ void matrixMulKernel(float *Md, float *Nd, float Pd) {
    int tx = threadIdx.x;
    int ty = threadIdx.y;
}

int main() {
    Tensor M = Tensor::rand(3, 3);
    Tensor N = Tensor::rand(3, 3);
    Tensor P = Tensor::rand(3, 3);
    Tensor ans = Tensor::matmul_square(M, N);
    
    for (auto v : ans) {
        std::cout << v << std::endl;
    }
    return 0;

}
