#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double A = 0;
    double R;

    if (argc > 1) A = strtod(argv[1], NULL);
    R = log10( A );

    if ( isinf(R) ) printf("INF: ");
    printf("log10( %f ) = %f\n", A, R);

    return 0;
}

