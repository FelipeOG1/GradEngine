#include <iostream>
#include "tensor.h"
int main() {
    Tensor a(10, 3);
    Tensor b(3, 30);
    Tensor out = Tensor::matmul(a, b);
    return 0;

}
