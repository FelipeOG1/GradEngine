#include "ops/ops.h"
#include "kernels/matmul.h"

namespace ops {
    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], b.shape()[1]);
            
            launch_matmul(a.data(), b.data(),
            c.data(), a.shape()[0], a.shape()[1], b.shape()[1]);
            
            return c;
        }
    }
}
