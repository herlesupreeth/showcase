#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

/* valgrind --leak-check=full ./memory_leak */
#define MEMORY_LEAK 0

void *routine(void *arg)
{
    printf("thread ... enter\n");
    sleep(1);
    printf("thread ... exit\n");

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thread;

    printf("main ..... enter\n");

    if (pthread_create(&thread, NULL, routine, NULL) != 0)
    {
        perror( "pthread_create" );
        return 0;
    }

    sleep(3);

    #if !(MEMORY_LEAK)
    pthread_join(thread, NULL);
    #endif

    printf("main ..... exit\n");
    return 0;
}

