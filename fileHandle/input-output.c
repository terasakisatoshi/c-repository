#include <stdio.h>
#include <stdlib.h>

void file_read_write(FILE *fin,FILE *fout){
    double a;
    while(fscanf(fin,"%lf",&a)!=EOF){
        fprintf(fout, "%f\n",a );
    }
}

int main(){
    FILE *fin,*fout;
    fin=fopen("input-output.dat","r");
    fout=fopen("new-input-output.dat","w");

    if(fin==NULL){
        fprintf(stderr, "file not found\n");
        exit(1);
    }
    if(fout==NULL){
        fprintf(stderr, "file not generated\n");
        exit(1);
    }

    file_read_write(fin,fout);
    fclose(fin);
    fclose(fout);

    return 0;
}