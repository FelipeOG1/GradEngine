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

void test_dot() {
    Tensor a(2, 2);
    Tensor b(2, 2);
    a.dot(b);   
    
}

int main() {
    test_tensor_addition();
    test_scalar_subtraction();
    test_tensor_subtraction();
    test_scalar_multiplication();
    test_tensor_multiplication();
    test_scalar_division();
    test_tensor_division();
    test_dot();
    
    std::cout << "All tests passed.\n";

    return 0;
}