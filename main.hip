#include "tensor.h"
#include <iostream>
#include <vector>
#include <memory>
#include "engine.h"
int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    Tensor c = a + b;
	//Engine::show_parents(c);
	auto a_ptr = std::make_shared<Tensor>(a);
	a.show_data();
	a_ptr->show_data();

    return 0;
}
