#include "tensor.h"
Tensor::Tensor(size_t r, size_t c)
    : _rows(r),
      _cols(c),
      _data(r * c),
      _size(r * c) {}


Tensor Tensor::rand(size_t r, size_t c) {
    Tensor result(r, c);
    static std::mt19937 rng(
        std::random_device{}()
    );

    std::uniform_real_distribution<float>
        dist(0.0f, 1.0f);
    
    for (int i=0; i < result.size(); i++) {
        result._data[i] = dist(rng);    
    }

    return result;
}

Tensor Tensor::dot(const Tensor& a, const Tensor& b) {
       
}

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


size_t Tensor::rows() const {
    return _rows;
}

size_t Tensor::cols() const {
    return _cols;
}

size_t Tensor::size() const {
    return _size;
}
