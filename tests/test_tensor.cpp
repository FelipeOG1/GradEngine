#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>
#include "../tensor.h"

// Helper to compare floats with a small epsilon
static bool approx_eq(float a, float b, float eps = 1e-5f) {
    return std::fabs(a - b) < eps;
}

void test_constructor_from_vector() {
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f};
    Tensor t(data, 2, 2);

    assert(t.size() == 4);
    assert(t.shape()[0] == 2);
    assert(t.shape()[1] == 2);

    assert(approx_eq(t(0, 0), 1.0f));
    assert(approx_eq(t(0, 1), 2.0f));
    assert(approx_eq(t(1, 0), 3.0f));
    assert(approx_eq(t(1, 1), 4.0f));
}

void test_upload_download() {
    std::vector<float> data = {5.0f, 6.0f, 7.0f, 8.0f};
    Tensor t(2, 2);
    t.upload_to_device(data.data(), data.size());

    std::vector<float> downloaded(4);
    t.download_to_host(downloaded.data(), downloaded.size());

    assert(approx_eq(downloaded[0], 5.0f));
    assert(approx_eq(downloaded[1], 6.0f));
    assert(approx_eq(downloaded[2], 7.0f));
    assert(approx_eq(downloaded[3], 8.0f));
}

void test_zeros() {
    Tensor t = Tensor::zeros(2, 3);
    assert(t.size() == 6);
    assert(t.shape()[0] == 2);
    assert(t.shape()[1] == 3);

    for (size_t i = 0; i < t.shape()[0]; ++i) {
        for (size_t j = 0; j < t.shape()[1]; ++j) {
            assert(approx_eq(t(i, j), 0.0f));
        }
    }
}

void test_full() {
    Tensor t = Tensor::full(3, 2, 7.5f);
    assert(t.size() == 6);
    assert(t.shape()[0] == 3);
    assert(t.shape()[1] == 2);

    for (size_t i = 0; i < t.shape()[0]; ++i) {
        for (size_t j = 0; j < t.shape()[1]; ++j) {
            assert(approx_eq(t(i, j), 7.5f));
        }
    }
}

void test_randint() {
    Tensor t = Tensor::randint(4, 5, 10, 20);
    assert(t.size() == 20);
    assert(t.shape()[0] == 4);
    assert(t.shape()[1] == 5);

    for (size_t i = 0; i < t.shape()[0]; ++i) {
        for (size_t j = 0; j < t.shape()[1]; ++j) {
            float val = t(i, j);
            assert(val >= 10.0f && val < 20.0f);
        }
    }
}

void test_rand() {
    Tensor t = Tensor::rand(3, 3);
    assert(t.size() == 9);
    assert(t.shape()[0] == 3);
    assert(t.shape()[1] == 3);
    // Just verify values are in [0, 1)
    for (size_t i = 0; i < t.shape()[0]; ++i) {
        for (size_t j = 0; j < t.shape()[1]; ++j) {
            float val = t(i, j);
            assert(val >= 0.0f && val < 1.0f);
        }
    }
}

void test_matmul_standard() {
    // A = [1 2]  B = [5 6]   A*B = [19 22]
    //     [3 4]      [7 8]         [43 50]
    std::vector<float> a_data = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> b_data = {5.0f, 6.0f, 7.0f, 8.0f};
    Tensor a(a_data, 2, 2);
    Tensor b(b_data, 2, 2);

    Tensor result = a.matmul(b);

    assert(approx_eq(result(0, 0), 19.0f));
    assert(approx_eq(result(0, 1), 22.0f));
    assert(approx_eq(result(1, 0), 43.0f));
    assert(approx_eq(result(1, 1), 50.0f));
}

void test_matmul_non_square() {
    // A = [1 2 3]  B = [7  8]   A*B = [58  64]
    //     [4 5 6]      [9  10]        [139 154]
    //                  [11 12]
    std::vector<float> a_data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::vector<float> b_data = {7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f};
    Tensor a(a_data, 2, 3);
    Tensor b(b_data, 3, 2);

    Tensor result = a.matmul(b);

    assert(result.shape()[0] == 2);
    assert(result.shape()[1] == 2);

    assert(approx_eq(result(0, 0), 58.0f));
    assert(approx_eq(result(0, 1), 64.0f));
    assert(approx_eq(result(1, 0), 139.0f));
    assert(approx_eq(result(1, 1), 154.0f));
}

