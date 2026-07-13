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

	void create_parents_node(const Tensor& a, const Tensor& b, Tensor& c, OpCode op) {
		auto a_ptr = std::make_shared<Tensor>(a);
		auto b_ptr = std::make_shared<Tensor>(b);
		auto new_node = std::make_shared<Node>(a_ptr, b_ptr, OpCode::SUM);
		c.parents_node = new_node;	
	}

         
    
};

