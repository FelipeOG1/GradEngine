#include <tensor.h>
#include <iostream>

int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    Tensor c = a.matsum(b);
    Tensor d = a.matsub(b);

    return 0;
}
