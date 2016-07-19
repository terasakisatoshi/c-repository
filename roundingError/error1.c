/*
桁落ち：値がほぼ等しい数値同士の減算では，有効数字が失われる．
ここでは \sqrt{x+1}-\sqrt{x} の計算結果を調べる．
減算を用いずに \frac{1}{\sqrt{x+1}+\sqrt{x}} をした時の結果と比較しよう．
*/

#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("x=1e15\n");
    x=1e15;
    printf("\\sqrt{x+1}-\\sqrt{x}=%.30f\n",sqrt(x+1)-sqrt(x));
    printf("\\frac{1}{\\sqrt{x+1}+\\sqrt{x}}=%.30f=\n",1.0/(sqrt(x+1)+sqrt(x))); 

    printf("x=1e16\n");
    x=1e16;
    //桁落ち発生
    printf("\\sqrt{x+1}-\\sqrt{x}=%.30f\n",sqrt(x+1)-sqrt(x));
    //桁落ち回避
    printf("\\frac{1}{\\sqrt{x+1}+\\sqrt{x}}=%.30f=\n",1.0/(sqrt(x+1)+sqrt(x))); 
    return 0; 
}