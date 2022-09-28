#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int A[4] = { 1,  2,  3,  4 };
int B[4] = { 5,  6,  7,  8 };
int C[4] = { 9, 10, 11, 12 };

int main(int argc, char *argv[]) 
{
    int i = -1;

    if (argc > 1) i = atoi( argv[1] );

    printf("B[%d] %d\n", i, B[i]);

    return 0;
}

