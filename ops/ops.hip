#include "ops/ops.h"
#include "kernels/matmul.h"
#include "kernels/elementWise.h"
namespace ops {

    namespace elementWise {
        Tensor matsum(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUM);
            
            return c;
            
        }
        
        Tensor matsub(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUB);
            
            return c;
        }
 
        
    }
    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], b.shape()[1]);
            
            launch_matmul(a.data(), b.data(),
            c.data(), a.shape()[0], a.shape()[1], b.shape()[1]);
            
            return c;
        }
    }
}
