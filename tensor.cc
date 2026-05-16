#include "tensor.h"
Tensor::Tensor(size_t r, size_t c)
    : _rows(r),
      _cols(c),
      _data(r * c),
      _grad(r * c),
      _size(r * c)  {}

Tensor Tensor::rand(size_t r, size_t c) {
    Tensor result(r, c);
    static std::mt19937 rng(
        std::random_device{}()
    );

    std::uniform_real_distribution<float>
        dist(0.0f, 1.0f);
    
    for (size_t i=0; i < result.size(); i++) {
        result._data[i] = dist(rng);    
    }

    return result;
}

Tensor Tensor::randint(size_t r, size_t c, int low, int high) {
    Tensor result(r, c);
    static std::mt19937 rng(
        std::random_device{}()
    );

    std::uniform_int_distribution<int>
        dist(low, high - 1);
    
    for (size_t i = 0; i < result.size(); i++) {
        result._data[i] = static_cast<float>(dist(rng));    
    }

    return result;
}

Tensor Tensor::matmul(const Tensor &a, const Tensor &b) {
    matmul_dims(a, b);
    Tensor out(a.rows(), b.cols());
    size_t width = a.cols();
    
    
    return out;
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
