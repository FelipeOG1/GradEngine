#include "tensor.h"
#include <iostream>
#include <vector>
#include <memory>
#include "engine.h"
#include "ops/opcodes.h"
int main() {
    
    Tensor a = Tensor::randint(2, 2, 1, 10);
    Tensor b = Tensor::randint(2, 2, 1, 10);
    Tensor c = a + b;
    Tensor d = c + a;
    
    Engine::show_parents(d);    
    return 0;
}
