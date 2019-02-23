#include <stdio.h>

int main(int argc, char const *argv[])
{
    int b[2][3] = {
        {0, 1, 2},
        {3, 4, 5}
    };

    int *c;
    c = (int*)b; // cast

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; ++j)
        {
            printf("b[%d][%d] = %d \n", i, j, b[i][j]);
            printf("c[%d] = %d\n",3 * i + j, c[3 * i + j]);
        }
    }

    //try to change value of b[1][2]
    b[1][2] = -100;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; ++j)
        {
            printf("b[%d][%d] = %d \n", i, j, b[i][j]);
            printf("c[%d] = %d\n",3 * i + j, c[3 * i + j]);
        }
    }
    return 0;
}