#pragma once

#include <cassert>
#include <cstddef>
#include <vector>
#include <random>
#include <iostream>
class Tensor {
private:
    size_t _rows;
    size_t _cols;
    size_t _size;
    std::vector<float> _data;
    std::vector<float> _grad;

    inline void check_bounds(size_t r, size_t c) const {
        assert(r < _rows);
        assert(c < _cols);
    }

    inline void check_dims(const Tensor& other) const {
        assert(_rows == other._rows);
        assert(_cols == other._cols);
    }
    
    static inline void matmul_dims(const Tensor& a, const Tensor& b) {
        assert(a.cols() == b.rows());
    }
    
public:
    Tensor(size_t r, size_t c);
    static Tensor rand(size_t r, size_t c);
    static Tensor randint(size_t r, size_t c, int low, int high);
    static Tensor matmul(const Tensor& a, const Tensor& b);
    
    void show();
    
    float& operator()(size_t r, size_t c);
    const float& operator()(size_t r, size_t c) const;

    Tensor operator+(float scalar) const;
    Tensor operator+(const Tensor& other) const;

    Tensor operator-(float scalar) const;
    Tensor operator-(const Tensor& other) const;
    
    Tensor operator*(float scalar) const;
    Tensor operator*(const Tensor& other) const;
    
    Tensor operator/(float scalar) const;
    Tensor operator/(const Tensor& other) const;

    
    size_t rows() const;
    size_t cols() const;
    size_t size() const;
};
