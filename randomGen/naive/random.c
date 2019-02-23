#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int r;
    srand(time(NULL));
    for (int k = 0; k < 5; k++) {
        r = rand();
        printf("%d\t%f\n", r, ((double)r) / RAND_MAX);
    }
    return 0;
}