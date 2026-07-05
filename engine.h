#pragma once
#include "ops/opcodes.h"
#include <vector>
#include <memory>

struct Node {
    const float* a_data;
    const float* b_data;
    const float* c_data;
    OpCode op;

    Node(const float* a, const float* b, const float* c, OpCode operation)
        : a_data(a), b_data(b), c_data(c), op(operation) {}
};

