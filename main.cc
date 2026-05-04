#include <iostream>
#include <vector> 
#include <cassert>
class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<float>data; 
    inline void check_bounds(size_t r, size_t c) { 
        assert(r <= rows);
        assert(c <= cols);
    } 
public:
    
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r * c) {};

    float& operator()(size_t r, size_t c){
        check_bounds(r, c);  
        return data[r * cols + c];      
    }
};

int main() {
    Matrix m(3, 3);
    m(3, 3) = 30;
    std::cout << m(0, 0);
    return 0;

}




