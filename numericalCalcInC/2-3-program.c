#include <stdio.h>
#include <stdlib.h>

#define N 4

//allocate memory you can access as a[i],...,a[j]
double* dvector(int i,int j){
    double *a=(double *)malloc((j-i+1)*sizeof(double));
    if(a==NULL){
        fprintf(stderr, "fail to allocate\n");
        exit(1);
    }

    return(a-i);
}

//free memory allocated by dvector
//int i is the first argument of dvector(int i, int j)
void free_dvector(double *a,int i){
    free((void*)(a+i));
}


//allocate matrix memory
double **dmatrix(int nr1,int nr2,int nl1,int nl2){
    int nrow,ncol;
    nrow =nr2-nr1+1;
    ncol =nl2-nl1+1;
    double **a=(double**)malloc(nrow*sizeof(double*));
    //allocate for rows
    if(a==NULL){
        printf("fail to allocate\n");
        exit(1);
    }

    a=a-nr1;

    //allocate for cols
    for(int i=nr1;i<=nr2;i++){
        a[i]=(double*)malloc(ncol*sizeof(double));
    }
    for(int i=nr1;i<=nr2;i++){

        a[i]=a[i]-nl1;
    }
    return (a);
}
//free matrix memory created by dmatrix
void free_dmatrix(double **a,int nr1,int nr2,int nl1,int nl2){
    for(int i=nr1;i<=nr2;++i){
        free((void*)(a[i]+nl1));
    }
    free((void*)(a+nr1));
}

//a[1,...,N][1,...,N]
void input_matrix(double **a,char c,FILE *fin,FILE *fout){
    fprintf(fout, "show matrix %c\n",c);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;j++){
            fscanf(fin,"%lf",&a[i][j]);
            fprintf(stderr,"%5.2f\t\n",a[i][j]);
            fprintf(fout, "%5.2f\t",a[i][j]);
        }
        fprintf(fout,"\n");
    }
}

//b[1,...,N]
void input_vector(double *b,char c,FILE *fin,FILE *fout){
    fprintf(fout, "show vector %c\n",c);
    for(int i=1;i<=N;i++){
        fscanf(fin,"%lf",&b[i]);
        fprintf(fout, "%5.2f\t\n",b[i]);
    }
}

int main(int argc, char const *argv[])
{
    FILE *fin=fopen("2-3-input.dat","r");
    FILE *fout=fopen("2-3-output.dat","w");
    double **a,*b;
    a=dmatrix(1,N,1,N);
    b=dvector(1,N);
    if(fin==NULL){
        fprintf(stderr, "file not found : 2-3-input.dat\n");
        exit(1);
    }
    if(fout==NULL){
        fprintf(stderr, "fail to make file 2-3-output.dat\n");
        exit(1);
    }
    input_matrix(a,'A',fin,fout);
    input_vector(b,'B',fin,fout);
    fclose(fin);
    fclose(fout);
    /*free allocate*/
    free_dmatrix(a,1,N,1,N);
    free_dvector(b,1);

    return 0;
}


