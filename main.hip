#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>
#include <tuple>



int main() {
    std::vector<float>mat = {3.0f,3.0f,
                           2.0f,2.0f};
    Tensor t(mat, 2, 2);
    std::cout << t(0, 0) << std::endl;
    dim3 grid(2, 2, 1);
    dim3 block(2, 2, 1);
    
}


