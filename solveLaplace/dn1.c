/**
*this program is called by solve-iter-laplace.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 101
#define M 101

int main(){
    double u;
    u=0;

    for (int i = 0; i < N; ++i)
    {
        printf("%f\n", u);
        double rad=(double)i/N;
        u=sin(rad*2*M_PI);
    }

    for (int j = 0; j < M; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            printf("0\n");
        }
    }
    return 0;
}