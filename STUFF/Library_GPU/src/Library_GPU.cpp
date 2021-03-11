#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <Library_GPU/Library_GPU.h>
#include "kernels.h"

int main(void) {
  int n = 5;
  size_t bytes = n * sizeof(float);

  cudaSetDevice(0);

  float *h_a, *h_b;
  float *d_a, *d_b;

  h_a = (float*)malloc(bytes);
  h_b= (float*)malloc(bytes);
  cudaMalloc(&d_a, bytes);
  cudaMalloc(&d_b, bytes);

  init_vector(h_a, n);

  cudaMemcpy(d_a, h_a, bytes, cudaMemcpyHostToDevice);

  int numBlocks = n / SIZE;

  cudaEventRecord(start, 0);





  cudaEventRecord(stop, 0);
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&gpuTime, start, stop);
  printf("GPU time = %.4f \n", gpuTime);

  cudaMemcpy(h_b, d_b, bytes, cudaMemcpyDeviceToHost);


}
