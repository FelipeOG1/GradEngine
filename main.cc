#include <iostream>
#include "tensor.h"
#include "gpuBuffer.hpp"
#include <vector>
int main() {
    Tensor M = Tensor::rand(3, 3);
    Tensor N = Tensor::rand(3, 3);
    Tensor P = Tensor::rand(3, 3);
    
    size_t size_alloc = (M.size() + N.size()) * sizeof(float);
    GpuBuffer b(size_alloc);
    b.upload(M.data(), M.size());
    
    return 0;

}
