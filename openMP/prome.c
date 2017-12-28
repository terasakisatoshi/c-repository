#include<stdio.h>
#include<math.h>
#include<omp.h>


int is_prime(int n) {
    const int m = floor(sqrt(n));
    int i = 0;
    for (i = 2; i <= m; i++) if (0 == n % i) return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    int arr[1000001];
    {
        unsigned int i = 0;
        for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
            arr[i] = i;
        }
    }

#ifdef _OPENMP
    printf("PROC: %d\n", omp_get_num_procs());
#endif
    {
        unsigned i = 0;
#ifdef _OPENMP
        #pragma omp parallel for
#endif
        for (i = 2; i < sizeof(arr) / sizeof(int); i++) {
            arr[i] = is_prime(arr[i]);
        }
    }

    {
        int primes = 0;
        unsigned int i = 0;
        for (i = 2; i < sizeof(arr) / sizeof(int); i++) {
            primes += arr[i];
        }
        printf("primes: %d\n", primes );
        return 0;
    }
}