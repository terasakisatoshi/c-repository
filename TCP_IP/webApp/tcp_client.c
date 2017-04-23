#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
    int sock;
    struct sockaddr_in addr;
    struct hostent *host;
    FILE *socket_fp;
    FILE *file_out_fp;
    FILE *file_in_fp;
    int ch;

    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(8001);

    host=gethostbyname("localhost");
    memcpy(&addr.sin_addr, host->h_addr_list[0], sizeof(addr.sin_addr));

    sock=socket(AF_INET,SOCK_STREAM,0);
    connect(sock, (struct sockaddr*)&addr,sizeof(struct sockaddr_in));
    socket_fp = fdopen(sock,"r+");
    file_in_fp=fopen("client_send.txt","r");

    while((ch=fgetc(file_in_fp)) != EOF){
        fputc(ch, socket_fp);
    }

    fclose(file_in_fp);
    fputc(0,socket_fp);
    file_out_fp=fopen("client_recv.txt","w");
    while((ch=fgetc(socket_fp))!=EOF){
        fputc(ch,file_out_fp);
    }
    fclose(file_out_fp);

    return 0;
}