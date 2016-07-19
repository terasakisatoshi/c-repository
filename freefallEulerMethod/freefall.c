/*
freefall.c
自由落下のシミュレーション
自由落下の運動方程式を数値的にときます
*/

/*
include spell
*/
#include <stdio.h>
#include <math.h>

#define BUFSIZE 256
#define DT 0.01
#define G 9.80665 //gravity accerator

int getdouble(double *x);

/*
main
*/

int main(){
    double v,x;
    double t=0;
    double h=DT;
    fprintf(stderr, "初速度を入力");
    if(getdouble(&v)==EOF)
        return 1;
    fprintf(stderr, "初期高度を入力してください");
    if(getdouble(&x)==EOF)
        return 1;
    printf("%f\t%f\t%f\n",t,x,v);

    //自由落下の計算　
    while(x>0){
        t+=h;
        v+=G*h;
        x-=v*h;
        printf("%f\t%f\t%f\n",t,x,v);
    }
    return 0;
}

int getdouble(double *x){
    char linebuf[BUFSIZE];
    int result =0;
    if(fgets(linebuf,BUFSIZE,stdin)!=NULL){
        if(sscanf(linebuf,"%lf",x)<=0){
            result=EOF;
        }
    }else{
        result=EOF;
    }
    return result;
}
