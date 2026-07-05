#include "tensor.h"
#include <iostream>
#include <vector>
#include <memory>
#include "engine.h"
int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    Tensor c = a + b;
    std::cout << c.parents_node->a_data << std::endl;
    return 0;
}
