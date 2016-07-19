#include <stdio.h>
#include <stdlib.h>
#include <string>

/*
実数を有限の桁数の2進数で表示するために生じる誤差．
10進数で有限でも，2進数展開した時に循環小数になる数値では丸め誤差が生じる．
*/
int SumZeroPtOneOrdTimes(int ord){
    printf("ord=%d\n",ord);
    double x=0.0;
    printf("0.1=%f\n",0.1);
    std::string val="1e"+std::to_string(ord);
    int count=atof(val.c_str());
    printf("take sum 0.1 for %d times\n",count);
    for (int i=0;i<count;++i){
        x+=0.1;
    }
    printf("the result is %f\n",x);
    printf("%d*0.1=%f\n",count,count*0.1);
    if(x>count*0.1){
        printf("x is greater than %d*0.1\n",count);
    }else if(x==count*0.1){
        printf("eqal!!\n");
    }
    else{
        printf("x is smaller than %d*0.1\n",count);
    }
    return 0;
}

int main(){
    for(int i =0;i<10;++i){
        SumZeroPtOneOrdTimes(i);
    }
    return 0;
}