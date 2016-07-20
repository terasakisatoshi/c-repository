#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    double a=1.0;
    fp=fopen("openfile-2column.dat","r");
    if(fp==NULL)
    {
        fprintf(stderr, "file not found openfile-2column.dat\n");
        exit(1);
    }
    else
    {
        while(a>0)
        {
            fscanf(fp,"%lf",&a);
            printf("a=%f\n",a);
        }
    }
    fclose(fp);
    return 0;
}