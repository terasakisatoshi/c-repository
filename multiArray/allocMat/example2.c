#include <stdio.h>
#define N   (3) /* 行列のサイズ */

void matrix_mul(double *, double *, double *, int) ;
void print_matrix(double *, int) ;

int main(int argc, char **argv)
{
  double a[N * N], b[N * N], c[N * N] ;
  int i, j ;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      a[i * N + j] = i + j ; b[i * N + j] = i - j ;
    }
  }
  matrix_mul(c, a, b, N) ;
  print_matrix(a, N) ; printf("\n") ;
  print_matrix(b, N) ; printf("\n") ;
  print_matrix(c, N) ;
  return 0 ;
}

void matrix_mul(double *c, double *a, double *b, int n)
{
  int i, j, k ;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i * n + j] = 0.0 ;
      for (k = 0; k < n; k++) c[i * n + j] += a[i * n + k] * b[k * n + j] ;
    }
  }
  return ;
}

void print_matrix(double *a, int n)
{
  int i, j ;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) printf("%+f ", a[i * n + j]) ; printf("\n") ;
  }
  return ;
}

