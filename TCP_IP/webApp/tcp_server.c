#define _POSIX_C_SOURCE 1 
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>

int main(int argc, char const *argv[])
{
    int sock;
    struct sockaddr_in addr;
    int fd;
    FILE *socket_fp;
    FILE *file_out_fp;
    FILE *file_in_fp;
    int ch;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8001);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    ch=bind(sock, (struct sockaddr*)&addr, sizeof(addr));
    ch=listen(sock,5);
    printf("クライアントからの接続を待ちます．\n");
    fd=accept(sock,NULL,NULL);
    printf("クライアント接続\n");

    socket_fp=fdopen(fd,"r+");
    file_out_fp=fopen("server_recv.txt","w");

    while((ch=fgetc(socket_fp))!=0){
        fputc(ch, file_out_fp);
    }

    fclose(file_out_fp);

    file_in_fp=fopen("server_send.txt","r");
    while((ch=fgetc(file_in_fp))!=EOF){
        fputc(ch,socket_fp);
    }

    fclose(file_in_fp);

    fclose(socket_fp);
    printf("通信を終了しました.\n");

    return 0;
}