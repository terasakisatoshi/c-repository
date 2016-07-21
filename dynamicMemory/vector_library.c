#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
*create vector as an array:
*you can start index from 1 to n
*i.e. a[i] for i 1,2,3,...,n
*/
double* create_vector(int n){
    double* a=(double*)malloc(sizeof(double)*n);
    if(a==NULL){
        fprintf(stderr, "fail to allocate\n");
        exit(1);
    }

    return(a-1);
}

/**
*free vector memory created by the function named
*create_vector(int n)
*/
void free_vector(double * a){
    free(a+1);
}

int main( int argc, char *argv[] ){
    srand(time(NULL));
    int n;
    if(argc!=2){
        n=5;
    }
    else{
        n=atoi(argv[1]);
    }

    double* a=create_vector(n);

    for (int i = 1; i <=n; ++i)
    {
        a[i]=rand()%10;
        printf("a[%d]=%f\n", i,a[i]);
    }

    free_vector(a);

    return 0;

}