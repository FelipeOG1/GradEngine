#include "tensor.h"
#include "ops/ops.h"

Tensor Tensor::matmul(const Tensor& other) {
    return ops::matmul(*this, other);
}
