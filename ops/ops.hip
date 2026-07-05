#include "ops/ops.h"
#include "tensor.h"
#include "engine.h"
#include "kernels/matmul.h"
#include "kernels/elementWise.h"

namespace ops {

    namespace elementWise {
        Tensor matsum(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUM);

            auto node = std::make_shared<Node>(a.data(), b.data(), c.data(), OpCode::SUM);
            c.parents_node = node;
            return c;
            
        }
        
        Tensor matsub(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUB);
            
                       
            return c;
        }

        Tensor matdiv(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::DIV);
            
                       
            return c;
        }

        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::MUL);
            
                       
            return c;
        }
        
        Tensor relu(const Tensor& t) {
            Tensor out(t.shape()[0], t.shape()[1]);
            launch_element_wise(t.data(), out.data(),
            t.size(), OpCode::RELU);
            
                       
            return out;

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
