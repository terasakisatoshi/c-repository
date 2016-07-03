/* -*- C -*- */

#include <stdio.h>

int main()
{
    int max_int=100;
	unsigned long counter=0;
    for(int n=2;n<=max_int;++n){
        for(int i=2;i<n;++i){
        	counter++;
        	if(n%i==0){
            	break;
            }
        }
        if(n==i){//n is prime!
        	printf("n=%d\n",n);
    	}
    }
    printf("counter:%lu\n",counter);
    return 0;
}