#include <stdio.h>
#include <pthread.h>

const int ThreadNum=4;

int helloThread(void * arg){
    int *p = (int *) arg;
    int num = *p;
    printf("HelloWorld %d\n",num);
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t thread_p[ThreadNum];
    int threadN[ThreadNum];
    for(int i=0;i<ThreadNum;i++){
        threadN[i]=i;
        pthread_create(&thread_p[i],NULL,&helloThread,(void *)&threadN[i]);
    }

    for(int i=0;i<ThreadNum;i++){
        pthread_join(thread_p[i],NULL);
    }
    return 0;
}