#include "tensor.h"
#include <iostream>
#include <vector>
#include <memory>
#include "engine.h"
int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    
    // Activamos requires_grad para que capture los padres
    a.set_requires_grad(true);
    b.set_requires_grad(true);
    
    Tensor c = a + b;
    
    // Verificamos que c capturó los padres
    if (c.creator_node()) {
        std::cout << "Tensor c capturó un GraphNode!\n";
        std::cout << "Op: " << (c.creator_node()->op == OpCode::SUM ? "SUM" : "OTRO") << "\n";
        std::cout << "Numero de padres: " << c.creator_node()->parents.size() << "\n";
        
        for (size_t i = 0; i < c.creator_node()->parents.size(); ++i) {
            std::cout << "Padre " << i << ": " << *c.creator_node()->parents[i] << "\n";
        }
    } else {
        std::cout << "Tensor c NO tiene GraphNode\n";
    }
    
    return 0;
}
