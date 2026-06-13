#pragma once
#include "ops/opcodes.h"
#include <vector>
#include <memory>

class Tensor;

struct GraphNode {
    OpCode op;
    std::vector<std::shared_ptr<Tensor>> parents;
    
    GraphNode(OpCode op, std::vector<std::shared_ptr<Tensor>> inputs) : op(op), parents(std::move(inputs)) {}
    GraphNode(OpCode op, std::shared_ptr<Tensor> a) : op(op), parents{std::move(a)} {}
    GraphNode(OpCode op, std::shared_ptr<Tensor> a, std::shared_ptr<Tensor> b) : op(op), parents{std::move(a), std::move(b)} {}
};

class AutoGradEngine {
private:
    AutoGradEngine() {}
public:
    AutoGradEngine(const AutoGradEngine&) = delete;
    AutoGradEngine& operator=(const AutoGradEngine&) = delete;
    

    static AutoGradEngine& get_instance() {
        static AutoGradEngine instance;
        return instance;
    }


   
    

    
};
