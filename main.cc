#include <iostream>
#include "tensor.h"
int main() {
    Tensor m(20, 10);
    std::cout << m(0, 0);     
    return 0;

}