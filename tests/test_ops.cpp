#include "../ops/ops.h"
#include "cassert"
#include "../tensor.h"
#include <vector>
#include "../engine.h"

void test_matsum_no_grad() {
  std::vector<float> v = {10.0f, 10.0f, 10.0f, 10.0f};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  Tensor c = ops::elementWise::matsum(a, b);
  assert(c(0, 0) == 20);
  assert(a.requires_grad() == false);
  assert(b.requires_grad() == false);
  assert(c.requires_grad() == false);
  assert(c.parents_node == nullptr);
  c.backward();
}

void test_matsum_grad() {
  std::vector<float> v = {10.0f, 10.0f, 10.0f, 10.0f};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  b.set_requires_grad(true);
  a.set_requires_grad(true);
  Tensor c = ops::elementWise::matsum(a, b);
  assert(c(0, 0) == 20);
  assert(a.requires_grad() == true);
  assert(b.requires_grad() == true);
  assert(c.requires_grad() == false);
  assert(c.parents_node != nullptr);
  assert(c.parents_node->parents[0]->data());
  assert(c.parents_node->parents[1]->data());
  
  
}

void test_matmul_grad() {
  std::vector<float> v = {10.0f, 10.0f, 10.0f, 10.0f};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  a.set_requires_grad(true);
  Tensor c = ops::elementWise::matmul(a, b);
  assert(c(0, 0) == 100);
  assert(a.requires_grad() == true);
  assert(b.requires_grad() == false);
  assert(c.requires_grad() == false);
  assert(c.parents_node->parents[0]->data());
  assert(c.parents_node->parents[1]->data());
   
}

void test_relu_grad() {
  std::vector<float> v = {1.0f, -2.0f, 3.0f, -4.0f};
  Tensor a(v, 2, 2);
  a.set_requires_grad(true);
  Tensor c = ops::elementWise::relu(a);
  assert(c.parents_node != nullptr);
  assert(c.parents_node->parents.size() == 1);
  assert(c.parents_node->parents[0]->data());
}


void run_test_ops() {
  test_matsum_no_grad();
  test_matsum_grad();
  test_matmul_grad();
  test_relu_grad();
}
