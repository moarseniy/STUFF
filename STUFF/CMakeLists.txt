cmake_minimum_required(VERSION 3.19)
project(MyProject LANGUAGES C CXX CUDA)

find_package(CUDA REQUIRED)
list(APPEND CUDA_NVCC_FLAGS ";-O3;${GPU_ARCH};-lineinfo")

set(CUDA_LIBS ${CUDA_LIBRARIES} ${CUDA_CUBLAS_LIBRARIES} ${CUDA_curand_LIBRARY})


#add_subdirectory(Library)
add_subdirectory(Library_GPU)
add_subdirectory(method)
