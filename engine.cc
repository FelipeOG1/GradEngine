#include <engine.h>
#include <iostream>
#include <tensor.h>
namespace Engine {
	void show_parents(Tensor& child) {
		
		std::cout << child.parents_node->a_data;
		std::cout << child.parents_node->a_data;

	}
}

