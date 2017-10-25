#include <iostream>
#include <omp.h>

int main() {
#pragma omp for simd
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
  }
  return 0;
}