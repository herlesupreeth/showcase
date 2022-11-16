#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double A = -1;
    double R;

    if (argc > 1) A = strtod(argv[1], NULL);
    R = sqrt( A );

    if ( isnan(R) ) printf("NaN: ");
    printf("sqrt( %f ) = %f\n", A, R);

    return 0;
}

