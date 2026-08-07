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

            c.backward = [](){ std::cout << "hello from CCC";};
            
            
            if (a.requires_grad() || b.requires_grad()) Engine::create_parents_node(a, b, c, OpCode::SUM);
		
            return c;
            
        }
        
        Tensor matsub(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUB);
            
            if (a.requires_grad() || b.requires_grad()) Engine::create_parents_node(a, b, c, OpCode::SUB);

                       
            return c;
        }

        Tensor matdiv(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::DIV);
            if (a.requires_grad() || b.requires_grad()) Engine::create_parents_node(a, b, c, OpCode::DIV);

                       
            return c;
        }

        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::MUL);
            if (a.requires_grad() || b.requires_grad()) Engine::create_parents_node(a, b, c, OpCode::MUL);

                       
            return c;
        }
        
        Tensor relu(const Tensor& t) {
            Tensor out(t.shape()[0], t.shape()[1]);
            launch_element_wise(t.data(), out.data(),
            t.size(), OpCode::RELU);
            
            if (t.requires_grad()) Engine::create_parents_node(t, out, OpCode::RELU);
            
            return out;

        }

        
    }
    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], b.shape()[1]);
            
            launch_matmul(a.data(), b.data(),
            c.data(), a.shape()[0], a.shape()[1], b.shape()[1]);

            if (a.requires_grad() || b.requires_grad()) Engine::create_parents_node(a, b, c, OpCode::MUL);
            
                       
            return c;
        }
    }
}
