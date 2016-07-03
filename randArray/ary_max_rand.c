#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/**
*@in a[]配列，numof_a 配列 a の要素数   
*@out a[]の値の最大値
*受け取る引数がポインタである．配列ではないため，配列の要素数は別の引数としつけとる必要がある．
*/
int maxof(const int a[],int numof_a)
{
    int max=a[0];
    for(int i=0;i<numof_a;i++){
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