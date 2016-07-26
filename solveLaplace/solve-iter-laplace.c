#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10000 //反復回数の上限
#define N 101
#define M 101
#define BUFSIZE 256
#define ERROR -1//入力時のエラーコード

/*関数のプロトタイプ宣言*/
int getuij(double u[][M]);
void putuij(double u[][M]);
void iteration(double u[][M]);
int getdouble(double *x);

/**********
***main****
**********/
int main(int argc, char const *argv[])
{
    double u[N][M];
    if (getuij(u)!=0){//fail to read
        fprintf(stderr, "fail to load initial value\n");
        exit(1);
    }
    for (int i = 0; i < LIMIT; ++i)
    {
        iteration(u);
    }
    putuij(u);
    return 0;
}


void iteration(double u[][M]){
    double u_next[N][M];
    for (int i = 1; i < N-1; ++i)
    {
        for (int j = 1; j < M-1; ++j)
        {
            u_next[i][j]
            =(u[i][j-1]+u[i-1][j]+u[i+1][j]+u[i][j+1])/4.0;
        }
    }
    /*uij*/
    for (int i = 1; i < N-1; ++i)
    {
        for (int j = 1; j < M-1; ++j)
        {
            u[i][j]=u_next[i][j];
        }
    }
}

void putuij(double u[][M]){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            printf("%lf ",u[i][j]);
        }
        printf("\n");
    }
}

int getuij(double u[][M]){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if(getdouble(&u[i][j])==EOF){
                fprintf(stderr, "fail to load %d %d\n",i,j);
                return ERROR;
            }
        }
    }
    return 0;
}

int getdouble(double *x){
    char linebuf[BUFSIZE];
    int result=0;

    if(fgets(linebuf,BUFSIZE,stdin)!=NULL){
        if(sscanf(linebuf,"%lf",x)<=0){
            return EOF;
        }
    }
    else{
            return EOF;
    }
    return result;
}