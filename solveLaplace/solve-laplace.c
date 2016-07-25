/**
*連立方程式の解法としてgauss消去法を使ったラプラス方程式を解いていきます．
*/

#include <stdio.h>
#include <stdlib.h>

#define N 9

void forward(double r[][N+1]);
void backward(double r[][N+1],double x[N]);

int main(){
    double r[N][N+1]=
    {{4,-1,0,-1,0,0,0,0,0,0},
     {-1,4,-1,0,-1,0,0,0,0},
     {0,-1,4,0,0,-1,0,0,0,0.25},
     {-1,0,0,4,-1,0,-1,0,0,0},
     {0,-1,0,-1,4,-1,0,-1,0,0},
     {0,0,-1,0,-1,4,0,0,-1,0.5},
     {0,0,0,-1,0,0,4,-1,0,0.25},
     {0,0,0,0,-1,0,-1,4,-1,0.5},
     {0,0,0,0,0,-1,0,-1,4,1.5}};

     double x[N];

     forward(r);
     backward(r,x);

     for (int i = 0; i < N; ++i)
     {
         for (int j = 0; j < N+1; ++j)
         {
             printf("%lf",r[i][j]);
         }
         printf("\n");
     }

     for (int i = 0; i < N; ++i)
     {
         printf("%lf\n", x[i]);
     }

     return 0;
}

void forward(double r[][N+1]){
    double rii,rki;
    for (int i = 0; i < N; ++i){
        rii=r[i][i];
        for (int j = 0; j < N+1; ++j)
            r[i][j]/=rii;
        for (int k=i+1;k<N;k++){
            rki=r[k][i];
            for(int j=i;j<N+1;j++)
                r[k][j]=r[k][j]-r[i][j]*rki;
        }
    }
}

void backward(double r[][N+1],double x[N]){
    double sum;
    for(int i =N-1;i>=0;--i){
        sum=0;
        for(int j=i+1;j<N;j++)
            sum+=r[i][j]*x[j];
        x[i]=r[i][N]-sum;
    }
}