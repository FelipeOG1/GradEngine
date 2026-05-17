#include <iostream>
#include "tensor.h"
#include "gpuBuffer.hpp"
#include <vector>
int main() {
    std::vector<float> v = {3.3f, 3.2f};
    GpuBuffer data(v.size() * sizeof(float));
    data.upload(v.data(), v.size() * sizeof(float));

    std::vector<float>dest(v.size());
    data.download(dest.data(), dest.size() * sizeof(float));
    
    for (auto& d : dest) {
        std::cout << d << std::endl;
    }
    return 0;

}
