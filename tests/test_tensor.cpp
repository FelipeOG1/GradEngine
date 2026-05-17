#include <cassert>
#include "../tensor.h"
#include <iostream>
void test_tensor_addition() {
    Tensor a(2, 2);
    Tensor b(2, 2);

    a(0,0) = 1;
    a(0,1) = 2;
    a(1,0) = 3;
    a(1,1) = 4;

    b(0,0) = 10;
    b(0,1) = 20;
    b(1,0) = 30;
    b(1,1) = 40;

    Tensor result = a + b;

    assert(result(0,0) == 11);
    assert(result(0,1) == 22);
    assert(result(1,0) == 33);
    assert(result(1,1) == 44);
}

void test_scalar_subtraction() {
    Tensor m(2, 2);

    m(0,0) = 10;
    m(0,1) = 20;
    m(1,0) = 30;
    m(1,1) = 40;

    Tensor result = m - 5.0f;

    assert(result(0,0) == 5);
    assert(result(0,1) == 15);
    assert(result(1,0) == 25);
    assert(result(1,1) == 35);
}

void test_tensor_subtraction() {
    Tensor a(2, 2);
    Tensor b(2, 2);

    a(0,0) = 10;
    a(0,1) = 20;
    a(1,0) = 30;
    a(1,1) = 40;

    b(0,0) = 1;
    b(0,1) = 2;
    b(1,0) = 3;
    b(1,1) = 4;

    Tensor result = a - b;

    assert(result(0,0) == 9);
    assert(result(0,1) == 18);
    assert(result(1,0) == 27);
    assert(result(1,1) == 36);
}

void test_scalar_multiplication() {
    Tensor m(2, 2);

    m(0,0) = 1;
    m(0,1) = 2;
    m(1,0) = 3;
    m(1,1) = 4;

    Tensor result = m * 2.0f;

    assert(result(0,0) == 2);
    assert(result(0,1) == 4);
    assert(result(1,0) == 6);
    assert(result(1,1) == 8);
}

void test_tensor_multiplication() {
    Tensor a(2, 2);
    Tensor b(2, 2);

    a(0,0) = 1;
    a(0,1) = 2;

    b(0,0) = 2;
    b(0,1) = 3;

    Tensor result = a * b;
    assert (result(0, 0) == 2);
    assert (result(0, 1) == 6);
    
}

void test_scalar_division() {
    Tensor m(2, 2);

    m(0,0) = 10;
    m(0,1) = 20;
    m(1,0) = 30;
    m(1,1) = 40;

    Tensor result = m / 2.0f;

    assert(result(0,0) == 5);
    assert(result(0,1) == 10);
    assert(result(1,0) == 15);
    assert(result(1,1) == 20);
}

void test_tensor_division() {
    Tensor a(2, 2);
    Tensor b(2, 2);

    a(0,0) = 10;
    a(0,1) = 20;
    a(1,0) = 30;
    a(1,1) = 40;

    b(0,0) = 2;
    b(0,1) = 4;
    b(1,0) = 5;
    b(1,1) = 8;

    Tensor result = a / b;

    assert(result(0,0) == 5);
    assert(result(0,1) == 5);
    assert(result(1,0) == 6);
    assert(result(1,1) == 5);
}

void test_matmul_square_2x2() {
    Tensor a(2, 2);
    Tensor b(2, 2);

    a(0,0) = 1; a(0,1) = 2;
    a(1,0) = 3; a(1,1) = 4;

    b(0,0) = 5; b(0,1) = 6;
    b(1,0) = 7; b(1,1) = 8;

    Tensor result = Tensor::matmul_square(a, b);

    assert(result(0,0) == 19);
    assert(result(0,1) == 22);
    assert(result(1,0) == 43);
    assert(result(1,1) == 50);
}

void test_matmul_square_identity() {
    Tensor a(2, 2);
    Tensor I(2, 2);

    a(0,0) = 1; a(0,1) = 2;
    a(1,0) = 3; a(1,1) = 4;

    I(0,0) = 1; I(0,1) = 0;
    I(1,0) = 0; I(1,1) = 1;

    Tensor result = Tensor::matmul_square(a, I);

    assert(result(0,0) == 1);
    assert(result(0,1) == 2);
    assert(result(1,0) == 3);
    assert(result(1,1) == 4);
}

void test_matmul_square_3x3() {
    Tensor a(3, 3);
    Tensor b(3, 3);

    a(0,0) = 1; a(0,1) = 2; a(0,2) = 3;
    a(1,0) = 4; a(1,1) = 5; a(1,2) = 6;
    a(2,0) = 7; a(2,1) = 8; a(2,2) = 9;

    b(0,0) = 1; b(0,1) = 0; b(0,2) = 0;
    b(1,0) = 0; b(1,1) = 1; b(1,2) = 0;
    b(2,0) = 0; b(2,1) = 0; b(2,2) = 1;

    Tensor result = Tensor::matmul_square(a, b);

    assert(result(0,0) == 1);
    assert(result(0,1) == 2);
    assert(result(0,2) == 3);
    assert(result(1,0) == 4);
    assert(result(1,1) == 5);
    assert(result(1,2) == 6);
    assert(result(2,0) == 7);
    assert(result(2,1) == 8);
    assert(result(2,2) == 9);
}

void test_dot() {
    Tensor a = Tensor::randint(2, 2, 1, 5);
    Tensor b = Tensor::randint(3, 3, 1, 5);
    
    a.show(); 
    b.show();
}

void test_randint() {
    Tensor r = Tensor::randint(3, 3, 0, 10);
    
    for (size_t i = 0; i < r.rows(); i++) {
        for (size_t j = 0; j < r.cols(); j++) {
            int val = static_cast<int>(r(i, j));
            assert(val >= 0 && val < 10);
        }
    }
}

int main() {
    test_tensor_addition();
    test_scalar_subtraction();
    test_tensor_subtraction();
    test_scalar_multiplication();
    test_tensor_multiplication();
    test_scalar_division();
    test_tensor_division();
    test_matmul_square_2x2();
    test_matmul_square_identity();
    test_matmul_square_3x3();
    test_dot();
    test_randint();
    
    std::cout << "All tests passed.\n";

    return 0;
}
