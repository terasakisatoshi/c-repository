#include<stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
        #ifdef _OPENMP
            printf("HelloWorld!!%d\n",omp_get_thread_num());
        #else
            printf("HelloWorld!!\n");
        #endif
    }
    return 0;
}