#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>


unsigned char g_data[163840];
int g_dataLen = sizeof(g_data);

int main(int argc, char *argv[])
{
    struct sockaddr_in localAddr;
    struct sockaddr_in remoteAddr;
    socklen_t localAddrLen;
    socklen_t remoteAddrLen;
    int option;
    int fd;

    char *pAddr = "127.0.0.1";
    int segment = 65507;
    int len;


    if (argc > 2)
    {
        segment = atoi( argv[1] );
        pAddr = argv[2];
    }
    else if (argc > 1)
    {
        segment = atoi( argv[1] );
    }

    fd = socket(AF_INET, SOCK_DGRAM, 0);
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
    localAddr.sin_port        = htons( 50002 );
    localAddr.sin_addr.s_addr = htonl( INADDR_ANY );

    if (bind(fd, (struct sockaddr *)&localAddr, localAddrLen) < 0)
    {
        perror( "bind" );
        close( fd );
        return -1;
    }

    printf("UDP peer address %s (segment %d)\n", pAddr, segment);
    remoteAddrLen = sizeof( struct sockaddr_in );
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port   = htons( 50001 );
    remoteAddr.sin_addr.s_addr = inet_addr( pAddr );

    if ( segment )
    {
        unsigned char *pBuf = g_data;
        int total = g_dataLen;
        int i = 1;

        for (;;)
        {
            len = (total >= segment) ? segment : total;
            if ((len = sendto(
                           fd,
                           pBuf,
                           len,
                           0,
                           (struct sockaddr *)(&remoteAddr),
                           remoteAddrLen)) < 0)
            {
                perror( "sendto" );
                break;
            }

            printf("UDP send %d bytes (%d)\n", len, i++);
            total -= len;
            if (total <= 0) break;
            pBuf += len;
        }
    }
    else
    {
        if ((len = sendto(
                       fd,
                       g_data,
                       g_dataLen,
                       0,
                       (struct sockaddr *)(&remoteAddr),
                       remoteAddrLen)) < 0)
        {
            perror( "sendto" );
        }
        printf("UDP send %d bytes\n", len);
    }

    printf("UDP send completed\n\n");
    close( fd );
    return 0;
}
