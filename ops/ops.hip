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
            
            if (a.requires_grad() || b.requires_grad()) {
                c.set_requires_grad(true);
                c.set_creator_node(std::make_shared<GraphNode>(OpCode::SUM,
                    std::make_shared<Tensor>(a), std::make_shared<Tensor>(b)));
            }
            
            return c;
            
        }
        
        Tensor matsub(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::SUB);
            
            if (a.requires_grad() || b.requires_grad()) {
                c.set_requires_grad(true);
                c.set_creator_node(std::make_shared<GraphNode>(OpCode::SUB,
                    std::make_shared<Tensor>(a), std::make_shared<Tensor>(b)));
            }
            
            return c;
        }

        Tensor matdiv(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::DIV);
            
            if (a.requires_grad() || b.requires_grad()) {
                c.set_requires_grad(true);
                c.set_creator_node(std::make_shared<GraphNode>(OpCode::DIV,
                    std::make_shared<Tensor>(a), std::make_shared<Tensor>(b)));
            }
            
            return c;
        }

        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], a.shape()[1]);
            
            launch_element_wise(a.data(), b.data(),
            c.data(), a.size(), OpCode::MUL);
            
            if (a.requires_grad() || b.requires_grad()) {
                c.set_requires_grad(true);
                c.set_creator_node(std::make_shared<GraphNode>(OpCode::MUL,
                    std::make_shared<Tensor>(a), std::make_shared<Tensor>(b)));
            }
            
            return c;
        }
        
        Tensor relu(const Tensor& t) {
            Tensor out(t.shape()[0], t.shape()[1]);
            launch_element_wise(t.data(), out.data(),
            t.size(), OpCode::RELU);
            
            if (t.requires_grad()) {
                out.set_requires_grad(true);
                out.set_creator_node(std::make_shared<GraphNode>(OpCode::RELU,
                    std::make_shared<Tensor>(t)));
            }
            
            return out;

        }

        
    }
    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b) {
            Tensor c(a.shape()[0], b.shape()[1]);
            
            launch_matmul(a.data(), b.data(),
            c.data(), a.shape()[0], a.shape()[1], b.shape()[1]);
            
            if (a.requires_grad() || b.requires_grad()) {
                c.set_requires_grad(true);
                c.set_creator_node(std::make_shared<GraphNode>(OpCode::MUL,
                    std::make_shared<Tensor>(a), std::make_shared<Tensor>(b)));
            }
            
            return c;
        }
    }
}
