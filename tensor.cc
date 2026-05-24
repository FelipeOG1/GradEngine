#include "tensor.h"

void Tensor::upload_to_device(float* host_ptr, size_t size) {
	_data.upload(host_ptr, size); 
}

void Tensor::download_to_host(float* host_ptr, size_t size) { 
	_data.download(host_ptr, size);
}
void Tensor::show_data() {
	std::vector<float> tmp(_size);
	download_to_host(tmp.data(), tmp.size());
	
	for (const auto &value : tmp) {
		std::cout<< value << std::endl;
	}
		
}

 
Tensor Tensor::rand(size_t r, size_t c) {
    Tensor result(r, c);
    static std::mt19937 rng(
        std::random_device{}()
    );

    std::uniform_real_distribution<float>
        dist(0.0f, 1.0f);
    
    std::vector<float> tmp(r * c);
    for (size_t i=0; i < result.size(); i++) {
        tmp[i] = dist(rng); 
    }
    
    result.upload_to_device(tmp.data(), tmp.size());
    
    return result;
}

Tensor Tensor::randint(size_t r, size_t c, int low, int high) {
    Tensor result(r, c);
    static std::mt19937 rng(
        std::random_device{}()
    );

    std::uniform_int_distribution<int>
        dist(low, high - 1);
    
    std::vector<float> tmp(r * c);
    
    for (size_t i = 0; i < result.size(); i++) {
        tmp[i] = static_cast<float>(dist(rng));    
    }

    result.upload_to_device(tmp.data(), tmp.size());

    return result;
}
