#pragma once
#include "ops/opcodes.h"
#include <vector>
#include <memory>

//TODO replace a_data, b_datad with actual std::shared_ptr<Tensor> and implement a copy constructor that performs shallow  copies.
// So std::make_share(Tensor& a) do not recreate same Tensor on RAM.

class Tensor;

struct Node {
    const float* a_data;
    const float* b_data;
    const float* c_data;
    OpCode op;

    Node(const float* a, const float* b, const float* c, OpCode operation)
    : a_data(a), b_data(b), c_data(c), op(operation) {}
};
namespace Engine {

void show_parents(Tensor& child);

};

