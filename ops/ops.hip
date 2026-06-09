#include "ops/ops.h"
#include "kernels/matmul.h"

namespace ops {
    Tensor matmul(const Tensor& a, const Tensor& b) {
        size_t h_A = a.shape()[0];
        size_t w_A = a.shape()[1];
        size_t w_B = b.shape()[1];
        
        Tensor result(h_A, w_B);
        launch_matmul(a.data(), b.data(), result.data(), h_A, w_A, w_B);
        return result;
    }
}
