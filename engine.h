#pragma once
#include <vector>
#include <memory>

//TODO replace a_data, b_datad with actual std::shared_ptr<Tensor> and implement a copy constructor that performs shallow  copies.
// So std::make_share(Tensor& a) do not recreate same Tensor on RAM.

class Tensor;
enum class OpCode;
struct Node {
	std::shared_ptr<Tensor> dad;
	std::shared_ptr<Tensor> mom;
    OpCode op;

    Node(std::shared_ptr<Tensor> a,std::shared_ptr<Tensor> b,OpCode operation)
    : dad(a), mom(b), op(operation) {}
};
namespace Engine {

void show_parents(Tensor& child);



};

