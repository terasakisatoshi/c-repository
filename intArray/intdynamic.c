/* -*- C -*- */

/**
*generate int array dynamically
*and then output its members
*/
#include <stdio.h>

int main()
{
    //get memory of an object its type is int 
    int* x=calloc(1,sizeof(int));
    if(x==NULL){
        puts("fail to keep memory domain");
    }else
    {
            *x=57;
            printf("*x = %d\n",*x);
            free(x);
    }
    
    return 0;
}