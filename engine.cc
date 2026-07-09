#include <engine.h>
#include <iostream>
#include <tensor.h>
#include <vector>
#include<ops/opcodes.h>
#include <unordered_set>
#include <array>
namespace Engine {
	void show_parents(Tensor& child) {
		
		child.parents_node->dad->show_data();
		child.parents_node->mom->show_data();

	}


         
    
};
    

