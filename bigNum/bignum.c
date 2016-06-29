/**
*多倍長整数の例題プログラム
*整数型の配列を用意して通常の整数では表現しきれない大きさの整数を表現する．
*/

#include <stdio.h>
#include <math.h>

#define N 8 /*解を格納する配列の要素数*/
#define ULIMIT 99
#define RESLIMIT 1000000UL /*7桁の富豪なし整数の最大値＋1*/
#define POW 3

void PrintResult(unsigned long result[]);
bool Power(short pow,unsigned long result[]);
int main(){
    unsigned long result[N]={0};
    result[0]=1;

    for(int i=0;i<ULIMIT;++i){
        if(Power(POW,result)){
            printf("n=%3d: ",i);
            PrintResult(result);
        }
        else{
            return 1;
        }

    }

    return 0;
}

/**
* show result
*/
void PrintResult(unsigned long result[]){
    for (int j=N-1;j>=0;--j){
        if(result[j]==0)printf("        ");//set 8 spaces
        else printf("%8lu",result[j]);
    }
    printf("\n");
}

/**
*calc power of result
*/
bool Power(short pow,unsigned long result[]){
    unsigned long midres[N]={0};

    for (int i=0;i<N;++i){
        midres[i]+=result[i]*pow;
        if(midres[i]>=RESLIMIT){//桁あふれ
            if(i!=N-1){
                midres[i+1]+=midres[i]/RESLIMIT;
            }else{//多倍長整数が桁あふれ
                printf("多倍長さ整数掛けたあふれしました\n");
                return false;
            }
            midres[i]=midres[i]%RESLIMIT;
        }
    }
    for (int i=0;i<N;++i){
        result[i]=midres[i];
    }
    return true;
}