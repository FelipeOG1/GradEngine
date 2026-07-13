#include <engine.h>
#include <iostream>
#include <tensor.h>
#include <vector>
#include<ops/opcodes.h>
#include <unordered_set>
#include <array>
namespace Engine {
	void show_parents(Tensor& child) {
		for (auto& parent : child.parents_node->parents) {
			parent->show_data();
		}
	}


         
    
};

