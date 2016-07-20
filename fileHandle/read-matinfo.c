#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 4

int main(){
    double a[ROW][COLUMN],b[ROW][COLUMN];
    FILE* fp;
    fp=fopen("read-matinfo.dat","r");
    if(fp==NULL){
        fprintf(stderr, "file not found read-matinfo.dat\n");
        exit(1);
    }else{
        printf("read mat info for A\n");
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COLUMN;j++){
                fscanf(fp,"%lf",&a[i][j]);
                printf("a[%d][%d]=%5.2f",i,j,a[i][j]);
                printf("\t");//space
            }
            printf("\n");
        }

        printf("read mat info for B\n");
        for(int i=0;i<ROW;i++){
            //you can scan line like below:
            fscanf(fp,"%lf %lf %lf %lf",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
            for(int j=0;j<COLUMN;j++){
                printf("b[%d][%d]=%5.2f",i,j,b[i][j]);
                printf("\t");//space
            }
            printf("\n");
        }
        fclose(fp);
    }
    return 0;
}