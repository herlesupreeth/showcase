#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    struct tm *pTm;
    time_t now;
    char tstamp[64];


    time( &now );
    pTm = localtime( &now );

    /* 
    * "YYYY_MM_DD_HH_MM_SS"
    */
    sprintf(
        tstamp,
        "%04u_%02u_%02u_%02u_%02u_%02u",
        pTm->tm_year + 1900,
        pTm->tm_mon + 1,
        pTm->tm_mday,
        pTm->tm_hour,
        pTm->tm_min,
        pTm->tm_sec
    );

    printf("%s\n", tstamp);
    return 0;
}
