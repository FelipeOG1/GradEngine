#pragma once
#include "tensor.h"

enum class OpCode { SUM, SUB, DIV, MUL };

namespace ops {

    namespace elementWise {


    }

    namespace standardMatrix {
        Tensor matmul(const Tensor& a, const Tensor& b);
        

    }
}
