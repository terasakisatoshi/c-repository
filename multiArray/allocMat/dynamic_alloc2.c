#include<stdio.h>
#include<stdlib.h>

#define N 3

void matrix_mul(double**, double*, double*);
void print_matrix(double*);

int main(int argc, char const *argv[])
{
    double *a, *b, *c;
    a = (double*)malloc(sizeof(double) * N * N);
    b = (double*)malloc(sizeof(double) * N * N);
    c = (double*)malloc(sizeof(double) * N * N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a[i * N + j] = i + j; b[i * N + j] = i - j;
        }
    }

    matrix_mul(&c, a, b);
    print_matrix(a); printf("\n");
    print_matrix(b); printf("\n");
    print_matrix(c);
    free(a);free(b);free(c);
    return 0;
}

void matrix_mul(double** c,double* a,double* b){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            (*c)[i*N+j]=0.0;
            for (int k = 0; k < N; ++k)
            {
                (*c)[i*N+j]+=a[i*N+k]*b[k*N+j];
            }
        }
    }
}

void print_matrix(double* a){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%+f",a[i*N+j]);
        }
        printf("\n");
    }
}