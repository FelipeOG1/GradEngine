#pragma once
#include "ops/opcodes.h"
#include <vector>
#include <memory>

class Tensor;
struct GraphNode {
    OpCode op;
    std::vector<std::shared_ptr<Tensor>> parents;
    
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
