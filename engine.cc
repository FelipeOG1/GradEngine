#include <engine.h>
#include <tensor.h>
#include<ops/opcodes.h>
namespace Engine {
	void show_parents(Tensor& child) {
		for (auto& parent : child.parents_node->parents) {
			parent->show_data();
		}
	}

	void create_parents_node(const Tensor& a, const Tensor& b, Tensor& c, OpCode op) {
		auto a_ptr = std::make_shared<Tensor>(a);
		auto b_ptr = std::make_shared<Tensor>(b);
		auto new_node = std::make_shared<Node>(a_ptr, b_ptr, op);
		c.parents_node = new_node;	
  }
  
  void create_parents_node(const Tensor& a, Tensor& c, OpCode op) {
		auto a_ptr = std::make_shared<Tensor>(a);
		auto new_node = std::make_shared<Node>(a_ptr, op);
    c.parents_node = new_node;
  }
    
};

