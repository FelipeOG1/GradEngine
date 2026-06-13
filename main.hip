#include "tensor.h"
#include <iostream>
#include <vector>
#include <memory>
#include "engine.h"
int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    
    a.set_requires_grad(true);
    b.set_requires_grad(true);
    
    Tensor c = a + b;
    std::cout << *c.creator_node()->parents[0] << std::endl;
    
    
    
    return 0;
}
