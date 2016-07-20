#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(){
    //double* のcastを行うこと
    double* a=(double*)malloc(sizeof(double)*N);
    if (a==NULL){
        printf("fail to allocate\n");
        exit(1);
    }

    for(int i=0;i<N;i++){
        a[i]=2.0*i;
    }

    printf("show vector info:\n");
    for(int i=0;i<N;i++){
        printf("a[%d]=%f\n",i,a[i]);
    }

    free(a);

    return 0;
}