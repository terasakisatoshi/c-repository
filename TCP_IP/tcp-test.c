#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RCVBUFSIZE 32 

void DieWIthError(char *errorMessage);

int main(int argc,char *argv[]){
    int sock;
    struct sockaddr_in echoSerAddr;
    unsigned short echoSerPort;
    char * serveIP;
    char *echoString;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRcvd,totalBytesRcvd;

    if ((argc <3) || (argc>4)){
        fprintf(stderr,'Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n',argv[0]);
        exit(1);
    }

    servIP=argv[1];
    echoString = argv[2];

    if (argc==4){
        echoServPort=atoi(argv[3]);
    }
    else{
        echoServPort=7;
    }

    if ((sock=socket(PF_INET,SOCK_stREAM,IPPROT_TCP))<0){
        DieWIthError("socket failed");
    }

    echoStringLen=strlen(echoString);

    if(send(sock,echoString,echoStringLen,0)!=echoStringLen){
        DieWIthError("send() send a different number of bytes than expected");
    }

    totalBytesRcvd=0;
    printf("Recv:\n");
    while(totalBytesRcvd<echoStringLen){
        if(bytesRcvd=recv(sock,echoBuffer,RCVBUFSIZE-1,0)<=0){
            DieWIthError("recv() failed or connection closed prematurely");
        }
        totalBytesRcvd+=bytesRcvd;
        echoBuffer[bytesRcvd]='\0';
        printf(echoBuffer);
    }
    printf("\n");
    close(sock);
    return 0;
}