#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    fprintf(stderr, "%c\n", spin[i & 0x3]);

    return 0;
}

