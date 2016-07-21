#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 4//num of row
#define N 3//num of column

int main(void){
    double **a=(double**)malloc(sizeof(double**)*M);
    if(a==NULL){
        fprintf(stderr, "fail to allocate\n");
        exit(1);
    }

    for (int i = 0; i < M; ++i)
    {
        a[i]=(double*)malloc(sizeof(double*)*N);
        if(a[i]==NULL){
            fprintf(stderr, "fail to allocate for %d-th row\n",i);
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
                a[i][j]=rand()%10;
                printf("a[%d][%d]=%f]\n",i,j,a[i][j]);
        }    
    }
    free(a);
    return 0;
}