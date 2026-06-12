#include <engine.h>

void test_constructor() {
    std::vector<float> a_data = {2.0f, 3.0f, 2.0f, 2.3f};
    
    std::vector<float> b_data = {1.0f, 10.0f, 3.0f, 1.3f};

    OpCode op {OpCode::DIV};
    Tensor a(a_data, 2, 2);
    Tensor b(b_data, 2, 2);
    
}

