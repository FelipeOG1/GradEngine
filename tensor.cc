#include "tensor.h"
#include <iostream>
Tensor::Tensor(size_t r, size_t c)
    : _rows(r),
      _cols(c),
      _data(r * c),
      _size(r * c) {}

float& Tensor::operator()(size_t r, size_t c) {
    check_bounds(r, c);
    return _data[r * _cols + c];
}

const float& Tensor::operator()(size_t r, size_t c) const {
    check_bounds(r, c);
    return _data[r * _cols + c];
}

Tensor Tensor::operator+(float scalar) const {
    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] += scalar;
    }

    return result;
}

Tensor Tensor::operator+(const Tensor& other) const {
    check_dims(other);

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] += other._data[i];
    }

    return result;
}

Tensor Tensor::operator-(float scalar) const {
    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] -= scalar;
    }

    return result;
}

Tensor Tensor::operator-(const Tensor& other) const {
    check_dims(other);

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] -= other._data[i];
    }

    return result;
}

Tensor Tensor::operator*(const Tensor& other) const {
     check_dims(other);

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] *= other._data[i];
    }

    return result;
 
}
Tensor Tensor::operator*(float scalar) const {

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] *= scalar;
    }

    return result;
}


Tensor Tensor::operator/(const Tensor& other) const {
    check_dims(other);

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] /= other._data[i];
    }

    return result;
 
}

Tensor Tensor::operator/(float scalar) const {

    Tensor result(*this);

    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] /= scalar;
    }

    return result;
}

Tensor Tensor::dot(const Tensor& other) const {
    check_dot_dims(other);
    Tensor result(*this);
    for (int i=0; i < result.rows(); i++) {
        for (int j=0; j < result.cols(); j++) {
            std::cout << result(i, j) << std::endl;
        }
    } 
    
    return result;
}

size_t Tensor::rows() const {
    return _rows;
}

size_t Tensor::cols() const {
    return _cols;
}

size_t Tensor::size() const {
    return _size;
}