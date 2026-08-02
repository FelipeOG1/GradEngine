#include <iostream>

// Forward declarations for all test suites
void run_test_ops();
void run_test_tensor();
void test_constructor();  // from test_engine.cppd

int main() {
    std::cout << "=== Running ops tests ===\n";
    run_test_ops();
    std::cout << "[PASS] All ops tests passed!\n\n";

    std::cout << "=== Running tensor tests ===\n";
    run_test_tensor();

    std::cout << "=== Running engine tests ===\n";
    test_constructor();
    std::cout << "[PASS] test_constructor\n";

    std::cout << "\n===========================\n";
    std::cout << "All tests passed!\n";
    std::cout << "===========================\n";
    return 0;
}
