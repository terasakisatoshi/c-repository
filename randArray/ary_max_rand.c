#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[],int sizeof_a)
{
    int max=a[0];
    for(int i=0;i<sizeof_a;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

int main(void){
    int number;//height の要素数
    printf("人数\n");
    scanf("%d",&number);
    int *height=(int*)calloc(number,sizeof(int));
    srand(time(NULL));
    for(int i=0;i<number;++i){
        height[i]=100+rand()%90;
        printf("height[%d]=%d\n",i,height[i]);
    }
    printf("最大値は%dです．\n",maxof(height,number));
    free(height);
    system("pause");
    return 0;
}