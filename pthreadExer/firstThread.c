#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void *threadFunc(void *arg){
    for(int i=0; i<3;i++){
        printf("I'm threadFunc: %d\n",i);
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t thread;
    if(pthread_create(&thread, NULL, threadFunc, NULL)!=0) {
        printf("Error: Failed to create new thread.\n");
        exit(1);
    }

    for(int i=0;i<5;i++){
        printf("I'm main: %d\n", i);
        sleep(1);
    }

    return 0;
}