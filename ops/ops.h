#pragma once
#include "ops/opcodes.h"

class Tensor; 

namespace ops {

    namespace elementWise {
        Tensor matsum(const Tensor& a, const Tensor& b);
        Tensor matsub(const Tensor& a, const Tensor& b);
        Tensor matmul(const Tensor& a, const Tensor& b);
        Tensor matdiv(const Tensor& a, const Tensor& b);
        Tensor relu(const Tensor& t);

    }

    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b);
        

    }
}
