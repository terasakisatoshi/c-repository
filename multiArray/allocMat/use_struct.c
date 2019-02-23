#include<stdio.h>

#define N 3

struct Matrix
{
    double e[N * N];
    int size;
};

typedef struct Matrix Matrix;

Matrix mat_mul(const Matrix* a, const Matrix* b);
void print_matrix(Matrix m);

int main(int argc, char const *argv[])
{
    Matrix a, b, c;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a.e[i * N + j] = i + j;
            b.e[i * N + j] = i - j;
        }
    }
    a.size = N;
    b.size = N;
    c = mat_mul(&a, &b);
    print_matrix(a); printf("\n");
    print_matrix(b); printf("\n");
    print_matrix(c);
    printf("%d\n", a.size);
    return 0;
}

Matrix mat_mul(const Matrix *a,const Matrix *b){
    Matrix c;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            c.e[i*N+j]=0.0;
            for (int k = 0; k < N; ++k)
            {
                c.e[i*N+j]+=a->e[i*N+k]*b->e[k*N+j];
            }
        }
    }
    c.size=N;
    return c;
}

void print_matrix(Matrix a){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%+f", a.e[i*N+j]);
        }
        printf("\n");
    }
}