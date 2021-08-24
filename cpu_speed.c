#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    unsigned long long target;
    unsigned long long current;
    unsigned int interval = 50; /* usec */
    unsigned int count;

    if (argc > 1)
    {
        interval = (unsigned int)atoi( argv[1] );
    }

    #if 1
    struct sched_param param;
    int prio;

    prio = sched_get_priority_max(SCHED_FIFO);
    if (prio < 0)
    {
        perror( "sched_get_priority_max" );
    }
    else
    {
        param.sched_priority = prio;
        if (sched_setscheduler(getpid(), SCHED_FIFO, &param) < 0)
        {
            perror( "sched_setscheduler" );
        }
    }
    #endif

    count = 0;
    gettimeofday(&t1, NULL);
    target = (((t1.tv_sec * 1000000LL) + t1.tv_usec) + interval);
    do
    {
        count++;
        gettimeofday(&t2, NULL);
        current = ((t2.tv_sec * 1000000LL) + t2.tv_usec);
    } while (current < target);

    printf("\n");
    printf("Run while-loop %u times during %u usec\n", count, interval);
    printf("\n");
    printf(
        "start time: %u.%u\n",
        (unsigned int)t1.tv_sec,
        (unsigned int)t1.tv_usec
    );
    printf(
        "end   time: %u.%u\n",
        (unsigned int)t2.tv_sec,
        (unsigned int)t2.tv_usec
    );
    printf("\n");


    return 0;
}

