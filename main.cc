#include <iostream>
#include "tensor.h"
int main() {
    Tensor::matmul_square(Tensor::rand(3, 3), Tensor::rand(3, 3));
    return 0;

}
