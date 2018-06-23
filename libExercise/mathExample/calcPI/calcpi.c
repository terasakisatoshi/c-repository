#include <math.h>
#include "calcgcd.h"


double calc_pi(int N) {
    int s = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            if (gcd(a, b) == 1) {
                s += 1;
            }
        }
    }
    double mypi;
    mypi = sqrt(6 * N * N / (double)s);
    return mypi;
}