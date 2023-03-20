#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define DO_READ    1
#define DO_SCANF   1
#define DO_GETCHAR 1
#define DO_GETC    1
#define DO_FGETS   1
#define DO_GETLINE 1


unsigned char g_buf[256];

int main(void)
{
    char spin[4] = { '-', '\\', '|', '/' };
    int i = 0;

    for (;;)
    {
        fprintf(stderr, "%c", spin[i & 0x3]);
        i++;
        usleep(100000);
        fprintf(stderr, "\b");
    }
    fprintf(stderr, "\n");

    return 0;
}

