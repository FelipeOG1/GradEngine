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

public:
    Tensor(size_t r, size_t c) : _data(r * c), _size( r * c ) {}
    
    static Tensor rand(size_t r, size_t c);
    static Tensor randint(size_t r, size_t c, int low, int high);

    void upload_to_device(float* host_ptr, size_t size) { _data.upload(host_ptr, size); }
    void dowload_to_host(float* host_ptr, size_t size) { _data.download(host_ptr, size); }
    
    Tensor operator()(size_t r, size_t c);
    

    size_t size() const { return _size; }
    
    
};

