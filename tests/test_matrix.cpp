#include <cassert>
#include "../matrix.h"
#include <iostream>
void test_matrix_addition() {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a(0,0) = 1;
    a(0,1) = 2;
    a(1,0) = 3;
    a(1,1) = 4;

    b(0,0) = 10;
    b(0,1) = 20;
    b(1,0) = 30;
    b(1,1) = 40;

    Matrix result = a + b;

    assert(result(0,0) == 11);
    assert(result(0,1) == 22);
    assert(result(1,0) == 33);
    assert(result(1,1) == 44);
}

void test_scalar_subtraction() {
    Matrix m(2, 2);

    m(0,0) = 10;
    m(0,1) = 20;
    m(1,0) = 30;
    m(1,1) = 40;

    Matrix result = m - 5.0f;

    assert(result(0,0) == 5);
    assert(result(0,1) == 15);
    assert(result(1,0) == 25);
    assert(result(1,1) == 35);
}

void test_matrix_subtraction() {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a(0,0) = 10;
    a(0,1) = 20;
    a(1,0) = 30;
    a(1,1) = 40;

    b(0,0) = 1;
    b(0,1) = 2;
    b(1,0) = 3;
    b(1,1) = 4;

    Matrix result = a - b;

    assert(result(0,0) == 9);
    assert(result(0,1) == 18);
    assert(result(1,0) == 27);
    assert(result(1,1) == 36);
}

void test_scalar_multiplication() {
    Matrix m(2, 2);

    m(0,0) = 1;
    m(0,1) = 2;
    m(1,0) = 3;
    m(1,1) = 4;

    Matrix result = m * 2.0f;

    assert(result(0,0) == 2);
    assert(result(0,1) == 4);
    assert(result(1,0) == 6);
    assert(result(1,1) == 8);
}

void test_matrix_multiplication() {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a(0,0) = 1;
    a(0,1) = 2;

    b(0,0) = 2;
    b(0,1) = 3;

    Matrix result = a * b;
    assert (result(0, 0) == 2);
    assert (result(0, 1) == 6);
    
}

void test_scalar_division() {
    Matrix m(2, 2);

    m(0,0) = 10;
    m(0,1) = 20;
    m(1,0) = 30;
    m(1,1) = 40;

    Matrix result = m / 2.0f;

    assert(result(0,0) == 5);
    assert(result(0,1) == 10);
    assert(result(1,0) == 15);
    assert(result(1,1) == 20);
}

void test_matrix_division() {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a(0,0) = 10;
    a(0,1) = 20;
    a(1,0) = 30;
    a(1,1) = 40;

    b(0,0) = 2;
    b(0,1) = 4;
    b(1,0) = 5;
    b(1,1) = 8;

    Matrix result = a / b;

    assert(result(0,0) == 5);
    assert(result(0,1) == 5);
    assert(result(1,0) == 6);
    assert(result(1,1) == 5);
}

void test_dot() {
    Matrix a(2, 2);
    Matrix b(2, 2);
    a.dot(b);   
    
}

int main() {
    test_matrix_addition();
    test_scalar_subtraction();
    test_matrix_subtraction();
    test_scalar_multiplication();
    test_matrix_multiplication();
    test_scalar_division();
    test_matrix_division();
    test_dot();
    
    std::cout << "All tests passed.\n";

    return 0;
}
