#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


unsigned int g_HZ = 1000;

unsigned int msec2tick(unsigned int msec)
{
    /*
    *    HZ
    *  ------ x msec = tick
    *   1000
    */
    return ((msec * g_HZ) / 1000);
}

unsigned int tick2msec(unsigned int tick)
{
    /*
    *   1000
    *  ------ x tick = msec
    *    HZ
    */
    return ((1000 * tick) / g_HZ);
}


int main(int argc, char *argv[])
{
    unsigned int msec = 1;
    unsigned int tick = 1;

    if (argc > 3)
    {
        g_HZ = atoi( argv[1] );
        msec = atoi( argv[2] );
        tick = atoi( argv[3] );
    }
    else if (argc > 2)
    {
        g_HZ = atoi( argv[1] );
        msec = atoi( argv[2] );
    }
    else if (argc > 1)
    {
        g_HZ = atoi( argv[1] );
    }
    else
    {
        printf("Usage: tick_msec HZ\n");
        printf("     : tick_msec HZ msec\n");
        printf("     : tick_msec HZ msec tick\n");
        printf("\n");
        return 0;
    }

    printf("HZ = %u\n", g_HZ);
    printf("msec %u ---> tick %u\n", msec, msec2tick( msec ));
    printf("tick %u ---> msec %u\n", tick, tick2msec( tick ));
    printf("\n");

    return 0;
}

