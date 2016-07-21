#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
*create matrix as a 2-dim array
*row index starts from 1 to num of row
*col index starts from 1 to num of col 
*/
double** create_matrix(int row,int col){
    double** a=(double**)malloc(sizeof(double*)*row);
    if(a==NULL){
        fprintf(stderr, "fail to allocate\n");
        exit(1);
    }
    //shift row index
    a=a-1;
    
    for (int i = 1; i <=row; ++i)
    {
        a[i]=(double*)malloc(sizeof(double)*col);
        if(a[i]==NULL){
            fprintf(stderr, "fail to allocate for %d-th row\n", i);
            exit(1);
        }
        //shift col index
        a[i]=a[i]-1;
    }

    return(a);
}

/**
*free memory created by the function named
*create_matrix
*/
void free_matrix(double** a,int row){
    for (int i = 1; i <=row; ++i)
    {
        free((void*)(a[i]+1));
    }
    free((void*)(a+1));
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int row=2,col=3;

    double** a=create_matrix(row,col);
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            a[i][j]=rand()%10;
            printf("a[%d][%d]=%f\n",i,j,a[i][j]);
        }
    }

    free_matrix(a,row);

    return 0;
}