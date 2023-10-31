#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int INIT(int init)
{
    printf("[1] INIT %d\n\n", init);
    return init;
}

int COND(int cond)
{
    printf("[2] COND %d\n", cond);
    return cond;
}

int LOOP(int loop)
{
    printf("[3] LOOP %d\n", loop);
    return loop;
}

int NEXT(int next)
{
    printf("[4] NEXT %d\n\n", next);
    return next;
}

int main(void)
{
    int i;

    for (i=INIT(0); COND(i<10); i=NEXT(i+1))
    {
        LOOP(i);
    }

    return 0;
}

