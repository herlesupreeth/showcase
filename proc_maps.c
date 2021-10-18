#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KILOBYTE(n) (n << 10)

/*
*  cat /proc/$PID/maps
*
*  address            perms  offset    dev    inode  pathname
*  08048000-08056000  r-xp   00000000  03:0c  64593  /usr/sbin/gpm
*/

char g_string[80] = {
    'H', 'e', 'l', 'l', 'o', ',', 0x20, 'w', 'o', 'r', 'l', 'd', '!', 0x00,
};

int main(int argc, char *argv[])
{
    void *pBuf = NULL;
    char string[80];
    int size = 1;
    pid_t pid;

    if (argc > 1)
    {
        size = atoi( argv[1] );
    }
    else
    {
        printf("Usage: proc_maps [KB]\n\n");
    }

    pid = getpid();
    printf("PID is [1;33m%d[0m\n\n", pid);
    printf("main()       at %p\n", main);
    printf("printf()     at %p\n", printf);
    printf("g_string[80] at %p\n", g_string);
    printf("string[80]   at %p\n", string);

    if (size > 0)
    {
        pBuf = malloc( KILOBYTE(size) );
        memset(pBuf, 0x5A, KILOBYTE(size));
        printf(
            "pBuf         at %p - %p (%d KB)\n",
            pBuf,
            (pBuf + KILOBYTE(size)),
            size
        );
    }

    usleep( 10000 );

    printf("\n");
    memset(string, 0, 80);
    sprintf(string, "cat /proc/%u/maps", pid);
    system( string );
    printf("\n");

    printf("Press ENTER to terminate ...\n");
    getchar();

    if ( pBuf ) free( pBuf );
    return 0;
}

