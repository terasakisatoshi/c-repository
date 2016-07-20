#include <stdio.h>
#include <stdlib.h>

int main(){
    double a=10.0;
    FILE *fp;
    fp=fopen("openfile-intro.dat","r");
    if(fp!=NULL){
        printf("open file...\n");
        while(a>0){
            printf("read...\n");
            fscanf(fp,"%lf",&a);
            printf("show read result... '%f'\n",a);
        }
        fclose(fp);
    }else{
        printf("file not found\n");
        exit(1);
    }
    return 0;
}