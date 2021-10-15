#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEGABYTE(n) (n << 20)

/*
*  cat /proc/$PID/maps
*
*  address            perms  offset    dev    inode  pathname
*  08048000-08056000  r-xp   00000000  03:0c  64593  /usr/sbin/gpm
*/

char g_string[80];

int main(int argc, char *argv[])
{
    void *pBuf = NULL;
    int size = 1;
    pid_t pid;

    if (argc > 1)
    {
        size = atoi( argv[1] );
    }
    else
    {
        printf("Usage: proc_maps [mega_byte]\n");
        printf("\n");
    }

    pid = getpid();
    printf("PID is %d\n", pid);
    printf("main() at %p\n", main);
    printf("g_string[80] at %p\n", g_string);

    if (size > 0)
    {
        pBuf = malloc( MEGABYTE(size) );
        memset(pBuf, 0x5A, MEGABYTE(size));
        printf(
            "pBuf at %p - %p (%d MB)\n",
            pBuf,
            (pBuf + MEGABYTE(size)),
            size
        );
    }

    sleep( 1 );

    printf("\n");
    memset(g_string, 0, 80);
    sprintf(g_string, "cat /proc/%u/maps", pid);
    system( g_string );
    printf("\n");

    printf("Press ENTER to terminate ...\n");
    getchar();

    if ( pBuf ) free( pBuf );
    return 0;
}

