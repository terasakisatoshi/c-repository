#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPENDING 5 
#define RCVBUFSIZE 32

void DieWithError(char * errorMessage){
    perror(errorMessage);
    exit(1);
}

void HandleTCPClient(int clntSocket){
    char echoBuffer[RCVBUFSIZE];
    int recvMsgSize;

    if((recvMsgSize=recv(clntSocket,echoBuffer,RCVBUFSIZE,0))<0){
        DieWithError("recv() failed");
    }

    while(recvMsgSize>0){
        if(send(clntSocket,echoBuffer,recvMsgSize,0)!=recvMsgSize){
            DieWithError("send() failed");
        }

        if((recvMsgSize=recv(clntSocket,echoBuffer,RCVBUFSIZE,0))<0){
            DieWithError("recv() failed");
        }
    }
    close(clntSocket);
}

int main(int argc, char const *argv[])
{
    int servSock;
    int clntSock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned short echoServPort;
    unsigned int clntLen;

    if (argc !=2)
    {
        fprintf(stderr, "Usage: %s <Server Port>\n",argv[0]);
        exit(1);
    }

    echoServPort=atoi(argv[1]);

    if((servSock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
        DieWithError("socket() failed");
    }

    memset(&echoServAddr,0,sizeof(echoServAddr));
    echoServAddr.sin_family=AF_INET;
    echoServAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    echoServAddr.sin_port=htons(echoServPort);

    if(bind(servSock,(struct sockaddr *)&echoServAddr,sizeof(echoServAddr))<0){
        DieWithError("bind failed");
    }

    if(listen(servSock,MAXPENDING)<0){
        DieWithError("listen() failed");
    }

    while(1){
        clntLen=sizeof(echoClntAddr);
        if((clntSock=accept(servSock,(struct sockaddr *)&echoClntAddr,&clntLen))<0){
            DieWithError("accpect() failed");
        }

        printf("Handling client %s \n", inet_ntoa(echoClntAddr.sin_addr));
        HandleTCPClient(clntSock);
    }
    return 0;
}
