#include <tensor.h>
#include <iostream>

int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    Tensor out = Tensor::relu(a);
    return 0;
}
