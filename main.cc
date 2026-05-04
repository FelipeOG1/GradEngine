#include <iostream>
#include <vector> 
#include <cassert>
#include <concepts>
#include<type_traits>


class Matrix {
private:
    size_t _rows;
    size_t _cols;
    std::vector<float>_data;
    inline void check_bounds(size_t r, size_t c) const { 
        assert(r <= _rows);
        assert(c <= _cols);
    }
    inline void check_dims(const Matrix& other) const {
        assert(_rows == other._rows);
        assert(_cols == other._cols);
    }
    
public:
    Matrix(size_t r, size_t c) : _rows(r), _cols(c), _data(r * c) {};
    float& operator()(size_t r, size_t c){
        check_bounds(r, c);  
        return _data[r * _cols + c];      
    }
    
    
    Matrix operator+(float scalar) {
        for (int i=0; i < (_rows*_cols); i++) {
            _data[i] += scalar;
        }
        return *(this);
    }
    
    Matrix operator+(const Matrix& other) {
        check_dims(other);
           
    }
    
    size_t rows() const { return _rows; }
    size_t cols() const { return _cols; }
    
    
};

int main() {
    Matrix m(30, 3);
    std::cout << m.rows();
    return 0;

}




