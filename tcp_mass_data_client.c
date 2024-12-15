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

    struct timespec ts[2];
    double td[2] = { 0, 0 };
    char *pAddr = "127.0.0.1";
    int total = 0;
    int len;


    if (argc > 1) pAddr = argv[1];

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
    localAddr.sin_port        = htons( 50002 );
    localAddr.sin_addr.s_addr = htonl( INADDR_ANY );

    if (bind(fd, (struct sockaddr *)&localAddr, localAddrLen) < 0)
    {
        perror( "bind" );
        close( fd );
        return -1;
    }

    remoteAddrLen = sizeof( struct sockaddr_in );
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port   = htons( 50001 );
    remoteAddr.sin_addr.s_addr = inet_addr( pAddr );

    printf("TCP client connect to %s\n", pAddr);
    if (connect(
            fd,
            (struct sockaddr *)&remoteAddr,
            remoteAddrLen) < 0)
    {
        perror( "connect" );
        close( fd );
        return -1;
    }

    for (;;)
    {
        clock_gettime(CLOCK_MONOTONIC, &(ts[0]));

        len = recv(fd, g_data, g_dataLen, 0);
        if (len <= 0)
        {
            perror( "recv" );
            break;
        }

        clock_gettime(CLOCK_MONOTONIC, &(ts[1]));
        td[0] = ((ts[1].tv_sec * 1000000000L) + ts[1].tv_nsec) -
                ((ts[0].tv_sec * 1000000000L) + ts[0].tv_nsec);
        td[1] += td[0];
        printf("%d ... %f us\n", len, td[0]/1e6);

        total += len;
        if (total >= g_dataLen)
        {
            printf("TCP client receive completed\n");
            break;
        }
    }

    printf("%d ... %f us (total)\n", total, td[1]/1e6);
    close( fd );
    return 0;
}
