#pragma once
#include <vector>
#include <memory>

//TODO replace a_data, b_datad with actual std::shared_ptr<Tensor> and implement a copy constructor that performs shallow  copies.
// So std::make_share(Tensor& a) do not recreate same Tensor on RAM.

class Tensor;
enum class OpCode;
struct Node {
    std::vector<std::shared_ptr<Tensor>> parents;
    OpCode op;

    Node(std::shared_ptr<Tensor> a,std::shared_ptr<Tensor> b,OpCode operation)
    : op(operation) {

        parents.push_back(std::move(a));
        parents.push_back(std::move(b));
    }
};
namespace Engine {

void show_parents(Tensor& child);

void setup_stuff(const Tensor& a, const Tensor& b, Tensor& c, OpCode op);

};

