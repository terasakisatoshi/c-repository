#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

int main(){
    srand(time(NULL));
    double *array;
    double *array_ori=(double*)malloc(sizeof(double)*N);
    if(array_ori==NULL){
        printf("fail to allocate\n");
        exit(1);
    }
    
    for(int i=0;i<N;++i){
        array_ori[i]=rand()%10;
    }

    array=array_ori-1;//shift index
    for(int i=1;i<=N;++i){
        printf("array[%d]=%f\tarray_ori[%d]=%f\n",i,array[i],i-1,array_ori[i-1]);
    }
    free(array_ori);
    return 0;
}