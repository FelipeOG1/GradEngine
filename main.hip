#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>

int main() {
    Tensor a = Tensor::rand(3, 3);
    Tensor b = Tensor::rand(2, 2);
    Tensor c = Tensor::randint(3, 3, 1, 10);
    Tensor d = Tensor::randint(3, 3, 1, 10);
    std::cout << d << std::endl;
    return 0;
}

