#pragma once

#include <cassert>
#include <cstddef>
#include <vector>

class Matrix {
private:
    size_t _rows;
    size_t _cols;
    std::vector<float> _data;
    size_t _size;

    inline void check_bounds(size_t r, size_t c) const {
        assert(r < _rows);
        assert(c < _cols);
    }

    inline void check_dims(const Matrix& other) const {
        assert(_rows == other._rows);
        assert(_cols == other._cols);
    }

public:
    Matrix(size_t r, size_t c);

    float& operator()(size_t r, size_t c);
    const float& operator()(size_t r, size_t c) const;

    Matrix operator+(float scalar) const;
    Matrix operator+(const Matrix& other) const;

    Matrix operator-(float scalar) const;
    Matrix operator-(const Matrix& other) const;

    size_t rows() const;
    size_t cols() const;
    size_t size() const;
};
