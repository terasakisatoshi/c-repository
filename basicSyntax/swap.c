#include<stdio.h>

void swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


int main() {
    int x = -1;
    int y = 1;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y );
}