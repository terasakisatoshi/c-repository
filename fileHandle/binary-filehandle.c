#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a[100];
    FILE *fp;
    fp=fopen("binary-filehandle.dat","w");
    if(fp==NULL){
        fprintf(stderr, "dat file not generated\n");
        exit(1);
    }else{
        srand((unsigned)time(NULL));
        for(int i=0;i<100;i++){
            a[i]=rand()%100;
            fprintf(fp, "%d\n",a[i]);
        }
        fclose(fp);
    }

    fp=fopen("binary-filehandle-binary.dat","wb");
    if(fp==NULL){
        fprintf(stderr, "binary dat file not generated\n");
        exit(1);
    }else{
        fwrite(a,sizeof(int),100,fp);//output as binary file
        fclose(fp);
    }

    fp=fopen("binary-filehandle-binary.dat","rb");
    if(fp==NULL){
        fprintf(stderr, "file not found\n");
        exit(1);
    }

    fread(a,sizeof(int),100,fp);
    for(int i=0;i<97;i+=4){
        printf("%d\t%d\t%d\t%d\n",a[i],a[i+1],a[i+2],a[i+3]);
    }
    return 0;

    return 0;
}