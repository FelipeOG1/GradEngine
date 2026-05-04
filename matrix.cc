#include "matrix.h"

Matrix::Matrix(size_t r, size_t c)
    : _rows(r),
      _cols(c),
      _data(r * c),
      _size(r * c) {}

float& Matrix::operator()(size_t r, size_t c) {
    check_bounds(r, c);
    return _data[r * _cols + c];
}

const float& Matrix::operator()(size_t r, size_t c) const {
    check_bounds(r, c);
    return _data[r * _cols + c];
}

Matrix Matrix::operator+(float scalar) const {
    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] += scalar;
    }

    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    check_dims(other);

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] += other._data[i];
    }

    return result;
}

Matrix Matrix::operator-(float scalar) const {
    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] -= scalar;
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    check_dims(other);

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] -= other._data[i];
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
     check_dims(other);

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] *= other._data[i];
    }

    return result;
 
}
Matrix Matrix::operator*(float scalar) const {

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] *= scalar;
    }

    return result;
}


Matrix Matrix::operator/(const Matrix& other) const {
    check_dims(other);

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] /= other._data[i];
    }

    return result;
 
}

Matrix Matrix::operator/(float scalar) const {

    Matrix result(*this);

    for (size_t i = 0; i < _size; i++) {
        result._data[i] /= scalar;
    }

    return result;
}

Matrix Matrix::dot(const Matrix& other) const {
    check_dot_dims(other);
    Matrix result(*this);
    
}

size_t Matrix::rows() const {
    return _rows;
}

size_t Matrix::cols() const {
    return _cols;
}

size_t Matrix::size() const {
    return _size;
}
