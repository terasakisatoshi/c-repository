#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    double sum=0.0;
    double a;
    fp=fopen("readtoEOF.dat","r");
    if(fp==NULL){
        printf("file not found readtoEOF.dat\n");
        exit(1);
    }else{
        while(fscanf(fp,"%lf",&a)!=EOF){
            printf("%f\n",a);
            sum+=a;
        }
        printf("sum of values written in dat is %f\n",sum);
        fclose(fp);
    }
    return 0;
}