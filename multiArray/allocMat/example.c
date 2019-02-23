/*
https://www.math.nagoya-u.ac.jp/~naito/lecture/2015_SS/Matrix/matrix.html
*/
#include<stdio.h>

#define N  3

void matrix_mul(double [][N], double [][N], double [][N]) ;
void print_matrix(double a[][N]) ;

int main(int argc, char **argv)
{
    double a[N][N], b[N][N], c[N][N] ;
    int i, j ;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i + j ; b[i][j] = i - j ;
        }
    }
    matrix_mul(c, a, b) ;
    print_matrix(a) ; printf("\n") ;
    print_matrix(b) ; printf("\n") ;
    print_matrix(c) ;
    return 0 ;
}

void matrix_mul(double c[][N], double a[][N], double b[][N])
{
    int i, j, k ;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = 0.0 ;
            for (k = 0; k < N; k++) c[i][j] += a[i][k] * b[k][j] ;
        }
    }
    return ;
}

void print_matrix(double a[][N])
{
    int i, j ;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) printf("%+f ", a[i][j]) ; printf("\n") ;
    }
    return ;
}