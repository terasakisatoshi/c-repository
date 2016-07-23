#include<stdio.h>
#include<stdlib.h>

#define N 5

//allocate memory you can access as a[i],...,a[j]
double* dvector(int i,int j){
    double *a=(double *)malloc((j-i+1)*sizeof(double));
    if(a==NULL){
        fprintf(stderr, "fail to allocate\n");
        exit(1);
    }

    return(a-i);
}

//free memory allocated by dvector
//int i is the first argument of dvector(int i, int j)
void free_dvector(double *a,int i){
    free((void*)(a+i));
}

int main(int argc, char const *argv[])
{
    double *a,*b;
    printf("allocate for a\n");
    a=dvector(1,N);
    for(int i=1;i<=N;i++){
        a[i]=(double)i/20.0;
        printf("a[%d]=%f \n", i,a[i]);
    }

    free_dvector(a,1);
    printf("free memory of a\n");

    printf("allocate for b\n");
    b=dvector(2,N+1);
    for(int j=2;j<=N+1;++j){
        b[j]=(double)j/20.0;
        printf("b[%d]=%f\n", j,b[j]);
    }
    free_dvector(b,2);
    printf("free memory of b\n");
    return 0;
}

