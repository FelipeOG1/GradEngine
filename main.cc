#include <iostream>
#include <vector> 
class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<float>data;   
public:
    
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r * c) {};

    float& operator()(size_t r, size_t c){
          
    }
};

int main() {
    Matrix m(2, 20);
    
    return 0;

}




