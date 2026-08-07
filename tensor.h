#pragma once
#include <cassert>
#include "gpu_buffer.hpp"
#include <vector>
#include <cstddef>
#include <iostream>
#include <memory>
#include <functional>
struct Node;

class Tensor {
private:
    GpuBuffer _data;
    size_t _size;
    std::vector<size_t> _shape;
    bool _requires_grad = false;
    std::vector<float> _host_data; //only use for start() and end();
    void _sync_host_to_device();
    void _upload_to_device(float* host_ptr, size_t size);
    void _download_to_host(float* host_ptr, size_t size);
  
      
public:
    std::function<void()> backward;
    std::shared_ptr<Node> parents_node = nullptr;
    std::shared_ptr<Tensor> grad = nullptr;
    Tensor(size_t r, size_t c) : _data(r * c), _size( r * c ), _shape(2){ 
      _shape[0] = r;
      _shape[1] = c;
    }
    
    Tensor(std::vector<float>& matrix, size_t r, size_t c) : _data(r*c), _size(r*c), _shape(2) {
        _shape[0] = r; _shape[1]= c;
        _data.upload(matrix.data(), matrix.size());

    }
    // Static operations 
    static Tensor rand(size_t r, size_t c);
    static Tensor randint(size_t r, size_t c, int low, int high);
    static Tensor full(size_t r, size_t c, float value);
    static Tensor zeros(size_t r, size_t c);
    
   
  
    //operations
    
    //standard matrix
    Tensor matmul(const Tensor& other);
    
    
    //element wise
    Tensor operator+(const Tensor& other);
    Tensor operator/(const Tensor& other);
    Tensor operator*(const Tensor& other);


    static Tensor relu(const Tensor& t);
    
    

    void show_data();
    
    
    float operator()(size_t r, size_t c);
    

    size_t size() const { return _size; }
    const std::vector<size_t>& shape() const { return _shape; }
	
	  float* data() { return _data.data(); }
	  const float* data() const { return _data.data(); }
    
	  // Autograd methods
    bool requires_grad() const { return _requires_grad; }
	  void set_requires_grad(bool requires_grad); 
    
    //iterators
    float* begin() {
      _sync_host_to_device();
      return _host_data.data();
    }
    
    float* end() {
      return _host_data.data() + _host_data.size();
    }


 
        
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

