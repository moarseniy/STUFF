cmake_minimum_required(VERSION 3.19)
project(Library_GPU)
 set(nvmatrix_PUBLIC_HEADERS
    src/Library_GPU.h)

  set(nvmatrix_HEADERS
    ${nvmatrix_PUBLIC_HEADERS}
    cu/kernels.h)

  set(nvmatrix_SOURCES
    src/Library_GPU.cpp)

  set(nvmatrix_KERNELS
    cu/kernels.cu)
    
    CUDA_COMPILE(nvmatrix_kcompiled ${nvmatrix_KERNELS} STATIC
             OPTIONS -DDLL_EXPORTS -D_MWAITXINTRIN_H_INCLUDED)
   add_library(Library_GPU STATIC ${nvmatrix_HEADERS} ${nvmatrix_SOURCES} ${nvmatrix_kcompiled})
target_link_libraries(Library_GPU ${CUDA_LIBS})

