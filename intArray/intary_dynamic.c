/* -*- C -*- */

#include <stdio.h>

int main()
{
	int count=5;
    printf("generate array... input size you want to...: ");
    scanf("%d",&count);
    //alloc int array its size is count...
    int* a=calloc(count,sizeof(int));
    if(a==NULL){
        puts("fail to allocate");
    }
    else{
        printf("the lengh of array you created is %d\n",count);
        for(int i=0;i<count;++i){
            a[i]=i;
        	printf("a[%d]=%d\n",i,a[i]);
        }
        free(a);
    }
    return 0;
}