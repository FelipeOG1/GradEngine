#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>

__global__ void matrixMulKernel(float* m, float* n, float* p, int width) {
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    float t_value = 0; //value computed by thread.
    
    for (int k=0;  k < width; ++k) {
        float m_element = m[ty * width + k];
        float n_element = n[k * width + tx];
        t_value += m_element * n_element;
    }
    p[ty * width + tx] = t_value;
}
int main() {
    GpuBuffer g(30);
    return 0;
}

