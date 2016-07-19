/*
情報落ち：絶対値の大きく異なる値を数値同士の演算において，絶対値の小さな数値が演算結果が反映されない現象
*/

#include <stdio.h>

int main(){
    double initx=1e10;
    double x=initx;
    double y=1e-8;
    printf("x=%f, y=%.8f\n",x,y);
    int count=1e7;
    for(int i=0;i<count;++i){
        x+=y;
    }
    printf("x+=y %d times = %f\n",count,x);

    x=initx;
    double tmp;
    for(int i=0;i<count;++i){
        tmp+=y;
    }
    printf("tmp+=y %d times = %f\n",count,tmp);
    x+=tmp;
    printf("x+tmp = %f\n",x);
    

    return 0;
}