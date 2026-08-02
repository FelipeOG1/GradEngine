#include "../ops/ops.h"
#include "cassert"
#include "../tensor.h"
#include <vector>
void test_matsum_no_grad() {
  std::vector<float> v = {10, 10, 10, 10};
  Tensor a(v, 2, 2) ; Tensor b(v, 2, 2);
  Tensor c = ops::elementWise::matsum(a, b);
  assert( c(0, 0) == 20);
}



void run_test_ops() {
  test_matsum_no_grad();
  
}
