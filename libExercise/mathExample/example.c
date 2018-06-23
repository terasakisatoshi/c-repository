#include <stdio.h>
#include "mylib.h"

int main(){
    printf("sin(%f)=%f\n", 30.0,sin_degree(30.0));
    printf("cos(%f)=%f\n", 60.0,cos_degree(60.0));
    return 0;
}