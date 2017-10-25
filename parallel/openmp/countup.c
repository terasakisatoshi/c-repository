#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    int a=0;
    #pragma omp parallel for reduction(+:a)
    for (int i=1;i<=1000000;i++){
        a+=i;
    }
    printf("a=%d\n",a );
    return 0;
}