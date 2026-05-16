
#include <iostream>
#include <vector>
#include <hip/hip_runtime.h>

__global__ void hello_from_gpu() {
    printf("hello from gpu %d\n", threadIdx.x);
}
int main() {
    std::cout << "starting gpu" << std::endl;
    hipLaunchKernelGGL(hello_from_gpu, dim3(1), dim3(4), 0, 0);
    
    std::cout << "Programa terminado." << std::endl;
    return 0;

}
