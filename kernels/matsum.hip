__global__ matsum(float* a, float* b, float* c, float* w_a) {
    int idx = blockIdx.x * blocDim.x + threadIdx.x
    if (idx < w_a) {
        c[idx] = a[idx] + b[idx];    
    }
    
}



