#include <iostream>
#include "tensor.h"
#include "gpuBuffer.hpp"
#include <vector>

__global__ void matrixMulKernel(float* md, float* nd, float* pd, int width) {
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    float t_value = 0;//value computed by thread.
    
    for (size_t k=0;  k < width; ++k) {
        float m_element = md[ty * width + k];
        float n_element = nd[k * width + tx];
        t_value += m_element * n_element;
    }
    pd[ty * width + tx] = t_value;
}

int main() {
    Tensor m(3, 3);
    Tensor n(3, 3);
    Tensor p(3, 3);
    GpuBuffer md(m.size());
    GpuBuffer nd(n.size());
    GpuBuffer pd(p.size());
    md.upload()
    return 0;

}
