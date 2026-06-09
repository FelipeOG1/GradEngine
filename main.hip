#include <tensor.h>
int main() {
    Tensor a = Tensor::randint(4, 4, 1, 10);
    Tensor b = Tensor::randint(4, 4, 1, 10);
    Tensor c = a.matmul(b);
    
    return 0;
    
};
