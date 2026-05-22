#include <iostream>
#include "tensor.h"
#include "GTensor.hpp"
#include <vector>

__global__ void matrixMulKernel(GTensor m, GTensor n, GTensor p) {
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    size_t width = m.size();
    float t_value = 0;//value computed by thread.
    
    for (size_t k=0;  k < width; ++k) {
        float m_element = m.data()[ty * width + k];
        float n_element = n.data()[k * width + tx];
        t_value += m_element * n_element;
    }
    p.data()[ty * width + tx] = t_value;
}

int main() {
    GTensor m(Tensor::rand(3, 3));
    GTensor n(Tensor::rand(3, 3));
    GTensor p(Tensor(0, 0)); return 0;
}

