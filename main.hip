#include <iostream>
#include "tensor.h"
#include "gpu_buffer.hpp"
#include <vector>
#include <chrono>
#include <tuple>


int main() {
    
    std::vector<float>a = {3.0 ,3.0f, 3.2, 2.4f,
                           2.0f, 2.3f, 3.0f, 1.0f,
                           3.0f, 1.0f, 1.3f, 3.3f,
                           3.0f, 1.0f, 1.3f, 3.3f};
    
    std::vector<float>b = {2.0, 5.0f, 2.2, 10.4f,
                           2.0f, 1.3f, 3.0f, 1.0f,
                           10.0f, 1.0f, 1.3f, 3.3f,
                           3.0f, 1.0f, 1.3f, 3.3f};
    
    
    Tensor m(a, 4, 4);
    Tensor n(b, 4, 4);
    Tensor(3, 3);
    Tensor z = Tensor::zeros(3, 3);
    

    std::cout<< z(0, 1) << std::endl;
    
    
    
}


