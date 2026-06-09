#pragma once
#include <cassert>
#include "gpu_buffer.hpp"
#include <vector>
#include <cassert>
#include <cstddef>
#include <vector>
#include <random>
#include <iostream>

class Tensor {
private:
    GpuBuffer _data;
    size_t _size;
    std::vector<size_t> _shape;
public:
    Tensor(size_t r, size_t c) : _data(r * c), _size( r * c ), _shape(2) { _shape[0] = r; _shape[1] = c; }
    Tensor(std::vector<float>& matrix, size_t r, size_t c) : _data(r*c), _shape(2) {
        _shape[0] = r; _shape[1]= c;
        _data.upload(matrix.data(), matrix.size());
        
    }
    
    static Tensor rand(size_t r, size_t c);
    static Tensor randint(size_t r, size_t c, int low, int high);
    static Tensor full(size_t r, size_t c, float value);
    static Tensor zeros(size_t r, size_t c);


    void upload_to_device(float* host_ptr, size_t size);
    void download_to_host(float* host_ptr, size_t size);
	void show_data();
    
    float operator()(size_t r, size_t c);
    

    size_t size() const { return _size; }
    const std::vector<size_t>& shape() const { return _shape; }
	
	float* data() { return _data.data(); }
	const float* data() const { return _data.data(); }
	; 
       
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Tensor& t) {
    os << "Tensor(shape=" << t.shape() << ", size=" << t.size() << ")";
    return os;
}