void test_matmul_identity() {
    std::vector<float> a_data = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> i_data = {1.0f, 0.0f, 0.0f, 1.0f};
    Tensor a(a_data, 2, 2);
    Tensor i(i_data, 2, 2);

    Tensor result = a.matmul(i);

    assert(approx_eq(result(0, 0), 1.0f));
    assert(approx_eq(result(0, 1), 2.0f));
    assert(approx_eq(result(1, 0), 3.0f));
    assert(approx_eq(result(1, 1), 4.0f));
}

void test_operator_add() {
    std::vector<float> a_data = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> b_data = {10.0f, 20.0f, 30.0f, 40.0f};
    Tensor a(a_data, 2, 2);
    Tensor b(b_data, 2, 2);

    Tensor result = a + b;

    assert(approx_eq(result(0, 0), 11.0f));
    assert(approx_eq(result(0, 1), 22.0f));
    assert(approx_eq(result(1, 0), 33.0f));
    assert(approx_eq(result(1, 1), 44.0f));
}

void test_operator_div() {
    // operator/ performs element-wise division
    std::vector<float> a_data = {10.0f, 20.0f, 30.0f, 40.0f};
    std::vector<float> b_data = {2.0f, 4.0f, 5.0f, 8.0f};
    Tensor a(a_data, 2, 2);
    Tensor b(b_data, 2, 2);

    Tensor result = a / b;

    assert(approx_eq(result(0, 0), 5.0f));
    assert(approx_eq(result(0, 1), 5.0f));
    assert(approx_eq(result(1, 0), 6.0f));
    assert(approx_eq(result(1, 1), 5.0f));
}

void test_operator_mul() {
    // operator* performs element-wise multiplication
    std::vector<float> a_data = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> b_data = {2.0f, 3.0f, 4.0f, 5.0f};
    Tensor a(a_data, 2, 2);
    Tensor b(b_data, 2, 2);

    Tensor result = a * b;

    assert(approx_eq(result(0, 0), 2.0f));
    assert(approx_eq(result(0, 1), 6.0f));
    assert(approx_eq(result(1, 0), 12.0f));
    assert(approx_eq(result(1, 1), 20.0f));
}

void test_relu() {
    std::vector<float> data = {-1.0f, 0.0f, 3.0f, -5.0f, 2.0f, -0.5f};
    Tensor t(data, 2, 3);

    Tensor result = Tensor::relu(t);

    assert(approx_eq(result(0, 0), 0.0f));
    assert(approx_eq(result(0, 1), 0.0f));
    assert(approx_eq(result(0, 2), 3.0f));
    assert(approx_eq(result(1, 0), 0.0f));
    assert(approx_eq(result(1, 1), 2.0f));
    assert(approx_eq(result(1, 2), 0.0f));
}

void test_operator_parenthesis() {
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    Tensor t(data, 2, 3);

    assert(approx_eq(t(0, 0), 1.0f));
    assert(approx_eq(t(0, 1), 2.0f));
    assert(approx_eq(t(0, 2), 3.0f));
    assert(approx_eq(t(1, 0), 4.0f));
    assert(approx_eq(t(1, 1), 5.0f));
    assert(approx_eq(t(1, 2), 6.0f));
}

void test_show_data() {
    // Just ensure it doesn't crash
    std::vector<float> data = {1.0f, 2.0f, 3.0f, 4.0f};
    Tensor t(data, 2, 2);
    t.show_data();
}

int main() {
    test_constructor_from_vector();
    std::cout << "[PASS] test_constructor_from_vector\n";

    test_upload_download();
    std::cout << "[PASS] test_upload_download\n";

    test_zeros();
    std::cout << "[PASS] test_zeros\n";

    test_full();
    std::cout << "[PASS] test_full\n";

    test_randint();
    std::cout << "[PASS] test_randint\n";

    test_rand();
    std::cout << "[PASS] test_rand\n";

    test_matmul_standard();
    std::cout << "[PASS] test_matmul_standard\n";

    test_matmul_non_square();
    std::cout << "[PASS] test_matmul_non_square\n";

    test_matmul_identity();
    std::cout << "[PASS] test_matmul_identity\n";

    test_operator_add();
    std::cout << "[PASS] test_operator_add\n";

    test_operator_div();
    std::cout << "[PASS] test_operator_div\n";

    test_operator_mul();
    std::cout << "[PASS] test_operator_mul\n";

    test_relu();
    std::cout << "[PASS] test_relu\n";

    test_operator_parenthesis();
    std::cout << "[PASS] test_operator_parenthesis\n";

    test_show_data();
    std::cout << "[PASS] test_show_data\n";

    std::cout << "\n===========================\n";
    std::cout << "All tests passed!\n";
    std::cout << "===========================\n";
    return 0;
}
