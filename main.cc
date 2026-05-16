#include <iostream>
#include "tensor.h"
int main() {
    Tensor a = Tensor::rand(3, 3); 
    std::cout << a(0, 0);
    return 0;

}
