#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define DT 0.005 /*刻みはば*/
#define TIMELIMIT 20.0 /*プログラムスタートからシミュレーション打ち切りまでの時間*/
#define R 0.1 /* 配置電荷と運動する電荷との距離の最小値*/
#define BUFSIZE 256 /*入力バッファ最大値*/
#define N 256 /*配置できる電荷の最大値*/
#define INITIAL_TIME 0.0

#define PI 3.141592653589793238
#define EPSILON_ZERO 8.854e-12

struct coordinate{
    double x;
    double y;
};

/**
*電荷構造体
*/
struct charge{
    struct coordinate qxy;
    double q;
};

/**
*実数入力インターフェイス
<@ in > double x
<@ out> 標準入力で得た値を実数として変換してxに格納．もしも変換できなけれはEOFを返す．
*/
int getdouble(double *x){
    char linebuf[BUFSIZE];
    int result=0;

    if(fgets(linebuf,BUFSIZE,stdin)!=NULL){//読み込み可能
        if(sscanf(linebuf,"%lf",x)<=0){//文字を実数に変換できなければ
            fprintf(stderr, "fail to convert into double\n");
            return EOF;//return error
        }
        else{
            fprintf(stderr, "suceed to read%f\n",*x);
        }
    }else{
        fprintf(stderr, "fail to read line\n");
        return EOF;
    }
    return result;
}

/**
*電荷の位置情報を入力
*戻り値は入力された電荷の個数．
*/
int inputq(struct charge qi[]){
    int i=0;
    for(i=0;i<N;i++){
        fprintf(stderr, "%d番目の電荷情報を入力していきます．\n",i);
        fprintf(stderr, "電荷の配置位置のx成分を入力\n");
        if(getdouble(&qi[i].qxy.x)==EOF) 
            break;
        fprintf(stderr, "電荷の配置位置のy成分を入力\n");
        if(getdouble(&qi[i].qxy.y)==EOF)
            break;
        fprintf(stderr, "電荷量を入力\n");
        if(getdouble(&qi[i].q)==EOF)
            break;
    }
    return i;
}

/**
*main
*/
int main(){
    double t=INITIAL_TIME;
    double h=DT;
    double rx,ry,r,rmin;/*電荷と質点の距離*/

    struct coordinate v,x;
    fprintf(stderr,"初速度vのx成分を入力\n");
    if(getdouble(&v.x)==EOF)
        exit(1);
    fprintf(stderr,"初速度vのy成分を入力\n");
    if(getdouble(&v.y)==EOF)

    fprintf(stderr,"初期位置のx成分を入力\n");
    if(getdouble(&x.x)==EOF)
        exit(1);
    fprintf(stderr,"初期位置のy成分を入力\n");
    if(getdouble(&x.y)==EOF)
        exit(1);
    
    struct charge qi[N];
    int nofq=inputq(qi);
    printf("%f\t%f\t%f\t%f\t%f\n",t,x.x,x.y,v.x,v.y);

    while(t<=TIMELIMIT){
        t+=h;
        rmin=DBL_MAX;
        for (int i = 0; i < nofq; ++i)
        {
            rx=qi[i].qxy.x-x.x;
            ry=qi[i].qxy.y-x.y;
            r=sqrt(rx*rx+ry*ry);
            if(r<rmin){
                rmin=r;
            }
            v.x+=1/4/PI/EPSILON_ZERO*(rx/r/r/r*qi[i].q)*h;/*速度の計算*/
            v.y+=1/4/PI/EPSILON_ZERO*(ry/r/r/r*qi[i].q)*h;/*速度の計算*/
        }
        x.x+=v.x*h;/*位置の計算*/
        x.y+=v.y*h;/*位置の計算*/
        printf("%f\t%f\t%f\t%f\t%f\n",t,x.x,x.y,v.x,v.y);
        if(rmin<R){
            break;
        }
    }
    return 0;
}