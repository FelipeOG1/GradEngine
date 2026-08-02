#include "../ops/ops.h"
#include "cassert"
#include "../tensor.h"
#include <vector>
#include "../engine.h"
void test_matsum_no_grad() {
  std::vector<float> v = {10, 10, 10, 10};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  Tensor c = ops::elementWise::matsum(a, b);
  assert( c(0, 0) == 20);
  assert(a.requires_grad() == false);
  assert(b.requires_grad() == false);
  assert(c.requires_grad() == false);
  assert (c.parents_node == nullptr);
}

void test_matsum_grad() {
  std::vector<float> v = {10, 10, 10, 10};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  b.set_requires_grad(true);
  Tensor c = ops::elementWise::matsum(a, b);
  assert( c(0, 0) == 20);
  assert(a.requires_grad() == true);
  assert(b.requires_grad() == false);
  assert(c.requires_grad() == false);
  assert(c.parents_node != nullptr);
  assert(c.parents_node->parents[0]->data());
  assert(c.parents_node->parents[1]->data());
  
  
}




void run_test_ops() {
  test_matsum_no_grad();
  
}
