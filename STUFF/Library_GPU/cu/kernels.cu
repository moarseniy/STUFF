#include <cuda_runtime.h>
#include "../cu/kernels.h"


__global__
void AddVector() {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
}

void StartAddVector() {
  AddVector<<<>>>
}
