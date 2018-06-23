#include <stdio.h>
#include"mypi.h"

int main(int argc, char const *argv[])
{
    int N = 1000;
    double approximated_pi = calc_pi(N);
    printf("pi=%f\n", approximated_pi);
    return 0;
}