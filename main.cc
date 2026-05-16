#include <iostream>
#include "tensor.h"
int main() {
    Tensor a(2, 3);
    Tensor b(3, 10);
    Tensor out = Tensor::matmul(a, b);
    return 0;

}
