#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

//allocate matrix memory
double **dmatrix(int nr1,int nr2,int nl1,int nl2){
    int nrow,ncol;
    double **a=(double**)malloc(nrow*sizeof(double*));
    nrow =nr2-nr1+1;
    ncol =nl2-nl1+1;

    //allocate for rows
    if(a==NULL){
        printf("fail to allocate\n");
        exit(1);
    }

    a=a-nr1;

    //allocate for cols
    for(int i=nr1;i<=nr2;i++){
        a[i]=(double*)malloc(ncol*sizeof(double));
    }
    for(int i=nr1;i<=nr2;i++){

        a[i]=a[i]-nl1;
    }
    return (a);
}
//free matrix memory created by dmatrix
void free_dmatrix(double **a,int nr1,int nr2,int nl1,int nl2){
    for(int i=nr1;i<=nr2;++i){
        free((void*)(a[i]+nl1));
    }
    free((void*)(a+nr1));
}

int main(int argc, char const *argv[])
{
    double **a;
    a=dmatrix(1,M,1,N);
    for (int i = 1; i <=M; ++i)
    {
        for (int j = 1; j <=N; ++j)
        {
            a[i][j]=(i+j)/2.0;
            printf("a[%d][%d]=%f\n", i,j,a[i][j]);
        }
    }

    return 0;
}
