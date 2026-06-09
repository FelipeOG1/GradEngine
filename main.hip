#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>
#include <tuple>



int main() {
    
    std::vector<float>mat = {3.0 ,3.0f,
                           2.0f,2.0f};
    Tensor t(mat, 2, 2);
    Tensor a = Tensor::full(3, 3, 10);
    std::cout << a(2, 1) << std::endl;
    dim3 grid(1);
    dim3 block(8);
    
}


