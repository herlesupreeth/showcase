#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>


unsigned char g_data[655360];
int g_dataLen = sizeof(g_data);

int main(int argc, char *argv[])
{
    struct sockaddr_in localAddr;
    struct sockaddr_in remoteAddr;
    socklen_t localAddrLen;
    socklen_t remoteAddrLen;
    int option;
    int fd;

    int segment = 8192;
    int len;


    if (argc > 1) segment = atoi( argv[1] );

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror( "socket" );
        return -1;
    }

    /* enable the port number re-use */
    option = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    localAddrLen = sizeof( struct sockaddr_in );
    localAddr.sin_family      = AF_INET;
    localAddr.sin_port        = htons( 50001 );
    localAddr.sin_addr.s_addr = htonl( INADDR_ANY );

    if (bind(fd, (struct sockaddr *)&localAddr, localAddrLen) < 0)
    {
        perror( "bind" );
        close( fd );
        return -1;
    }

    if (listen(fd, 4) < 0)
    {
        perror( "listen" );
        close( fd );
        return -1;
    }

    printf("TCP server listen (segment %d)\n", segment);

    for (;;)
    {
        int sock;

        remoteAddrLen = sizeof( struct sockaddr_in );
        bzero(&remoteAddr, remoteAddrLen);
        sock = accept(
                   fd,
                   (struct sockaddr *)&remoteAddr,
                   &remoteAddrLen
               );
        if (sock < 0)
        {
            perror( "accept" );
            break;
        }

        printf("TCP client connect from %s\n", inet_ntoa(remoteAddr.sin_addr));
        option = 1;
        setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &option, sizeof(option));

        if ( segment )
        {
            unsigned char *pBuf = g_data;
            int total = g_dataLen;
            int i = 1;

            for (;;)
            {
                len = (total >= segment) ? segment : total;
                if ((len = send(sock, pBuf, len, 0)) < 0)
                {
                    perror( "send" );
                    break;
                }

                printf("TCP server send %d bytes (%d)\n", len, i++);
                total -= len;
                if (total <= 0) break;
                pBuf += len;
            }
        }
        else
        {
            if ((len = send(sock, g_data, g_dataLen, 0)) < 0)
            {
                perror( "send" );
                break;
            }
            printf("TCP server send %d bytes\n", len);
        }

        printf("TCP server send completed\n\n");
        close( sock );
    }

    close( fd );
    return 0;
}
