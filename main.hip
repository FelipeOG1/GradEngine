#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>

int main() {
    Tensor a = Tensor::rand(3, 3);
    Tensor b = Tensor::rand(2, 2);
    
    return 0;
}

