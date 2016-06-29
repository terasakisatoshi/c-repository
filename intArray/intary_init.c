/* -*- C -*- */

#include <stdio.h>
// formula...
// sizeof(a)/sizeof(a[0]) 

int main()
{
    int a[5]={1,2,3,4,5};
    int size_a=sizeof(a)/sizeof(a[0]);
    printf("size of array a is %d\n",size_a);
    for(int i=0; i< size_a;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
}